// SeCaptureSubjectContextEx 
 
int __fastcall SeCaptureSubjectContextEx(_DWORD *a1, _DWORD *a2, int *a3)
{
  int v6; // r7
  int result; // r0
  unsigned int v8; // r8
  unsigned int *v9; // r9
  int v10; // r0
  unsigned int v11; // r2
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r3
  unsigned int v15; // r7
  unsigned int *v16; // r8
  int v17; // r0
  int v18; // r5
  unsigned int v19; // r2
  unsigned int v20; // r5
  unsigned int v21; // r2
  __int16 v22; // r3

  a3[3] = a2[44];
  if ( a1 )
  {
    if ( (a1[240] & 8) != 0 )
    {
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v8 + 0x134);
      v9 = a1 + 236;
      v10 = KeAbPreAcquire((unsigned int)(a1 + 236), 0, 0);
      do
        v11 = __ldrex(v9);
      while ( !v11 && __strex(0x11u, v9) );
      __dmb(0xBu);
      if ( v11 )
        return sub_7C5590(v10, 17);
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      if ( (a1[240] & 8) != 0 )
      {
        v6 = a1[226] & 0xFFFFFFF8;
        ObfReferenceObject(v6);
        a3[1] = a1[226] & 3;
      }
      else
      {
        v6 = 0;
      }
      __dmb(0xBu);
      do
        v12 = __ldrex(v9);
      while ( v12 == 17 && __strex(0, v9) );
      if ( v12 != 17 )
        ExfReleasePushLockShared(a1 + 236);
      v13 = KeAbPostRelease((unsigned int)(a1 + 236));
      v14 = (__int16)(*(_WORD *)(v8 + 308) + 1);
      *(_WORD *)(v8 + 308) = v14;
      if ( !v14 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
        KiCheckForKernelApcDelivery(v13);
    }
    else
    {
      v6 = 0;
    }
    *a3 = v6;
  }
  else
  {
    *a3 = 0;
  }
  result = ObFastReferenceObject(a2 + 61);
  if ( result )
  {
    a3[2] = result;
  }
  else
  {
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v15 + 308);
    v16 = a2 + 42;
    v17 = KeAbPreAcquire((unsigned int)(a2 + 42), 0, 0);
    v18 = v17;
    do
      v19 = __ldrex(v16);
    while ( !v19 && __strex(0x11u, v16) );
    __dmb(0xBu);
    if ( v19 )
      ExfAcquirePushLockSharedEx(a2 + 42, v17, (unsigned int)(a2 + 42));
    if ( v18 )
      *(_BYTE *)(v18 + 14) |= 1u;
    v20 = ObFastReferenceObjectLocked(a2 + 61);
    __dmb(0xBu);
    do
      v21 = __ldrex(v16);
    while ( v21 == 17 && __strex(0, v16) );
    if ( v21 != 17 )
      ExfReleasePushLockShared(a2 + 42);
    result = KeAbPostRelease((unsigned int)(a2 + 42));
    v22 = *(_WORD *)(v15 + 308) + 1;
    *(_WORD *)(v15 + 308) = v22;
    if ( !v22 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      result = KiCheckForKernelApcDelivery(result);
    a3[2] = v20;
  }
  return result;
}
