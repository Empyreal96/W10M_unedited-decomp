// PfpPrefetchEntireDirectory 
 
int __fastcall PfpPrefetchEntireDirectory(_DWORD *a1, int a2, int a3, _DWORD *a4, int a5)
{
  __int64 v9; // kr00_8
  int v10; // r4
  int v11; // r4
  char v13[8]; // [sp+18h] [bp-40h] BYREF
  int v14[2]; // [sp+20h] [bp-38h] BYREF
  char v15[8]; // [sp+28h] [bp-30h] BYREF
  int v16[10]; // [sp+30h] [bp-28h] BYREF

  memset(v16, 0, 20);
  v9 = *(_QWORD *)(a5 + 4);
  v16[4] |= 2u;
  v10 = PfpOpenHandleCreate(v16, a1, SHIDWORD(v9), v9, 1048577, 16417, 0, a2);
  if ( v10 >= 0 )
  {
    if ( a4 )
    {
      v11 = v16[1];
      if ( IoQueryFileInformation(v16[1], 6, 8, (int)v14, (int)v13) >= 0 )
      {
        a4[2] = v14[0];
        a4[3] = v14[1];
        *a4 = *(_DWORD *)(v11 + 12);
        a4[1] = v16[3];
      }
    }
    v10 = NtFsControlFile(v16[0], 0, 0, 0, (int)v15, 590112, a3);
    if ( v10 >= 0 )
      v10 = 0;
  }
  if ( (v16[4] & 4) != 0 )
    PfpOpenHandleClose(v16, (int)a1);
  return v10;
}
