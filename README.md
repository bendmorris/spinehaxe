# Update

In true Haxe spirit, @jeremyfa has created a cool system to keep the Spine runtimes up to date *automatically*: <https://github.com/jeremyfa/spine-hx>

You should check it out! (If you prefer spinehaxe, using `import spine.*` instead of `import spinehaxe.*` will keep your code compatible with both.)

[![Build Status](https://img.shields.io/travis/bendmorris/spinehaxe/dev.svg?style=flat)](https://travis-ci.org/bendmorris/spinehaxe)

This is an attempt to build a current Haxe runtime for 
[Spine](http://esotericsoftware.com/). It is based on great work by the authors 
of [spinehx](https://github.com/nitrobin/spinehx) as well as the official Spine 
runtimes for AS3 and libgdx.

## Versioning and Spine Compatibility

The major/minor version of spinehaxe correspond to the most recent version of 
Spine that spinehaxe has been updated for; the patch version is separately 
increased by one for each spinehaxe release.

## Renderers

This library contains runtime support and does not depend on any other library. 
Additional renderer libraries are used to integrate Spine animations with a 
specific Haxe engine. Some of these include:

- OpenFL (included in the spinehaxe.platform.openfl package)
- HaxeFlixel: included in [flixel-addons](https://github.com/HaxeFlixel/flixel-addons)
- HaxePunk: [SpinePunk](https://github.com/bendmorris/SpinePunk)
