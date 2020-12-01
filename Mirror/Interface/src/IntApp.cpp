
#include <Mirror.h>
class Interface : public Mirror::Application
{
public:
    Interface() {
    };
   
};

Mirror::Application* Mirror::CreateApplication() {
    return new Interface();
}