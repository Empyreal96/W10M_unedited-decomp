// KiConnectSecondaryInterrupt 
 
int __fastcall KiConnectSecondaryInterrupt(int a1)
{
  unsigned int v3; // r1
  int v4; // r0
  int v5; // r7
  int v6; // r9
  int v7; // r5
  int v8; // r3
  int v9; // r10
  unsigned int v10; // r2
  int v11; // r6
  int v12; // r0
  unsigned int v13; // r1
  int v14; // r3

  if ( !KiSecondaryInterruptServicesEnabled )
    return sub_553774();
  v3 = *(unsigned __int8 *)(a1 + 48);
  v4 = *(_DWORD *)(a1 + 44);
  v5 = 0;
  v6 = 0;
  if ( (unsigned int)(v4 - 4096) > 0xFF
    || v3 > 0xC
    || *(_DWORD *)(a1 + 52) >= (unsigned int)KeNumberProcessors_0
    || *(unsigned __int8 *)(a1 + 49) < v3 && *(_BYTE *)(a1 + 49) )
  {
    return -1073741585;
  }
  v7 = KiGlobalSecondaryIDT + 28 * (v4 - 4096);
  v8 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v8 & 0xFFFFFFC0) + 0x134);
  KeWaitForSingleObject(v7 + 4, 0, 0, 0, 0);
  v9 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v7);
  }
  else
  {
    do
      v10 = __ldrex((unsigned int *)v7);
    while ( __strex(1u, (unsigned int *)v7) );
    __dmb(0xBu);
    if ( v10 )
      KxWaitForSpinLockAndAcquire((unsigned int *)v7);
  }
  if ( !*(_BYTE *)(a1 + 51) )
  {
    v11 = *(_DWORD *)(v7 + 24);
    if ( v11 )
    {
      if ( *(_BYTE *)(a1 + 56) )
      {
        if ( *(_BYTE *)(v11 + 56) )
        {
          if ( *(_DWORD *)(v11 + 64) == *(_DWORD *)(a1 + 64) )
          {
            v5 = 1;
            v6 = 1;
            KiInsertInterruptObjectOrdered(*(_DWORD *)(v7 + 24), a1);
            if ( !*(_BYTE *)(v11 + 49) )
            {
              if ( *(_BYTE *)(a1 + 49) )
                *(_DWORD *)(v7 + 24) = a1;
            }
          }
        }
      }
    }
    else
    {
      *(_DWORD *)(a1 + 4) = a1 + 4;
      *(_DWORD *)(a1 + 8) = a1 + 4;
      *(_DWORD *)(v7 + 24) = a1;
      *(_BYTE *)(v7 + 20) = 0;
      v5 = 1;
    }
    *(_BYTE *)(a1 + 51) = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v7);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v7 = 0;
  }
  KfLowerIrql(v9);
  v12 = KeSetEvent(v7 + 4, 0, 0);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = (__int16)(*(_WORD *)(v13 + 0x134) + 1);
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  if ( !v5 )
    return -1073741585;
  if ( v6 )
    return 295;
  return 0;
}
