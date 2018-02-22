#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder
{
private:
	// A map container from the STL
	// that holds related pairs of strings and Textures
	std::map<std::string, sf::Texture> m_Textures;

	// A pointer to the class itself
	// the one and only instance of this class
	static TextureHolder* m_s_Instance;

public:

	// Constructor
	TextureHolder();

	// Getter for texture by name (static)
	static sf::Texture& GetTexture(std::string const& filename);
};