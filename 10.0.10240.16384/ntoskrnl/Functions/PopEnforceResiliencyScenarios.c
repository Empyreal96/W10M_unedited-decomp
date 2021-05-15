// PopEnforceResiliencyScenarios 
 
int __fastcall PopEnforceResiliencyScenarios(int a1)
{
  PopEnforceDeepSleep(*(unsigned __int8 *)(a1 + 4));
  PpmAcquireLock(&PopFxSystemLatencyLock);
  PoFxSendSystemLatencyUpdate();
  PpmReleaseLock((int *)&PopFxSystemLatencyLock);
  return PopCoalescingEnforce(*(_DWORD *)a1);
}
