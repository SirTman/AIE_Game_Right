#include "DiffcultySelect.h"
#include <iostream>


DiffcultySelect::DiffcultySelect()
{
}

void DiffcultySelect::RangeSet()
{
	while (true)
	{
		system("cls");
		std::cout << "Current minimun: " + m_MIN;
		std::cin >> m_MIN;

		std::cout << "\nCurrent maximun: " + m_MAX;
		std::cin >> m_MAX;
		if (m_MIN > m_MAX || m_MIN == m_MAX)
		{
			std::cout << "\nMin can't be bigger than or equal to the Max ";
			continue;
		}
		int Diffrence = m_MAX - m_MIN;
		if (Diffrence <= 3)
		{
			std::cout << "\nMin can't be 3 numbers close to each other Max ";
			continue;
		}
		system("cls");
		break;
	}
	

};

DiffcultySelect::~DiffcultySelect()
{
}
