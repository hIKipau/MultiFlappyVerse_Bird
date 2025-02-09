#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 3.0f
#define SPLASH_SCENE_BACKGROUND_FILEPATH "../Resources/res/whiteSplashScreen.png"

#define GAME_MENU_BACKGROUND_FILEPATH "../Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "../Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "../Resources/res/PlayButton.png"

#define GAME_BACKGROUND_FILEPATH "../Resources/res/sky.png"
#define LAND_FILEPATH "../Resources/res/land.png"

#define GAME_OVER_BACKGROUND_FILEPATH "../Resources/res/sky.png"

#define PIPE_UP_FILEPATH "../Resources/res/pipeUp.png"
#define PIPE_DOWN_FILEPATH "../Resources/res/pipeDown.png"
#define SCORING_PIPE_FILEPATH "../Resources/res/InvisibleScoringPipe.png"
#define FLAPPY_BIRD_FONT_FILEPATH "../Resources/fonts/FlappyFont.ttf"
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 3.0f

#define BIRD_FRAME_1_FILEPATH "../Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "../Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "../Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "../Resources/res/bird-04.png"
#define BIRD_ANIMATION_DURATION 0.4f
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3
#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f
#define ROTATION_SPEED 100.0f

enum  GameStates {
    eReady,
    ePlaying,
    eGameOver
};

#define FLASH_SPEED 1500.0f
#define GAME_OVER_BACKGROUND_FILEPATH "../Resources/res/sky.png"
#define GAME_OVER_TITLE_FILEPATH "../Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "../Resources/res/Game-Over-Body.png"
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

#define BRONZE_MEDAL_FILEPATH "../Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "../Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "../Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "../Resources/res/Platinum-Medal.png"
#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE  5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100

#define HIT_SOUND_FILEPATH "../Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "../Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "../Resources/audio/Wing.wav"

