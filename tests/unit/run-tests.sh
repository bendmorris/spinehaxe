#!/bin/sh -e
#
# Builds and runs the unit tests

mkdir -p build
haxe -neko build/tests.n -dce full -debug -cp src -cp ../../../spinehaxe -lib openfl --remap flash:openfl -main TestMain
neko build/tests.n
#haxe -swf build/tests.swf -dce full -debug -cp src -cp ../../spinehaxe -lib openfl -lib spinehaxe -main TestMain
 #build/tests.n
