#!/bin/bash

# Disable hardware video acceleration to avoid Vulkan/VDPAU errors
export LIBVA_DRIVER_NAME=none
export VDPAU_DRIVER=none

# Run the VideoPlayer application
./VideoPlayer
