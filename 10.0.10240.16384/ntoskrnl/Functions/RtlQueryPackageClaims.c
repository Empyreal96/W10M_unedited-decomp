// RtlQueryPackageClaims 
 
int __fastcall RtlQueryPackageClaims(int a1, int a2, _DWORD *a3, int a4, _DWORD *a5, int a6, _DWORD *a7)
{
  int v10; // r4
  _DWORD *v12; // r6
  int v13; // [sp+10h] [bp-290h] BYREF
  _DWORD *v14; // [sp+14h] [bp-28Ch]
  char v15[8]; // [sp+18h] [bp-288h] BYREF
  char v16[8]; // [sp+20h] [bp-280h] BYREF
  int v17; // [sp+28h] [bp-278h]

  v14 = a5;
  v10 = RtlpQueryPackageIdentityAttributes(a1, a2, (int)v16, a7);
  if ( v10 < 0 )
    return v10;
  if ( !a2 )
  {
    if ( !a3 )
      goto LABEL_7;
    return -1073741811;
  }
  if ( !a3 )
    return -1073741811;
  v10 = RtlStringCbPrintfExW(a2, *a3, &v13, v15, 2048, L"%wZ", *(_DWORD *)(v17 + 20));
  if ( v10 < 0 )
    return v10;
  *a3 = v13 - a2 + 2;
LABEL_7:
  if ( !a4 )
    goto LABEL_10;
  v12 = v14;
  v10 = RtlStringCbPrintfExW(a4, *v14, &v13, 0, 2048, L"%wZ", *(_DWORD *)(v17 + 20) + 8);
  if ( v10 < 0 )
    return v10;
  *v12 = v13 - a4 + 2;
LABEL_10:
  if ( !a6 )
    return v10;
  return sub_54B61C();
}
