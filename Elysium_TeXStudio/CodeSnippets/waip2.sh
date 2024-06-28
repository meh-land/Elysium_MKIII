#!/bin/bash -eu
cd ~
git clone https://github.com/meh-land/GP_laravel.git
cd GP_laravel

composer install
cp .env.example .env


php artisan key:generate
php artisan migrate
php artisan passport:install



cd ~
git clone https://github.com/meh-land/web_App.git
cd Dashboard

npm install
