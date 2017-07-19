#pragma once
#include <string>
class Splash
{
public:
	Splash();
	virtual void RunningSplash();
	~Splash();
private:
	std::string m_title = "Char Type";
	std::string m_flashText = "[Press Enter]";

	bool m_ShowFlashText = true;
	bool m_KeyPressed = false;
};
