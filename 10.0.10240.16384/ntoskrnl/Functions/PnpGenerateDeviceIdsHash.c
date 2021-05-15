// PnpGenerateDeviceIdsHash 
 
int __fastcall PnpGenerateDeviceIdsHash(int a1, int a2, _DWORD *a3)
{
  int v3; // r4
  int v4; // r7
  int v5; // r6
  unsigned __int16 **v7; // r9
  unsigned __int16 *v8; // r5
  unsigned __int16 *v9; // t1
  unsigned int v11; // [sp+0h] [bp-30h] BYREF
  _DWORD v12[2]; // [sp+8h] [bp-28h] BYREF
  unsigned __int16 v13[16]; // [sp+10h] [bp-20h] BYREF

  v3 = 0;
  v4 = 0;
  v5 = 0;
  *a3 = 0;
  v12[0] = a1;
  v12[1] = a2;
  v7 = (unsigned __int16 **)v12;
  while ( 1 )
  {
    v9 = *v7++;
    v8 = v9;
    if ( v9 )
    {
      while ( *v8 )
      {
        v3 = RtlInitUnicodeStringEx((int)v13, v8);
        if ( v3 < 0 )
          return v3;
        v3 = RtlHashUnicodeString(v13, 1, 0, &v11);
        if ( v3 < 0 )
          return v3;
        v4 += v11;
        v8 += wcslen(v8) + 1;
        if ( !v8 )
          break;
      }
    }
    if ( v3 < 0 )
      return v3;
    if ( (unsigned int)++v5 >= 2 )
    {
      *a3 = v4;
      return v3;
    }
  }
}
