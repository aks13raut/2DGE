#include "ProgressBar.hpp"
#include "spdlog/spdlog.h"
namespace gui {
ProgressBar::ProgressBar(){
    m_totalBar.setFillColor(sf::Color::White);
    m_totalBar.setSize({800,40});
    m_progressBar.setFillColor(sf::Color::Blue);
    m_progressBar.setSize({0,40});
}
void ProgressBar::progress(float percent){
    m_progress += percent;
    auto incr = m_totalBar.getSize().x;
    incr = incr * percent / 100;

    auto size = m_progressBar.getSize();
    size.x += incr;
    
    m_progressBar.setSize(size);
}
float ProgressBar::getProgress(){
    return m_progress;
}
bool ProgressBar::isComplete(){
    return m_isComplete;
}
void ProgressBar::handleEvent(sf::Event e, const sf::RenderWindow& window){

}
void ProgressBar::render(sf::RenderTarget& renderer){
    renderer.draw(m_totalBar);
    renderer.draw(m_progressBar);
}
void ProgressBar::setPosition(const sf::Vector2f& pos){
    m_position = pos;

    m_totalBar.setPosition(m_position);
    m_progressBar.setPosition  (m_position);
}
sf::Vector2f ProgressBar::getSize() const {
    return m_totalBar.getSize();
}
}