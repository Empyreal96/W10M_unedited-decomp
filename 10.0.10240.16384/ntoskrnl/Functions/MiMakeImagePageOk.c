// MiMakeImagePageOk 
 
int MiMakeImagePageOk(unsigned int a1, int a2, ...)
{
  unsigned int v2; // r6
  unsigned int *v3; // r9
  int v4; // r4
  int *v5; // r5
  int v6; // r4
  unsigned __int64 *v7; // r3
  unsigned __int64 v8; // kr00_8
  unsigned int *v9; // r0
  unsigned int v10; // r1
  int v11; // r7
  int v12; // r0
  int v13; // r1
  int v14; // r5
  int v15; // r6
  int v16; // r0
  int v17; // r1
  unsigned __int8 *v18; // r3
  unsigned int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r1
  unsigned __int8 *v22; // r1
  unsigned int v23; // r2
  int v24; // r3
  int v25; // r3
  int v28; // [sp+14h] [bp-24h]
  int varg_r2; // [sp+48h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+48h] [bp+10h]
  unsigned int *varg_r3; // [sp+4Ch] [bp+14h]
  int v33; // [sp+50h] [bp+18h]
  int v34; // [sp+54h] [bp+1Ch]
  va_list va1; // [sp+58h] [bp+20h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, unsigned int *);
  v33 = va_arg(va1, _DWORD);
  v34 = va_arg(va1, _DWORD);
  v2 = a2;
  v3 = varg_r3;
  if ( (*(_DWORD *)(v33 + 12) & 0x40000000) != 0 )
    return -1073740748;
  v5 = (int *)(*(_DWORD *)(v33 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v33 + 8) & 0x3FC)));
  v6 = *v5;
  v28 = *v5;
  if ( (MiFlags & 0x80000) == 0
    || (*(_DWORD *)(v6 + 52) & 0xC000000) == 0
    || (*(_WORD *)((*(_DWORD *)(v33 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v33 + 8) & 0x3FC))) + 0x12) & 2) != 0
    && (*(_DWORD *)(v6 + 28) & 0x4000000) != 0 )
  {
    return -1073740760;
  }
  if ( (*(_BYTE *)(v33 + 18) & 7) == 2 && !*(_WORD *)(v33 + 16) )
  {
    MiUnlinkPageFromList(v33, 0);
    *(_DWORD *)(v33 + 12) &= 0xC0000000;
  }
  MiAddLockedPageCharge(v33, 1);
  v7 = (unsigned __int64 *)(v6 + 64);
  do
    v8 = __ldrexd(v7);
  while ( __strexd(v8 + 1, v7) );
  __dmb(0xBu);
  v9 = (unsigned int *)(v33 + 12);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 & 0x7FFFFFFF, v9) );
  MiObtainProtoReference(v34, 0);
  MiUnlockProtoPoolPage(v34, 17);
  if ( v3 )
    MiUnlockWorkingSetExclusive((int)v3, 1);
  else
    KfLowerIrql(1);
  v11 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  MiGetSessionIdForVa(a1);
  v12 = MiStartingOffset(v5, v2);
  v14 = v13;
  v15 = v12;
  v16 = MiComputeImagePteIndex(v33);
  v4 = MiValidateImagePfn(v28, v17, v15, v14, v11, v16);
  MiDereferenceControlAreaProbe(v28);
  if ( v3 )
  {
    KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v3);
    }
    else
    {
      v18 = (unsigned __int8 *)v3 + 3;
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 | 0x80, v18) );
      __dmb(0xBu);
      if ( v19 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v3);
      while ( 1 )
      {
        v20 = *v3;
        if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v20 & 0x40000000) == 0 )
        {
          do
            v21 = __ldrex(v3);
          while ( v21 == v20 && __strex(v20 | 0x40000000, v3) );
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
  }
  MiRelockProtoPoolPage(v34, 0);
  MiReturnPfnReferenceCount(v34);
  v22 = (unsigned __int8 *)(v33 + 15);
  do
    v23 = __ldrex(v22);
  while ( __strex(v23 | 0x80, v22) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v23 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v24 = *(_DWORD *)(v33 + 12);
      __dmb(0xBu);
    }
    while ( (v24 & 0x80000000) != 0 );
    do
      v23 = __ldrex(v22);
    while ( __strex(v23 | 0x80, v22) );
  }
  if ( v4 >= 0 )
  {
    v25 = *(_DWORD *)(v33 + 12);
    if ( (v25 & 0x40000000) != 0 || !MiIsFaultPteIntact(a1, a2, (int *)varg_r2a, v25) )
      v4 = -1073740748;
  }
  MiRemoveLockedPageChargeAndDecRef(v33);
  return v4;
}
