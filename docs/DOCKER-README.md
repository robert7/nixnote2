# Docker build helper
Following the recipe will create [AppImage packaged binary](https://appimage.org/). 
This then should run on all distributions which are ~same date or more recent then selected build system
(e.g. Ubuntu 16.04).
So basically, if build with 16.04, then all newer distribution then 2016 should be OK. 
**At least in theory :)**

## Ubuntu 16.04 (xenial)

### Basic version 
```bash
cd $PROJECTDIR
./development/build-with-docker-xenial.sh
```

Now terminate session (Ctrl-D), to return to host
```bash
# at host
ls appdir/*.AppImage # => this one file is your result binary
```

### More advanced combination with container reuse (experimental)
```bash
docker run --name nixnote2_xenial -v $PROJECTDIR/appdir:/opt/nixnote2/appdir -it nixnote2/xenial /bin/bash

... compile or whatever...

# from other terminal session at host:
docker stop nixnote2_xenial
# later: restart & reuse
docker start -a nixnote2_xenial
```

## Ubuntu 14.04 (trusty)
WORK IN PROGRESS - !! doesn't work yet !!

```bash  
#docker build -t nixnote2/trusty -f ./development/docker/Dockerfile.ubuntu_trusty .
#docker run -it nixnote2/trusty /bin/bash
```
