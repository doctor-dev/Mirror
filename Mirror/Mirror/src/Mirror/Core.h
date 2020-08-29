#pragma once
#ifdef MR_Platform_Windows
     #ifdef MR_Build_DLL
          #define MIRROR_API __declspec(dllimport)
     #else
           #define MIRROR_API __declspec(dllexport)


#endif // MR_BUILD_DLL

#endif // MR_Platform_Windows
