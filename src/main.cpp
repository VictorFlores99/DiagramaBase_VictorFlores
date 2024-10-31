#include <SerieNavidad.hpp>
#include <Lienzo.hpp>
#include <Vector.hpp>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    Vector p(0,5);
    Vector t(100,100);
    Lienzo lienzo(p,t);
    SerieNavidad serie1(20);
    SerieNavidad serie2(20);

    bool estado = true;
    int incremento=0;
    while (true)
    {
        serie1.Alternar(estado);
        lienzo.Dibujar(serie1);
        estado = estado ? false : true;

        // Incremento
        serie2.Apagar();
        serie2.Encender(incremento);
        lienzo.Dibujar(serie2);
        incremento++;

        sleep(1);
        lienzo.Limpiar();
    }
    
    return 0;
}
