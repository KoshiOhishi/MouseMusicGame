#include "Mouse.h"
#include "DxLib.h"

void Mouse::Update()
{
	ResetRot();
	ButtonUpdate();
	GetMousePoint(&posX, &posY);
	rot += GetMouseWheelRotVol();
}

void Mouse::ButtonUpdate()
{
	for (int i = 0; i < 3; i++)
		prevButton[i] = button[i];

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		button[0] = 1;
	else
		button[0] = 0;

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)
		button[1] = 1;
	else
		button[1] = 0;

	if ((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0)
		button[2] = 1;
	else
		button[2] = 0;

}

void Mouse::SetMousePoint(int x, int y)
{
	DxLib::SetMousePoint(x, y);
}

bool Mouse::IsPush(int buttonnum)
{
	int n = buttonnum;
	if (n == 4) n = 3;
	n--;

	if (button[n] == TRUE)
		return true;

	return false;
}

bool Mouse::IsTrigger(int buttonnum)
{
	int n = buttonnum;
	if (n == 4) n = 3;
	n--;

	if (prevButton[n] == FALSE && button[n] == TRUE)
		return true;

	return false;
}

void Mouse::ResetRot()
{
	rot = 0;
}

int Mouse::GetPosX()
{
	return posX;
}

int Mouse::GetPosY()
{
	return posY;
}

int Mouse::GetRot()
{
	return rot;
}

int Mouse::isWheelMoving()
{
	if (rot > 0)
		return 1;

	if (rot < 0)
		return 2;
		
	return 0;
}