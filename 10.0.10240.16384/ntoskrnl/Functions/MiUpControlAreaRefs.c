// MiUpControlAreaRefs 
 
int __fastcall MiUpControlAreaRefs(int a1, unsigned int *a2, unsigned int *a3, unsigned int *a4)
{
  unsigned int *v5; // r5
  int v6; // r3
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r2
  unsigned int *v10; // r4
  int v11; // r8
  int v12; // r4
  unsigned int *v13; // r7
  int v14; // r10
  unsigned int *v15; // r5
  unsigned __int8 *v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r1
  int result; // r0
  unsigned int *v21; // [sp+0h] [bp-28h] BYREF
  unsigned int *var24[11]; // [sp+4h] [bp-24h] BYREF

  v21 = a2;
  var24[0] = a3;
  var24[1] = a4;
  v5 = **(unsigned int ***)(a1 + 44);
  v6 = (unsigned __int8)*(_DWORD *)(a1 + 28) >> 3;
  if ( (v6 == 4 || v6 == 6) && v5[8] && (v5[7] & 0x20) == 0 )
  {
    v7 = v5 + 13;
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 + 1, v7) );
    __dmb(0xBu);
  }
  v9 = v5[7];
  v10 = 0;
  v11 = 0;
  v21 = 0;
  var24[0] = 0;
  if ( (v9 & 0x20) == 0 && v5[8] && (v9 & 0x400) == 0 )
  {
    v12 = *(_DWORD *)(a1 + 12);
    MiLockNestedVad(a1);
    MiGetProtoPteAddress((_DWORD *)a1, v12, 1, &v21);
    v10 = v21;
    if ( v21 )
      v11 = 1;
    else
      MiUnlockNestedVad(a1);
  }
  v13 = v5 + 9;
  v14 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5 + 9);
  }
  else
  {
    v16 = (unsigned __int8 *)v5 + 39;
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 | 0x80, v16) );
    __dmb(0xBu);
    if ( v17 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v5 + 9);
    while ( 1 )
    {
      v18 = *v13;
      if ( (*v13 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v18 & 0x40000000) == 0 )
      {
        do
          v19 = __ldrex(v13);
        while ( v19 == v18 && __strex(v18 | 0x40000000, v13) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  ++v5[5];
  ++v5[6];
  if ( v10 )
  {
    MiGetProtoPteAddress((_DWORD *)a1, *(_DWORD *)(a1 + 16), 3, var24);
    v15 = var24[0];
    while ( v10 != v15 )
    {
      MiReferenceSubsection((int)v10);
      v10 = (unsigned int *)v10[2];
    }
    if ( v15 )
      MiReferenceSubsection((int)v15);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v13, (int)var24[10]);
  }
  else
  {
    __dmb(0xBu);
    *v13 = 0;
  }
  result = KfLowerIrql(v14);
  if ( v11 == 1 )
    result = MiUnlockNestedVad(a1);
  return result;
}
