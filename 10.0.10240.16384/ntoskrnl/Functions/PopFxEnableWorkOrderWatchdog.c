// PopFxEnableWorkOrderWatchdog 
 
int __fastcall PopFxEnableWorkOrderWatchdog(int a1)
{
  int v1; // r5

  v1 = 0;
  if ( PopFxWatchdogWorkOrderTimeout )
  {
    v1 = *(_DWORD *)(a1 + 24);
    if ( v1 )
      KeSetCoalescableTimer(v1);
  }
  return v1;
}
