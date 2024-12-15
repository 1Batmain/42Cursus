#!/bin/bash

# monitoring.sh: Displays system staton every terminals each 9min.

KERNEL=$(uname -v ) #| awk '{for (i = 4; i <= NF; i++) printf "%s%s", $i, (i < NF ? OFS : ORS)}')

PCPU=$(lscpu | grep Socket | awk -v FS=':' 'END{ print $2 }' | sed -e "s/ //g")
VCPU=$(nproc)

FULL_GIG_RAM=$(free -h | grep Mem | awk -v FS=' ' 'END{print $2}')
AVAILABLE_MO_RAM=$(free -m | grep Mem | awk -v FS=' ' 'END{print $7}')
FULLMO_RAM=$(free -m | grep Mem | awk -v FS=' ' 'END{print $2}')
USEMO_RAM=$(free -m | grep Mem | awk -v FS=' ' 'END{print $3}')
USEPERCENT_RAM=$(echo "scale=2; $USEMO_RAM / $FULLMO_RAM * 100" | bc)

FULLDISK=$(df --total | awk -v FS=' ' 'END{print $2}')
USEDISK=$(df --total | awk -v FS=' ' 'END{print $3}')
AVAILABLEDISK=$(df --total | awk -v FS=' ' 'END{print $4}')
USEPERCENTDISK=$(df --total | awk -v FS=' ' 'END{print $5}')

LASTSHUTDOWN=$(last -x | grep shutdown| head -n1| awk -v FS=' ' '{for (i = 5; i <= NF; i++) printf "%s%s", $i ,(i < NF ? OFS : ORS)}')
USELVM=$(cat /etc/fstab | grep "mapper" | wc -l | awk '{if($1 >= "1") {printf("yes\n")} else {printf("no\n")}}')

ACTIVCONNEXION=$(ss -Ht | wc -l)
LOGGEDUSERS=$(users | wc -w)


output="
				Architecture			Kernel

#OS		:		$(uname -om) 		$KERNEL	
		                  - - - - - - - - - - - - - - - - - - - - - - - - - - -

 			Physical		Virtual

 #CPU		:	$PCPU			$VCPU

			FULL			AVAILABLE  		USE 

#RAM		:	$FULL_GIG_RAM		|	$AVAILABLE_MO_RAM Mo		|	$USEPERCENT_RAM %
#Disk		:	$FULLDISK	|	$AVAILABLEDISK	|	$USEPERCENTDISK

#Last boot	:	$LASTSHUTDOWN
#LVM use	:	$USELVM

#Connections 	:	$ACTIVCONNEXION
#User log	:	$LOGGEDUSERS
#Network	:	$(ss -ta | grep ESTAB | wc -l)
#Sudo commands	:	$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)	
"
echo "$output" | wall
