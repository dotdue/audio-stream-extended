#define FILTERSCRIPT
#include <a_samp>
#include <pawn.cmd>
#include <audio-stream-extended>

CMD:audio(playerid, const params[])
{
    new string[128], bool:ret = PlayAudioStreamForPlayerEx(playerid, "https://live.hunter.fm/pop_normal", strval(params));

    format(string, sizeof string, "[DEBUG] return = %s, volume = %i", ret ? "true" : "false", strval(params));
    SendClientMessage(playerid, 0xCDCDCDFF, string);
    return 1;
}

CMD:getaudio(playerid)
{
    new string[128], bool:ret = GetPlayerLastAudioStream(playerid, string);

    format(string, sizeof string, "[DEBUG] return = %s, audio = %s", ret ? "true" : "false", string);
    SendClientMessage(playerid, 0xCDCDCDFF, string);
    return 1;
}
