// SmKmKeyGenGenerate 
 
int __fastcall SmKmKeyGenGenerate(unsigned int *a1, int a2, int a3, unsigned int a4)
{
  unsigned int v8; // r5
  int v9; // r0
  int v10; // r7
  unsigned int v11; // r5
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v18; // r4
  unsigned int v19; // r2
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r1
  __int16 v26; // r3

  while ( 1 )
  {
    while ( 1 )
    {
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v8 + 308);
      v9 = KeAbPreAcquire((unsigned int)a1, 0, 0);
      v10 = v9;
      do
        v11 = __ldrex(a1);
      while ( !v11 && __strex(0x11u, a1) );
      __dmb(0xBu);
      if ( v11 )
        ExfAcquirePushLockSharedEx(a1, v9, (unsigned int)a1);
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      v12 = SmKmKeyGenKeyFind(a1, a2);
      v13 = v12;
      if ( v12 )
        break;
      __dmb(0xBu);
      do
        v14 = __ldrex(a1);
      while ( v14 == 17 && __strex(0, a1) );
      if ( v14 != 17 )
        ExfReleasePushLockShared(a1);
      v15 = KeAbPostRelease((unsigned int)a1);
      v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v17 = *(_WORD *)(v16 + 0x134) + 1;
      *(_WORD *)(v16 + 308) = v17;
      if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
        KiCheckForKernelApcDelivery(v15);
      v18 = SmKmKeyGenNewKey(a1, a2, a4);
      if ( v18 < 0 )
        return v18;
    }
    if ( *(_DWORD *)(v12 + 16) == a4 )
      break;
    __dmb(0xBu);
    do
      v19 = __ldrex(a1);
    while ( v19 == 17 && __strex(0, a1) );
    if ( v19 != 17 )
      ExfReleasePushLockShared(a1);
    v20 = KeAbPostRelease((unsigned int)a1);
    v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v22 = *(_WORD *)(v21 + 0x134) + 1;
    *(_WORD *)(v21 + 308) = v22;
    if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
      KiCheckForKernelApcDelivery(v20);
    SmKmKeyGenKeyDelete(a1, v13);
  }
  memmove(a3, *(_DWORD *)(v12 + 12), a4);
  v18 = 0;
  __dmb(0xBu);
  do
    v23 = __ldrex(a1);
  while ( v23 == 17 && __strex(0, a1) );
  if ( v23 != 17 )
    ExfReleasePushLockShared(a1);
  v24 = KeAbPostRelease((unsigned int)a1);
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v26 = *(_WORD *)(v25 + 0x134) + 1;
  *(_WORD *)(v25 + 308) = v26;
  if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
    KiCheckForKernelApcDelivery(v24);
  return v18;
}
