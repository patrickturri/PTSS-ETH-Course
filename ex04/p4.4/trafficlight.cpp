/* Programming Techniques for Scientific Simulations, HS 2020
 * Exercise 4.4
 */

#include <iostream>

class Trafficlight
{
public:
    enum light
    {
        green,
        orange,
        red
    };

    Trafficlight(light l = red) : id_(counter_++), state_(l)
    {
        std::cout << "Constructing " << id_ << std::endl;
    }
    Trafficlight(const Trafficlight &rhs) : id_(counter_++), state_(rhs.state_)
    {
        std::cout << "Copy constructing " << id_ << " from " << rhs.id_ << std::endl;
    }
    Trafficlight &operator=(const Trafficlight &rhs)
    {
        std::cout << "Assigning " << rhs.id_ << " to " << id_ << std::endl;
        if (this != &rhs)
        {
            state_ = rhs.state_;
        }
        return *this;
    }
    ~Trafficlight() { std::cout << "Destructing " << id_ << std::endl; }

    void print_state() const;

private:
    static int counter_;
    const int id_; // Unique ID
    light state_;
};

int Trafficlight::counter_ = 0;

void Trafficlight::print_state() const
{
    switch (state_)
    {
    case Trafficlight::red:
        std::cout << "red" << std::endl;
        break;
    case Trafficlight::orange:
        std::cout << "orange" << std::endl;
        break;
    case Trafficlight::green:
        std::cout << "green" << std::endl;
        break;
    default:
        std::cout << "broken?!" << std::endl;
        break;
    }
}

int main()
{
    Trafficlight a(Trafficlight::green);

    Trafficlight *b_ptr = new Trafficlight(Trafficlight::orange);

    Trafficlight c(a);

    Trafficlight d = *b_ptr;

    Trafficlight e;
    e = a;

    Trafficlight &f = a;

    a.print_state();
    b_ptr->print_state();
    c.print_state();
    d.print_state();
    e.print_state();
    f.print_state();

    delete b_ptr;

    return 0;
}
