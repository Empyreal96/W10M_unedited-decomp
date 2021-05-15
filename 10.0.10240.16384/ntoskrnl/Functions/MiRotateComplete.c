// MiRotateComplete 
 
int __fastcall MiRotateComplete(_DWORD *a1)
{
  int v2; // r3
  _DWORD **v3; // r6
  unsigned int *v4; // r4
  int v5; // r8
  _DWORD *i; // r3
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r1

  v2 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v3 = (_DWORD **)(v2 + 260);
  v4 = (unsigned int *)(v2 + 492);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v4);
  }
  else
  {
    v7 = (unsigned __int8 *)v4 + 3;
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    __dmb(0xBu);
    if ( v8 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v4);
    while ( 1 )
    {
      v9 = *v4;
      if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v9 & 0x40000000) == 0 )
      {
        do
          v10 = __ldrex(v4);
        while ( v10 == v9 && __strex(v9 | 0x40000000, v4) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  for ( i = *v3; i != a1; i = (_DWORD *)*i )
    v3 = (_DWORD **)i;
  *v3 = (_DWORD *)*i;
  return MiUnlockWorkingSetExclusive((int)v4, v5);
}
