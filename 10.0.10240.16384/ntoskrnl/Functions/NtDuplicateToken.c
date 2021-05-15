// NtDuplicateToken 
 
int __fastcall NtDuplicateToken(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v7; // r8
  int v8; // r10
  int v9; // r6
  int v10; // r4
  _DWORD *v11; // r2
  int v12; // r0
  int v13; // r5
  int v14; // r0
  int v15; // r6
  int v17; // [sp+0h] [bp-68h]
  int v18; // [sp+4h] [bp-64h]
  char v19; // [sp+10h] [bp-58h] BYREF
  char v20; // [sp+11h] [bp-57h] BYREF
  char v21; // [sp+12h] [bp-56h]
  int v22; // [sp+14h] [bp-54h] BYREF
  int v23; // [sp+18h] [bp-50h]
  int v24[2]; // [sp+1Ch] [bp-4Ch] BYREF
  int v25; // [sp+24h] [bp-44h] BYREF
  int v26; // [sp+28h] [bp-40h]
  int v27; // [sp+2Ch] [bp-3Ch]
  _DWORD *v28; // [sp+30h] [bp-38h]
  int v29; // [sp+34h] [bp-34h]
  _DWORD _38[17]; // [sp+38h] [bp-30h] BYREF
  int varg_r3; // [sp+7Ch] [bp+14h]

  _38[14] = a1;
  _38[16] = a3;
  varg_r3 = a4;
  v26 = a4;
  LOBYTE(varg_r3) = a4;
  v23 = a3;
  v7 = a2;
  _38[15] = a2;
  v22 = a1;
  v24[0] = a1;
  v27 = a3;
  v28 = a6;
  v19 = 0;
  v20 = 0;
  v25 = 0;
  v21 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v8 = v21;
  if ( v21 )
  {
    v9 = a5;
    if ( a5 < 1 || a5 > 2 )
    {
      v10 = -1073741811;
      v24[1] = -1073741811;
      return v10;
    }
    v11 = a6;
    if ( (unsigned int)a6 >= MmUserProbeAddress )
      v11 = (_DWORD *)MmUserProbeAddress;
    *v11 = *v11;
  }
  else
  {
    v9 = a5;
  }
  v12 = SeCaptureSecurityQos(a3, v8, &v19, _38);
  if ( v12 < 0 )
    return v12;
  v12 = SeCaptureObjectAttributeSecurityDescriptorPresent(a3, v8, &v20);
  if ( v12 < 0 )
    return v12;
  v12 = ObReferenceObjectByHandle(v22, 2, SeTokenObjectType, v8, v24);
  if ( v12 < 0 )
    return v12;
  if ( !v7 )
    v7 = v29;
  v13 = v24[0];
  if ( v19 )
    v14 = _38[1];
  else
    v14 = *(_DWORD *)(v24[0] + 172);
  if ( *(_DWORD *)(v24[0] + 168) == 2
    && (v9 == 2 && v14 > *(_DWORD *)(v24[0] + 172) || v9 == 1 && *(int *)(v24[0] + 172) < 2) )
  {
    ObfDereferenceObject(v24[0]);
    v10 = -1073741659;
  }
  else
  {
    v22 = 0;
    v15 = SepDuplicateToken(v24[0], v23, v26, v9, v14, v8, 0, &v22);
    v23 = v15;
    if ( v15 >= 0 )
    {
      v15 = ObInsertObjectEx(v22, 0, v7, 1, 0, 0, &v25);
      v23 = v15;
      if ( v15 >= 0 )
      {
        if ( !v20 )
          SepAppendAceToTokenObjectAcl(v22, 8, (unsigned __int16 *)SeAliasAdminsSid, (int)&SeAliasAdminsSid, v17, v18);
        ObfDereferenceObject(v22);
      }
    }
    ObfDereferenceObject(v13);
    if ( v15 >= 0 )
      *a6 = v25;
    v10 = v15;
  }
  return v10;
}
