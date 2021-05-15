// KeForceResumeProcess 
 
int __fastcall KeForceResumeProcess(unsigned int *a1)
{
  _DWORD **v2; // r9
  int v3; // r8
  unsigned int v4; // r10
  unsigned int *v5; // r4
  int result; // r0
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  unsigned __int8 *v10; // r3
  unsigned int v11; // r2
  _DWORD *i; // r5
  unsigned int v13; // r1

  __mrc(15, 0, 13, 0, 3);
  v2 = (_DWORD **)(a1 + 10);
  v3 = KfRaiseIrql(2);
  v4 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v5 = a1 + 12;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52B080();
  v7 = (unsigned __int8 *)a1 + 51;
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(a1 + 12);
  while ( 1 )
  {
    v9 = *v5;
    if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v9 & 0x40000000) == 0 )
    {
      do
        v13 = __ldrex(v5);
      while ( v13 == v9 && __strex(v9 | 0x40000000, v5) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( a1[37] + ((a1[25] >> 3) & 1) )
  {
    __dmb(0xBu);
    v10 = (unsigned __int8 *)(a1 + 25);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 & 0xF7, v10) );
    __dmb(0xBu);
    a1[37] = 0;
    for ( i = *v2; i != v2; i = (_DWORD *)*i )
      KiThawSingleThread(v4 + 1408, i - 117, 1);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 12);
    }
    else
    {
      __dmb(0xBu);
      *v5 = 0;
    }
    result = KiExitDispatcher(v4 + 1408, 0, 1, 0, v3);
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 12);
    }
    else
    {
      __dmb(0xBu);
      *v5 = 0;
    }
    result = KfLowerIrql(v3);
  }
  return result;
}
