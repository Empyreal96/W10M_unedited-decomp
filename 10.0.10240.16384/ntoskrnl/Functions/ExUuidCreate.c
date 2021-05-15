// ExUuidCreate 
 
int __fastcall ExUuidCreate(int a1)
{
  int v2; // r6
  unsigned int v3; // r4
  int v4; // r0
  unsigned int v5; // r8
  int v6; // r7
  unsigned int v7; // r1
  signed int v8; // r1
  unsigned __int64 v9; // kr08_8
  int v11; // r0
  unsigned int v12; // r2
  unsigned int v13; // r1
  int v14; // r0
  int v15; // r3
  unsigned int v16; // r1
  int v17; // r0
  int v18; // r3
  int v19; // [sp+0h] [bp-20h]

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  while ( 1 )
  {
    do
    {
      v5 = unk_9203C4;
      v4 = ExpUuidCachedValues[0];
      *(_DWORD *)(a1 + 8) = dword_9203CC;
      v19 = v4;
      *(_DWORD *)(a1 + 12) = unk_9203D0;
      v6 = (unsigned __int8)ExpUuidCacheValid;
      __dmb(0xBu);
      do
      {
        v7 = __ldrex(&dword_9203C8);
        v8 = v7 - 1;
      }
      while ( __strex(v8, &dword_9203C8) );
      __dmb(0xBu);
    }
    while ( v4 != ExpUuidCachedValues[0] || v5 != unk_9203C4 );
    if ( v8 >= 0 )
    {
      v9 = __PAIR64__(v5, v4) - v8;
      *(_DWORD *)a1 = v9;
      *(_WORD *)(a1 + 6) = HIWORD(v9) & 0xFFF | 0x1000;
      *(_WORD *)(a1 + 4) = WORD2(v9);
      if ( !v6 )
        v2 = 1073872982;
      return v2;
    }
    --*(_WORD *)(v3 + 308);
    v11 = KeAbPreAcquire((unsigned int)&ExpUuidLock, 0, 0);
    do
      v12 = __ldrex((unsigned __int8 *)&ExpUuidLock);
    while ( __strex(v12 | 1, (unsigned __int8 *)&ExpUuidLock) );
    __dmb(0xBu);
    if ( (v12 & 1) != 0 )
      break;
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    if ( __PAIR64__(v5, v19) == *(_QWORD *)ExpUuidCachedValues )
    {
      v2 = ExpUuidGetValues(ExpUuidCachedValues);
      if ( v2 )
      {
        __dmb(0xBu);
        do
          v16 = __ldrex((unsigned int *)&ExpUuidLock);
        while ( __strex(v16 - 1, (unsigned int *)&ExpUuidLock) );
        if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)&ExpUuidLock);
        v17 = KeAbPostRelease((unsigned int)&ExpUuidLock);
        v18 = (__int16)(*(_WORD *)(v3 + 308) + 1);
        *(_WORD *)(v3 + 308) = v18;
        if ( !v18 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
          KiCheckForKernelApcDelivery(v17);
        return v2;
      }
      ExpUuidSaveSequenceNumberIf();
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)&ExpUuidLock);
      while ( __strex(v13 - 1, (unsigned int *)&ExpUuidLock) );
    }
    else
    {
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)&ExpUuidLock);
      while ( __strex(v13 - 1, (unsigned int *)&ExpUuidLock) );
    }
    if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&ExpUuidLock);
    v14 = KeAbPostRelease((unsigned int)&ExpUuidLock);
    v15 = (__int16)(*(_WORD *)(v3 + 308) + 1);
    *(_WORD *)(v3 + 308) = v15;
    if ( !v15 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
      KiCheckForKernelApcDelivery(v14);
  }
  return sub_7D1394(v11);
}
