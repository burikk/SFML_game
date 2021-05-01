/*------------------------------------------------------------

Temat projektu: Gra komputerowa, w ktorej mam jednego bohatera na pulpicie,
bedzie strzelal w objekty wylatujacy z lewej strony, majacy na sobie punkty
ects jako healthpoints(krotko mowiac o gierke). Zwyciestwo jest po przebiciu
ostatniego przedmiotu. Chetnie bym powiedzial i omowil o swoich planach i gierke z
Panem prowadzacym

Zakres projektu:
1. ........
2. ........
3. ........
itd ........

Co zrealizowalem w biezacym tygodniu?
W biezacym tygodniu zrealizowalem:
Stworzyłem pierwszego przeciwnika w klasie Enemy oraz zrobiłem dla niego poruszanie na mapie.

Co planuje na kolejny tydzien?
Następnie będę robił strzelanie pocisków głównego bohatera lub działania z tekstem, menu i td.
------------------------------------------------------------*/

/*------------------------------------------------------------

Program glowny

------------------------------------------------------------*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
//#include "Engine.h"


#include "Game.h"
#include "DEFINITIONS.h"
using namespace sf;

int main()
{

	//Engine engine;
	//engine.start();
	Game game(SCREEN_WIDTH, SCREEN_HEIGHT, "FLIGHT GAME");

	return EXIT_SUCCESS;
}