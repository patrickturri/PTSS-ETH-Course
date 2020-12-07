#include <iostream>
#include <stdexcept>

class Plane
{
public:
    void start()
    {
        std::cout << "Plane started successfully." << std::endl;
    }

    void serve_food()
    {
        throw std::runtime_error("The food is not edible!");
    }

    void land()
    {
        std::cout << "Plane landed successfully." << std::endl;
    }
};

int main()
{
    // TODO: Modify this code so that the plane lands, but serve_food is still called.
    Plane plane;
    try
    {
        plane.start();
        try
        {
            plane.serve_food();
        }
        catch (const std::runtime_error &e)
        {
            std::cout << e.what() << "\n";
        }
        plane.land();
    }
    catch (...)
    {
        std::cout << "We all are going to die..."
                  << "\n";
    }
}
