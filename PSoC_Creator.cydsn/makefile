# Generic GNU Make driver file.
OUT_DIR= output
CONFIG= debug
GEN_SOURCE_DIR= Generated_Source/PSoC5

include platform_$(CONFIG).mk
include app_source.mk
include $(GEN_SOURCE_DIR)/gen_source.mk

GEN_OBJECTS_CortexM3= $(addprefix $(OUT_DIR_CortexM3)/,$(notdir $(addsuffix .o,$(basename $(GEN_C_SOURCE_CortexM3))))) $(addprefix $(OUT_DIR_CortexM3)/,$(notdir $(addsuffix .o,$(basename $(GEN_ASM_SOURCE_CortexM3))))) 
GEN_SEP_OBJECTS_CortexM3= $(addprefix $(OUT_DIR_CortexM3)/,$(notdir $(addsuffix .o,$(basename $(GEN_SEP_C_SOURCE_CortexM3))))) 
DEPS_CortexM3= $(addprefix $(OUT_DIR_CortexM3)/,$(notdir $(addsuffix .c.d,$(basename $(APP_C_SOURCE_CortexM3))))) $(addprefix $(OUT_DIR_CortexM3)/,$(notdir $(addsuffix .c.d,$(basename $(GEN_C_SOURCE_CortexM3))))) $(addprefix $(OUT_DIR_CortexM3)/,$(notdir $(addsuffix .c.d,$(basename $(GEN_SEP_C_SOURCE_CortexM3))))) 
APP_OBJECTS_CortexM3= $(addprefix $(OUT_DIR_CortexM3)/,$(notdir $(addsuffix .o,$(basename $(APP_C_SOURCE_CortexM3))))) 

all : $(OUT_DIR_CortexM3)/$(DESIGN).hex
prebuild_CortexM3 :
	Export/prebuild.sh

postbuild_CortexM3= Export/postbuild.sh

$(OUT_DIR_CortexM3)/$(DESIGN).hex : prebuild_CortexM3 $(OUT_DIR_CortexM3)/$(DESIGN).elf
	$(postbuild_CortexM3) $(OUT_DIR_CortexM3)/$(DESIGN).elf $(OUT_DIR_CortexM3)

$(OUT_DIR_CortexM3)/$(DESIGN).elf : $(APP_OBJECTS_CortexM3) $(GEN_SEP_OBJECTS_CortexM3) $(OUT_DIR_CortexM3)/$(DESIGN).a $(GEN_LIBS_CortexM3) $(APP_LIBS_CortexM3)
	"$(LD)" -Wl,--start-group $^ -o $@ $(LDFLAGS_CortexM3) -Wl,--end-group

$(OUT_DIR_CortexM3)/$(DESIGN).a : $(GEN_OBJECTS_CortexM3)
	"$(AR)" $(ARFLAGS) $@ $^

$(OUT_DIR_CortexM3)/%.o : $(GEN_SOURCE_DIR)/%.c
	@mkdir -p $(OUT_DIR_CortexM3)
	@"$(CC)" $(CDEPGEN_CortexM3)
	"$(CC)" -c $(CFLAGS_CortexM3) $< -o $@

$(OUT_DIR_CortexM3)/%.o : $(GEN_SOURCE_DIR)/%.s
	@mkdir -p $(OUT_DIR_CortexM3)
	"$(AS)" $(ASFLAGS_CortexM3) $< -o $@

$(OUT_DIR_CortexM3)/%.o : %.c
	@mkdir -p $(OUT_DIR_CortexM3)
	@"$(CC)" $(CDEPGEN_CortexM3)
	"$(CC)" -c $(CFLAGS_CortexM3) $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OUT_DIR)
-include $(DEPS_CortexM3)
