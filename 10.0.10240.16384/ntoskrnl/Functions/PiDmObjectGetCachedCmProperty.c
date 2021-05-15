// PiDmObjectGetCachedCmProperty 
 
int __fastcall PiDmObjectGetCachedCmProperty(int a1, int a2, int a3, int a4, _DWORD *a5, int a6, _DWORD *a7)
{
  int v7; // r6
  int v8; // r5
  int v10; // r0
  char v11[16]; // [sp+20h] [bp-78h] BYREF
  char v12[104]; // [sp+30h] [bp-68h] BYREF

  v7 = a6;
  v8 = -1073741802;
  if ( a6 )
  {
    if ( !*a7 )
      v7 = 0;
  }
  else
  {
    *a7 = 0;
  }
  if ( a4 != 9 )
    return v8;
  if ( a1 != 1 )
    return v8;
  v10 = CmMapCmObjectTypeToPnpObjectType(1);
  v8 = PiDmObjectGetCachedObjectProperty(v10);
  if ( v8 < 0 )
    return v8;
  *a5 = 1;
  if ( *a7 >= 0x4Eu )
  {
    v8 = PnpStringFromGuid(v11, v12);
    if ( v8 >= 0 )
    {
      *a7 = 78;
      memmove(v7, (int)v12, 0x4Eu);
    }
    return v8;
  }
  return sub_7C6554();
}
