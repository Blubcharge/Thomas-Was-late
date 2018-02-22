#include "stdafx.h"
#include "TextureHolder.h"
#include <assert.h>

using namespace sf;
using namespace std;

// Initialise the static reference here - to a null pointer (zero)
TextureHolder* TextureHolder::m_s_Instance = nullptr;

// Implement constructor
TextureHolder::TextureHolder()
{
	// Throw an error and stop execution in debug mode if a copy of the class already exists
	assert(m_s_Instance == nullptr);

	// Assign ourselves to the instance pointer 
	// - this is the new instance of the class which has just been creted.
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	// Get a reference to m_Textures using m_s_Instance
	// SARAH'S NOTE: DO NOT CALL THINGS "m" - BAD PRACTICE!!!! (angry Sarah)
	auto& m = m_s_Instance->m_Textures;
	// "auto" is the equivalent of map<string, Texture>
	// SARAH'S NOTE: I only use auto for iterators, as it reduces readability and maintainability
	//					since its harder to see what types are used in a file.

	// Create an iterator to hold a key value pair (kvp)
	//    and search for the required kvp
	//    using the passed in file name
	auto keyValuePair = m.find(filename);
	// "auto" in this case is map<string, Texture>::iterator
	// SARAH'S NOTE: better use of auto, iterators are very cumbersome without it.

	// Did we find out match?
	// (iterator will be at the end if we did not)
	if (keyValuePair != m.end())
	{
		// Yes! We found it!
		// Return the texture that has already been loaded
		// This is the second part of the kvp, the value (texture in this case)
		return keyValuePair->second;
	}
	else
	{
		// No! We failed to find it!
		// Lets create it then!
		// Create a new key value pair using the filename
		// the subscript ([]) operator creates an entry in the map if there is not already one there.
		auto& texture = m[filename];
		// blank texture created, now just load it from file using sfml
		texture.loadFromFile(filename);

		// return the texture to the calling code
		return texture;
	}

}