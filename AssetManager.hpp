#pragma once

#include <map>

#include<SFML/Graphics.hpp>

namespace hIKipau {
    class AssetManager {
    public:
        AssetManager() = default;
        ~AssetManager() = default;

        void LoadTexture( std::string name, std::string fileName);
        sf::Texture& GetTexture(const std::string &name );

        void LoadFront(std::string name, std::string fileName);
        sf::Font &GetFont(const std::string &name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}
