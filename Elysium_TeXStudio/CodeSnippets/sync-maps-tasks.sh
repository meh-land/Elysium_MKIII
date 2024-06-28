#!/bin/bash
srv_ip=192.168.1.202
my_keys="$(ls ~/.ssh | grep .pub | sed 's/.pub//g')"
eval "$(ssh-agent -s)"

cd ~/.ssh
ssh-add $my_keys
# sync directories
rsync -avz yahia@$srv_ip:/home/yahia/GP_laravel/storage/app/maps /home/pi

rsync -avz yahia@$srv_ip:/home/yahia/GP_laravel/storage/app/tasks /home/pi