
#include "sound_device.h"
#include "sound_buffer.h"
#include "sound_source.h"
#include "music_player.h"
#include <system/configuration.h>
#include <engine.h>

void SoundExample()
{
    std::unordered_map<std::string, std::shared_ptr<wase::scene::Scene>> scenes =
    {
            { "main", std::make_shared<wase::scene::Scene>() },
    };

    wase::system::Configuration config
    { 
            "Wase Engine", 1280, 720, true,
            scenes, "main"
    };

    // put sounds in your build folder.
    wase::sound::SoundDevice* soundDevice = LISTENER;
    SB_INIT();
    uint32_t sound1 = SB_LOAD("1.wav");
    uint32_t sound2 = SB_LOAD("2.wav");
    uint32_t sound3 = SB_LOAD("3.wav");
    
    wase::sound::SoundSource mySpeaker;
    wase::sound::SoundSource mySpeaker2;
    wase::sound::SoundSource mySpeaker3;
    mySpeaker.Play(sound1);
    mySpeaker2.Play(sound2);
    mySpeaker3.Play(sound3);

    MP_LOAD("date a live.wav");
    MP_PLAY();

    while (1)
    {
            MP_UPDATE();
    }

    MP_CLEAN();
    SB_CLEAN();

    wase::Engine engine;
    engine.initialize(config);
    engine.run();
}