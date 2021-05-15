// IoEnumerateEnvironmentVariablesEx 
 
int __fastcall IoEnumerateEnvironmentVariablesEx(int a1, int a2, int a3)
{
  int v6; // r4
  int v7; // r5
  int v9; // [sp+0h] [bp-28h]
  int v10; // [sp+8h] [bp-20h] BYREF
  int v11; // [sp+Ch] [bp-1Ch] BYREF
  void **v12; // [sp+10h] [bp-18h] BYREF

  v6 = IopOpenSystemVariableDevice(&v11, &v10, &v12);
  if ( v6 >= 0 )
  {
    v9 = a3;
    v7 = v11;
    v6 = ((int (__fastcall *)(int, int, int, int, int))v12[2])(v11, v10, a1, a2, v9);
    if ( v7 )
      ObfDereferenceObject(v7);
  }
  return v6;
}
