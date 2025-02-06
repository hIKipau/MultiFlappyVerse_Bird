#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace hIKipau {

    class HUD {
    public:
        HUD(GameDataRef data);
        void Draw();
        void UodateScore(int score);

    private:
        GameDataRef _data;
        sf::Text _scoreText;

    };

}