# System-dependent makefile options for ONCVPSP
# This must be carefully edited before executing "make" in src
#
# Copyright (c) 1989-2014 by D. R. Hamann, Mat-Sim Research LLC and Rutgers
# University
 
##### Edit the following lines to correspond to your compilers ####

F77        = /usr/local/bin/gfortran	
F90        = /usr/local/bin/gfortran	
CC         = /usr/local/bin/gcc	
FCCPP      = /usr/local/bin/cpp-11

FLINKER     = $(F90)

FCCPPFLAGS = -ansi #-DLIBXC_VERSION=517  #This probably should not be changed

##### Edit the following optimization flags for your system ####

FFLAGS     = -O3 -fallow-argument-mismatch #-msse3 
CFLAGS     = -O3		

##### Edit the following LAPACK and BLAS library paths for your system ####

LIBS = -L/Users/mverstra/CODES/LAPACK/ -llapack -lblas

##### Edit the following for to use libxc if available #####

OBJS_LIBXC =	exc_libxc_stub.o

# oncvpsp is presently compatible with libxc-2.0.3, not later releases
# To build oncvpsp with libxc, uncomment the following 3 lines and edit
# the paths to point to your libxc library and include directories
# make clean in src before rebuilding after changing this

#LIBS += -L/Users/mverstra/CODES/LIBXC/lib -lxcf90 -lxc
#FFLAGS += -I/Users/mverstra/CODES/LIBXC/include
#OBJS_LIBXC =	functionals.o exc_libxc.o 

LIBS += -L/Users/mverstra/CODES/LIBXC/5.1.7/lib -lxcf90 -lxc
FFLAGS += -I/Users/mverstra/CODES/LIBXC/5.1.7/include
FCCPPFLAGS += -I/Users/mverstra/CODES/LIBXC/5.1.7/include
OBJS_LIBXC =	functionals.o exc_libxc.o 

