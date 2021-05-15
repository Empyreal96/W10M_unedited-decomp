// ObpRegisterObject 
 
int __fastcall ObpRegisterObject(int result, int a2, unsigned int a3, unsigned int a4)
{
  int v4; // r6
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  unsigned int v9; // r5
  int v10; // r0
  unsigned int v11; // r1
  char v12; // r2
  char v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r1
  __int16 v16; // r3
  unsigned int v17[8]; // [sp+0h] [bp-20h] BYREF

  v17[0] = a3;
  v17[1] = a4;
  v4 = result;
  if ( (dword_682610 & 0x80) != 0 )
    result = EtwTraceObject(4400, result);
  if ( (ObpTraceFlags & 0x73) != 0 )
  {
    v17[0] = 0;
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 310);
    v6 = KeAbPreAcquire((unsigned int)&ObpStackTraceLock, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex((unsigned __int8 *)&ObpStackTraceLock);
    while ( __strex(v8 | 1, (unsigned __int8 *)&ObpStackTraceLock) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&ObpStackTraceLock, v6, (unsigned int)&ObpStackTraceLock);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    if ( (ObpTraceFlags & 0x73) == 0
      || (ObpTraceFlags & 0x20) != 0
      && (*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 188) & 0x200) == 0
      || !ObpIsObjectPoolTagTraced(v4)
      || ObpGetObjectRefInfo(v4, v17) < 0 )
    {
      goto LABEL_20;
    }
    v9 = v17[0];
    if ( !v17[0] )
    {
      v10 = ExAllocatePoolWithTag(512, 6124, 1951556175);
      v9 = v10;
      if ( !v10 )
      {
LABEL_20:
        __dmb(0xBu);
        do
          v14 = __ldrex((unsigned int *)&ObpStackTraceLock);
        while ( __strex(v14 - 1, (unsigned int *)&ObpStackTraceLock) );
        if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
        result = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
        v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v16 = *(_WORD *)(v15 + 0x136) + 1;
        *(_WORD *)(v15 + 310) = v16;
        if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 )
          result = KiCheckForKernelApcDelivery(result);
        return result;
      }
      v11 = (((unsigned int)(v4 + 24) >> 4) & 0xFFFFF) % 0x191;
      *(_DWORD *)(v10 + 4) = *(_DWORD *)(ObpObjectTable + 4 * v11);
      *(_DWORD *)(ObpObjectTable + 4 * v11) = v10;
      *(_WORD *)(v10 + 26) = 508;
    }
    ++ObpNumTracedObjects;
    *(_DWORD *)v9 = v4;
    __mrc(15, 0, 13, 0, 3);
    RtlStringCbCopyA(v9 + 8);
    *(_WORD *)(v9 + 24) = 0;
    memset((_BYTE *)(v9 + 28), 0, 12 * *(unsigned __int16 *)(v9 + 26));
    v12 = *(_BYTE *)(v4 + 13) | 1;
    v13 = ObpTraceFlags;
    *(_BYTE *)(v4 + 13) = v12;
    if ( (v13 & 0x40) != 0 )
      *(_BYTE *)(v4 + 13) = v12 | 2;
    goto LABEL_20;
  }
  return result;
}
