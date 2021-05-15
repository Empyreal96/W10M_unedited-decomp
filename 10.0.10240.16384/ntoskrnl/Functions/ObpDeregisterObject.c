// ObpDeregisterObject 
 
int __fastcall ObpDeregisterObject(int result)
{
  int v1; // r6
  _DWORD *v2; // r7
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r5
  unsigned int v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r2
  _DWORD *v9; // r5
  int v10; // r3
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  unsigned int v15; // r1
  __int16 v16; // r3

  v1 = result;
  if ( (dword_682610 & 0x80) != 0 )
    result = EtwTraceObject(4401, result);
  if ( (*(_BYTE *)(v1 + 13) & 1) != 0 && (*(_BYTE *)(v1 + 13) & 2) == 0 )
  {
    v2 = 0;
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v3 + 310);
    v4 = KeAbPreAcquire((unsigned int)&ObpStackTraceLock, 0, 0);
    v5 = v4;
    do
      v6 = __ldrex((unsigned __int8 *)&ObpStackTraceLock);
    while ( __strex(v6 | 1, (unsigned __int8 *)&ObpStackTraceLock) );
    __dmb(0xBu);
    if ( (v6 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&ObpStackTraceLock, v4, (unsigned int)&ObpStackTraceLock);
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    if ( (ObpTraceFlags & 0x73) == 0 )
    {
      __dmb(0xBu);
      do
        v7 = __ldrex((unsigned int *)&ObpStackTraceLock);
      while ( __strex(v7 - 1, (unsigned int *)&ObpStackTraceLock) );
LABEL_33:
      if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
      result = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
      v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v16 = *(_WORD *)(v15 + 0x136) + 1;
      *(_WORD *)(v15 + 310) = v16;
      if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 )
        result = KiCheckForKernelApcDelivery(result);
      return result;
    }
    v8 = (((unsigned int)(v1 + 24) >> 4) & 0xFFFFF) % 0x191;
    v9 = *(_DWORD **)(ObpObjectTable + 4 * v8);
    if ( !v9 )
      goto LABEL_31;
    do
    {
      if ( *v9 == v1 )
        break;
      v2 = v9;
      v9 = (_DWORD *)v9[1];
    }
    while ( v9 );
    if ( !v9 )
    {
LABEL_31:
      __dmb(0xBu);
      do
        v7 = __ldrex((unsigned int *)&ObpStackTraceLock);
      while ( __strex(v7 - 1, (unsigned int *)&ObpStackTraceLock) );
      goto LABEL_33;
    }
    v10 = v9[1];
    if ( v2 )
      v2[1] = v10;
    else
      *(_DWORD *)(ObpObjectTable + 4 * v8) = v10;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&ObpStackTraceLock);
    while ( __strex(v11 - 1, (unsigned int *)&ObpStackTraceLock) );
    if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
    v12 = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_WORD *)(v13 + 0x136) + 1;
    *(_WORD *)(v13 + 310) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 )
      KiCheckForKernelApcDelivery(v12);
    result = ExFreePoolWithTag((unsigned int)v9);
  }
  return result;
}
