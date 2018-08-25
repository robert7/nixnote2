# Docker build helper
Following the scripts will create [AppImage packaged binary](https://appimage.org/).
This then should run on all distributions which are ~same date or more recent then selected build system
(e.g. Ubuntu 16.04).
So basically, if build with 16.04, then all newer distribution then 2016 should be OK - plus/minus.

**At least in theory :)**

Note: the following build **should work regardless on the distribution you are currently on** (and
internally will do a build with Ubuntu (even if you are on Fedora or whatever :)).

So on whatever distribution you are on, the build will use Ubuntu (Xenial or Trusty) and the
binary should work on your system (as all dependencies are included in the resulting
binary).

Of course supposed you have [docker installed](https://www.google.com/search?q=docker+ce+download+linux)..

## Ubuntu 16.04 (xenial)

```bash
cd $PROJECTDIR
# pass branch name as 1st parameter to script (default: master)
./development/build-with-docker-xenial.sh
```


## Ubuntu 14.04 (trusty)
WORK IN PROGRESS - !! **doesn't work yet** !!

```bash
cd $PROJECTDIR
# pass branch name as 1st parameter to script (default: master)
#./development/build-with-docker-trusty.sh
```
