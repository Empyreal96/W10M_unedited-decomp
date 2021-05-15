// WheapPredictiveFailureAnalysis 
 
unsigned int __fastcall WheapPredictiveFailureAnalysis(unsigned int result)
{
  unsigned int v1; // r7
  unsigned int v2; // r4
  unsigned int v3; // r1
  _DWORD *v4; // r5
  int v5; // r6
  int v6; // r3
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  unsigned int v10; // r1

  v1 = result;
  v2 = result + 28;
  if ( !WheapPolicyDisableOffline
    && WheapPfaInitialized
    && *(_WORD *)(result + 38)
    && *(_DWORD *)(result + 40) == 2
    && (*(_DWORD *)(result + 132) & 1) == 0 )
  {
    v3 = 0;
    if ( *(_WORD *)(result + 38) )
    {
      v4 = (_DWORD *)(result + 156);
      while ( (v4[3] & 1) == 0 )
      {
        ++v3;
        v4 += 18;
        if ( v3 >= *(unsigned __int16 *)(result + 38) )
          goto LABEL_10;
      }
    }
    else
    {
LABEL_10:
      v4 = (_DWORD *)(result + 156);
    }
    result = memcmp((unsigned int)(v4 + 4), (unsigned int)MEMORY_ERROR_SECTION_GUID, 16);
    if ( !result )
    {
      v5 = *v4 + v2;
      v6 = *(_DWORD *)(v1 + 16);
      if ( (v6 & 4) != 0 )
      {
        if ( (v6 & 8) != 0 && (*(_DWORD *)v5 & 2) != 0 )
          result = WheaAttemptPhysicalPageOffline(*(__int64 *)(v5 + 16) >> 12, 1u);
      }
      else
      {
        v7 = KeAbPreAcquire((unsigned int)&WheapPfaLock, 0, 0);
        v8 = v7;
        do
          v9 = __ldrex((unsigned __int8 *)&WheapPfaLock);
        while ( __strex(v9 | 1, (unsigned __int8 *)&WheapPfaLock) );
        __dmb(0xBu);
        if ( (v9 & 1) != 0 )
          v7 = ExfAcquirePushLockExclusiveEx(&WheapPfaLock, v7, (unsigned int)&WheapPfaLock);
        if ( v8 )
          *(_BYTE *)(v8 + 14) |= 1u;
        WheapPfaMemoryCheck(v7, v5);
        __dmb(0xBu);
        do
          v10 = __ldrex((unsigned int *)&WheapPfaLock);
        while ( __strex(v10 - 1, (unsigned int *)&WheapPfaLock) );
        if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)&WheapPfaLock);
        result = KeAbPostRelease((unsigned int)&WheapPfaLock);
      }
    }
  }
  return result;
}
