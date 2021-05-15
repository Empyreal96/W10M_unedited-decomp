// IoGetEnvironmentVariableEx 
 
int __fastcall IoGetEnvironmentVariableEx(int a1, int a2, int a3, int a4, int a5)
{
  int v9; // r4
  int v10; // r5
  int v12; // [sp+4h] [bp-2Ch]
  int v13; // [sp+10h] [bp-20h] BYREF
  int v14; // [sp+14h] [bp-1Ch] BYREF
  int v15[6]; // [sp+18h] [bp-18h] BYREF

  v9 = IopOpenSystemVariableDevice(&v14, &v13, v15);
  if ( v9 >= 0 )
  {
    v12 = a4;
    v10 = v14;
    v9 = (*(int (__fastcall **)(int, int, int, int, int, int, int))v15[0])(v14, v13, a1, a2, a3, v12, a5);
    if ( v10 )
      ObfDereferenceObject(v10);
  }
  return v9;
}
