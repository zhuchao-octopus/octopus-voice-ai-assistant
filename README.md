

# Open Voice AI Assistant Project

This project is a local AI voice assistant based on the Allwinner T113 platform. The assistant supports speech recognition, dialogue management, and speech synthesis.

#项目整体的目录结构
octopus-ai-voice-assistant/
├── CMakeLists.txt              # CMake 构建文件
├── README.md                  # 项目说明文件
├── data/                      # 数据存放目录 (音频文件，模型文件等)
│   ├── models/                # 存放语言模型的文件
│   ├── audio/                 # 存放测试音频文件
├── src/                       # 源代码目录
│   ├── main.cpp               # 主程序文件
│   ├── audio_processor/       # 语音处理模块
│   │   ├── AudioRecorder.cpp  # 音频录制相关代码
│   │   ├── AudioRecorder.h    # 音频录制相关头文件
│   │   ├── AudioPlayer.cpp    # 音频播放相关代码
│   │   └── AudioPlayer.h      # 音频播放相关头文件
│   ├── speech_recognition/    # 语音识别模块 (Whisper.cpp)
│   │   ├── WhisperRecognizer.cpp   # Whisper 语音识别处理
│   │   └── WhisperRecognizer.h     # Whisper 语音识别头文件
│   ├── language_model/        # 语言模型模块 (Llama.cpp)
│   │   ├── LanguageModel.cpp  # Llama 语言模型处理
│   │   └── LanguageModel.h    # Llama 语言模型头文件
│   ├── dialogue_manager/      # 对话管理模块
│   │   ├── DialogueManager.cpp   # 管理对话的核心逻辑
│   │   └── DialogueManager.h     # 对话管理相关头文件
├── include/                   # 公共头文件
│   ├── AudioProcessor.h       # 音频处理相关的公共头文件
│   ├── SpeechRecognition.h    # 语音识别相关的公共头文件
│   ├── LanguageModel.h        # 语言模型相关的公共头文件
│   ├── DialogueManager.h      # 对话管理相关的公共头文件
├── scripts/                   # 脚本文件 (如安装脚本，配置文件等)
│   ├── setup.sh               # 设置环境的脚本
│   └── test.sh                # 测试脚本，启动语音助手测试
├── test/                      # 单元测试目录
│   ├── test_speech_recognition.cpp  # 语音识别单元测试
│   ├── test_language_model.cpp     # 语言模型单元测试
│   └── test_dialogue_manager.cpp   # 对话管理单元测试
└── venv/                      # 虚拟环境目录 (可选)

###################################################################################
#开发顺序总结：
1. 完成环境配置。
2. 实现语音识别功能（whisper.cpp）。
3. 实现语音合成功能。
4. 实现与大语言模型的接口。
5. 集成各模块，完成语音助手框架。
6. 优化性能与离线推理能力。
7. 添加用户界面和交互功能（如有需要）。

## Modules

1. **Speech Recognition**: Converts speech to text using Whisper.
2. **Language Model**: Uses a local Llama model for generating responses.
3. **Dialogue Management**: Handles the logic for maintaining a conversation flow.
4. **Audio Processing**: Captures and plays back audio.

## Setup
###################################################################################
To set up the environment:
请确保系统已安装：
- CMake ≥ 3.15
- GCC / Clang（支持 C++17）
- make
- Python 3（用于虚拟环境）
- 相关依赖库（如 PortAudio、OpenAL，依据实际模块）

### 🚀 编译步骤

#### 1️⃣ 激活虚拟环境

Linux / macOS:
```bash
source venv/bin/activate


 echo "Hello, I am a speech synthesis system." | text2wave -o output.wav
```bash
./scripts/setup.sh



