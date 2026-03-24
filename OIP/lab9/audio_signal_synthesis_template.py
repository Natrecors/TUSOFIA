import numpy as np
from scipy.io import wavfile
import matplotlib.pyplot as plt

# --- ПАРАМЕТРИ ---
sampling_rate = 44100
frequency = 490          # Честота за Фак. No завършващ на 9
duration = 1             # Продължителност 1 секунда
amplitude = 1            # Амплитуда

# --- ФУНКЦИИ ЗА ГЕНЕРИРАНЕ ---
def generate_sine_wave(freq, dur, amp):
    t = np.linspace(0, dur, int(sampling_rate * dur), endpoint=False)
    signal = amp * np.sin(2 * np.pi * freq * t)
    return t, signal

def generate_rectangular_wave(freq, dur, amp):
    t = np.linspace(0, dur, int(sampling_rate * dur), endpoint=False)
    # Eq. 2 от ръководството
    signal = amp * np.sign(np.sin(2 * np.pi * freq * t))
    return t, signal

def generate_asymetric_triangular_wave(freq, dur, amp):
    t = np.linspace(0, dur, int(sampling_rate * dur), endpoint=False)
    period = 1 / freq
    # Eq. 3 от ръководството
    signal = amp * ((2 / period) * (t % period) - 1)
    return t, signal

def generate_symetric_triangular_wave(freq, dur, amp):
    t = np.linspace(0, dur, int(sampling_rate * dur), endpoint=False)
    period = 1 / freq
    # Eq. 4 от ръководството
    signal = 2 * amp * (1 - (2 / period) * np.abs((t % period) - (period / 2))) - 1
    return t, signal

# --- ФУНКЦИИ ЗА ВИЗУАЛИЗАЦИЯ И ЗАПИС ---
def visualize_signal(t, signal, title, filename):
    plt.figure(figsize=(10, 4))
    plt.plot(t, signal)
    plt.title(title)
    plt.xlabel("Time (s)")
    plt.ylabel("Amplitude")
    plt.grid(True)
    plt.xlim(0, 0.01) # Zoom: показваме първите 10ms (около 5 периода)
    plt.tight_layout()
    plt.savefig(filename)
    plt.close() # Затваряме графиката, за да не се трупат

def plot_spectrum(signal, title, filename):
    n = len(signal)
    fft_vals = np.fft.fft(signal)
    freqs = np.fft.fftfreq(n, 1 / sampling_rate)
    
    # Взимаме само положителните честоти
    pos_mask = freqs > 0
    freqs = freqs[pos_mask]
    fft_vals = 2.0 / n * np.abs(fft_vals[pos_mask])
    
    plt.figure(figsize=(10, 6))
    plt.plot(freqs, fft_vals)
    plt.title(title)
    plt.xlabel("Frequency (Hz)")
    plt.ylabel("Amplitude")
    plt.grid(True)
    plt.xlim(0, 3000) 
    plt.tight_layout()
    plt.savefig(filename)
    plt.close()

def save_wav(filename, signal):
    max_val = np.max(np.abs(signal))
    if max_val > 0:
        signal = signal / max_val
    wavfile.write(filename, sampling_rate, signal.astype(np.float32))

# --- MAIN ---
def main():
    # 1. Sinusoidal
    t, sig_sin = generate_sine_wave(frequency, duration, amplitude)
    visualize_signal(t, sig_sin, "Sin wave", "SinWave.png")
    plot_spectrum(sig_sin, "Sin wave spectrum", "SinWaveSpec.png")
    save_wav("SinWave.wav", sig_sin)

    # 2. Rectangular
    t, sig_rect = generate_rectangular_wave(frequency, duration, amplitude)
    visualize_signal(t, sig_rect, "Rectangular wave", "RectWave.png")
    plot_spectrum(sig_rect, "Rectangular wave spectrum", "RectWaveSpec.png")
    save_wav("RectWave.wav", sig_rect)

    # 3. Asymmetric Triangle
    t, sig_asym = generate_asymetric_triangular_wave(frequency, duration, amplitude)
    visualize_signal(t, sig_asym, "Asymmetric Triangular wave", "AsymTriWave.png")
    plot_spectrum(sig_asym, "Asymmetric Triangle spectrum", "AsymTriSpec.png")
    save_wav("AsymTriWave.wav", sig_asym)

    # 4. Symmetric Triangle
    t, sig_sym = generate_symetric_triangular_wave(frequency, duration, amplitude)
    visualize_signal(t, sig_sym, "Symmetric Triangular wave", "SymTriWave.png")
    plot_spectrum(sig_sym, "Symmetric Triangle spectrum", "SymTriSpec.png")
    save_wav("SymTriWave.wav", sig_sym)

if __name__ == "__main__":
    main()