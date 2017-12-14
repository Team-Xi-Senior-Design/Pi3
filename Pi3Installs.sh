#!/bin/bash

# install Screen
sudo apt-get install screen -y


# install CMUSphix
sudo wget https://sourceforge.net/projects/cmusphinx/files/sphinxbase/5prealpha/sphinxbase-5prealpha.tar.gz/download -O sphinxbase.tar.gz -y
sudo wget https://sourceforge.net/projects/cmusphinx/files/pocketsphinx/5prealpha/pocketsphinx-5prealpha.tar.gz/download -O pocketsphinx.tar.gz -y

tar -xzvf sphinxbase.tar.gz -y
tar -xzvf pocketsphinx.tar.gz -y

sudo apt-get install bison libasound2-dev swig -y

cd sphinxbase-5prealpha
./configure --enable-fixed
make
sudo make install -y

cd ../pocketsphinx-5prealpha
./configure
make
sudo make install -y