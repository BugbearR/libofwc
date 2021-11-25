# for GNU make
BUILD_CONF ?= release
#BUILD_CONF = debug
CFLAGS ?= -g

CUR_DIR = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))

TEST_TARGET_BASE_NAME = $(notdir $(CUR_DIR:%/=%))
TEST_TARGET ?= $(TEST_TARGET_BASE_NAME)
LIBS = ofwc
LIBS_OPTS = $(addprefix -l,$(LIBS))

SRC_DIR ?= ../src
BUILD_DIR ?= ../build
DIST_DIR ?= ../dist

TEST_SRC_DIR ?= src
TEST_BUILD_DIR ?= build
TEST_DIST_DIR ?= dist

TEST_BUILD_FULL_DIR = $(TEST_BUILD_DIR)/$(BUILD_CONF)
TEST_DIST_FULL_DIR = $(TEST_DIST_DIR)/$(BUILD_CONF)
DIST_FULL_DIR = $(DIST_DIR)/$(BUILD_CONF)

TEST_TARGET_FULL = $(TEST_DIST_FULL_DIR)/bin/$(TEST_TARGET)

INCLUDE_DIRS ?= ../include
INCLUDE_DIRS_OPTS = $(addprefix -I,$(INCLUDE_DIRS))

LIB_DIRS ?= $(DIST_FULL_DIR)/lib $(TEST_DIST_FULL_DIR)/lib
LIB_DIRS_OPTS = $(addprefix -L,$(LIB_DIRS))

EXCLUDE_SRCS =
TEST_SRCS = $(filter-out $(EXCLUDE_SRCS:%=$(TEST_SRC_DIR)/%), $(wildcard $(TEST_SRC_DIR)/**/*.c $(TEST_SRC_DIR)/*.c))
TEST_OBJS = $(patsubst $(TEST_SRC_DIR)/%,$(TEST_BUILD_FULL_DIR)/%,$(patsubst %.c,%.o,$(TEST_SRCS)))
TEST_DEPENDS = $(patsubst $(TEST_SRC_DIR)/%,$(TEST_BUILD_FULL_DIR)/%,$(patsubst %.c,%.d,$(SRCS)))

include Makefile.local.mk

.PHONY: all
all: $(TEST_TARGET_FULL)

.PHONY: test
test: $(TEST_TARGET_FULL)
	$(TEST_TARGET_FULL)

.PHONY: clean
clean:
	-rm -rf $(TEST_BUILD_FULL_DIR)

$(TEST_TARGET_FULL): $(TEST_OBJS)
	@mkdir -p $$(dirname "$@")
	$(CC) $(LDFLAGS) $(LIB_DIRS_OPTS) -o $@ $(TEST_OBJS) $(LIBS_OPTS)

$(TEST_BUILD_FULL_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	@mkdir -p $$(dirname "$@")
	$(CC) $(CFLAGS) $(INCLUDE_DIRS_OPTS) -c -o $@ $<

$(TEST_BUILD_FULL_DIR)/%.d: $(TEST_SRC_DIR)/%.c
	@mkdir -p $$(dirname "$@")
	$(CC) $(CFLAGS) $(INCLUDE_DIRS_OPTS) -c -fsyntax-only -MMD -MF $@ -MT $(patsubst %.d,%.o,$@) $<

ifneq ($(MAKECMDGOALS),clean)
-include $(TEST_DEPENDS)
endif
