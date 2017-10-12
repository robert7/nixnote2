#!/bin/sh
#
# Copy files to /usr/share and /usr/bin as needed
#

package_dir=$(cd `dirname $0` && pwd)

if [ "$(id -u)" != "0" ]; then
   echo "This script must be run as root" 1>&2
   exit 1
fi

# Desktop launcher
cp $package_dir/nixnote2.desktop /usr/share/applications/nixnote2.desktop

# Shared files
mkdir -p /usr/share/nixnote2
#cp -r $package_dir/certs /usr/share/nixnote2/
# $package_dir/certs directory not found
cp -r $package_dir/help /usr/share/nixnote2/
cp -r $package_dir/images /usr/share/nixnote2/
cp -r $package_dir/java /usr/share/nixnote2/
cp -r $package_dir/qss /usr/share/nixnote2/
cp -r $package_dir/translations /usr/share/nixnote2/
cp $package_dir/changelog.txt /usr/share/nixnote2/
cp $package_dir/copyright /usr/share/nixnote2/
cp $package_dir/gpl.txt /usr/share/nixnote2/
cp $package_dir/license.html /usr/share/nixnote2/
cp $package_dir/README.txt /usr/share/nixnote2/
cp $package_dir/shortcuts.txt /usr/share/nixnote2/

# Executable
cp $package_dir/nixnote2 /usr/bin/nixnote2

echo "Install complete"
