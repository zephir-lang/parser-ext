#!/bin/sh

sudo apt-get -y update
sudo apt-get -y upgrade
sudo apt-get -y dist-upgrade

sudo apt-get install -y gcc valgrind re2c
sudo apt-get install -y software-properties-common python-software-properties

sudo add-apt-repository -y ppa:ondrej/php5
sudo apt-get update
sudo apt-get install -y php5-dev php5-cli
