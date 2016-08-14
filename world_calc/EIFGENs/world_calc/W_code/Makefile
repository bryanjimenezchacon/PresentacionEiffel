INCLUDE_PATH = 
SHELL = /bin/sh
CC = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/mingw/bin/gcc"
CPP = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/mingw/bin/gcc"
CFLAGS = -O0 -DEIF_IL_DLL -pipe -imacros eif_config.mingw.h -D_WIN32_WINNT=0x0500 -DWINVER=0x0500 -D_UNICODE -DUNICODE   -DEIF_IEEE_BEHAVIOR -DWORKBENCH -I"C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/studio/spec/win64/include" -I. $(INCLUDE_PATH)
CPPFLAGS = -O0 -DEIF_IL_DLL -pipe -imacros eif_config.mingw.h -D_WIN32_WINNT=0x0500 -DWINVER=0x0500 -D_UNICODE -DUNICODE   -DWORKBENCH -I"C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/studio/spec/win64/include" -I. $(INCLUDE_PATH)
LDFLAGS = 
CCLDFLAGS =   -mwindows
LDSHAREDFLAGS =  
EIFLIB = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/studio/spec/win64/lib/mingw/wkbench.a"
EIFTEMPLATES = C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/studio/config/win64/templates
LIBS = 
MAKE = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/msys/1.0/bin/make.exe"
AR = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/mingw/bin/ar"
LD = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/mingw/bin/ld"
MKDEP =   --
MV = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/msys/1.0/bin/cp"
CP = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/msys/1.0/bin/cp"
RANLIB = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/mingw/bin/ranlib.exe"
RM = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/msys/1.0/bin/rm" -f
FILE_EXIST = 
RMDIR = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/msys/1.0/bin/rd"
X2C = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/studio/spec/win64/bin/x2c.exe"
SHAREDLINK = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/mingw/bin/dllwrap"
SHAREDLIBS = -luser32 -lws2_32 -ladvapi32 -lgdi32 -lshell32 -lmsimg32 -lcomdlg32 -luuid -lole32 -loleaut32 -lcomctl32 -lmpr -lshlwapi -lwinspool -lstdc++ 
SHARED_SUFFIX = .dll
COMMAND_MAKEFILE = 
START_TEST = if [ ! -f finished ] ; then 
END_TEST = ; fi 
CREATE_TEST = "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/msys/1.0/bin/touch" finished
PATH := C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/mingw/libexec/gcc/mingw32/3.4.2;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;C:\Program Files\Haskell\bin;C:\Program Files\Haskell Platform\8.0.1\lib\extralibs\bin;C:\Program Files\Haskell Platform\8.0.1\bin;C:\ProgramData\Oracle\Java\javapath;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Skype\Phone\;C:\Program Files (x86)\scala\bin;C:\Program Files\Haskell Platform\8.0.1\mingw\bin;C:\Users\ariel\AppData\Roaming\cabal\bin;C:\Users\ariel\AppData\Roaming\local\bin;C:\Users\ariel\AppData\Local\atom\bin 
SYSTEM_IN_DYNAMIC_LIB = world_calc.dll 
IL_SYSTEM = libworld_calc.dll
IL_OBJECTS = libworld_calc.o
IL_RESOURCE = world_calc

.SUFFIXES:.cpp .o 

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

SUBDIRS = C1

EXTERNALS = 

all::  $(IL_SYSTEM)
OBJECTS= $(IL_OBJECTS)

PRECOMP_OBJECTS= 

$(IL_SYSTEM): $(OBJECTS) $(IL_RESOURCE).res
	$(RM) $(IL_SYSTEM) 
	$(CC) -shared -Wl,--kill-at -o $(IL_SYSTEM) $(IL_RESOURCE).res  $(OBJECTS) $(EXTERNALS) $(SHAREDLIBS)
	$(RM) $(OBJECTS)
	echo Success > completed.eif

../../../$(IL_RESOURCE).rc:
	$(MV) "C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/studio/config/win64/mingw/eiffel.rc" ../../../$(IL_RESOURCE).rc

$(IL_RESOURCE).res: ../../../$(IL_RESOURCE).rc Makefile
	"C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/mingw/bin/windres" --preprocessor='"C:\Program Files\Eiffel Software\EiffelStudio 16.05 GPL/gcc/win64/mingw/bin/cpp.exe"' -I ../../../ ../../../$(IL_RESOURCE).rc  -O coff -o $(IL_RESOURCE).res


clean: sub_clean local_clean
clobber: sub_clobber local_clobber

local_clean::
	$(RM) core finished *.o *.so *.a

local_clobber:: local_clean
	$(RM) Makefile config.sh finish_freezing

sub_clean::
	for i in $(SUBDIRS); \
	do \
		if [ -r $$i/Makefile ]; then \
			(cd $$i ; $(MAKE) clean); \
		fi; \
	done

sub_clobber::
	for i in $(SUBDIRS); \
	do \
		if [ -r $$i/Makefile ]; then \
			(cd $$i ; $(MAKE) clobber); \
		fi; \
	done

