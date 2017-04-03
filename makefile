SOURCE_DIR = src
INCLUDE_DIR = include
OBJ_DIR = bin
DOC_DIR = doc
DEPEND_DIR = depend
TEST_DIR = test

VERSION_STAGE = alpha
VERSION_MAJOR = 0
VERSION_MINOR = 0
VERSION_PATCH = 0

TARGET = libmagenta-$(VERSON_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)-$(VERSON_STAGE).so
TARGET_LINK = libmagenta.so

CPP_FILES = $(shell find $(SOURCE_DIR) -path $(SOURCE_DIR)/$(TEST_DIR) -prune -o -type f -name "*.cpp" -printf '%p ')
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(patsubst %.cpp,%.o,$(notdir $(CPP_FILES))))
DEPEND_FILES = $(patsubst $(OBJ_DIR)/%,$(DEPEND_DIR)/%,$(patsubst %.o,%.d,$(OBJ_FILES)))

TEST_CPP_FILES = $(shell find $(SOURCE_DIR)/$(TEST_DIR) -type f -name "*.cpp" -printf '%p ')
TEST_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(patsubst %.cpp,%.o,$(notdir $(TEST_CPP_FILES))))
TEST_DEPEND_FILES = $(patsubst $(OBJ_DIR)/%,$(DEPEND_DIR)/%,$(patsubst %.o,%.d,$(TEST_OBJ_FILES)))

LIBS = -lboost_unit_test_framework
VERSION_FLAGS = -D VERSION_STAGE="$(VERSION_STAGE)" -D VERSION_MAJOR=$(VERSION_MAJOR) -D VERSION_MINOR=$(VERSON_MINOR) -D VERSION_PATCH=$(VERSION_PATCH)
DEBUG_FLAGS = -g -O0 -DDEBUG
WARNING_FLAGS = -Wall -Wextra
INCLUDE_FLAGS = -I include
LIB_FLAGS =
COMPILER = g++
COMPILER_FLAGS = -std=c++17 -fPIC $(WARNING_FLAGS) $(DEBUG_FLAGS) $(INCLUDE_FLAGS) $(VERSION_FLAGS)

COMPILE = $(COMPILER) $(COMPILER_FLAGS)
LINK = $(COMPILER) $(COMPILER_FLAGS) $(LIBS) $(LIB_FLAGS) $(OBJ_FILES)

PREFIX = /usr/lib
DOXYFILE = Doxyfile

.PHONY : clean install uninstall test doc

$(TARGET) : $(OBJ_FILES)
	$(LINK) -shared -o $@

test: $(TEST_OBJ_FILES) $(OBJ_FILES)
	$(LINK) $(TEST_OBJ_FILES) -o $@.out

.SECONDEXPANSION:
$(OBJ_DIR)/%.o : $$(shell find $(SOURCE_DIR) -type f -name %.cpp)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEPEND_DIR)
	$(COMPILE) -c $< -o $@
	$(COMPILE) -MM $< > $(DEPEND_DIR)/$*.d
	@sed -i '1s/^/$(OBJ_DIR)\//' $(DEPEND_DIR)/$*.d

install: $(TARGET)
	install -m 755 $(TARGET) $(PREFIX)/$(TARGET)
	ln -sf $(PREFIX)/$(TARGET) $(PREXIX)/$(TARGET_LINK)

uninstall:
	rm -f $(PREFIX)/$(TARGET) $(PREFIX)/$(TARGET_LINK)

clean :
	$(RM) -r $(OBJ_DIR) $(DEPEND_DIR) $(TARGET) test.out $(DOC_DIR)

doc :
	@mkdir -p $(DOC_DIR)
	doxygen $(DOXYFILE)

-include $(TEST_DEPEND_FILES) $(DEPEND_FILES)
