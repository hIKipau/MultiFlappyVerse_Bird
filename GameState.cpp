#include <sstream>
#include "SplashState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include <SFML/Audio.hpp>

#include <iostream>

namespace hIKipau {
    GameState::GameState(GameDataRef data) : _data(data) {}

    void GameState::Init() {
        _hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH);
        _wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH);
        _pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH);
        _hitSound.setBuffer(_hitSoundBuffer);
        _wingSound.setBuffer(_wingSoundBuffer);
        _pointSound.setBuffer(_pointSoundBuffer);

        this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
        this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        this->_data->assets.LoadTexture("Land", LAND_FILEPATH);
        this->_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
        this->_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
        this->_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
        this->_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
        this->_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
        this->_data->assets.LoadFront("Flappy Font", FLAPPY_BIRD_FONT_FILEPATH);

        pipe = new Pipe(_data);
        land = new Land(_data);
        bird = new Bird(_data);
        flash = new Flash(_data);
        hud = new HUD(_data);

        _background.setTexture(this->_data->assets.GetTexture("Game Background"));

        _score = 0;
        hud->UodateScore(_score);
        _gameState = GameStates::eReady;
    }

    void GameState::HandleInput() {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }

            if (this->_data->input.IsSpriteClicked(this->_background, sf::Mouse::Left, this->_data->window)) {
                if ( GameStates::eGameOver != _gameState ) {
                    _gameState =  GameStates::ePlaying;
                    bird->Tap();
                    _wingSound.play();
                }
            }
        }

    }

    void GameState::Update(float dt) {
        if ( GameStates::eGameOver != _gameState ) {
            bird->Animate(dt);
            land->MoveLand(dt);
        }

        if (GameStates::ePlaying == _gameState) {
            pipe->MovePipes(dt);

            if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
                pipe->RandomisePipeOffset();
                pipe->SpawnInvisiblePipe();
                pipe->SpawnBottomPipe();
                pipe->SpawnTopPipe();
                pipe->SpawnScoringPipes();

                clock.restart();
            }
            bird->Update(dt);
            std::vector<sf::Sprite> landSprites = land->GetSprites();

            for( int i =0; i < landSprites.size(); i++) {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, landSprites.at(i), 1.0f) ) {
                    _gameState = GameStates::eGameOver;
                    clock.restart();
                    _hitSound.play();
                }
            }

            std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();

            for( int i =0; i < pipeSprites.size(); i++) {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, pipeSprites.at(i), 1.0f) ) {
                    _gameState = GameStates::eGameOver;
                    clock.restart();
                    _hitSound.play();
                }
            }

            if (GameStates::ePlaying == _gameState){
                std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprites();

                for( int i =0; i < scoringSprites.size(); i++) {
                     if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, scoringSprites.at(i), 1.0f) ) {
                         _score++;
                         hud->UodateScore(_score);
                         scoringSprites.erase(scoringSprites.begin() + i);
                         _pointSound.play();
                     }
                }
            }

        }

        if (GameStates::eGameOver == _gameState) {
            flash->Show( dt);
            if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS) {
                _data->machine.AddState(StateRef(new GameOverState(_data,_score)),true);
            }
        }

    }

    void GameState::Draw(float dt) {
        _data->window.clear( sf::Color::Red );
        _data->window.draw(_background);
        pipe->DrawPipes();
        land->DrawLand();
        bird->Draw();
        flash->Draw();
        hud->Draw();
        _data->window.display();
    }

}
