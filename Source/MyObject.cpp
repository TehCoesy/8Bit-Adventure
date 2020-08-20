// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

MyObject::MyObject() {
}

MyObject::~MyObject() {
}

int* MyObject::GetID() {
	return &m_iID;
}

std::string* MyObject::GetName() {
	return &m_strName;
}

void MyObject::Update(float fDeltaTime) {

}

void MyObject::Render(sf::RenderWindow* MainWindow) {
	for (int i = 0; i < m_AnimationList.size(); i++)
	{
		if (m_AnimationList.at(i).GetID() == m_iDirection)
		{
			for (int k = 0; k < m_AnimationList.at(i).GetAnimationFrames().size(); k++)
			{
				MainWindow->clear();

				m_Texture = RM->GetTexture(m_AnimationList.at(i).GetAnimationFrames().at(k).GetID());
				m_Sprite.setTexture(*m_Texture.GetTexture());
				m_Sprite.setScale(2.0f, 2.0f);
				MainWindow->draw(m_Sprite);

				MainWindow->display();
			}
			break;
		}
	}
}

void MyObject::SetDirection(int iDirection)
{
	m_iDirection = iDirection;
}

void MyObject::AddAnimation(int iAnimID) {
	for (int i = 0; i < RM->GetAnimationList().size(); i++)
	{
		if (RM->GetAnimationList().at(i).GetID() == iAnimID)
		{
			m_AnimationList.push_back(RM->GetAnimationList().at(i));
			break;
		}
	}
}
