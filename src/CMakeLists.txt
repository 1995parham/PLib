# In The Name Of God
# ========================================
# [] File Name : CMakeLists.txt
#
# [] Creation Date : 08-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
add_library(PLib PStack.c PStack.h types.h PLog.c PLog.h
        PString.c PString.h PQueue.c PQueue.h PNode.h)
add_executable(Plib.out main.c PStack.c PStack.h types.h PLog.c PLog.c
        PString.c PString.h PQueue.c PQueue.h PNode.h)


# Add personal c flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O0 -g -std=gnu11 ")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -DDEBUG")
