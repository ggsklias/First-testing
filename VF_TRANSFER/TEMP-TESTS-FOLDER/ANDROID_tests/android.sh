#!/bin/bash -ex

EXEC=a.out
LIBRARY=$VFEXECINSTALL/verify/arm-linux-androideabi/bionic/lib/libpareon.so

case $1 in
  file)
    adb push -p $EXEC '/data/local/'
    adb push -p $LIBRARY '/data/local/'
    adb shell \ "cd /data/local/; LD_LIBRARY_PATH=. VFRUN_OUT=file ./a.out"
    adb pull '/data/local/pareon*' '.'
    ;;
  none)
    adb push -p $EXEC '/data/local/'
    adb push -p $LIBRARY '/data/local/'
    adb shell \ "cd /data/local/; LD_LIBRARY_PATH=. VFRUN_OUT=file ./a.out"
    ;;
esac
