// SmcCacheAdd 
 
int __fastcall SmcCacheAdd(int a1, int *a2, int *a3)
{
  int v6; // r7
  unsigned int i; // r6
  int **v8; // r5
  unsigned int v9; // r4
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r2
  int v14; // r3
  unsigned int *v15; // r0
  unsigned int v16; // r2
  unsigned int v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r1
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3

  v6 = 0;
  for ( i = a1 + 8; ; i += 16 )
  {
    v8 = (int **)(i - 8);
    if ( !*(_DWORD *)(i - 8) )
    {
      v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v9 + 308);
      v10 = KeAbPreAcquire(i, 0, 0);
      v11 = v10;
      do
        v12 = __ldrex((unsigned __int8 *)i);
      while ( __strex(v12 | 1, (unsigned __int8 *)i) );
      __dmb(0xBu);
      if ( (v12 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)i, v10, i);
      if ( v11 )
        *(_BYTE *)(v11 + 14) |= 1u;
      if ( !*v8 )
      {
        *v8 = a2;
        do
        {
          v13 = *(_DWORD *)(i + 4) & 0xFFFFF000 | ((unsigned __int16)*(_DWORD *)(i + 4) + 1) & 0xFFF;
          *(_DWORD *)(i + 4) = v13;
          v14 = v6 | (16 * (v13 & 0xFFF));
          *a2 = v14;
        }
        while ( v14 == -1 );
        *a3 = v14;
        a2 = 0;
        __dmb(0xBu);
        v15 = (unsigned int *)(i - 4);
        do
          v16 = __ldrex(v15);
        while ( __strex(0, v15) );
        __dmb(0xBu);
        __pld(v15);
        v17 = *v15 & 0xFFFFFFFE;
        do
          v18 = __ldrex(v15);
        while ( v18 == v17 && __strex(v17 + 2, v15) );
        __dmb(0xBu);
        if ( v18 != v17 )
          ExfAcquireRundownProtection(v15);
      }
      __dmb(0xBu);
      do
        v19 = __ldrex((unsigned int *)i);
      while ( __strex(v19 - 1, (unsigned int *)i) );
      if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)i);
      v20 = KeAbPostRelease(i);
      v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v22 = *(_WORD *)(v21 + 0x134) + 1;
      *(_WORD *)(v21 + 308) = v22;
      if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
        KiCheckForKernelApcDelivery(v20);
      if ( !a2 )
        break;
    }
    if ( (unsigned int)++v6 >= 0x10 )
      return -1073741671;
  }
  KeSetEvent(*(_DWORD *)(a1 + 276), 0, 0);
  return 0;
}
