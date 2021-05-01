#pragma once


#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "images/sega.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "images/sky.png"
#define GAME_BACKGROUND_FILEPATH "images/1.png"
#define GAME_OVER_BACKGROUND_FILEPATH "images/1.png"
#define GAME_OVER_TITLE_FILEPATH "images/gameOverTitle.png"
#define GAME_OVER_CONTAINER_FILEPATH "images/f.png"
#define GAME_OVER_RETRY_BUTTON_FILEPATH "images/retryPlay.png"
#define GAME_OVER_BAR_FILEPATH "images/bar.png"

#define COIN_FILEPATH "images/c.png"

#define GAME_TITLE_FILEPATH "images/Fly_1.png"
#define PLAY_BUTTON_FILEPATH "images/play.png"
#define SETTINGS_BUTTON_FILEPATH "images/settings.png"
#define EXIT_BUTTON_FILEPATH "images/exit.png"
#define PLAYER_FRAME_1_FILEPATH "images/Fly_1.png"
#define PLAYER_FRAME_2_FILEPATH "images/Fly_2.png"

#define HIT_SOUND_FILEPATH "audio/karate.ogg"
#define PLAYER_SOUND_FILEPATH "audio/airplain.ogg"

#define PLAYER_SCORE_FONT_FILEPATH "fonts/AmaticBold.ttf"

#define ENEMY_FILEPATH "images/matematyka.png"

#define ENEMY_MOVEMENT_SPEED 300.0f//150.0f
#define ENEMY_SPAWN_FREQUENCY 2.0f

#define LEFT_WALL_FILEPATH "images/LeftWall.png"

#define PLAYER_ANIMATION_DURATION 0.25f

#define PLAYER_STATE_FLYING 1
#define PLAYER_STATE_FLYING_UP 2
#define PLAYER_STATE_FLYING_DOWN 3
#define PLAYER_STATE_FLYING_LEFT 4
#define PLAYER_STATE_FLYING_RIGHT 5
#define PLAYER_STATE_DEAD 6
//#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};

#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f