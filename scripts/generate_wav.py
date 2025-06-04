import pyttsx3
from pydub import AudioSegment
import os

# 初始化 pyttsx3 引擎
engine = pyttsx3.init()

# 设置语音参数（可选）
engine.setProperty('rate', 150)  # 设置语速，默认值是200
engine.setProperty('volume', 1)  # 设置音量，范围是0.0到1.0

# 需要转换的文本
text = "Hello, I am an AI voice assistant, and this is a test."

# 设置输出路径
wav_output_file = "../data/audio/test_output.wav"
mp3_output_file = "../data/audio/test_output.mp3"

# 确保输出目录存在
os.makedirs(os.path.dirname(wav_output_file), exist_ok=True)

# 生成语音并保存为 WAV 文件
try:
    print("Generating audio...")
    engine.save_to_file(text, wav_output_file)
    engine.runAndWait()  # 执行并等待生成过程完成
    print(f"✅ Audio file saved at: {wav_output_file}")
except Exception as e:
    print(f"❌ Failed to generate audio: {str(e)}")

# 使用 pydub 将 WAV 文件转换为 MP3 文件
try:
    print(f"Converting {wav_output_file} to {mp3_output_file}...")
    audio = AudioSegment.from_wav(wav_output_file)
    audio.export(mp3_output_file, format="mp3")
    print(f"✅ MP3 file saved at: {mp3_output_file}")
except Exception as e:
    print(f"❌ Failed to convert to MP3: {str(e)}")
