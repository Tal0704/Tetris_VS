#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
 
template<typename _Ty>
std::ostream& operator<<(std::ostream& stream, sf::Vector2<_Ty> vect)
{
	stream << vect.x << ", " << vect.y;
	return stream;
}

namespace deb {


}

