// PopFxReleasePowerIrp 
 
int __fastcall PopFxReleasePowerIrp(_DWORD *a1)
{
  unsigned int *v2; // r5
  int result; // r0
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r0
  unsigned int *v7; // r0
  unsigned int v8; // r1
  int v9; // r5
  int v10; // r6
  int v11; // r7
  int v12; // r8
  unsigned int v13; // r1
  int v14; // r9
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int v17; // r1
  int v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r1
  int v21; // [sp+10h] [bp-20h]

  v2 = (unsigned int *)(a1[7] + 44);
  v21 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54AF24();
  v4 = (unsigned __int8 *)v2 + 3;
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v2);
  while ( 1 )
  {
    v6 = *v2;
    if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v6 & 0x40000000) == 0 )
    {
      do
        v19 = __ldrex(v2);
      while ( v19 == v6 && __strex(v6 | 0x40000000, v2) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  __dmb(0xBu);
  v7 = a1 + 4;
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 & 0xFFFFFFEF, v7) );
  __dmb(0xBu);
  v9 = a1[72];
  v10 = a1[76];
  v11 = a1[78];
  v12 = a1[74];
  __dmb(0xBu);
  do
    v13 = __ldrex(v7);
  while ( __strex(v13, v7) );
  __dmb(0xBu);
  if ( (v13 & 0x20) != 0 )
  {
    v14 = 1;
    __dmb(0xBu);
    do
      v20 = __ldrex(v7);
    while ( __strex(v20, v7) );
    __dmb(0xBu);
    if ( (v20 & 0x100) != 0 )
    {
      v9 = a1[73];
      v10 = a1[77];
      v11 = a1[79];
      v12 = a1[75];
    }
  }
  else
  {
    v14 = 0;
    KeSetEvent((int)(a1 + 80), 0, 0);
    __dmb(0xBu);
    v15 = a1 + 28;
    do
    {
      v16 = __ldrex(v15);
      v17 = v16 - 1;
    }
    while ( __strex(v17, v15) );
    __dmb(0xBu);
    if ( !v17 )
      KeSetEvent((int)(a1 + 29), 0, 0);
  }
  v18 = a1[7];
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v18 + 44);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)(v18 + 44) = 0;
  }
  result = KfLowerIrql(v21);
  if ( v14 )
    result = PopRequestPowerIrp(v9, 2, v12, v10, v11, 1u, 0);
  return result;
}
