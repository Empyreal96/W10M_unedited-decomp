// MiFreePhysicalView 
 
int __fastcall MiFreePhysicalView(int result, int a2)
{
  unsigned int *v2; // r4
  int v3; // r6
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r1

  if ( (*(_DWORD *)(a2 + 28) & 7) == 1 )
  {
    v2 = (unsigned int *)(result + 492);
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = sub_54489C();
    }
    else
    {
      v4 = (unsigned __int8 *)v2 + 3;
      do
        v5 = __ldrex(v4);
      while ( __strex(v5 | 0x80, v4) );
      __dmb(0xBu);
      if ( v5 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v2);
      while ( 1 )
      {
        v6 = *v2;
        if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v6 & 0x40000000) == 0 )
        {
          do
            v7 = __ldrex(v2);
          while ( v7 == v6 && __strex(v6 | 0x40000000, v2) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      --MEMORY[0xC0402124];
      result = MiUnlockWorkingSetExclusive((int)v2, v3);
    }
  }
  return result;
}
