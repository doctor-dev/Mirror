#pragma once
#ifdef MR_Platform_Windows

extern Mirror::Application* Mirror::CreateApplication();

int main(int argc,char** argv)
{
    Mirror::Log::Init();
    MR_CORE_WARN("Initialized Log!");
    int a = 5;
    MR_INFO("Hello! Var={0}", a);
    
   
    auto app = Mirror::CreateApplication();
    app->Run();
    delete app;

}
#endif