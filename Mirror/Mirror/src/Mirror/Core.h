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

#define BIT(X) (1<<X)
<<<<<<< Updated upstream
=======

#ifdef MR_ENABLE_ASSERTS
#define MR_ASSERT(x, ...) { if(!(x)) { MR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define MR_CORE_ASSERT(x, ...) { if(!(x)) { MR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define MR_ASSERT(x, ...)
#define MR_CORE_ASSERT(x, ...)
#endif
>>>>>>> Stashed changes
