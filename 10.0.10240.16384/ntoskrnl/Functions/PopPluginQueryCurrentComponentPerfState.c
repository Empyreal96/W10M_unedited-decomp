// PopPluginQueryCurrentComponentPerfState 
 
int __fastcall PopPluginQueryCurrentComponentPerfState(int a1, int a2, _DWORD *a3)
{
  int v3; // r5
  int result; // r0
  _DWORD v6[8]; // [sp+0h] [bp-20h] BYREF

  v3 = *(_DWORD *)(a1 + 36);
  v6[0] = *(_DWORD *)(a1 + 40);
  v6[1] = a2;
  v6[2] = *a3;
  result = (*(int (__fastcall **)(int, _DWORD *))(v3 + 64))(34, v6);
  if ( !result )
    PopFxBugCheck(1541, 34, v3, 0);
  a3[2] = v6[4];
  a3[3] = v6[5];
  return result;
}
