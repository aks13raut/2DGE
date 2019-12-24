#pragma once

#include <functional>

#include "Widget.hpp"

namespace gui
{
    enum class ButtonSize
    {
        Small,
        Wide,
    };

    class Button : public gui::Widget
    {
        public:
            Button(ButtonSize s = ButtonSize::Wide);

            void setFunction(std::function<void(void)> func);
            void setText    (const std::string& str);
            void setTexture (const sf::Texture& tex);

            void handleEvent    (sf::Event e, const sf::RenderWindow& window) override;
            void render         (sf::RenderTarget& renderer) override;
            void setPosition    (const sf::Vector2f& pos)   override;
            sf::Vector2f getSize() const    override;

        private:
            void updateText();

            sf::Vector2f    m_position;

            Rectangle   m_button;
            Text        m_text;
            std::function<void(void)> m_function = [](){};

    };

    inline std::unique_ptr<Button> makeButton(ButtonSize s = ButtonSize::Wide) { return std::make_unique<Button>(s); }
}
