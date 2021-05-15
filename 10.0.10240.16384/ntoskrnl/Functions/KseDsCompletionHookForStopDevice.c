// KseDsCompletionHookForStopDevice 
 
int __fastcall KseDsCompletionHookForStopDevice(int a1, int a2)
{
  return KsepDsEventPnpStopDevice(*(_DWORD *)(a1 + 8), a1, a2, *(_DWORD *)(a2 + 24));
}
