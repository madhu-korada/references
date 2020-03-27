---
layout: default
title: Linux Commands
lang-ref: chapter1.0
---
### Save colored terminal output

#### AHA
Install aha i.e. to "converts ANSI escape sequences of a unix terminal to HTML code"

```bash
hitech@hitech-Latitude-E5570:~$ sudo apt-get install aha
```


then save your grep (or ls) output like this:

```bash
hitech@hitech-Latitude-E5570:~$ ls --color=always | aha --black --title 'ls-with-colors' > ls-with-colors.html
```


options:
```bash
--black param to set background as black color
--title param to set the title for HTML page
```


### NMAP

###### Find all the devices connected to the network :- ```sudo nmap -sP 192.168.16.*```

###### Find device connected to lan :- ```sudo nmap -sP 10.42.0.1/24```


### Using screen commands 

###### Create a screen              :- ```screen -S screen_name```

###### Open the screen              :- ```screen -r screen_name```

###### List all screens             :- ```screen -ls```

###### Kill a screen                :- ```screen -X -S 25486 kill```

###### Exit the screen              :- ```CNTL+A+D```

###### check the screen name and id :- ```echo $STY```


### Kill Programms


###### kill all ros stuff     :- ```killall -9 roscore``` or ```killall -9 rosmaster```

### Basic commands

###### open new terminal       :- ```Crtl + Alt + T```
###### New window in terminal :- ```Crtl + shift + T ```
###### Close terminal         :- ```Crtl + shift + W```
###### switch b/w terminals   :- ```Alt + ~```
###### manual for the command :- ```man "command"```
###### file transfer protocol :- ```ftp```
###### storage used by sys    :- ```df```
###### reverse search         :- ```cntrl + R```
###### super user mode        :- ```sudo su```
###### description            :- ```whatis "command"```
###### location of command     :- ```whereis "command"```

### ls - list directory contents

###### List files            :- ```ls```
###### List hidden files     :- ```la```
###### List by date          :- ```ls -ltr```
###### List only directories :- ```ls -d */```
###### List sub-directories  :- ```ls -R```
###### Info of directory     :- ```ls -ld /folder_name/```
###### In reverse direction  :- ```ls -r```

### du - estimate file space usage

###### Size of a folder      :- ```du /folder_name/```
###### Size of all folders   :- ```du -csh *```

### apt - package management system

###### display all the packages to be updated :- ```apt-get update```
###### update of the package lists 
###### and check for broken dependencies      :- ```apt-get check```
###### upgrade the packages                   :- ```apt-get upgrade```
###### smart-upgrade (only important packages) :- ```apt-get dist-upgrade```
###### replace new packages with old (system wide):- ```apt-get full-upgrade```

### Install Programs

###### install a package                      :- ```apt-get install <package_name>```
###### install a package & Fix Broken Packages:- ```apt-get -f install <package_name>```
###### download but not install               :- ```apt-get download <package_name>```

### Remove Programs

###### remove a package		       :- ```apt-get remove <package_name>```
###### completely remove traces of package    :- ```apt-get purge <package_name>```
###### removes packages that were installed by other packages and are no longer needed:- ```apt-get autormove```
###### removes an installed package and dependencies :- ```apt-get autormove```
###### remove .deb files for packages that are no longer installed in system      :- ```apt-get autoclean```
###### The same as above, except it removes all packages from the package cache    :- ```apt-get clean```

### Search Commands

###### lists the searched packages            :- ```apt-cache search <search_term>```
###### same as above by marking it with ii (installed) and un (not installed)  :- ```dpkg -l *<search_term>*```
###### description of package and other information including version, size, dependencies and conflicts.            :- ```apt-cache show <package_name> (or) dpkg --print-avail <package_name>```
###### similar to laocate                     :- ```delocate <package_name>```
###### list all packages installed            :- ```apt-cache pkgnames```



### find - search for files in a directory hierarchy

###### locating files by name                 :- ```find $HOME -name 'file.name' (use "-iname" for case-insensitive)```
###### loacting files of same extension       :- ```find $HOME -name '*.name'```
###### searches everywhere (slow process)     :- ```sudo find / -iname '*.ogg' ```
###### locate by size (+ represents larger)   :- ```find $HOME -iname '*.ogg' -size +100M ```
###### locate files by their access time      :- ```find $HOME -atime +30 (more than 30 days)```
###### similar, case-insensitive and ogg ext. :- ```find $HOME -iname '*.ogg' -atime +30```
###### not greater than 20 mb                 :- ```find $HOME -iname '*.ogg' ! -size +20M```
###### ogg or mp3 files                       :- ```find $HOME -iname '*.ogg' -o -iname '*.mp3'```

### Info about hard disks 
###### to check which drives system can see   :- ```sudo fdisk -l```
###### all info about disks                   :- ```sudo lsblk -o NAME,FSTYPE,SIZE,MOUNTPOINT,LABEL```

### Bash rc method 
###### open with gedit                        :- ```gedit ~/.bashrc```
###### to activate modified bashrc            :- ```source ~/.bashrc  (or) bash```


### cp - copy, mv - move

###### copying a file	     :- ```cp /location/of/file /where/to/be/moved```
###### copying a directory   :- ```cp -r /location/of/file /where/to/be/moved```
###### moving a file         :- ```mv /location/of/file /where/to/be/moved``` 

### rm - remove

###### removing a file	      :- ```rm /file/name```
###### removing empty dir    :- ```rmdir /name/of/dir```
###### removing dir of files :- ```rm -r```
###### make a directory      :- ```mkdir /name/of/dir```

### cd - change directory

###### home dir              :- ```cd ~ ```
###### root dir              :- ```cd /```












