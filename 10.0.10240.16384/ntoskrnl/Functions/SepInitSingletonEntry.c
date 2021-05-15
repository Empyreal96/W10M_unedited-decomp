// SepInitSingletonEntry 
 
int __fastcall SepInitSingletonEntry(int a1, int a2, unsigned int a3, unsigned int a4)
{
  int result; // r0
  unsigned int *v7; // r4
  int v8; // r6
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1

  result = SepGetSingletonEntryFromIndexNumber();
  v7 = (unsigned int *)result;
  if ( result )
  {
    v8 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = sub_52AF34();
    }
    else
    {
      v9 = (unsigned __int8 *)v7 + 3;
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 | 0x80, v9) );
      __dmb(0xBu);
      if ( v10 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v7);
      while ( 1 )
      {
        v11 = *v7;
        if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v11 & 0x40000000) == 0 )
        {
          do
            v12 = __ldrex(v7);
          while ( v12 == v11 && __strex(v11 | 0x40000000, v7) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v7[3] = a4;
      v7[4] = 0;
      v7[2] = a3;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v7);
      }
      else
      {
        __dmb(0xBu);
        *v7 = 0;
      }
      result = KfLowerIrql(v8);
    }
  }
  return result;
}
