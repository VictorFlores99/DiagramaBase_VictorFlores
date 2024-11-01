#include <ftxui/dom/elements.hpp> //Traer objetos tipo HTML
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    int ancho = 100;
    int altura = 50;
    int tiempo = 0;
    int brazosP1X1=200;
    int brazosP1Y1=60;
    int brazosP1Y2=70;
    int brazosP2X1=85;
    int brazosP2Y1 = 60;
    int brazosP2Y2 = 70;



    while(true)
    {

        auto can = Canvas(300, 200); // Canvas es un objeto que se construye con ancho y alto
        can.DrawPointCircle(75, 50, 10);
        can.DrawPointLine(75, 60, 75, 80);
        can.DrawPointLine(75, 80, 85, 100);
        can.DrawPointLine(75, 80, 65, 100);
        can.DrawPointLine(75, 70, brazosP2X1, brazosP2Y1);
        can.DrawPointLine(75, 70, brazosP2X1, brazosP2Y2);
        can.DrawPointCircle(ancho, altura, 10);
        can.DrawPointCircle(210, 50, 10);
        can.DrawPointLine(210, 60, 210, 80);
        can.DrawPointLine(210, 80, 220, 100);
        can.DrawPointLine(210, 80, 200, 100);
        can.DrawPointLine(210, 70, brazosP1X1, brazosP1Y1);
        can.DrawPointLine(210, 70, brazosP1X1, brazosP1Y2);
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full()); // Los naranjas son objetos
        Element lienzo = bgcolor(Color::Blue, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.01s); // Delay entre los ciclos. FPS

        tiempo++;
        frame++; // Numero de frame en el tiempo

        if (tiempo > 0 && tiempo < 41)
        {
            altura--;
            ancho++;
            brazosP2X1 = 95;
            brazosP2Y1 = 60;
            brazosP2Y2 = 70;
        }
        if (tiempo > 41 && tiempo < 80)
        {
            altura++;
            ancho++;
            brazosP2X1 = 85;
            brazosP2Y1 = 60;
            brazosP2Y2 = 70;
        }
        if (tiempo > 80 && tiempo < 119)
        {
            altura--;
            ancho--;
            brazosP1X1 = 190;
            brazosP1Y1 = 50;
            brazosP1Y2 = 60;
        }
        if (tiempo > 119 && tiempo < 158)
        {
            altura++;
            ancho--;
            brazosP1X1 = 200;
            brazosP1Y1 = 60;
            brazosP1Y2 = 70;
        }

        if (tiempo == 158)
        {
            tiempo = 0;
            altura=50;
            ancho=100;
        }
    }

    return 0;
}