#include "gameObject.h"
#include <assert.h>
#include "global.h"

//�R���X�g���N�^�i�e�����O���Ȃ��j
GameObject::GameObject(void) :
	GameObject(nullptr, "")
{

}

//�R���X�g���N�^�i���O�Ȃ��j
GameObject::GameObject(GameObject * parent) :
	GameObject(parent, "")
{
}

//�R���X�g���N�^�i�W���j
GameObject::GameObject(GameObject * parent, const std::string& name)
	: pParent_(parent),



	objectName_(name)
{
	childList_.clear();
	state_ = { 0, 1, 1, 0 };

	if(parent)
		transform_.pParent_ = &parent->transform_;

}

//�f�X�g���N�^
GameObject::~GameObject()
{
}

// �폜���邩�ǂ���
bool GameObject::IsDead()
{
	return (state_.dead != 0);
}

// �������폜����
void GameObject::KillMe()
{
	state_.dead = 1;
}

// Update������
void GameObject::Enter()
{
	state_.entered = 1;
}

// Update������
void GameObject::Leave()
{
	state_.entered = 0;
}

// Draw������
void GameObject::Visible()
{
	state_.visible = 1;
}

// Draw������
void GameObject::Invisible()
{
	state_.visible = 0;
}

// �������ς݂��ǂ���
bool GameObject::IsInitialized()
{
	return (state_.initialized != 0);
}

// �������ς݂ɂ���
void GameObject::SetInitialized()
{
	state_.initialized = 1;
}

// Update���s���Ă�����
bool GameObject::IsEntered()
{
	return (state_.entered != 0);
}

// Draw���s���Ă�����
bool GameObject::IsVisibled()
{
	return (state_.visible != 0);
}

//�q�I�u�W�F�N�g���X�g���擾
std::list<GameObject*>* GameObject::GetChildList()
{
	return &childList_;
}

//�e�I�u�W�F�N�g���擾
GameObject * GameObject::GetParent(void)
{
	return pParent_;
}

//���O�ŃI�u�W�F�N�g�������i�Ώۂ͎����̎q���ȉ��j
GameObject * GameObject::FindChildObject(const std::string & name)
{
	//�q�������Ȃ��Ȃ�I���
	if (childList_.empty())
		return nullptr;

	//�C�e���[�^
	auto it = childList_.begin();	//�擪
	auto end = childList_.end();	//����

	//�q�I�u�W�F�N�g����T��
	while (it != end) {
		//�������O�̃I�u�W�F�N�g���������炻���Ԃ�
		if ((*it)->GetObjectName() == name)
			return *it;

		//���̎q���i���j�ȍ~�ɂ��Ȃ����T��
		GameObject* obj = (*it)->FindChildObject(name);
		if (obj != nullptr)
		{
			return obj;
		}

		//���̎q��
		it++;
	}

	//������Ȃ�����
	return nullptr;
}

//�I�u�W�F�N�g�̖��O���擾
const std::string& GameObject::GetObjectName(void) const
{
	return objectName_;
}

//�q�I�u�W�F�N�g��ǉ��i���X�g�̍Ō�ցj
void GameObject::PushBackChild(GameObject * obj)
{
	assert(obj != nullptr);

	obj->pParent_ = this;
	childList_.push_back(obj);
}

//�q�I�u�W�F�N�g��ǉ��i���X�g�̐擪�ցj
void GameObject::PushFrontChild(GameObject * obj)
{
	assert(obj != nullptr);

	obj->pParent_ = this;
	childList_.push_front(obj);
}

//�q�I�u�W�F�N�g��S�č폜
void GameObject::KillAllChildren(void)
{
	//�q�������Ȃ��Ȃ�I���
	if (childList_.empty())
		return;

	//�C�e���[�^
	auto it = childList_.begin();	//�擪
	auto end = childList_.end();	//����

	//�q�I�u�W�F�N�g��1���폜
	while (it != end)
	{
		KillObjectSub(*it);
		delete *it;
		it = childList_.erase(it);
	}

	//���X�g���N���A
	childList_.clear();
}

//�I�u�W�F�N�g�폜�i�ċA�j
void GameObject::KillObjectSub(GameObject * obj)
{
	if (!childList_.empty())
	{
		auto list = obj->GetChildList();
		auto it = list->begin();
		auto end = list->end();
		while (it != end)
		{
			KillObjectSub(*it);
			delete *it;
			it = list->erase(it);
		}
		list->clear();
	}
	obj->Release();
}


//RootJob���擾
GameObject * GameObject::GetRootJob()
{
	if (GetParent() == nullptr)
	{
		return this;
	}
	else return GetParent()->GetRootJob();
}




void GameObject::UpdateSub()
{
	Update();
	Transform();

	for (auto it = childList_.begin(); it != childList_.end(); it++)
	{
		(*it)->UpdateSub();
	}

	for (auto it = childList_.begin(); it != childList_.end();)
	{
		if ((*it)->IsDead() == true)
		{
			(*it)->ReleaseSub();
			SAFE_DELETE(*it);
			it = childList_.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void GameObject::DrawSub()
{
	Draw();

	//���̎q�I�u�W�F�N�g�̕`�揈��
	for (auto it = childList_.begin(); it != childList_.end(); it++)
	{
		(*it)->DrawSub();
	}
}

void GameObject::ReleaseSub()
{
	for (auto it = childList_.begin(); it != childList_.end(); it++)
	{
		(*it)->ReleaseSub();
		SAFE_DELETE(*it);
	}

	Release();
}




////���[�J���s��̎擾�i���̃I�u�W�F�N�g�̍s��j
//XMMATRIX GameObject::GetLocalMatrix(void)
//{
//	return transform_.GetWorldMatrix();
//}

//���[���h�s��̎擾�i�e�̉e�����󂯂��ŏI�I�ȍs��j
XMMATRIX GameObject::GetWorldMatrix(void)
{
	return transform_.GetWorldMatrix();
}

