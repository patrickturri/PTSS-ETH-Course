#include <iostream>
#include <stdexcept>

void timeStep(int step, double dt)
{
    if (step == 3 || step == 6)
    {
        throw std::domain_error("Getting unphysical results!");
    }
    else if (step == 9)
    {
        throw "YOLO!!!";
    }
    else
    {
        // ...
    }
}

void simulation(double tStart, double tEnd, double dt)
{
    double t = tStart;
    int step = 0;
    while (t < tEnd)
    {
        std::cout << "Info: Doing step " << step
                  << " with time step dt = " << dt << '\n';
        try
        {
            timeStep(step, dt);
        }
        catch (std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            // handle ...
        }
        catch (...)
        { // catches anything else
            std::cerr << "Error: I cannot handle, maybe caller can?\n";
            throw; // cannot handle, so better re-throw!
        }
        // increment time & iteration counter
        t += dt;
        ++step;
    }
}

int main()
{

    double tStart = 0.;
    double tEnd = 1.;
    int Nsteps = 10;
    double dt = (tEnd - tStart) / Nsteps;

    simulation(tStart, tEnd, dt);
}
