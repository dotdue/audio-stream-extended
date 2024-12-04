#if defined _INC_audio_stream_extended
    #endinput
#endif
#define _INC_audio_stream_extended

#include <a_samp>

static
    g_PlayerLastAudioStreamUrl[MAX_PLAYERS][128 char];

stock Audio_PlayAudioStreamForPlayer(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, bool:usepos = false)
{
    strpack(g_PlayerLastAudioStreamUrl[playerid], url);
    return PlayAudioStreamForPlayer(playerid, url, posX, posY, posZ, distance, usepos);
}
#if defined _ALS_PlayAudioStreamForPlayer
    #undef PlayAudioStreamForPlayer
#else
    #define _ALS_PlayAudioStreamForPlayer
#endif

#define PlayAudioStreamForPlayer Audio_PlayAudioStreamForPlayer

stock bool:GetPlayerLastAudioStream(playerid, dest[], maxlength = sizeof dest)
    return bool:(strunpack(dest, g_PlayerLastAudioStreamUrl[playerid], maxlength));

stock bool:PlayAudioStreamForPlayerEx(playerid, const url[], volume = 100)
{
    StopAudioStreamForPlayer(playerid);

    if (!(0 <= volume <= 100))
        return false;

    if (volume == 100)
        return bool:(PlayAudioStreamForPlayer(playerid, url));

    return bool:(PlayAudioStreamForPlayer(playerid, url, 0.0, 0.0, 100000.0 - (volume * 1000.0), 100000.0, true));
}

public OnPlayerDisconnect(playerid, reason)
{
    g_PlayerLastAudioStreamUrl[playerid][0] = '\0';

    #if defined Audio_OnPlayerDisconnect
        return Audio_OnPlayerDisconnect(playerid, reason);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect Audio_OnPlayerDisconnect
#if defined Audio_OnPlayerDisconnect
    forward Audio_OnPlayerDisconnect(playerid, reason);
#endif
