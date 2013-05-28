
#PyAAF Requires boost
export BOOST_ROOT=/Users/mark/Homebrew

#if you built the sdk yourself you set AAFSDK_ROOT 
export AAFSDK_ROOT=/Users/mark/Dev/aaf/aaf-git/AAFx86_64DarwinSDK/g++

#or if you download prebuilt AFF-devel-libs 
#http://sourceforge.net/projects/aaf/files/AAF-devel-libs
#export AAFSDK_ROOT=/Users/mark/Dev/AAF-devel-libs-x86_64Darwin-1.1.6.0

#might need use g++ instead of clang on newer versions of OSX
#clang seems to work linking against the current SDK but not 1.1.6.0 devel-libs
#export CPP='gcc'
#export CC='gcc'
#export CXX='g++'

#if you want to regenerate the source code
#python generate.py

mkdir build
cd build

#For debugging symbosl
cmake -DCMAKE_BUILD_TYPE=Debug ../

#For Release
#cmake ../

make -j 8 VERBOSE=1

cp -v core.so ../pyaaf

#fix linking on mac osx
cd ..
sh ./tools/fixup_bundle.sh ./pyaaf/core.so