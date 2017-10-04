#include <iostream>

#include "IApplication.hpp"

using namespace My;

// 实例化
namespace My {
    extern IApplication* g_pApp;
}

int main(int argc, char* argv[])
{
    int ret;

    if ((ret = g_pApp->Initialize()) != 0)
    {
        std::cout << "App Initialize failed, will exit now~" << std::endl;
        return ret;
    }

    while (!g_pApp -> IsQuit())
    {
        g_pApp -> Tick();
    }

    g_pApp -> Finalize();

    return 0;
}