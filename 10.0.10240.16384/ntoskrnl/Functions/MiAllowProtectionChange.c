// MiAllowProtectionChange 
 
int __fastcall MiAllowProtectionChange(int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6)
{
  int v6; // r5
  unsigned int *v9; // r4
  int v10; // r5
  int v11; // lr
  int v13; // r0
  unsigned int v14; // r1
  unsigned int v15; // r0
  char v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r2
  int v19; // [sp+10h] [bp-38h]
  int v20; // [sp+14h] [bp-34h] BYREF
  int v21; // [sp+18h] [bp-30h] BYREF
  int v22; // [sp+1Ch] [bp-2Ch]
  int v23; // [sp+20h] [bp-28h]
  unsigned int v24[9]; // [sp+24h] [bp-24h] BYREF

  v6 = *(_DWORD *)(a3 + 28);
  v23 = a4;
  v22 = a1;
  if ( (v6 & 0xC0) == 192 && (v6 & 0x38) != 0 )
    return -1073741755;
  v9 = (unsigned int *)(a1 + 492);
  v21 = 0;
  v10 = 0;
  v11 = KfRaiseIrql(2);
  v19 = v11;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51D29C();
  v13 = *v9 & 0x7FFFFFFF;
  do
    v14 = __ldrex(v9);
  while ( v14 == v13 && __strex(v13 + 1, v9) );
  __dmb(0xBu);
  if ( v14 != v13 )
    ExpWaitForSpinLockSharedAndAcquire(v9, v14);
  v15 = a5;
  if ( a5 <= a6 )
  {
    while ( 1 )
    {
      MiQueryAddressState(v15, v11, a3, v22, &v21, &v20, v24);
      v16 = v20;
      if ( v20 == -1 )
      {
        v16 = 0;
        v20 = 0;
      }
      if ( (v16 & 2) == 0 || (v23 & 4) != 0 )
        break;
      v15 = v24[0];
      v11 = v19;
      if ( v24[0] > a6 )
        goto LABEL_15;
    }
    v10 = MiArbitraryCodeBlocked(a2);
  }
LABEL_15:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v9);
  }
  else
  {
    __dmb(0xBu);
    do
      v17 = __ldrex(v9);
    while ( __strex(v17 & 0xBFFFFFFF, v9) );
    __dmb(0xBu);
    do
      v18 = __ldrex(v9);
    while ( __strex(v18 - 1, v9) );
  }
  KfLowerIrql(v19);
  return v10;
}
