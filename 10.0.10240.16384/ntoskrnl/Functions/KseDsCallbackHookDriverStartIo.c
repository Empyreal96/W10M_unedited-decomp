// KseDsCallbackHookDriverStartIo 
 
int __fastcall KseDsCallbackHookDriverStartIo(int a1, int a2)
{
  int v4; // r0

  v4 = (*(int (__fastcall **)(_DWORD))off_617624)(*(_DWORD *)(a1 + 8));
  (*(void (__fastcall **)(int, int))(v4 + 4))(a1, a2);
  return KsepDsEventDriverStartIo(*(_DWORD *)(a1 + 8), a1, a2);
}
