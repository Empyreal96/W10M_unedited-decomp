// PspJobClose 
 
void __fastcall PspJobClose(int a1, _DWORD *a2, int a3, unsigned int a4)
{
  unsigned int v5; // r5
  unsigned int *v6; // r2
  unsigned int v7; // r4
  int v8; // r3
  unsigned __int8 *v9; // r7
  int v10; // r0
  unsigned int v11; // r2
  int v12; // r4
  unsigned int v13; // r1
  int v14; // r0
  __int16 v15; // r3
  int v16; // r0
  __int16 v17; // r3
  int v18; // r2
  int v19; // r3

  if ( a4 <= 1 )
  {
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    __dmb(0xBu);
    v6 = a2 + 186;
    do
    {
      v7 = __ldrex(v6);
      v8 = __strex(v7 | 1, v6);
    }
    while ( v8 );
    __dmb(0xBu);
    if ( v5 )
    {
      v8 = *(__int16 *)(v5 + 310) - 1;
      *(_WORD *)(v5 + 310) = v8;
    }
    ExAcquireResourceExclusiveLite((int)(a2 + 8), 1, (int)v6, v8);
    if ( (a2[44] & 0x2000) != 0 )
    {
      v16 = ExReleaseResourceLite((int)(a2 + 8));
      if ( v5 )
      {
        v17 = *(_WORD *)(v5 + 310) + 1;
        *(_WORD *)(v5 + 310) = v17;
        if ( !v17 && *(_DWORD *)(v5 + 100) != v5 + 100 )
          KiCheckForKernelApcDelivery(v16);
      }
      PspTerminateAllProcessesInJobHierarchy(a2, 0, 0);
      if ( v5 )
      {
        v19 = *(__int16 *)(v5 + 310) - 1;
        *(_WORD *)(v5 + 310) = v19;
      }
      ExAcquireResourceExclusiveLite((int)(a2 + 8), 1, v18, v19);
    }
    v9 = (unsigned __int8 *)(a2 + 138);
    v10 = KeAbPreAcquire((unsigned int)(a2 + 138), 0, 0);
    do
      v11 = __ldrex(v9);
    while ( __strex(v11 | 1, v9) );
    __dmb(0xBu);
    if ( (v11 & 1) != 0 )
    {
      sub_7C01B4(v10);
    }
    else
    {
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      v12 = a2[53];
      a2[53] = 0;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)v9);
      while ( __strex(v13 - 1, (unsigned int *)v9) );
      if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
        ExfTryToWakePushLock(a2 + 138);
      KeAbPostRelease((unsigned int)(a2 + 138));
      v14 = ExReleaseResourceLite((int)(a2 + 8));
      if ( v5 )
      {
        v15 = *(_WORD *)(v5 + 310) + 1;
        *(_WORD *)(v5 + 310) = v15;
        if ( !v15 && *(_DWORD *)(v5 + 100) != v5 + 100 )
          KiCheckForKernelApcDelivery(v14);
      }
      if ( v12 )
        ObfDereferenceObject(v12);
    }
  }
}
