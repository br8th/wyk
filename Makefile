BUILD_DIR := build
EXECUTABLES = wyk wykd

default: wyk

# Compile all
wyk:
	@ $(MAKE) -f c.make NAME=wyk MODE=release SOURCE_DIR=src
	@ cp build/wyk wyk

# Compile the C interpreter. We set SNIPPET=true, allowing unused-functions.
debug:
	@ $(MAKE) -f c.make NAME=wykd MODE=debug SOURCE_DIR=src SNIPPET=true
	@ cp build/wykd wykd

# Remove all build outputs and intermediate files.
clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR)
	@for file in $(EXECUTABLES); do \
        if [ -e $$file ]; then rm $$file; fi; \
    done
	@echo "Done."