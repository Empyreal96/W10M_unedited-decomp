// MmQueryWorkingSetInformation 
 
int __fastcall MmQueryWorkingSetInformation(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  int v8; // r5
  int v9; // r8
  int v11; // r0
  unsigned int v12; // r1
  unsigned int v13; // r1
  unsigned int v14; // r2

  *a6 = 0;
  v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492;
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5173A4();
  v11 = *(_DWORD *)v8 & 0x7FFFFFFF;
  do
    v12 = __ldrex((unsigned int *)v8);
  while ( v12 == v11 && __strex(v11 + 1, (unsigned int *)v8) );
  __dmb(0xBu);
  if ( v12 != v11 )
    ExpWaitForSpinLockSharedAndAcquire(v8, v12);
  *a1 = *(_DWORD *)(v8 + 84) << 12;
  *a2 = *(_DWORD *)(v8 + 52) << 12;
  *a3 = *(_DWORD *)(v8 + 56) << 12;
  *a4 = *(_DWORD *)(v8 + 48) << 12;
  *a5 = *(_DWORD *)(v8 + 68) << 12;
  if ( (*(_BYTE *)(v8 + 112) & 0x80) == 128 )
    *a6 |= 4u;
  if ( (*(_BYTE *)(v8 + 112) & 0x40) != 0 )
    *a6 |= 1u;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v8);
  }
  else
  {
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)v8);
    while ( __strex(v13 & 0xBFFFFFFF, (unsigned int *)v8) );
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)v8);
    while ( __strex(v14 - 1, (unsigned int *)v8) );
  }
  KfLowerIrql(v9);
  return 0;
}
