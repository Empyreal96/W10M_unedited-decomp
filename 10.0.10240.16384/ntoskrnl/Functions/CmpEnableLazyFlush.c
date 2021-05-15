// CmpEnableLazyFlush 
 
int __fastcall CmpEnableLazyFlush(int result)
{
  unsigned int v1; // r5
  unsigned int i; // r4

  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&CmpHoldLazyFlush);
  while ( __strex(v1 & ~result, (unsigned int *)&CmpHoldLazyFlush) );
  __dmb(0xBu);
  if ( v1 == result )
  {
    for ( i = 0; i < 2; ++i )
      result = CmpArmLazyWriter(i, 0, 1);
  }
  return result;
}
