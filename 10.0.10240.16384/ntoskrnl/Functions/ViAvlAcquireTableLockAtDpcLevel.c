// ViAvlAcquireTableLockAtDpcLevel 
 
int __fastcall ViAvlAcquireTableLockAtDpcLevel(int a1, int a2)
{
  unsigned int *v4; // r4
  int result; // r0
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r6
  char v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r1

  v4 = (unsigned int *)(a1 + 128);
  if ( (*(_BYTE *)(a2 + 5) & 4) != 0 )
  {
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_518B88();
    v6 = (unsigned __int8 *)(a1 + 131);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 128));
    result = 0x40000000;
    while ( 1 )
    {
      v8 = *v4;
      if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v8 & 0x40000000) == 0 )
      {
        do
          v10 = __ldrex(v4);
        while ( v10 == v8 && __strex(v8 | 0x40000000, v4) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  else if ( (dword_682604 & 0x210000) != 0 )
  {
    result = ExpAcquireSpinLockSharedAtDpcLevelInstrumented(a1 + 128);
  }
  else
  {
    result = *v4 & 0x7FFFFFFF;
    do
      v11 = __ldrex(v4);
    while ( v11 == result && __strex(result + 1, v4) );
    __dmb(0xBu);
    if ( v11 != result )
      result = ExpWaitForSpinLockSharedAndAcquire(v4);
  }
  v9 = *(_BYTE *)(a2 + 5);
  *(_DWORD *)a2 = a1;
  *(_BYTE *)(a2 + 5) = v9 | 2;
  return result;
}
