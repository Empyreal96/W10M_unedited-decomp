// PopSetNotificationWork 
 
int __fastcall PopSetNotificationWork(int result)
{
  unsigned int v1; // r1
  int v2; // r0

  if ( (PopNotifyEvents & result) != result )
  {
    if ( (PoDebug & 0x10) != 0 )
    {
      result = sub_529D04();
    }
    else
    {
      __dmb(0xBu);
      do
        v1 = __ldrex((unsigned int *)&PopNotifyEvents);
      while ( __strex(v1 | result, (unsigned int *)&PopNotifyEvents) );
      __dmb(0xBu);
      v2 = PopGetPolicyWorker(4);
      result = PopCheckForWork(v2);
    }
  }
  return result;
}
