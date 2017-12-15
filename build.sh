#!/bin/bash

APP=gwu22
APP_DBG=`printf "%s_dbg" "$APP"`
INST_DIR=/usr/sbin
CONF_DIR=/etc/controller
CONF_DIR_APP=$CONF_DIR/$APP
PID_DIR=/var/run

SOCK=udp
DEBUG_PARAM="-Wall -pedantic"
MODE_DEBUG=-DMODE_DEBUG
MODE_FULL=-DMODE_FULL

#CPU=-DCPU_ANY
#CPU=-DCPU_ALLWINNER_A20
CPU=-DCPU_ALLWINNER_H3
#CPU=-DCPU_CORTEX_A5

PINOUT=-DPINOUT3
#PINOUT=-DPINOUT2

NONE=-DNONEANDNOTHING


function move_bin {
	([ -d $INST_DIR ] || mkdir $INST_DIR) && \
	cp $APP $INST_DIR/$APP && \
	chmod a+x $INST_DIR/$APP && \
	chmod og-w $INST_DIR/$APP && \
	echo "Your $APP executable file: $INST_DIR/$APP";
}

function move_bin_dbg {
	([ -d $INST_DIR ] || mkdir $INST_DIR) && \
	cp $APP_DBG $INST_DIR/$APP_DBG && \
	chmod a+x $INST_DIR/$APP_DBG && \
	chmod og-w $INST_DIR/$APP_DBG && \
	echo "Your $APP executable file for debugging: $INST_DIR/$APP_DBG";
}

function move_conf {
	([ -d $CONF_DIR ] || mkdir $CONF_DIR) && \
	([ -d $CONF_DIR_APP ] || mkdir $CONF_DIR_APP) && \
	cp  config.tsv $CONF_DIR_APP && \
	cp  device.tsv $CONF_DIR_APP && \
	cp  lcorrection.tsv $CONF_DIR_APP && \
	chmod -R a+w $CONF_DIR_APP
	echo "Your $APP configuration files are here: $CONF_DIR_APP";
}

#your application will run on OS startup
function conf_autostart {
	cp -v starter_init /etc/init.d/$APP && \
	chmod 755 /etc/init.d/$APP && \
	update-rc.d -f $APP remove && \
	update-rc.d $APP defaults 30 && \
	echo "Autostart configured";
}
function build_lib {
	gcc $1 $CPU -c app.c -D_REENTRANT $DEBUG_PARAM -pthread && \
	gcc $1 $CPU -c crc.c $DEBUG_PARAM && \
	gcc $1 $CPU $PINOUT -c gpio.c $DEBUG_PARAM && \
	gcc $1 $CPU -c timef.c  $DEBUG_PARAM&& \
	gcc $1 $CPU -c $SOCK.c $DEBUG_PARAM && \
	gcc $1 $CPU -c util.c $DEBUG_PARAM && \
	gcc $1 $CPU -c dht22.c $DEBUG_PARAM && \
	cd acp && \
	gcc $1 $CPU -c main.c $DEBUG_PARAM && \
	cd ../ && \
	echo "library: making archive..." && \
	rm -f libpac.a
	ar -crv libpac.a app.o crc.o gpio.o timef.o $SOCK.o util.o dht22.o acp/main.o && echo "library: done"
	rm -f *.o acp/*.o
}
function build {
	cd lib && \
	build_lib $1 && \
	cd ../ 
	gcc -D_REENTRANT $1 $3 $CPU main.c -o $2 $DEBUG_PARAM -pthread -L./lib -lpac && echo "Application successfully compiled. Launch command: sudo ./"$2
}

function full {
	DEBUG_PARAM=$NONE
	build $NONE $APP $MODE_FULL && \
	build $MODE_DEBUG $APP_DBG $MODE_FULL && \
	move_bin && move_bin_dbg && move_conf && conf_autostart
}
function full_nc {
	DEBUG_PARAM=$NONE
	build $NONE $APP $MODE_FULL && \
	build $MODE_DEBUG $APP_DBG $MODE_FULL  && \
	move_bin && move_bin_dbg
}
function part_debug {
	build $MODE_DEBUG $APP_DBG $NONE
}
function uninstall {
	pkill -F $PID_DIR/$APP.pid --signal 9
	update-rc.d -f $APP remove
	rm -f $INST_DIR/$APP
	rm -f $INST_DIR/$APP_DBG
	rm -rf $CONF_DIR_APP
}
function uninstall_nc {
	pkill -F $PID_DIR/$APP.pid --signal 9
	rm -f $INST_DIR/$APP
	rm -f $INST_DIR/$APP_DBG
}

f=$1
${f}
