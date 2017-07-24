#pragma once
class GameState
{
	friend class GameStateManager;
public:
	GameState() {}
	virtual ~GameState() {}
	bool isActive() const { return m_active; }

protected:

	void enter() { m_active = true; onEnter(); } 
	void exit() { m_active = false; onExit(); } 
	
	virtual void onUpdate(float deltaTime) = 0; 
	virtual void onDraw() = 0;

	// can be overwritten in derived classes that need to behave 
	// in certain ways when activated/deactivated or pushed/popped 
	virtual void onEnter() {} 
	virtual void onExit() {} 
	virtual void onPushed() {} 
	virtual void onPopped() {}

private:
	bool m_active = false;
};

