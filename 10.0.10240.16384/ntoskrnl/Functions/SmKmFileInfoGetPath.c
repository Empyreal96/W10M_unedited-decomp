// SmKmFileInfoGetPath 
 
int __fastcall SmKmFileInfoGetPath(int a1, _BYTE *a2, int a3)
{
  int v6; // r7
  int v7; // r4
  unsigned int v8; // r2
  int v10; // [sp+8h] [bp-228h] BYREF
  unsigned __int16 v11; // [sp+10h] [bp-220h] BYREF
  int v12; // [sp+14h] [bp-21Ch]

  v6 = IoSetThreadHardErrorMode(0);
  v7 = ObQueryNameStringMode(*(_DWORD *)(a1 + 4), (int)&v11, 520, &v10, 0);
  if ( v7 >= 0 )
  {
    memset(a2, 0, a3);
    v8 = v11;
    if ( v11 >= (unsigned int)(a3 - 2) )
      v8 = a3 - 2;
    memmove((int)a2, v12, v8);
    v7 = 0;
  }
  IoSetThreadHardErrorMode(v6);
  return v7;
}
