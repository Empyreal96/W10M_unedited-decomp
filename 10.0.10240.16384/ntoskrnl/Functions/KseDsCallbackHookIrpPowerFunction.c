// KseDsCallbackHookIrpPowerFunction 
 
int __fastcall KseDsCallbackHookIrpPowerFunction(int a1, int a2)
{
  unsigned __int8 *v2; // r3
  int v3; // r7
  int v4; // r5
  int v7; // r9
  int v8; // r0
  int v9; // r4
  int v11; // [sp+10h] [bp-20h]

  v2 = *(unsigned __int8 **)(a2 + 96);
  v3 = 0;
  v4 = v2[1];
  v11 = *v2;
  v7 = 0;
  if ( v4 == 3 || v4 == 2 )
  {
    v7 = *((_DWORD *)v2 + 4);
    v3 = *((_DWORD *)v2 + 3);
    if ( v3 == 1 )
      (*((void (__fastcall **)(int, int, int (*)(), _DWORD))off_617624 + 1))(
        a1,
        a2,
        KseDsCompletionHookForPowerDevice,
        0);
  }
  v8 = (*(int (__fastcall **)(_DWORD))off_617624)(*(_DWORD *)(a1 + 8));
  v9 = (*(int (__fastcall **)(int, int))(v8 + 4 * v11 + 16))(a1, a2);
  if ( v4 == 3 || v4 == 2 )
  {
    if ( v3 )
    {
      if ( v3 == 1 )
        KsepDsEventDevicePowerIrp(*(_DWORD *)(a1 + 8), a1, a2, v4, 1, v7, v9);
    }
    else
    {
      KsepDsEventSystemPowerIrp(*(_DWORD *)(a1 + 8), a1, a2, v4, 0, v7, v9);
    }
  }
  return v9;
}
