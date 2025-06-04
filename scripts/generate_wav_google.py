from gtts import gTTS
from pydub import AudioSegment
from pydub.utils import which
import os

# 使用 ffmpeg
AudioSegment.converter = which("ffmpeg")

# 调试信息
print("Script started...")

# 文本和输出目录
text = "hello i am a ai voice assistant"
output_dir = "data/audio"
output_file = os.path.join(output_dir, "hello_ai_voice_assistant.wav")
temp_mp3_file = os.path.join(output_dir, "temp.mp3")

# 确保目录存在
os.makedirs(output_dir, exist_ok=True)

# 创建 MP3 文件
try:
    print("Generating MP3...")
    tts = gTTS(text=text, lang='en')
    tts.save(temp_mp3_file)
    print(f"✅ MP3 file saved at: {temp_mp3_file}")
except Exception as e:
    print(f"❌ Failed to generate MP3: {str(e)}")
    exit(1)

# 检查生成的 MP3 文件
if os.path.exists(temp_mp3_file):
    print(f"✅ MP3 file exists: {temp_mp3_file}")
else:
    print("❌ MP3 file was not generated.")

# 转换 MP3 -> WAV
try:
    print("Converting MP3 to WAV...")
    audio = AudioSegment.from_mp3(temp_mp3_file)
    audio.export(output_file, format="wav")
    os.remove(temp_mp3_file)  # 删除临时 MP3 文件
    print(f"✅ WAV file saved to: {output_file}")
except Exception as e:
    print(f"❌ Failed to convert MP3 to WAV: {str(e)}")
