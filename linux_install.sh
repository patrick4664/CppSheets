#!/bin/bash
echo "Installing..."
cp CppSheets /usr/bin
cp libxlnt.{so,so.1.2} /usr/lib
cp CppSheets.desktop /usr/share/applications
cp CppSheets.png /usr/share/icons/hicolor/48x48
ldconfig
update-desktop-database
echo "Done"
