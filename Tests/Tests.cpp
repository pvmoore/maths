#include "_pch.h"

using namespace maths;
using std::string;
using std::vector;

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
#endif
    printf("Manual tests\n");

    PerlinNoise2D noise(100,100, 0);
    noise.setOctaves(7)
         .setPersistence(0.5)
         .generate();
        
    for(auto i = 0; i < 10; i++) {
        //printf("v=%f\n", noise.get(i, 0));
    }
    



    printf("Finished\n");
}
