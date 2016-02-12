# In The Name Of God
# ========================================
# [] File Name : CMakeLists.txt
#
# [] Creation Date : 08-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
set(PLib_SOURCES PStack.c PLog.c PString.c PQueue.c
	PAQueue.c PPThread.c)
set(PLib_HEADERS PStack.h PTypes.h PLog.h PString.h
	PQueue.h PNode.h PAQueue.h PPThread.h)

add_library(PLib ${PLib_SOURCES} ${PLib_HEADERS})
add_executable(Plib.out main.c ${PLib_SOURCES} ${PLib_HEADERS})

target_link_libraries(PLib pthread)
target_link_libraries(Plib.out pthread)

include_directories("${PROJECT_BINARY_DIR}")

# Add personal c flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O0 -g -std=gnu11 ")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -DDEBUG")
