// SeSubProcessToken 
 
int __fastcall SeSubProcessToken(int a1, int a2, int *a3, int a4, int a5, _BYTE *a6)
{
  int v6; // r8
  int v7; // r6
  int v9; // r10
  int v10; // r5
  int v11; // r4
  char v12; // r3
  int v13; // r7
  int v14; // r3
  int v16; // [sp+0h] [bp-1B0h]
  int v17; // [sp+4h] [bp-1ACh]
  char v18[4]; // [sp+10h] [bp-1A0h] BYREF
  unsigned __int16 *v19; // [sp+14h] [bp-19Ch] BYREF
  int v20; // [sp+18h] [bp-198h]
  int *v21; // [sp+1Ch] [bp-194h]
  int v22; // [sp+20h] [bp-190h] BYREF
  _BYTE *v23; // [sp+24h] [bp-18Ch]
  int v24[4]; // [sp+28h] [bp-188h] BYREF
  int v25[6]; // [sp+38h] [bp-178h] BYREF
  char v26[28]; // [sp+50h] [bp-160h] BYREF
  char v27[92]; // [sp+6Ch] [bp-144h] BYREF
  char v28[232]; // [sp+C8h] [bp-E8h] BYREF

  v20 = a4;
  v6 = a2;
  v21 = a3;
  *a3 = 0;
  v19 = 0;
  v25[0] = 24;
  v7 = 0;
  v25[1] = 0;
  v25[2] = 0;
  v25[3] = 0;
  v25[4] = 0;
  v25[5] = 0;
  v23 = a6;
  *a6 = 0;
  v18[0] = 0;
  v9 = 0;
  __mrc(15, 0, 13, 0, 3);
  v10 = SepDuplicateToken(a2, (int)v25, 0, 1, 0, 0, 1u, &v22);
  if ( v10 >= 0 )
  {
    v11 = v22;
    if ( (*(_DWORD *)(v22 + 176) & 0x4000) != 0 && *(_DWORD *)(v22 + 120) != a5 )
      return sub_7F67F4();
    v12 = v20;
    *(_DWORD *)(v22 + 120) = a5;
    if ( (v12 & 2) != 0 )
    {
      v13 = 1;
    }
    else
    {
      v13 = 0;
      v6 = 0;
    }
    if ( SepMandatorySubProcessToken(v6, (_DWORD *)v11, a1, &v19) < 0
      || SepSetTrustLevelForProcessToken(v11, a1, v18, v14) < 0
      || (SepTokenSingletonAttributesConfig & 3) == 3 && SepSetProcessUniqueAttribute(v11) < 0 )
    {
LABEL_28:
      JUMPOUT(0x7F6816);
    }
    if ( !v13 || v19 )
      v7 = 1;
    else
      v7 = (unsigned __int8)v18[0];
    if ( v7 )
    {
      v24[0] = 0;
      v24[2] = v11;
      v24[3] = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 176);
      v24[1] = 0;
      SepCreateAccessStateFromSubjectContext(v24, (int)v26, (int)v28, 0, 0);
    }
    else
    {
      SeCreateAccessState((int)v26, (int)v28, 0, 0);
    }
    v9 = 1;
    v10 = ObInsertObject(v11, v26, 0, 0, 0, 0);
    if ( v10 >= 0 )
    {
      SepAppendAceToTokenObjectAcl(v11, 8, (unsigned __int16 *)SeAliasAdminsSid, (int)&SeAliasAdminsSid, v16, v17);
      *(_BYTE *)(v11 + 180) = (v20 & 1) != 0;
      *v21 = v11;
      *v23 = v7;
    }
  }
  if ( v10 < 0 )
    goto LABEL_28;
  if ( v9 )
  {
    SepDeleteAccessState((int)v26);
    if ( !v7 )
      SeReleaseSubjectContext((int)v27);
  }
  return v10;
}
