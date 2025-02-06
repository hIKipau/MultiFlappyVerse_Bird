#include "Game.hpp"
#include "SplashState.hpp"
#include <stdlib.h>
#include <time.h>


namespace hIKipau
{
    Game::Game(int width, int height, std::string title) {
        srand(time(NULL));
        _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        _data->machine.AddState(StateRef(new SplashState(this->_data)));

        this->Run();
    }

    void Game::Run() {
        float newTime, frameTime, interpolation;
        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;
        const float dt = 1.0f / 60.0f; // 60 FPS
        sf::Clock frameClock;

        while (this->_data->window.isOpen()) {
            this->_data->machine.ProcessStateChanges();

            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt) {
                this->_data->machine.GetActiveState()->HandleInput();
                this->_data->machine.GetActiveState()->Update(dt);
                accumulator -= dt;
            }

            interpolation = accumulator / dt;
            this->_data->machine.GetActiveState()->Draw(interpolation);

            // Ограничение частоты кадров - супер важно!!!
            sf::Time frameTime = frameClock.restart();
            if (frameTime.asSeconds() < dt) {
                sf::sleep(sf::seconds(dt - frameTime.asSeconds()));
            }
        }
    }

}
