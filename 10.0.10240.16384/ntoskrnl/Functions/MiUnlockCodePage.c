// MiUnlockCodePage 
 
unsigned int __fastcall MiUnlockCodePage(unsigned int result, unsigned int a2)
{
  unsigned int *v2; // r9
  int v3; // r4
  unsigned int v4; // r7
  unsigned int v5; // t1
  int v6; // r5
  int v7; // r6
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int *v10; // r2
  unsigned int v11; // r0

  v2 = (unsigned int *)result;
  v3 = 1;
  if ( result > a2 )
    v4 = 0;
  else
    v4 = (a2 - result + 4) >> 2;
  if ( v4 )
  {
    while ( 1 )
    {
      v5 = *v2++;
      v6 = MmPfnDatabase + 24 * (v5 >> 12);
      v7 = KfRaiseIrql(2);
      v8 = (unsigned __int8 *)(v6 + 15);
      do
        v9 = __ldrex(v8);
      while ( __strex(v9 | 0x80, v8) );
      __dmb(0xBu);
      if ( v9 >> 7 )
        break;
      MiRemoveLockedPageChargeAndDecRef(v6);
      __dmb(0xBu);
      v10 = (unsigned int *)(v6 + 12);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 & 0x7FFFFFFF, v10) );
      result = KfLowerIrql(v7);
      if ( ++v3 > v4 )
        return result;
    }
    result = sub_50BA00();
  }
  return result;
}
