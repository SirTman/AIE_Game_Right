#pragma once
#include <string>
class Splash
{
public:
	Splash();
	virtual void RunningSplash();
	~Splash();
private:
	std::string m_title = "Char Snap";
	std::string m_flashText = "[Press Enter]";
	int m_counter = 0;
	bool m_ShowFlashText = true;
	
	bool m_KeyPressed = false;
};
