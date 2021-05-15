// KseDsCallbackHookIrpFunction 
 
int __fastcall KseDsCallbackHookIrpFunction(int a1, int a2)
{
  int v4; // r5
  int v5; // r0
  int v6; // r4

  v4 = **(unsigned __int8 **)(a2 + 96);
  v5 = (*(int (__fastcall **)(_DWORD))off_617624)(*(_DWORD *)(a1 + 8));
  v6 = (*(int (__fastcall **)(int, int))(v5 + 4 * v4 + 16))(a1, a2);
  if ( v4 == 3 || v4 == 4 )
    KsepDsEventDataIrp(*(_DWORD *)(a1 + 8), a1, a2, v4);
  return v6;
}
