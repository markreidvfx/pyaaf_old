
export BOOST_ROOT=/Users/mark/Homebrew
export AAFSDK_ROOT=/Users/mark/Dev/aaf/aaf-git
export AAF_PLATFORM=x86_64Darwin

#if you want to regenerate the source code
#python generate.py

mkdir build
cd build
cmake ../
make -j 8
cp core.so ../pyaaf
