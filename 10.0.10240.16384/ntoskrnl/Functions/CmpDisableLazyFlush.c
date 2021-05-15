// CmpDisableLazyFlush 
 
int __fastcall CmpDisableLazyFlush(int result)
{
  unsigned int v1; // r4

  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&CmpHoldLazyFlush);
  while ( __strex(v1 | result, (unsigned int *)&CmpHoldLazyFlush) );
  __dmb(0xBu);
  return result;
}
