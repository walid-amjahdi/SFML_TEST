#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	// window rendering 
	sf::VideoMode size = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(size , "title", sf::Style::Fullscreen);

	// sprites 
	sf::CircleShape circle(50.f);
	circle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
	circle.setFillColor(sf::Color::Blue);

	//time and physics

	sf::Clock clock;
	sf::Vector2f velocity(0.f, 0.f);
	float gravity = 9.81f;


	// game loop 
	while (window.isOpen())
	{ 
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::KeyPressed)
				if (evnt.key.code == sf::Keyboard::Escape)
					window.close();
			if (evnt.type == sf::Event::Closed)
					window.close();
		}

		// delta time 
		float deltaTime = clock.restart().asSeconds() ;
		velocity = { 0.f,0.f };
		// mvmnt 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if(circle.getPosition().x + circle.getGlobalBounds().width <= window.getSize().x)
				velocity += {500.f,0.f };
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (circle.getPosition().x >= 0)
				velocity += { -500.f,0.f };
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (circle.getPosition().y >= 0)
				velocity += { 0.f,-500.f };
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (circle.getPosition().y + circle.getGlobalBounds().height < window.getSize().y)
				velocity += { 0.f,500.f };
		}
		circle.move(velocity * deltaTime);

		// drawing 
		window.clear(sf::Color::White);
		window.draw(circle);
		window.display();

	}
	return 0; 
}