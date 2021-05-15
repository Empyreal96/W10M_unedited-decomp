// PopCoalescingSetTimer 
 
int PopCoalescingSetTimer()
{
  int result; // r0
  unsigned int v1; // r2

  if ( PopCoalescingState )
  {
    PopPrintEx(3, "PopCoalescing: Coalescing timer activated\n");
    result = KiSetTimerEx(
               &PopCoalescingTimer,
               0,
               -10000000 * PopCoalescingTimerInterval,
               (unsigned __int64)(-10000000i64 * PopCoalescingTimerInterval) >> 32,
               0,
               0,
               &PopCoalescingTimerDpc);
    __dmb(0xBu);
    do
      v1 = __ldrex(byte_61F3C1);
    while ( __strex(v1 | 2, byte_61F3C1) );
    __dmb(0xBu);
  }
  return result;
}
