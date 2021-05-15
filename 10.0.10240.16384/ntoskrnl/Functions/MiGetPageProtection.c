// MiGetPageProtection 
 
int __fastcall MiGetPageProtection(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v5; // r4
  unsigned int *v8; // r6
  unsigned int v9; // r2
  int v10; // r4
  int v12; // r5
  int v13; // r2
  unsigned int *v14; // r4
  unsigned int *v15; // r5
  unsigned int v16; // r1
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  unsigned int v20; // r0
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r1

  v5 = *(_DWORD *)a2;
  if ( (*(_DWORD *)a2 & 2) == 0 )
  {
    if ( (v5 & 0x400) == 0 || (v5 & 0xFFFFE000) == -8192 )
      return (v5 >> 5) & 0x1F;
    v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v13 = (v5 >> 2) & 0x3FFFFE00 | v5 & 0x1FC;
    v14 = (unsigned int *)(v13 - 0x40000000);
    if ( v13 - 0x40000000 >= (unsigned int)dword_640484 && (unsigned int)v14 < dword_640488
      || *(_DWORD *)(v12 + 272) && MiLocateCloneAddress(v12, v13 - 0x40000000) )
    {
      return MmMakeProtectNotWriteCopy[MiCaptureProtectionFromLockedProto(v14)];
    }
    v15 = (unsigned int *)(v12 + 492);
    if ( a4 == 1 )
    {
      MiUnlockWorkingSetExclusive(v15, a3);
    }
    else
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v15);
      }
      else
      {
        __dmb(0xBu);
        do
          v16 = __ldrex(v15);
        while ( __strex(v16 & 0xBFFFFFFF, v15) );
        __dmb(0xBu);
        do
          v17 = __ldrex(v15);
        while ( __strex(v17 - 1, v15) );
      }
      KfLowerIrql(a3);
    }
    v10 = MiCaptureProtectionFromProto(v14);
    if ( a4 == 1 )
    {
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v15);
      }
      else
      {
        v21 = (unsigned __int8 *)v15 + 3;
        do
          v22 = __ldrex(v21);
        while ( __strex(v22 | 0x80, v21) );
        __dmb(0xBu);
        if ( v22 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v15);
        while ( 1 )
        {
          v23 = *v15;
          if ( (*v15 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v23 & 0x40000000) == 0 )
          {
            do
              v24 = __ldrex(v15);
            while ( v24 == v23 && __strex(v23 | 0x40000000, v15) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
    }
    else
    {
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v15);
      }
      else
      {
        v18 = *v15 & 0x7FFFFFFF;
        do
          v19 = __ldrex(v15);
        while ( v19 == v18 && __strex(v18 + 1, v15) );
        __dmb(0xBu);
        if ( v19 != v18 )
        {
          ExpWaitForSpinLockSharedAndAcquire(v15);
          return v10;
        }
      }
    }
    return v10;
  }
  v8 = (unsigned int *)(MmPfnDatabase + 24 * (v5 >> 12));
  if ( (*(_DWORD *)(a1 + 28) & 7) != 6 || !MiRotatedToFrameBuffer(a2) )
  {
    if ( !MI_IS_PFN(v5 >> 12) )
      goto LABEL_46;
    v9 = v8[5];
    if ( ((v9 >> 27) & 1) != 0 )
    {
      v20 = MiLocateWsle(a2 << 10, *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492, *v8);
      return MiGetPfnProtection((int)v8, (_DWORD *)(MEMORY[0xC0402024] * v20 - 1069537344));
    }
    if ( (v8[1] | 0x80000000) != a2 )
LABEL_46:
      KeBugCheckEx(26, 266753, a2);
    if ( (v9 & 0x7000000) != 0x1000000 )
      return (v8[2] >> 5) & 0x1F;
    if ( (v5 & 0x20) == 0 )
      return 24;
    if ( (v5 & 0x80) != 0 )
      return 4;
    return 1;
  }
  return sub_5379C8();
}
