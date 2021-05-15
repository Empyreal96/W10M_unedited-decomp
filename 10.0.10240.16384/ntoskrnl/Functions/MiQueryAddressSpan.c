// MiQueryAddressSpan 
 
int __fastcall MiQueryAddressSpan(int a1, int a2, int a3)
{
  int v6; // r4
  int v7; // r7
  unsigned int *v8; // r10
  int v9; // r8
  int result; // r0
  int v11; // r0
  unsigned int v12; // r1
  int v13; // r0
  int v14; // r7
  int v15; // r3
  unsigned int v16; // r5
  int v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r2
  unsigned int *v20; // r2
  unsigned int v21; // r1
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  unsigned int *v25; // [sp+10h] [bp-30h]
  unsigned int v26; // [sp+14h] [bp-2Ch] BYREF
  int v27; // [sp+18h] [bp-28h] BYREF
  int v28; // [sp+1Ch] [bp-24h] BYREF
  int v29; // [sp+20h] [bp-20h]

  v27 = 0;
  v6 = 0;
  v7 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v8 = (unsigned int *)(v7 + 492);
  v29 = v7;
  v25 = (unsigned int *)(v7 + 492);
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_537374();
  v11 = *v8 & 0x7FFFFFFF;
  do
    v12 = __ldrex(v8);
  while ( v12 == v11 && __strex(v11 + 1, v8) );
  __dmb(0xBu);
  if ( v12 != v11 )
    ExpWaitForSpinLockSharedAndAcquire((unsigned int *)(v7 + 492));
  v13 = MiQueryAddressState(a2, v9, a3, v7, &v27, &v28, &v26);
  v14 = v28;
  *(_DWORD *)(a1 + 16) = v13;
  if ( v14 )
    v15 = MmProtectToValue[v14];
  else
    v15 = 0;
  v16 = v26;
  *(_DWORD *)(a1 + 20) = v15;
  if ( v16 >> 12 > *(_DWORD *)(a3 + 16) )
  {
LABEL_17:
    v17 = 1;
    goto LABEL_19;
  }
  while ( MiQueryAddressState(v16, v9, a3, v29, &v27, &v28, &v26) == *(_DWORD *)(a1 + 16) && v28 == v14 )
  {
    ++v6;
    v16 = v26;
    if ( (v6 & 0x1F) == 0 && ExSpinLockIsContended(v25) )
      goto LABEL_31;
    if ( KeShouldYieldProcessor() )
    {
      v20 = v25;
LABEL_31:
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v20);
      }
      else
      {
        __dmb(0xBu);
        do
          v21 = __ldrex(v25);
        while ( __strex(v21 & 0xBFFFFFFF, v25) );
        __dmb(0xBu);
        do
          v22 = __ldrex(v25);
        while ( __strex(v22 - 1, v25) );
      }
      KfLowerIrql(v9);
      v9 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v25);
      }
      else
      {
        v23 = *v25 & 0x7FFFFFFF;
        do
          v24 = __ldrex(v25);
        while ( v24 == v23 && __strex(v23 + 1, v25) );
        __dmb(0xBu);
        if ( v24 != v23 )
          ExpWaitForSpinLockSharedAndAcquire(v25);
      }
    }
    if ( v16 >> 12 > *(_DWORD *)(a3 + 16) )
    {
      v8 = v25;
      goto LABEL_17;
    }
  }
  v8 = v25;
  v17 = 0;
LABEL_19:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v8);
  }
  else
  {
    __dmb(0xBu);
    do
      v18 = __ldrex(v8);
    while ( __strex(v18 & 0xBFFFFFFF, v8) );
    __dmb(0xBu);
    do
      v19 = __ldrex(v8);
    while ( __strex(v19 - 1, v8) );
  }
  KfLowerIrql(v9);
  if ( v17 == 1 )
    result = (*(_DWORD *)(a3 + 16) + 1) << 12;
  else
    result = v16;
  return result;
}
