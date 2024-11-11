# Define the directories
DIRS = 1 2 3 4

.PHONY: all clean $(DIRS)

# Target to build all directories
all: $(DIRS)

# Build each directory
$(DIRS):
	$(MAKE) -C $@

# Clean all directories
clean:
	for dir in $(DIRS); do \
		$(MAKE) -C $$dir clean; \
	done