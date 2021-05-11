#pragma once

#include "../component.h"
#include "../../core/utils/log_utils.h"

#include <SDL.h>
#include <SDL_mixer.h>
#include <map>

class AudioSource : public Component
{
public:
	bool playing = false;
	bool loop;

private:
	Mix_Chunk* audioClip;
	int channel = -1;

public:
	AudioSource(const char* path, const bool loop, const Uint8 volume, const bool playOnAwake)
	{
		this->loop = loop;

		audioClip = Mix_LoadWAV(path);
		if (!audioClip)
		{
			log_utils::error(Mix_GetError());
			return;
		}

		setVolume(volume);

		if (playOnAwake)
		{
			play();
		}
	}

	void init()
	{
	}

	void update(float dt)
	{
	}

	void render()
	{
	}

	void play()
	{
		channel = Mix_PlayChannel(-1, audioClip, loop);
	}

	void onStateChange(const bool state)
	{
		if (channel != -1)
		{
			if (!state)
			{
				Mix_Pause(channel);
			}
			else
			{
				Mix_Resume(channel);
			}
		}
	}

	void setVolume(float volume)
	{
		if (volume > 128)
		{
			volume = 128;
		}
		else if (volume < 0)
		{
			volume = 0;
		}
		else
		{
			volume = (volume / 100) * 128;
		}

		audioClip->volume = (Uint8)volume;
	}

	~AudioSource()
	{
		Mix_FreeChunk(audioClip);
	}
};