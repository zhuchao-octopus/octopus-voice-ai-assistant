# Create a CMake static library target named "speech_recognition"
# It will compile WhisperRecognizer.cpp as part of the library.
add_library(speech_recognition
    WhisperRecognizer.cpp
)

# Specify public include directories for this library.
# This allows other targets to include headers from this module
# using #include "WhisperRecognizer.h"
target_include_directories(speech_recognition PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}         # Local header files like WhisperRecognizer.h
    ${PROJECT_SOURCE_DIR}/include       # (Optional) Shared interface headers like SpeechRecognition.h
)

# Link the whisper library (from whisper.cpp subdirectory) and external dependencies
# "whisper" target is created by the CMakeLists.txt in src/external/whisper.cpp
# "sndfile" is required for loading audio (e.g., .wav files)
#target_link_libraries(speech_recognition
#    whisper
#    sndfile
#)
