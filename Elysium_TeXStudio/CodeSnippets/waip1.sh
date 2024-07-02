#!/bin/bash -eu
sudo apt update

sudo apt install curl -y
sudo apt install git -y
sudo apt install net-tools -y
sudo apt upgrade -y



sudo apt install apache2 -y

sudo systemctl start apache2

sudo systemctl enable apache2



sudo apt install mysql-server -y
sudo mysql_secure_installation 



sudo apt install -y build-essential libxml2-dev libsqlite3-dev curl libcurl4-openssl-dev pkg-config libssl-dev libonig-dev libzip-dev zlib1g-dev libpng-dev libjpeg-dev libfreetype6-dev libgmp-dev libpq-dev libicu-dev libbz2-dev libxpm-dev libwebp-dev libtidy-dev libxslt1-dev zip
cd ~
wget https://www.php.net/distributions/php-8.1.0.tar.gz
tar -xzf php-8.1.0.tar.gz
cd php-8.1.0
./configure --prefix=/usr/local/php --with-openssl --with-zlib --enable-bcmath --with-bz2 --enable-calendar --with-curl --enable-exif --enable-ftp --with-gd --enable-mbstring --with-mysqli --with-pdo-mysql --enable-soap --enable-sockets --enable-sysvsem --enable-sysvshm --enable-shmop --with-tidy --with-xmlrpc --with-xsl --enable-zip --with-pear --with-webp --with-jpeg --with-xpm --with-freetype --enable-intl

make
sudo make install
echo 'export PATH="/usr/local/php/bin:$PATH"' >> ~/.bashrc
export PATH="/usr/local/php/bin:$PATH"
source ~/.bashrc
section ">>> {Done: Updated Successfully}"





cd ~
curl -sS https://getcomposer.org/installer | php
sudo mv composer.phar /usr/local/bin/composer




cd ~
composer global require laravel/installer

export PATH="$PATH:$HOME/.config/composer/vendor/bin"



cd ~
curl https://raw.githubusercontent.com/creationix/nvm/master/install.sh | bash
source ~/.bashrc

nvm install 16.15.1
nvm use 16.15.1

npm install -g npm@8.11.0




sudo mysql
CREATE USER 'my_username'@'localhost' IDENTIFIED BY 'my_password';
GRANT ALL PRIVILEGES ON *.* TO 'my_username'@'localhost';
FLUSH PRIVILEGES;
EXIT;
