// PopPluginQueryComponentPerfCapabilities 
 
int __fastcall PopPluginQueryComponentPerfCapabilities(int a1, int a2, _DWORD *a3, int a4)
{
  int v6; // r2
  int result; // r0
  int v8; // [sp+0h] [bp-10h] BYREF
  _DWORD *v9; // [sp+4h] [bp-Ch]
  int v10; // [sp+8h] [bp-8h]

  v8 = a2;
  v9 = a3;
  v10 = a4;
  v6 = *(_DWORD *)(a1 + 36);
  result = 0;
  if ( v6 )
  {
    v8 = *(_DWORD *)(a1 + 40);
    v9 = (_DWORD *)a2;
    result = (*(int (__fastcall **)(int, int *))(v6 + 64))(28, &v8);
    if ( result )
      *a3 = v10;
  }
  return result;
}
