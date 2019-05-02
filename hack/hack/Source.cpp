#include <SFML/Graphics.hpp>
#include <vector>

enum {FTP, HTTP, SSH, SMTP, DNS, SQL};
enum {RED, BLUE, NOBODY};

struct protect {
	int FTP = 0, HTTP = 0, SSH = 0, SMTP = 0, DNS = 0, SQL = 0;
};

struct serverInfo {
	protect defence;
	int exits[6];
	std::string name, IP;
};

class server
{
public:
	server(int pos, int genKey, std::string IP) {
		connected[RED] = false;
		connected[BLUE] = false;
		root = NOBODY;
		
		/**************
		create reading server using genKey
		**************/

		info.IP = IP;
	}

	void draw(sf::RenderWindow *window) {

	}

private:
	serverInfo info;
	int posID;
	bool connected[2];
	int root;
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFMLworks");
	sf::CircleShape shape1(100.f, 6);
	sf::CircleShape shape2(100.f, 6);
	shape1.setOrigin(50, 50);
	shape2.setOrigin(50, 50);


	shape1.setFillColor(sf::Color::Green);
	shape1.setOutlineColor(sf::Color::Red);
	shape1.setOutlineThickness(-10);
	shape1.setPosition(250, 250);

	shape2.setFillColor(sf::Color::Green);
	shape2.setOutlineColor(sf::Color::Blue);
	shape2.setOutlineThickness(-10);
	shape2.setPosition(150, 100);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape1);
		window.draw(shape2);
		window.display();
	}

	return 0;
}