// IoQueryEnvironmentVariableInfoEx 
 
int __fastcall IoQueryEnvironmentVariableInfoEx(int a1, int a2, int a3, int a4)
{
  int v8; // r4
  int v9; // r5
  int v11; // [sp+4h] [bp-24h]
  int v12; // [sp+8h] [bp-20h] BYREF
  int v13; // [sp+Ch] [bp-1Ch] BYREF
  void **v14; // [sp+10h] [bp-18h] BYREF

  v8 = IopOpenSystemVariableDevice(&v13, &v12, &v14);
  if ( v8 >= 0 )
  {
    v11 = a4;
    v9 = v13;
    v8 = ((int (__fastcall *)(int, int, int, int, int, int))v14[3])(v13, v12, a1, a2, a3, v11);
    if ( v9 )
      ObfDereferenceObject(v9);
  }
  return v8;
}
