// MiInsertVadEvent 
 
int __fastcall MiInsertVadEvent(int result, _DWORD *a2, int a3)
{
  int v4; // r8
  int v5; // r9
  unsigned int *v6; // r4
  int v7; // r6
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r1

  v4 = result;
  if ( a3 == 1 )
  {
    v5 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v6 = (unsigned int *)(v5 + 492);
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_546F78();
    v8 = (unsigned __int8 *)(v5 + 495);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v5 + 492));
    while ( 1 )
    {
      result = *v6;
      if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (result & 0x40000000) == 0 )
      {
        do
          v10 = __ldrex(v6);
        while ( v10 == result && __strex(result | 0x40000000, v6) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  else
  {
    v7 = 17;
    v5 = 0;
  }
  *a2 = *(_DWORD *)(v4 + 36);
  *(_DWORD *)(v4 + 36) = a2;
  if ( v7 != 17 )
    result = MiUnlockWorkingSetExclusive(v5 + 492, v7);
  return result;
}
