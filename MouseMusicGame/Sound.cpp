#include "Sound.h"
#include "DxLib.h"

Sound::Sound()
{

}

Sound::~Sound()
{
	DeleteSound();
}

void Sound::LoadSound(const char* filename)
{
	soundHandle = LoadSoundMem(filename);
}

void Sound::Play()
{
	PlaySoundMem(soundHandle, DX_PLAYTYPE_BACK);
}

void Sound::Stop()
{
	StopSoundMem(soundHandle);
}

void Sound::DeleteSound()
{
	DeleteSoundMem(soundHandle);
}

void Sound::SetVolume(int vol)
{
	ChangeVolumeSoundMem(vol * 255 / 100, soundHandle);
}

bool Sound::isPlayNow()
{
	return CheckSoundMem(soundHandle);
}
