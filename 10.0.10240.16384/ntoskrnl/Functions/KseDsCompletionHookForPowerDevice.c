// KseDsCompletionHookForPowerDevice 
 
int __fastcall KseDsCompletionHookForPowerDevice(int a1, int a2)
{
  return KsepDsEventDevicePowerCompleted(*(_DWORD *)(a1 + 8), a1, a2, *(_DWORD *)(a2 + 24));
}
