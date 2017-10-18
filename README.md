# CDebugMacros
Assisted debug prints with tags, colors, file &amp; function location

This simple C header provides macros that can print following on a *NIX based console

[M] - main.cpp::main hello world
[M] - main.cpp::main One argument 0xDEADBEEF  
[W] - main.cpp::main hello world int 44 string = mondays eh?  float = 99.23  
[E] - main.cpp::main ---- the sky is falling ---- 

Using the macros is as simple as:
```C++
#include "DBG_MACROS.hpp"

int main(int argc, char *argv[] )
{
   DBG_MSG("hello world ");
}
```

