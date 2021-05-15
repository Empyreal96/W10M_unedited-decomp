// PopPluginRegisterComponentPerfStates 
 
int __fastcall PopPluginRegisterComponentPerfStates(int a1, int a2, int a3)
{
  int v4; // r4
  int result; // r0
  _DWORD v6[8]; // [sp+0h] [bp-20h] BYREF

  v4 = *(_DWORD *)(a1 + 36);
  result = 0;
  if ( v4 )
  {
    v6[0] = *(_DWORD *)(a1 + 40);
    v6[1] = a2;
    v6[2] = 0;
    v6[3] = 0;
    v6[4] = a3;
    result = (*(int (__fastcall **)(int, _DWORD *))(v4 + 64))(32, v6);
  }
  return result;
}
