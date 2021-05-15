// MiUpdateLastSubsectionSize 
 
int __fastcall MiUpdateLastSubsectionSize(int a1, __int64 *a2, unsigned int a3)
{
  _DWORD *v4; // r0
  int v7; // lr
  unsigned __int64 *v8; // r7
  unsigned __int64 v9; // kr08_8
  unsigned __int64 v10; // kr18_8
  __int16 v11; // r1
  unsigned __int64 v12; // kr20_8
  unsigned int *v13; // r4
  int v14; // r7
  unsigned __int8 *v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r1

  v4 = *(_DWORD **)a1;
  if ( a3 )
  {
    v7 = *v4;
    __dmb(0xBu);
    v8 = (unsigned __int64 *)(v7 + 16);
    do
      v9 = __ldrexd(v8);
    while ( v9 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v8) );
    __dmb(0xBu);
    do
      v10 = __ldrexd(v8);
    while ( __strexd(v9 + __PAIR64__(a3 >> 20, a3 << 12), v8) );
    __dmb(0xBu);
    v11 = *(_WORD *)(v7 + 8);
    v12 = __PAIR64__(v11 & 0x3FF, *(_DWORD *)(v7 + 4)) + a3;
    *(_DWORD *)(v7 + 4) = v12;
    *(_WORD *)(v7 + 8) = (WORD2(v12) ^ v11) & 0x3FF ^ v11;
  }
  v13 = v4 + 9;
  v14 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51AFEC();
  v16 = (unsigned __int8 *)v13 + 3;
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 | 0x80, v16) );
  __dmb(0xBu);
  if ( v17 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v13);
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
  if ( a3 )
  {
    *(_DWORD *)(a1 + 36) -= a3;
    *(_DWORD *)(a1 + 28) += a3;
  }
  *(_DWORD *)(a1 + 24) = (*a2 >> 12) - *(_DWORD *)(a1 + 20);
  *(_WORD *)(a1 + 18) = *(_WORD *)(a1 + 18) & 0xF | (16 * *(_WORD *)a2);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v13);
  }
  else
  {
    __dmb(0xBu);
    *v13 = 0;
  }
  return KfLowerIrql(v14);
}
