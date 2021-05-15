// KeThawProcess 
 
int __fastcall KeThawProcess(int a1, int a2)
{
  _DWORD **v3; // r6
  unsigned int *v4; // r4
  int result; // r0
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r0
  int v9; // r2
  int v10; // r10
  unsigned __int8 *v11; // r3
  unsigned int v12; // r2
  __int64 v13; // r8
  __int64 v14; // r0
  unsigned int v15; // r5
  unsigned int v16; // lr
  _DWORD *i; // r0
  _DWORD *j; // r5
  unsigned int v19; // r1
  unsigned int v21; // [sp+Ch] [bp-24h]
  int v22; // [sp+10h] [bp-20h]

  __mrc(15, 0, 13, 0, 3);
  v3 = (_DWORD **)(a1 + 40);
  v22 = KfRaiseIrql(2);
  v21 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v4 = (unsigned int *)(a1 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_526E14();
  v6 = (unsigned __int8 *)(a1 + 51);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 | 0x80, v6) );
  __dmb(0xBu);
  if ( v7 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 48));
  while ( 1 )
  {
    v8 = *v4;
    if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v8 & 0x40000000) == 0 )
    {
      do
        v19 = __ldrex(v4);
      while ( v19 == v8 && __strex(v8 | 0x40000000, v4) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v9 = *(_DWORD *)(a1 + 148);
  v10 = ((*(_DWORD *)(a1 + 100) >> 3) & 1) + v9;
  if ( v10 )
  {
    if ( a2 )
    {
      __dmb(0xBu);
      v11 = (unsigned __int8 *)(a1 + 100);
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 & 0xF7, v11) );
      __dmb(0xBu);
      v13 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        HIDWORD(v14) = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        LODWORD(v14) = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( HIDWORD(v14) == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
      v16 = (unsigned __int64)(v14 - *(_QWORD *)(a1 + 56) - v13) >> 32;
      v15 = v14 - *(_DWORD *)(a1 + 56) - v13;
      goto LABEL_15;
    }
    *(_DWORD *)(a1 + 148) = v9 - 1;
  }
  v16 = 0;
  v15 = 0;
LABEL_15:
  if ( a2 && (*(_DWORD *)(a1 + 100) & 0x10) != 0 )
  {
    for ( i = *v3; i != v3; i = (_DWORD *)*i )
      *(_QWORD *)(i - 77) += __PAIR64__(v16, v15);
  }
  if ( v10 == 1 )
  {
    for ( j = *v3; j != v3; j = (_DWORD *)*j )
      KiThawSingleThread(v21 + 1408, j - 117, 0);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    result = KiExitDispatcher(v21 + 1408, 0, 1, 0, v22);
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 48);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    result = KfLowerIrql(v22);
  }
  return result;
}
