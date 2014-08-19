#!/bin/bash

args=$*

if [[ -z $args ]]; then
	echo "Type -h to get help"
else
	if [[ $args == "-h" ]]; then
		echo "set-state <on|off>"
		echo "get-state"
		echo "set-color <red|green|blue>"
		echo "get-color"
		echo "set-refresh-rate <0..5>"
		echo "get-refresh-rate"
	else
		# echo "$args" | ./ivi_server
		# ./ivi_server &

		pipe=/tmp/ivideon_pipe

		if [[ ! -p $pipe ]]; then
		    echo "Reader not running"

		    exit 1
		fi

	    echo "$args" > $pipe

	    if read line < $pipe; then
	        echo $line
	    fi
	fi
fi