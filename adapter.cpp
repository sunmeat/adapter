// this code sample will work in Visual Studio 2022 for Windows!

#include <iostream>
#include <windows.h>
using namespace std;

#pragma comment(lib, "winmm.lib")

__interface Chief
{
    void* makeBreakfast();
    void* makeLunch();
    void* makeDinner();
};

class ScrewNut {};
class Pipe {};
class Gasket {};

// Adaptee - тот, кого адаптируют
class Plumber // сантехник
{
public:
    void* getScrewNut() // гайка
    {
        return new ScrewNut();
    }

    void* getPipe() // кусок трубы
    {
        return new Pipe();
    }

    void* getGasket() // прокладка
    {
        return new Gasket();
    }
};

// Adapter
class ChiefAdapter : public Plumber, public Chief
{
public:
    void* makeBreakfast()
    {
        return getGasket();
    }

    void* makeLunch()
    {
        return getPipe();
    }

    void* makeDinner()
    {
        return getScrewNut();
    }
};

// Client
class Client
{
public:
    void eat(void* dish)
    {
        cout << "...Bon Appetit!\n";
        Sleep(1000);
    }
};

void callAmbulance()
{
    cout << "OOPS!\n";
    // PlaySound(L"C:\\1\\siren.WAV", NULL, SND_NODEFAULT | SND_LOOP);
    system("start https://trancemusic.000webhostapp.com/siren.wav");
}

int main()
{
    system("title Adapter Pattern Example");

    Client client;
    Chief* chief = new ChiefAdapter;

    void* dish = chief->makeBreakfast();
    client.eat(dish);

    dish = chief->makeLunch();
    client.eat(dish);

    dish = chief->makeDinner();
    client.eat(dish);

    callAmbulance();
}