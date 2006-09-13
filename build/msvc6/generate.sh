#! /bin/sh
#
# This script generates the Visual Studio 6 build files for Windows.
#
# 20041214 larsa

rm -f simvoleon2.dsp simvoleon2.dsw install-headers.bat

../../configure --with-msvcrt=mtd --with-suffix=d \
  --enable-debug --enable-symbols || exit 1
cp lib/config.h lib/config-debug.h

../../configure --enable-msvcdsp --with-msvcrt=mt \
  --disable-debug --disable-symbols --enable-optimization || exit 1
cp lib/config.h lib/config-release.h

cp config-wrapper.h lib/config.h

make || exit 1

build_pwd=`pwd`
build="`cygpath -w $build_pwd | sed -e 's/\\\\/\\\\\\\\/g'`"
build_pwd="`pwd | sed -e 's/\\//\\\\\\\\/g'`\\\\"

source_pwd=`cd ../..; pwd`
source="`cygpath -w $source_pwd | sed -e 's/\\\\/\\\\\\\\/g'`"
source_pwd="`(cd ../..; pwd) | sed -e 's/\\//\\\\\\\\/g'`"

sed \
  -e "s/$build/./g" \
  -e "s/$build_pwd//g" \
  -e "s/$source/..\\\\../g" \
  -e "s/$source_pwd/..\\\\../g" \
  -e 's/$/\r/g' \
  <simvoleon2.dsp >new.dsp

mv new.dsp simvoleon2.dsp

sed \
  -e "s/$build/./g" \
  -e "s/$build_pwd//g" \
  -e "s/$source/..\\\\../g" \
  -e "s/$source_pwd/..\\\\../g" \
  -e 's/$/\r/g' \
  <install-headers.bat >new.bat

mv new.bat install-headers.bat

echo "Done."
echo "Now, make sure there are no absolute paths in the .dsp file."

