#! /bin/bash

#Get Exec File Path
BinFolder=$1
#Get Bin File
BinFile=$2

#Get Serial Port
getTTY(){
    ttys=()
    for entry in "$(ls /dev/tty.u*)"
    do
        ttys+=($entry)
    done
}

#Mango Z1 Download Flash Loader
ZigbeeDownload(){
if [ -z "${ttys[0]}" ]
    then
        echo "Not Serial USB"
    else
        if [ -z "${BinFolder}" ]
        then
            if [ -z "${BinFile}" ]
            then
                ~/stm32ld ${ttys[0]} 115200 bin.makeProject/Sample.bin
            else
                ~/stm32ld ${ttys[0]} 115200 bin.makeProject/${BinFile}.bin
            fi
        else
        ~/stm32ld ${ttys[0]} 115200 ${BinFolder}/${BinFile}.bin
        fi
    fi
}

#Download Command
commandDownload()
{
    
    if [ -z "${ttys[1]}" ]
    then
        echo "Not Serial USB"
        ZigbeeDownload
    else
        if [ -z "${BinFolder}" ]
        then
            if [ -z "${BinFile}" ]
            then
                ~/stm32ld ${ttys[1]} 115200 bin.makeProject/Sample.bin
            else
                ~/stm32ld ${ttys[1]} 115200 bin.makeProject/${BinFile}.bin
            fi
        else
        ~/stm32ld ${ttys[1]} 115200 ${BinFolder}/${BinFile}.bin
        fi
    fi
}


#Download Show Menu 
download(){
    printf "do you want to download [Y/N] : ";
    read -r downloadflag;

    if [ -z "$downloadflag" ]
    then
        echo "not flag input"
        download
    elif [ "$downloadflag" = "Y" ]
    then
        echo "download start"
        commandDownload
    elif [ "$downloadflag" = "y" ]
    then
        echo "download start"
        commandDownload
    elif [ "$downloadflag" = "N" ]
    then
        echo "not downlaod "
    elif [ "$downloadflag" = "n" ]
    then
        echo "not download"
    else
        echo -e "wrong parameter"
        download
    fi
}

#getTTY

#echo "GET : ${ttys[1]}"

#getBin

#get usb to serial port get
getTTY
#download function do
commandDownload
