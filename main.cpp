#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Edge Collision v1.0", sf::Style::Close | sf::Style::Titlebar);
	int sclX;
	int sclY;


	// window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	sf::Clock deltaClock;

	sf::RectangleShape rect;
	sf::Vector2f rectPos(640, 310);
	sf::Vector2f velocity(200, 200);

	rect.setPosition(rectPos);
	rect.setSize(sf::Vector2f(100, 100));

	while (window.isOpen()) {
		float dt = deltaClock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// physics
		if (rectPos.x < 0 || rectPos.x > (1280 - 100)) velocity.x *= -1;
		if (rectPos.y < 0 || rectPos.y > (720 - 100)) velocity.y *= -1;


		rectPos.x += velocity.x * dt;
		rectPos.y += velocity.y * dt;
		rect.setPosition(rectPos);	

		window.clear(sf::Color::Black);
		window.draw(rect);
		window.display();
	}
	return 0;
}