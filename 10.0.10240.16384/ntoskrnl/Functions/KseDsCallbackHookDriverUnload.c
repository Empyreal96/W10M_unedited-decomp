// KseDsCallbackHookDriverUnload 
 
int __fastcall KseDsCallbackHookDriverUnload(int a1)
{
  int v2; // r0

  v2 = (*(int (**)(void))off_617624)();
  (*(void (__fastcall **)(int))(v2 + 8))(a1);
  return KsepDsEventDriverUnload(a1, *(_DWORD *)(a1 + 12));
}
