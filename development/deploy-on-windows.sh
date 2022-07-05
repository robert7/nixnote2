#!/bin/bash

usage="$0 [folder_to_deploy]"

if [[ -z $1 ]];
then echo $usage
    exit 1
fi

deploy_folder=$1

if [[ ! -e $deploy_folder ]]; then
    echo "The folder to deploy is not found. Exiting."
    exit 1
fi

IFS=':'
read -a paths <<< $PATH


for p in "${paths[@]}";
do
    if [[ "$p" == *"Qt"*Tools* ]]; then
        runtime_dir=$p
    elif [[ "$p" == *"Qt"** ]]; then
        qtlib_dir=$p
    fi
done

if [ -z $runtime_dir ] || [ -z $qtlib_dir ]; then
    echo "Qt environment variable not set. You can do this by running qtenv2.bat or by hand. Will exit."
    exit 1
fi

declare -a runtime_libs qt_libs third_party_libs

runtime_libs=(libssp-*.dll libstdc++-*.dll libwinpthread-*.dll libgcc_s_dw*.dll)

qt_libs=(freetype*.dll Qt*Network.dll icudt*.dll Qt*OpenGL.dll icuin*.dll Qt*Positioning.dll icuuc*.dll Qt*PrintSupport.dll libxml*.dll Qt*Qml.dll liblcms*.dll libxslt*.dll Qt*Sensors.dll libpng*.dll openjpeg.dll Qt*Sql.dll Qt*Core.dll Qt*Widgets.dll Qt*Gui.dll Qt*Xml.dll libQt*WebKit.dll Qt*Multimedia.dll zlib1.dll libQt*WebKitWidgets.dll Qt*MultimediaWidgets.dll libeay32.dll ssleay32.dll)

third_party_libs=(libtidy.dll libpoppler.dll libpoppler-qt5.dll libhunspell*.dll)

for lib in ${runtime_libs[@]};do
    cp -n $runtime_dir'/'$lib $deploy_folder
done

for lib in ${qt_libs[@]};do
    cp -n $qtlib_dir'/'$lib $deploy_folder
done

for lib in ${third_party_libs[@]};do
    cp -n '../winlib/'$lib $deploy_folder
done

cp -r -n ../translations ../resources/images ../java ../themes.ini ../colors.txt ../shortcuts.txt $deploy_folder

echo "Deployment finished."
