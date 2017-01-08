set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required
cmake_minimum_required (VERSION 2.6)
project (DS_Wet1 CXX)
add_executable(DS_Wet1 Animal.cpp Animal.h avlTree.h library1.h library1.cpp magicManager.h Zoologist.cpp Zoologist.h #RPtst.h GuyOmerTests.cpp)
        main1.cpp)

#set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required
#cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
# Above line indicates to Cmake that minimum version 2.8 is required.
# As you may have noted all lines beginning with hash symbol are treated as comments by Cmake.
#SET(sampleName DS_Wet1)
# set(CMAKE_CXX_STANDARD 11) # Not relevant for Wet1
# In the above line we declared a variable sampleName and assigned it a value MyApp. We will make use of the same later.
#project(DS_Wet1)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG -Wall")
# here we define the project or solution (for visual studio) name
# In following lines we try to find out the packages of additional libraries, if reqd. Here we are trying to locate PCL and mrpt library.
# u may replace the names by yours. Each such package should have a Cmake file in them, if not then we may have to manually define the paths.
# we Show that later.
#find_package(PCL 1.2 REQUIRED)
#FIND_PACKAGE(MRPT REQUIRED base;bayes;obs;gui)

# here we specify the additional include directories for the project. These files come in additional include directories option of VC++
# project.
# either the variable values from package like ${PCL_INCLUDE_DIRS} or absolute paths as shown in second and third line may be used.
#include_directories(${PCL_INCLUDE_DIRS})
#include_directories("G:/Matlab/extern/include")
#include_directories("C:/Program Files/MobileRobots/Aria/include")

# here we specify the additional library directories for the linker in the project. These files come in additional library directories
# option of VC++ project.
# either the variable values from package like ${PCL_LIBRARY_DIRS} or absolute paths as shown in second and third line may be used.
# An update, link_directories is being pulled out, you may use TARGET_LINK_LIBRARIES instead as shown below
#link_directories(${PCL_LIBRARY_DIRS})
#link_directories("C:/Program Files/MobileRobots/Aria/lib")

# here we add definitions for any package if requred.
#add_definitions(${PCL_DEFINITIONS})

# The following line is very important.
# It specifies the executable name. Here the executable is the first parameter i.e. MyApp and a file MyApp.exe will be created on
# compilation in windows platform.
# Followed by the executable name come all your source and header files.
# All cpp fles will be clubbed into source folder and all .h files will be added to header files folder of the project.
#SET(SOURCE_FILES Zoologist.cpp Zoologist.h Animal.h Animal.cpp avlTree.h magicManager.h #tests.cpp tests.h
#        library1.cpp library1.h # maybe without
#        RPtst.h GuyOmerTests.cpp)
#add_executable (DS_Wet1 ${SOURCE_FILES})

# There may be some additional dependencies which you may have to specify for the project, which you may do as in following lines.
# Note that first parameter is the executable name.
#target_link_libraries (DS_Wet1 ${PCL_LIBRARIES}) # libeng.lib libmx.lib libmex.lib libmat.lib Aria.lib winmm.lib wsock32.lib)
# Add the required libraries for linking:
#TARGET_LINK_LIBRARIES(${sampleName}
#${MRPT_LIBS} # This is filled by FIND_PACKAGE(MRPT ...)
#"" # Optional extra libs...
#)
# End of CMakeLists.Txt file. Save it as a plain text file and the name should be exactly CMakeLists.Txt