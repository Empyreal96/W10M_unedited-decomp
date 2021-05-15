// KseDsCompletionHookForStartDevice 
 
int __fastcall KseDsCompletionHookForStartDevice(int a1, int a2)
{
  return KsepDsEventPnpStartDevice(*(_DWORD *)(a1 + 8), a1, a2, *(_DWORD *)(a2 + 24));
}
