// LdrpFetchAddressOfSecurityCookie 
 
int __fastcall LdrpFetchAddressOfSecurityCookie(unsigned int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  int v12[6]; // [sp+8h] [bp-18h] BYREF

  v12[0] = (int)a4;
  RtlImageNtHeaderEx(1, a1, 0i64, v12);
  v8 = (_DWORD *)RtlImageDirectoryEntryToData(a1, 1, 10, (int)v12);
  v9 = v12[0];
  *a3 = 0;
  if ( v8 )
  {
    if ( v9 )
    {
      if ( v9 == *v8 && *v8 >= 0x48u )
      {
        v10 = v8[15];
        if ( v10 > a1 && v10 < a1 + a2 - 4 )
        {
          if ( a4 )
            *a4 = v8;
          return v10;
        }
      }
    }
  }
  if ( !a4 )
    return 0;
  if ( !v8 )
  {
    *a4 = 0;
    return 0;
  }
  return sub_7CDC30();
}
