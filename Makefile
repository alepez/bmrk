default: all
.PHONY: default

all: build/CMakeCache.txt
	@cd build && make all
.PHONY: all

build/CMakeCache.txt: CMakeLists.txt
	@mkdir -p build
	@cd build && cmake ..

test: all
	@./build/test/lib/unit_tests
.PHONY: test

distclean:
	@rm -rf build/*  tmp/* default.profdata default.profraw
.PHONY: distclean
