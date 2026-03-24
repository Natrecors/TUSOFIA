import numpy as np
from scipy.io import wavfile

class MusicGenerator:
    def __init__(self, sampling_rate):
        self.sampling_rate = sampling_rate

    def generate_sine_wave(self, frequency, duration, amplitude):
        num_samples = int(self.sampling_rate * duration)
        time = np.linspace(0, duration, num_samples, endpoint=False)
        audio_signal = amplitude * np.sin(2 * np.pi * frequency * time)
        return audio_signal

    def generate_music(self, notes):
        composed_music = np.array([])
        for note in notes:
            frequency = note[1]
            duration = note[2]
            # Генерираме сигнал за текущата нота (амплитуда 0.5)
            audio_signal = self.generate_sine_wave(frequency, duration, 0.5)
            composed_music = np.append(composed_music, audio_signal)
        return composed_music

    def save_signal_to_wav(self, filename, signal):
        max_amplitude = np.max(np.abs(signal))
        if max_amplitude > 0:
            normalized_signal = signal / max_amplitude
        else:
            normalized_signal = signal
        wavfile.write(filename, self.sampling_rate, normalized_signal.astype(np.float32))

def main():
    sampling_rate = 44100
    music_generator = MusicGenerator(sampling_rate)

    # Ноти за "Für Elise" (примерът от шаблона)
    notes = [
        ('E5', 659.26, 0.5),
        ('D#5', 622.25, 0.5),
        ('E5', 659.26, 0.5),
        ('D#5', 622.25, 0.5),
        ('E5', 659.26, 0.5),
        ('B4', 493.88, 0.5),
        ('D5', 587.33, 0.5),
        ('C5', 523.25, 0.5),
        ('A4', 440.00, 1),
    ]

    composed_music = music_generator.generate_music(notes)
    music_generator.save_signal_to_wav("composed_music.wav", composed_music)

if __name__ == "__main__":
    main()