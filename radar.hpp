#include <iostream>
#include <vector>

class Radar{

private:
    int radarNumber = 1;
    int xDepth = 100;
    int yDepth = 100;


public:
    void sweep();
    bool detection();
    std::string logTarget();

};