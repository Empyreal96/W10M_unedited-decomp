// KseDsCallbackHookIrpDeviceControlFunction 
 
int __fastcall KseDsCallbackHookIrpDeviceControlFunction(int a1, int a2)
{
  int v4; // r5
  int v5; // r0
  int v7; // [sp+0h] [bp-18h]

  v4 = **(unsigned __int8 **)(a2 + 96);
  v5 = (*(int (__fastcall **)(_DWORD))off_617624)(*(_DWORD *)(a1 + 8));
  v7 = (*(int (__fastcall **)(int, int))(v5 + 4 * v4 + 16))(a1, a2);
  KsepDsEventDataIrp(*(_DWORD *)(a1 + 8), a1, a2, v4);
  return v7;
}
