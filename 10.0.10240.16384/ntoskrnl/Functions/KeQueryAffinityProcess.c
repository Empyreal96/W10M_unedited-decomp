// KeQueryAffinityProcess 
 
int __fastcall KeQueryAffinityProcess(int a1, _DWORD *a2, int *a3, _WORD *a4)
{
  int v7; // r9
  unsigned int *v8; // r5
  int result; // r0
  int v10; // r0
  unsigned int v11; // r1
  int v12; // r2
  int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r2

  v7 = KfRaiseIrql(2);
  v8 = (unsigned int *)(a1 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51738C();
  v10 = *v8 & 0x7FFFFFFF;
  do
    v11 = __ldrex(v8);
  while ( v11 == v10 && __strex(v10 + 1, v8) );
  __dmb(0xBu);
  if ( v11 != v10 )
    ExpWaitForSpinLockSharedAndAcquire(a1 + 48, v11);
  v12 = *(_DWORD *)(a1 + 68);
  v13 = *(_DWORD *)(a1 + 72);
  *a2 = *(_DWORD *)(a1 + 64);
  a2[1] = v12;
  a2[2] = v13;
  v14 = *(_DWORD *)(a1 + 100);
  if ( a4 )
    *a4 = *(_WORD *)(a1 + 112);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(a1 + 48);
  }
  else
  {
    __dmb(0xBu);
    do
      v15 = __ldrex(v8);
    while ( __strex(v15 & 0xBFFFFFFF, v8) );
    __dmb(0xBu);
    do
      v16 = __ldrex(v8);
    while ( __strex(v16 - 1, v8) );
  }
  result = KfLowerIrql(v7);
  if ( a3 )
    *a3 = (v14 >> 8) & 1;
  return result;
}
