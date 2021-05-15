// MiWaitForRotateToComplete 
 
int __fastcall MiWaitForRotateToComplete(unsigned int a1, int a2)
{
  unsigned int v3; // r0
  int v4; // r6
  int v5; // r4
  _DWORD *i; // r2
  int v7; // r5
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int *v11; // r4
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r1

  v3 = a1 >> 12;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_DWORD *)(v4 + 0x74);
  for ( i = *(_DWORD **)(v5 + 260); ; i = (_DWORD *)*i )
  {
    if ( !i )
      return 0;
    v7 = i[1];
    if ( v3 >= *(_DWORD *)(v7 + 12) && v3 <= *(_DWORD *)(v7 + 16) )
      break;
  }
  if ( i[2] == v4 )
    return 0;
  v9 = (unsigned int *)(i[1] + 20);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 + 1, v9) );
  __dmb(0xBu);
  v11 = (unsigned int *)(v5 + 492);
  MiUnlockWorkingSetExclusive((int)v11, a2);
  MiLockVad(v4, v7);
  MiUnlockAndDereferenceVad(v7);
  KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v11);
  }
  else
  {
    v12 = (unsigned __int8 *)v11 + 3;
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 | 0x80, v12) );
    __dmb(0xBu);
    if ( v13 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v11);
    while ( 1 )
    {
      v14 = *v11;
      if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v14 & 0x40000000) == 0 )
      {
        do
          v15 = __ldrex(v11);
        while ( v15 == v14 && __strex(v14 | 0x40000000, v11) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  return 1;
}
