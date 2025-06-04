# Declare a CMake library target named "language_model" built from LanguageModel.cpp
# Create a static or shared library target named 'language_model' and include all necessary source files
add_library(language_model
    ChatGPTModel.cpp
    LlamaModel.cpp
    LanguageModelWrapper.cpp
)

# Specify public include directories for the language_model target.
# ${CMAKE_CURRENT_SOURCE_DIR} refers to the current directory (src/language_model),
# so headers in this directory can be included as #include "LanguageModel.h".
target_include_directories(language_model PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include  # Optional: expose shared headers like "LanguageModel.h"
)

# Optionally, link any dependencies (e.g., external LLM engines or HTTP clients)
# For now, leave it blank or comment it until specific libraries are added
# target_link_libraries(language_model
#     llama  # For local LLaMA GGUF inference (added in root CMakeLists.txt)
# )
