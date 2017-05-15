#!/bin/sh
bindir=$(pwd)
cd /home/cshome/m/mismith/COSC342/lab09-OpenGLContinuation/Part05/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		GDB_COMMAND-NOTFOUND -batch -command=$bindir/gdbscript  /home/cshome/m/mismith/COSC342/lab09-OpenGLContinuation/build/RelWithDebInfo/Part05 
	else
		"/home/cshome/m/mismith/COSC342/lab09-OpenGLContinuation/build/RelWithDebInfo/Part05"  
	fi
else
	"/home/cshome/m/mismith/COSC342/lab09-OpenGLContinuation/build/RelWithDebInfo/Part05"  
fi
