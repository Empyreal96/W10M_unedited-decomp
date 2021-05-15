// MiSecureVad 
 
int __fastcall MiSecureVad(int a1, int a2, int a3, int a4, int *a5)
{
  unsigned int v5; // r8
  unsigned int v6; // r10
  unsigned int v7; // r9
  unsigned int *v8; // r5
  int v9; // r7
  int result; // r0
  int v11; // r4
  unsigned int v12; // r1
  unsigned int v14; // r4
  unsigned int v15; // r0
  int v16; // r0
  unsigned int v17; // r1
  unsigned int v18; // r2
  int v19; // [sp+10h] [bp-38h] BYREF
  int v20; // [sp+14h] [bp-34h] BYREF
  int v21; // [sp+18h] [bp-30h]
  int v22; // [sp+1Ch] [bp-2Ch]
  int v23; // [sp+20h] [bp-28h]
  unsigned int v24[9]; // [sp+24h] [bp-24h] BYREF

  v5 = a2 & 0xFFFFF000;
  v6 = (a3 + a2 - 1) | 0xFFF;
  v21 = a4;
  v22 = a1;
  v20 = 0;
  v7 = a2 & 0xFFFFF000;
  if ( (a4 & 1) != 0 )
  {
LABEL_23:
    v16 = MiAddSecureEntry(a1, v5, v6, a4, 0);
    *a5 = v16;
    if ( v16 )
      result = 0;
    else
      result = -1073741670;
    return result;
  }
  v23 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v8 = (unsigned int *)(v23 + 492);
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51CCB4();
  v11 = *v8 & 0x7FFFFFFF;
  do
    v12 = __ldrex(v8);
  while ( v12 == v11 && __strex(v11 + 1, v8) );
  __dmb(0xBu);
  if ( v12 != v11 )
    ExpWaitForSpinLockSharedAndAcquire(v8, v12);
  if ( v5 > v6 )
  {
LABEL_17:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v8);
    }
    else
    {
      __dmb(0xBu);
      do
        v14 = __ldrex(v8);
      while ( __strex(v14 & 0xBFFFFFFF, v8) );
      __dmb(0xBu);
      do
        v15 = __ldrex(v8);
      while ( __strex(v15 - 1, v8) );
    }
    KfLowerIrql(v9);
    a4 = v21;
    a1 = v22;
    goto LABEL_23;
  }
  while ( 1 )
  {
    MiQueryAddressState(v7, v9, v22, v23, &v20, &v19, v24);
    if ( !v19 || v19 == -1 || (v19 & 0xFFFFFFF8) == 16 )
      break;
    if ( v21 == 2 ? (v19 & 7) == 0 : (v19 & 4) == 0 )
      break;
    v7 = v24[0];
    if ( v24[0] > v6 )
      goto LABEL_17;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v8);
  }
  else
  {
    __dmb(0xBu);
    do
      v17 = __ldrex(v8);
    while ( __strex(v17 & 0xBFFFFFFF, v8) );
    __dmb(0xBu);
    do
      v18 = __ldrex(v8);
    while ( __strex(v18 - 1, v8) );
  }
  KfLowerIrql(v9);
  return -1073741755;
}
