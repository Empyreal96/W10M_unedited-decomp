// PopPluginRegisterCrashdumpDevice 
 
int __fastcall PopPluginRegisterCrashdumpDevice(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v4)(int, int *); // r3
  int v6; // r4
  int v8; // [sp+0h] [bp-10h] BYREF
  int v9; // [sp+4h] [bp-Ch]

  v8 = a3;
  v9 = a4;
  v4 = *(int (__fastcall **)(int, int *))(a1 + 64);
  v9 = a2;
  v8 = 0;
  v6 = 0;
  if ( !v4(25, &v8) || !v8 )
    return -1073741637;
  *(_DWORD *)(a3 + 336) = v8;
  return v6;
}
