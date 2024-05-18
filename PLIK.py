import wave
import struct
from build.Debug.Project3 import *

chart=input("1-sin 2-cos 3-squarewave 4-sawtooth: ")
SIGNAL(int (chart))

with wave.open('murloc.wav') as f:
    data = f.readframes(f.getnframes())
    duration = f.getnframes()/f.getframerate()
    audio = struct.unpack('{n}h'.format(n=f.getnframes()*f.getnchannels()), data)

AUDIO(audio,duration)
