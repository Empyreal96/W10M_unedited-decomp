// PopCoalescingInitialize 
 
int PopCoalescingInitialize()
{
  int result; // r0

  PopCoalescingState = 0;
  result = PoRegisterCoalescingCallback((int)PopPoCoalescinCallback, 0, &PopCoalescingRegistration, 0);
  if ( result >= 0 )
  {
    KeInitializeTimerEx(&PopCoalescingTimer, 0);
    PopCoalescingTimerDpc = 19;
    byte_61F3A1 = 1;
    word_61F3A2 = 0;
    dword_61F3AC = (int)PopCoalesingTimerDpcCallback;
    dword_61F3B0 = 0;
    dword_61F3BC = 0;
    dword_61F3A8 = 0;
    result = PopUpdateDiskIdleTimeoutSetting();
  }
  return result;
}
