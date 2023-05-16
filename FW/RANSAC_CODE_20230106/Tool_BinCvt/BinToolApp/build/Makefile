#-------------------------------------------------------------------------------
# Software tool and environment definitions
#-------------------------------------------------------------------------------
CC       = gcc#     # GNU gcc. set ANSI C compiler
CXX		 = gcc#g++
RM       = rm -rf#  # Remove files
CP       = cp -rf#  # Copy files or directory
MV       = mv -f#   # Remove files or directory
MKDIR    = mkdir#   # Make directory
SED      = sed#     # Stream editor
LIB      = 

MAKEFILE = makefile $(BUILD_SETTING_FILE)
#===================================
#    MAKE
#===================================


#-------------------------------------------------------------------------------
# Target compile time symbol definitions
#-------------------------------------------------------------------------------
TARGET    = bin_tool#           # Target name for output files
EXTENSIONS = #   				# Flags for various target extensions

# Directory define
APPSRCROOT	= ../src
BUILDDIR 	= .
OBJDIR 	  	= $(BUILDDIR)/obj


INCLUDE_PREFIX = -I
ALL_INCLUDES = $(addprefix $(INCLUDE_PREFIX), $(HDRPATH))

#-------------------------------------------------------------------------------
# Build process output type
#-------------------------------------------------------------------------------
EXETYPE    = exe#   # Target image file format

#-------------------------------------------------------------------------------
# Include file search path options
#-------------------------------------------------------------------------------
INC      := $(INC) -I"$(TOOLSINC)"#

#-------------------------------------------------------------------------------
# Compiler flag definitions
#-------------------------------------------------------------------------------
#UDEFS = 
#DEFS    = $(patsubst %,-D%,$(DDEFS) $(UDEFS))
DEFS    = $(patsubst %,-D%,$(DDEFS))

MISC    = -c -fmessage-length=0 -MD -MP -MF $(@:.o=.d)
CFLAGS  = -c -O2 $(MISC) -D__EXECUTE_FILENAME__=\"$(TARGET)\" $(DEFS) -fshort-enums -Wl,-subsystem,console
MAKETARGETDIR = $(SHELL) -ec 'if [ ! -d $(@D) ]; then mkdir -p $(@D); fi'

#-------------------------------------------------
# Object groups that area specific to this target
#-------------------------------------------------

BINTOOL_SOURCES =	main.c \
					crc.c \
					lz.c
					#Add New File Here!

BINTOOL_OBJS 	:= $(addprefix $(OBJDIR)/, $(BINTOOL_SOURCES:%.c=%.o) $(SRC:%.c=%.o))


OBJECTS 		 = 	$(BINTOOL_OBJS)

DEP_FILES 		 = $(OBJECTS:%.o=%.d)

#===============================================
#        TARGET RULES
#===============================================
ifneq ($(MAKECMDGOALS),clean)
-include $(DEP_FILES)
endif

.PHONY startlog:
	@echo ''
	@echo 'Bin Toll Build Start!'
#	@echo -------------------------------------------------------------------------

all : startlog exist exe
	
exist :
	@echo ''
	@echo CREATING $(OBJDIR)
	@if test ! -d $(OBJDIR); then $(MKDIR) $(OBJDIR); fi
#	@echo -------------------------------------------------------------------------


exe : $(TARGET).$(EXETYPE)

$(TARGET).$(EXETYPE) : $(OBJECTS)
	@echo Building target: $@
	@$(CC) $(EXTENSIONS) $(ALL_INCLUDES) -o $(OBJDIR)/$(TARGET).$(EXETYPE) -Wl,-Map,$(TARGET).map $(OBJECTS) $(LIB)
	@echo Finished building target: $@
	@echo ''
	@$(MV) $(OBJDIR)/$(TARGET).$(EXETYPE) $(BUILDDIR)
#	@echo -------------------------------------------------------------------------

$(OBJDIR)/%.o : $(APPSRCROOT)/%.c $(MAKEFILE)
	@echo Compiling $@
	@$(MAKETARGETDIR)
	@$(CXX) $(CFLAGS) $(EXTENSIONS) $(ALL_INCLUDES) -o $@ $<
	@$(RM) $(OBJDIR)/$(*F).d.bak
#	@echo -------------------------------------------------------------------------

clean :
	@echo ''
	@echo CLEAN Binary
	@echo     ... remove obj, dependency files, execute files
	@$(RM) -fR $(BUILDDIR)/$(TARGET).* $(BUILDDIR)/obj
	@echo ''
#	@echo -------------------------------------------------------------------------

