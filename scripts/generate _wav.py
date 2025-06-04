from gtts import gTTS
import os
from pydub import AudioSegment

# Text to be converted to speech
text = "Hello, I am an AI voice assistant."

# Language for TTS (English)
language = 'en'

# Create the TTS object
tts = gTTS(text=text, lang=language, slow=False)

# Output file path
output_dir = "../data/audio/"
os.makedirs(output_dir, exist_ok=True)  # Ensure the directory exists
output_file = os.path.join(output_dir, "hello_ai_voice_assistant.wav")

# Save the speech to a temporary MP3 file
temp_mp3_file = "temp.mp3"
tts.save(temp_mp3_file)

# Convert MP3 to WAV
audio = AudioSegment.from_mp3(temp_mp3_file)

# Export as WAV to the specified directory
audio.export(output_file, format="wav")

# Remove the temporary MP3 file
os.remove(temp_mp3_file)

print(f"WAV file has been saved to: {output_file}")
