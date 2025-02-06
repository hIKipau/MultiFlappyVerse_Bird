#include "AssetManager.hpp"

namespace hIKipau {

    void AssetManager::LoadTexture(std::string name, std::string fileName) {
        sf::Texture texture;
        if (texture.loadFromFile(fileName)) {
            this->_textures[name] = texture;
        }
    }

    sf::Texture& AssetManager::GetTexture(const std::string &name) {
         return this->_textures.at(name);
    }

    void AssetManager::LoadFront(std::string name, std::string fileName) {
        sf::Font font;
        if (font.loadFromFile(fileName)) {
            this->_fonts[name] = font;
        }
    }

    sf::Font &AssetManager::GetFont(const std::string &name) {
        return this->_fonts.at(name);
    }

};
