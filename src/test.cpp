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

    while(true)
    {
            
        auto can = Canvas(300, 200);      // Canvas es un objeto que se construye con ancho y alto
        can.DrawPointCircle(75, 50, 10);
        can.DrawPointLine(75, 60, 75, 80);
        can.DrawPointLine(75, 80, 85, 100);
        can.DrawPointLine(75, 80, 65, 100);
        can.DrawPointLine(75, 70, 85, 60);
        can.DrawPointLine(75, 70, 85, 70);
        can.DrawPointCircle(ancho,altura,10);
        can.DrawPointCircle(200, 50, 10);
        can.DrawPointLine(200, 60, 200, 80);
        can.DrawPointLine(200, 80, 210, 100);
        can.DrawPointLine(200, 80, 190, 100);
        can.DrawPointLine(200, 70, 190, 60);
        can.DrawPointLine(200, 70, 190, 70);
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());  //Los naranjas son objetos
        Element lienzo = bgcolor(Color::Blue, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s); //Delay entre los ciclos. FPS
        ancho++;
        tiempo++;
        frame++; //Numero de frame en el tiempo

        if(tiempo>0 && tiempo <41){
            altura--;
        }if(tiempo>41 && tiempo <80){
            altura++;
        }

        

        if(tiempo==80){
            return 0;
        }
        
    }

    return 0;
}