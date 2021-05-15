// MiPerformMemoryChange 
 
int __fastcall MiPerformMemoryChange(unsigned int a1, unsigned int a2, int *a3, int *a4, char a5)
{
  unsigned int v9; // r1
  int v10; // r5
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r2
  unsigned int v15; // r3
  _BYTE *v16; // r0
  int v17; // r3
  unsigned int v18; // r0
  int v20; // [sp+4h] [bp-24h]

  v20 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54E618();
  do
    v9 = __ldrex((unsigned __int8 *)&dword_63F7A8 + 3);
  while ( __strex(v9 | 0x80, (unsigned __int8 *)&dword_63F7A8 + 3) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_63F7A8);
  while ( 1 )
  {
    v10 = dword_63F7A8;
    if ( (dword_63F7A8 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_63F7A8 & 0x40000000) == 0 )
    {
      do
        v18 = __ldrex((unsigned int *)&dword_63F7A8);
      while ( v18 == v10 && __strex(v10 | 0x40000000, (unsigned int *)&dword_63F7A8) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v11 = *(_DWORD *)(MmPhysicalMemoryBlock - 4) - 1;
  *(_DWORD *)(MmPhysicalMemoryBlock - 4) = v11;
  v12 = *a3;
  if ( v11 )
    *a3 = 0;
  else
    *a3 = MmPhysicalMemoryBlock;
  MmPhysicalMemoryBlock = v12;
  v13 = *(_DWORD *)(dword_63F720 - 4) - 1;
  *(_DWORD *)(dword_63F720 - 4) = v13;
  v14 = *a4;
  if ( v13 )
    *a4 = 0;
  else
    *a4 = dword_63F720;
  dword_63F720 = v14;
  v15 = a1 + a2;
  if ( (a5 & 1) != 0 )
  {
    if ( v15 - 1 > dword_640504 )
      dword_640504 = v15 - 1;
    v16 = RtlSetBits(&dword_634C98, a1, a2);
    if ( (a5 & 4) != 0 )
      goto LABEL_17;
    v17 = dword_640508 + a2;
  }
  else
  {
    if ( v15 - 1 == dword_640504 )
      dword_640504 = a1 - 1;
    v16 = RtlClearBits(&dword_634C98, a1, a2);
    v17 = dword_640508 - a2;
  }
  dword_640508 = v17;
LABEL_17:
  MiInitializeNonPagedPoolThresholds(v16);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_63F7A8);
  }
  else
  {
    __dmb(0xBu);
    dword_63F7A8 = 0;
  }
  return KfLowerIrql(v20);
}
