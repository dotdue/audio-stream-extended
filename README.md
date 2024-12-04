# audio-stream-extended
Library for [SA-MP](https://sa-mp.mp) and [OPEN-MP](https://open.mp)

**Functions**
```c
GetPlayerLastAudioStream(playerid, dest[], maxlength = sizeof dest);
PlayAudioStreamForPlayerEx(playerid, const url[], volume = 100);
```

[Examples](https://github.com/dotdue/audio-stream-extended/blob/main/examples.pwn?raw=true)

```c
PlayAudioStreamForPlayerEx(playerid, "https://live.hunter.fm/pop_normal", 80);
```
