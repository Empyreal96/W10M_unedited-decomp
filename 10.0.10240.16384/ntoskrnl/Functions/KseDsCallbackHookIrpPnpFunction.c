// KseDsCallbackHookIrpPnpFunction 
 
int __fastcall KseDsCallbackHookIrpPnpFunction(int a1, int a2, int a3)
{
  unsigned __int8 *v4; // r3
  int v6; // r6
  int v7; // r9
  int (*v8)(); // r2
  int v9; // r0
  int v12; // [sp+0h] [bp-20h]

  v4 = *(unsigned __int8 **)(a2 + 96);
  v6 = v4[1];
  v7 = *v4;
  if ( !v4[1] )
  {
    v8 = KseDsCompletionHookForStartDevice;
LABEL_5:
    (*((void (__fastcall **)(int, int, int (*)(), _DWORD, int))off_617624 + 1))(a1, a2, v8, 0, a3);
    goto LABEL_6;
  }
  if ( v6 == 4 )
  {
    v8 = KseDsCompletionHookForStopDevice;
    goto LABEL_5;
  }
LABEL_6:
  v9 = (*(int (__fastcall **)(_DWORD))off_617624)(*(_DWORD *)(a1 + 8));
  v12 = (*(int (__fastcall **)(int, int))(v9 + 4 * v7 + 16))(a1, a2);
  KsepDsEventPnpIrp(*(_DWORD *)(a1 + 8), a1, a2, v6);
  return v12;
}
