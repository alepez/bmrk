all:
	@mkdir -p build && cd build && cmake .. && make all

test: all
	@cd build && make test
