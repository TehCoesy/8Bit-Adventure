#pragma once
#include <memory>
#include <stack>
// Precompiled Headers
#include "stdafx.h"

// Local
#include "Singleton.h"
#include "State.h"

typedef std::unique_ptr<State> StateRef;
class StateManager : public Singleton<StateManager> {
private:
	std::stack<StateRef> m_aState;
	StateRef m_srNewState;

	bool m_isRemoving;
	bool m_isAdding;
	bool m_isReplacing;
public:
	StateManager();
	~StateManager();

	void AddState(StateRef newState, bool isReplacing = true);
	void AddState(StateRef newState);
	void RemoveState();

	void ProcessStateChanges();

	StateRef& GetActiveState();
};