// KseSkipDriverUnloadCallbackHookDriverUnload 
 
int __fastcall KseSkipDriverUnloadCallbackHookDriverUnload(int a1)
{
  return KsepSkipDriverUnloadEventDriverUnload(a1, *(_DWORD *)(a1 + 12));
}
