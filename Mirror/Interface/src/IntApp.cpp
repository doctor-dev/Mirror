
#include <mirror.h>
class Interface : public Mirror::Application
{
public:
    Interface() {
    };
    int x = 3;
};

void main() 
{
    Interface x;
    x.Run();
    
    

}