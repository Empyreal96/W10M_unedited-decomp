// PopPluginRegisterDevice 
 
int __fastcall PopPluginRegisterDevice(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int (__fastcall *v6)(int, int *); // lr
  int v7; // r5
  int v9[3]; // [sp+0h] [bp-28h] BYREF
  int v10; // [sp+Ch] [bp-1Ch]
  int v11; // [sp+10h] [bp-18h]

  v6 = *(int (__fastcall **)(int, int *))(a1 + 64);
  v7 = 0;
  *a6 = 0;
  if ( v6 && *(_DWORD *)(a1 + 8) >= 2u && a4 )
  {
    v9[1] = a3;
    v9[2] = a4;
    v9[0] = a2;
    v10 = 0;
    v11 = 0;
    if ( !v6(3, v9) )
      sub_55148C();
    if ( v11 )
    {
      v7 = v11;
      *a6 = v10;
    }
  }
  return v7;
}
