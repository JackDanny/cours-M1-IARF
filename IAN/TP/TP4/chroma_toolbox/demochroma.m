filename = 'musique-extrait.wav';
[f_audio,sideinfo] = wav_to_audio('', 'WAV/', filename);
shiftFB = estimateTuning(f_audio);

paramPitch.winLenSTMSP = 4410;
paramPitch.shiftFB = shiftFB;
paramPitch.visualize = 1;
parameter.saveDir = 'F0/';
[f_pitch,sideinfo] = audio_to_pitch_via_FB(f_audio,paramPitch,sideinfo);

paramCP.applyLogCompr = 0;
paramCP.visualize = 1;
paramCP.inputFeatureRate = sideinfo.pitch.featureRate;
[f_CP,sideinfo] = pitch_to_chroma(f_pitch,paramCP,sideinfo);

