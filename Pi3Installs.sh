#!/bin/bash

# install Screen
sudo apt-get install screen -y


# install CMUSphix
sudo wget -v -O sphinxbase.tar.gz https://sourceforge.net/projects/cmusphinx/files/sphinxbase/5prealpha/sphinxbase-5prealpha.tar.gz/download
sudo wget -v -O pocketsphinx.tar.gz https://sourceforge.net/projects/cmusphinx/files/pocketsphinx/5prealpha/pocketsphinx-5prealpha.tar.gz/download

tar -xzvf sphinxbase.tar.gz
tar -xzvf pocketsphinx.tar.gz

sudo apt-get install bison libasound2-dev swig python-dev gcc atuomake autoconf libtool libpulse-dev -y

cd sphinxbase-5prealpha
./autogen.sh
./configure --enable-fixed
make
sudo make install

cd ../pocketsphinx-5prealpha
./autogen.sh
./configure
make
sudo make install
