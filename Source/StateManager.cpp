 #include "StateManager.h"


void StateManager::AddState(StateRef newState, bool isReplacing, bool _processParent)
{
	this->_isAdding = true;
	this->_isReplacing = isReplacing;
	this->_processParent = _processParent;

	this->_newState = std::move(newState);
}

void StateManager::RemoveState()
{
	this->_isRemoving = true;
}

void StateManager::ProcessStateChanges()
{
	if (this->_isRemoving && !this->_states.empty())
	{
		this->_states.pop_back();

		if (!this->_states.empty())
		{
			this->_states.back()->Resume();
		}

		this->_isRemoving = false;
	}

	if (this->_isAdding)
	{
		if (!this->_states.empty())
		{
			if (this->_isReplacing)
			{
				while (!_states.empty()) this->_states.pop_back();
			}
			else
			{
				this->_states.back()->Pause();
			}
		}
		else {
			if (this->_processParent) {
				this->_processParent = false;
			}
		}

		this->_states.push_back(std::move(this->_newState));
		this->_states.back()->Init();
		this->_isAdding = false;
	}
}

StateRef &StateManager::GetActiveState()
{
	return this->_states.back();
}

void StateManager::Render(sf::RenderWindow* window) {
	if (this->_processParent) {
		this->_states.front()->Render(window);
		/*auto p = this->_states.end();
		p--; p--;
		p->get()->Render(window);*/
	}
	this->GetActiveState()->Render(window);
}

void StateManager::clear() {
	while (!_states.empty()) {
		_states.pop_back();
	}
}