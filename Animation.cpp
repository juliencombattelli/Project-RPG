#include "Animation.hpp"

rpg::Animation::Animation() : m_texture(NULL)
{

}

void rpg::Animation::addFrame(sf::IntRect rect)
{
    m_frames.push_back(rect);
}

void rpg::Animation::setSpriteSheet(const sf::Texture& texture)
{
    m_texture = &texture;
}

const sf::Texture* rpg::Animation::getSpriteSheet() const
{
    return m_texture;
}

std::size_t rpg::Animation::getSize() const
{
    return m_frames.size();
}

const sf::IntRect& rpg::Animation::getFrame(std::size_t n) const
{
    return m_frames[n];
}
