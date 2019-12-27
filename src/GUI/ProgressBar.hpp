#pragma once

#include "Widget.hpp"

namespace gui
{
    class ProgressBar : public gui::Widget
    {
        public:
            ProgressBar(MessageBus *msgBus);
            void    progress    (float percent);
            float   getProgress ();
            bool    isComplete  ();
            void    handleEvent (sf::Event e, const sf::RenderWindow& window) override;
            void    render      (sf::RenderTarget& renderer) override;
            void    setPosition (const sf::Vector2f& pos)   override;
            sf::Vector2f getSize() const    override;
        private:
            sf::Vector2f    m_position;
            Rectangle       m_totalBar;
            Rectangle       m_progressBar;
            float           m_progress;
            bool            m_isComplete;
    };
}