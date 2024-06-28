#!/bin/bash -eu
cd ~
git clone https://github.com/meh-land/Dashboard-Backend.git
cd Dashboard-Backend

composer install
cp .env.example .env


php artisan key:generate
php artisan migrate
php artisan passport:install
