#include "./image.h"
#include "io_strategies/dummy_strategy.h"
#include<string>

int main()
{
    std::string const str = "name/media/cd";
    igg::DummyIoStrategy strategy;
    igg::Image image(strategy);
    


    return 0;
}
