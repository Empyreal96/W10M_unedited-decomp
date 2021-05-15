// KeFreezeProcess 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeFreezeProcess(int a1, int a2)
{
  int v4; // r9
  unsigned int v5; // r10
  unsigned int *v6; // r4
  int result; // r0
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r9 OVERLAPPED
  unsigned int v14; // r10 OVERLAPPED
  unsigned int v15; // r2
  unsigned int v16; // r8
  unsigned __int8 *v17; // r3
  unsigned int v18; // r2
  _DWORD *i; // r5
  _DWORD *v20; // r6
  _DWORD *v21; // t1
  unsigned int v22; // r1
  int v23; // [sp+8h] [bp-28h]
  unsigned int v24; // [sp+Ch] [bp-24h]

  __mrc(15, 0, 13, 0, 3);
  v4 = KfRaiseIrql(2);
  v23 = v4;
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v24 = v5;
  v6 = (unsigned int *)(a1 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_521684();
  v8 = (unsigned __int8 *)(a1 + 51);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 48));
  while ( 1 )
  {
    v10 = *v6;
    if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v10 & 0x40000000) == 0 )
    {
      do
        v22 = __ldrex(v6);
      while ( v22 == v10 && __strex(v10 | 0x40000000, v6) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v11 = *(_DWORD *)(a1 + 148);
  v12 = (*(_DWORD *)(a1 + 100) >> 3) & 1;
  if ( a2 )
  {
    *(_QWORD *)&v13 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v15 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v16 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v15 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
    *(_QWORD *)(a1 + 56) = __PAIR64__(v15, v16) - __PAIR64__(v14, v13);
    __dmb(0xBu);
    v17 = (unsigned __int8 *)(a1 + 100);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 | 8, v17) );
    __dmb(0xBu);
    v4 = v23;
    v5 = v24;
  }
  else
  {
    *(_DWORD *)(a1 + 148) = v11 + 1;
  }
  if ( v12 + v11 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 48);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    result = KfLowerIrql(v4);
  }
  else
  {
    v21 = *(_DWORD **)(a1 + 40);
    v20 = (_DWORD *)(a1 + 40);
    for ( i = v21; i != v20; i = (_DWORD *)*i )
      KiFreezeSingleThread(v5 + 1408, i - 117);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    result = KiExitDispatcher(v5 + 1408, 0, 1, 0, v4);
  }
  return result;
}
