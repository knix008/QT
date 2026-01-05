# Makefile for Qt VideoPlayer Application

# Project settings
PROJECT = VideoPlayer
PRO_FILE = VideoPlayer.pro
TARGET = VideoPlayer

# Qt tools
QMAKE = qmake
MAKE = make

# qmake generates this Makefile
QMAKE_MAKEFILE = Makefile.qmake

# Default target
.PHONY: all
all: $(TARGET)

# Generate Makefile from .pro file and build
$(TARGET): $(QMAKE_MAKEFILE)
	@echo "Building project..."
	$(MAKE) -f $(QMAKE_MAKEFILE)

$(QMAKE_MAKEFILE): $(PRO_FILE)
	@echo "Running qmake..."
	$(QMAKE) -o $(QMAKE_MAKEFILE) $(PRO_FILE)

# Explicit build target
.PHONY: build
build: $(TARGET)

# Clean build artifacts
.PHONY: clean
clean:
	@echo "Cleaning build artifacts..."
	@if [ -f $(QMAKE_MAKEFILE) ]; then $(MAKE) -f $(QMAKE_MAKEFILE) clean; fi
	@rm -f *.o moc_*.cpp moc_*.h ui_*.h qrc_*.cpp
	@rm $(TARGET)
	@echo "Clean complete."

# Deep clean (remove all generated files including qmake Makefile)
.PHONY: distclean
distclean:
	@echo "Deep cleaning..."
	@if [ -f $(QMAKE_MAKEFILE) ]; then $(MAKE) -f $(QMAKE_MAKEFILE) distclean; fi
	@rm -f $(QMAKE_MAKEFILE) .qmake.stash
	@rm -f $(TARGET)
	@rm -f *.o moc_*.cpp moc_*.h ui_*.h qrc_*.cpp
	@rm -rf .obj .moc .ui
	@echo "Distclean complete."

# Run the application
.PHONY: run
run: $(TARGET)
	@echo "Running $(TARGET)..."
	@export LIBVA_DRIVER_NAME=none && export VDPAU_DRIVER=none && ./$(TARGET)

# Rebuild from scratch
.PHONY: rebuild
rebuild: distclean all

# Install target (uses qmake's install rules)
.PHONY: install
install: $(TARGET)
	@if [ -f $(QMAKE_MAKEFILE) ]; then $(MAKE) -f $(QMAKE_MAKEFILE) install; fi

# Help target
.PHONY: help
help:
	@echo "Qt VideoPlayer Makefile"
	@echo ""
	@echo "Available targets:"
	@echo "  all (default) - Build the application"
	@echo "  build         - Build the application"
	@echo "  clean         - Remove build artifacts"
	@echo "  distclean     - Remove all generated files"
	@echo "  run           - Build and run the application"
	@echo "  rebuild       - Clean and rebuild from scratch"
	@echo "  install       - Install the application"
	@echo "  help          - Show this help message"
