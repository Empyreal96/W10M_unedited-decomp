// CmpCoalescingCallback 
 
int __fastcall CmpCoalescingCallback(int a1)
{
  int result; // r0

  if ( a1 == 1 )
  {
    __dmb(0xBu);
    do
      result = __ldrex((unsigned int *)&CmpHoldLazyFlush);
    while ( __strex(result | 8, (unsigned int *)&CmpHoldLazyFlush) );
    __dmb(0xBu);
  }
  else if ( a1 == 2 )
  {
    result = CmpEnableLazyFlush(8);
  }
  else
  {
    result = sub_50F6AC(a1);
  }
  return result;
}
