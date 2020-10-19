#pragma once
#ifdef MR_Platform_Windows

extern Mirror::Application* Mirror::CreateApplication();

int main(int argc,char** argv)
{
    Mirror::Log::Init();
    
    
   
    auto app = Mirror::CreateApplication();
    app->Run();
    delete app;

}
#endif