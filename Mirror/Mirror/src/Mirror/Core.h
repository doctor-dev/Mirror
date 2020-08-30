#pragma once
#ifdef MR_Platform_Windows
     #ifdef MR_Build_DLL
          #define MIRROR_API __declspec(dllexport)
     #else
           #define MIRROR_API __declspec(dllimport)


#endif // MR_BUILD_DLL
#else
    #error Only supports windows

#endif // MR_Platform_Windows
