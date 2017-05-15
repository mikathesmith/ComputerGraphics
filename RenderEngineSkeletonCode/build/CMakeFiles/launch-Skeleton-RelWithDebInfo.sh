#!/bin/sh
bindir=$(pwd)
cd /home/cshome/m/mismith/COSC342/RenderEngineSkeletonCode/Skeleton/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		GDB_COMMAND-NOTFOUND -batch -command=$bindir/gdbscript  /home/cshome/m/mismith/COSC342/RenderEngineSkeletonCode/build/RelWithDebInfo/Skeleton 
	else
		"/home/cshome/m/mismith/COSC342/RenderEngineSkeletonCode/build/RelWithDebInfo/Skeleton"  
	fi
else
	"/home/cshome/m/mismith/COSC342/RenderEngineSkeletonCode/build/RelWithDebInfo/Skeleton"  
fi
