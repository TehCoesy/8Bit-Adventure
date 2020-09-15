#pragma once

#include <memory>
#include <stack>
#include <list>
#include "State.h"
#include"Singleton.h"


typedef std::unique_ptr<State> StateRef;

class StateManager: public Singleton<StateManager>
{
public:
	StateManager() { _processParent = false; }
	~StateManager() { }

	void AddState(StateRef newState, bool isReplacing = true, bool _processParent = false);
	void RemoveState();
	
	void ProcessStateChanges();
	void Render(sf::RenderWindow* window);

	StateRef &GetActiveState();
	void clear();

private:
	std::list<StateRef> _states;
	StateRef _newState;

	bool _isRemoving;
	bool _isAdding, _isReplacing;
	bool _processParent;
};
