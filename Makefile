include Makefile.inc
rebuild:
	make clean; make all;

all:
	cd src; make all;

clean:
	cd src; make clean;
	@rm -f *.tasks strace_out;
	@rm -rf .config/;

pvs-studio-test:
	pvs-studio-analyzer trace -- make all
	pvs-studio-analyzer analyze
	plog-converter -a '64:1,2,3;GA:1,2,3;OP:1,2,3' -t tasklist -o report.tasks PVS-Studio.log

cpp-check-test:
	cppcheck --quiet --enable=all --force --inconclusive .