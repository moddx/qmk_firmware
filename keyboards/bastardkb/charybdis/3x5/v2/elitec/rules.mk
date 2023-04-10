# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

AUDIO_SUPPORTED = no        # Audio is not supported

# Charybdis nano is a split 3x5 keyboard with a maximum of 3 thumb keys (2 on
# the trackball side).
SPLIT_KEYBOARD = yes  # todo mses moved in 569be5951e94c59138a172871f4213ec802e6877

# POINTING_DEVICE_ENABLE = yes # Enable trackball # todo mses moved in 569be5951e94c59138a172871f4213ec802e6877, seems to be in info.json
POINTING_DEVICE_DRIVER = pmw3389
MOUSE_SHARED_EP = no # Unify multiple HID interfaces into a single Endpoint
