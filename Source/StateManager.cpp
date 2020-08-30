// Precompiled Headers
#include "stdafx.h"

#include "StateManager.h"

StateManager::StateManager() {
}

StateManager::~StateManager() {
}

void StateManager::AddState(StateRef newState, bool isReplacing) {
	this->m_isAdding = true;
	this->m_isReplacing = isReplacing;

	this->m_srNewState = std::move(newState);
}

void StateManager::AddState(StateRef newState) {
	this->m_isAdding = true;
	this->m_isReplacing = true;

	this->m_srNewState = std::move(newState);
}

void StateManager::RemoveState() {
	this->m_isRemoving = true;
}

void StateManager::ProcessStateChanges()
{
	if (this->m_isRemoving && !this->m_aState.empty())
	{
		this->m_aState.pop();
		if (!this->m_aState.empty())
		{
			this->m_aState.top()->Resume();
		}
		this->m_isRemoving = false;
	}

	if (this->m_isAdding)
	{
		if (!this->m_aState.empty())
		{
			if (this->m_isReplacing)
			{
				this->m_aState.pop();
			}
			else
			{
				this->m_aState.top()->Pause();
			}
		}
		this->m_aState.push(std::move(this->m_srNewState));
		this->m_aState.top()->Init();
		this->m_isAdding = false;
	}
}
StateRef& StateManager::GetActiveState()
{
	return this->m_aState.top();
}