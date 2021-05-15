// PopCoalescingCheck 
 
unsigned int __fastcall PopCoalescingCheck(unsigned int a1, unsigned int a2, int a3)
{
  unsigned int v3; // r5
  int v4; // r6
  unsigned int v5; // r4
  __int64 v6; // r0

  v3 = a2;
  if ( a1 )
  {
    if ( a3 )
    {
      if ( a2 > a1 )
        v3 = a1 / 0x3E8 + 1;
    }
    else
    {
      v4 = 10000000 * PopCoalescingFlushInterval;
      v5 = (10000000 * (unsigned __int64)(unsigned int)PopCoalescingFlushInterval) >> 32;
      LODWORD(v6) = KeQueryInterruptTime();
      if ( v6 - PopCoalescingLastFlushTime >= __PAIR64__(v5, v4) )
      {
        PopGetPolicyWorker(32);
        PopCheckForWork();
      }
    }
  }
  return v3;
}
