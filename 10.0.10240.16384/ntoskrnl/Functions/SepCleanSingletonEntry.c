// SepCleanSingletonEntry 
 
int SepCleanSingletonEntry()
{
  int result; // r0
  unsigned int *v1; // r4
  int v2; // r6
  unsigned __int8 *v3; // r3
  unsigned int v4; // r1
  unsigned int v5; // r0
  int v6; // r0
  unsigned int v7; // r1

  result = SepGetSingletonEntryFromIndexNumber();
  v1 = (unsigned int *)result;
  if ( result )
  {
    v2 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = sub_5259D0();
    }
    else
    {
      v3 = (unsigned __int8 *)v1 + 3;
      do
        v4 = __ldrex(v3);
      while ( __strex(v4 | 0x80, v3) );
      __dmb(0xBu);
      if ( v4 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v1);
      while ( 1 )
      {
        v5 = *v1;
        if ( (*v1 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v5 & 0x40000000) == 0 )
        {
          do
            v7 = __ldrex(v1);
          while ( v7 == v5 && __strex(v5 | 0x40000000, v1) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v6 = v1[4];
      v1[2] = 0;
      v1[3] = 0;
      if ( v6 )
      {
        AuthzBasepFreeSecurityAttributesList(v6);
        ExFreePoolWithTag(v1[4], 1950639443);
        v1[4] = 0;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v1);
      }
      else
      {
        __dmb(0xBu);
        *v1 = 0;
      }
      result = KfLowerIrql(v2);
    }
  }
  return result;
}
