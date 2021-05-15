// PopPluginRequestComponentPerfState 
 
int __fastcall PopPluginRequestComponentPerfState(int a1, int a2, int a3, int a4, char *a5)
{
  int v5; // r8
  char v10; // r2
  int result; // r0
  _DWORD v12[10]; // [sp+0h] [bp-28h] BYREF

  v5 = *(_DWORD *)(a1 + 36);
  memset(v12, 0, 20);
  v12[0] = *(_DWORD *)(a1 + 40);
  v12[1] = a2;
  v12[3] = a3;
  v12[4] = a4;
  if ( v5 )
  {
    if ( !(*(int (__fastcall **)(int, _DWORD *))(v5 + 64))(33, v12) )
      PopFxBugCheck(1541, 33, v5, 0);
    v10 = BYTE1(v12[2]);
    result = LOBYTE(v12[2]);
  }
  else
  {
    result = 1;
    v10 = 1;
  }
  if ( result )
    *a5 = v10;
  return result;
}
