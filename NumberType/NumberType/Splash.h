#pragma once
#include <string>
class Splash
{
public:
	Splash();

	std::string m_title = "Char Type";
	std::string m_flashText = "[Press Enter]";

	bool m_ShowFlashText = true;
	bool m_KeyPressed = false;
	

	virtual void RunningSplash();
	~Splash();
};
