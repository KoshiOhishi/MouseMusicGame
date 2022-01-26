#include "Input.h"
#include "DxLib.h"

void Input::Update()
{
	memcpy(PrevKeys, Keys, 256);
	GetHitKeyStateAll(Keys);
}

bool Input::IsPush(int keynum)
{
	if (Keys[keynum] == TRUE)
		return true;

	return false;
}

bool Input::IsTrigger(int keynum)
{
	if (PrevKeys[keynum] == FALSE && Keys[keynum] == TRUE)
		return true;

	return false;
}