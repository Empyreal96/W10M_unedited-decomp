// SepGetAnonymousToken 
 
int __fastcall SepGetAnonymousToken(_DWORD *a1, _DWORD *a2)
{
  int v4; // r5
  _DWORD *v5; // r4
  int v6; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r2
  int v11; // r3
  _DWORD *v12; // [sp+10h] [bp-48h] BYREF
  int v13; // [sp+18h] [bp-40h]
  int v14; // [sp+1Ch] [bp-3Ch]
  int v15; // [sp+20h] [bp-38h]
  int v16; // [sp+24h] [bp-34h]
  int v17[12]; // [sp+28h] [bp-30h] BYREF

  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17[0] = 24;
  v17[1] = 0;
  v17[2] = 0;
  v17[3] = 0;
  v17[4] = 0;
  v17[5] = 0;
  v4 = SepDuplicateToken(SeAnonymousLogonTokenNoEveryone, v17, 1, 2, 2, 0, 1, &v12);
  if ( v4 < 0 )
    return v4;
  v5 = v12;
  if ( a1 )
  {
    v4 = SepSetTokenPackage(v12, a1[120]);
    if ( v4 < 0 )
      goto LABEL_12;
    v4 = SepSetTokenCapabilities(v5, a1[120], a1[121], a1[122]);
    if ( v4 < 0 )
      goto LABEL_12;
    v5[30] = a1[30];
    v4 = SepSetTokenLowboxNumber(v5, a1[120]);
    if ( v4 < 0 )
      goto LABEL_12;
    v6 = AppContainerPrivilegesEnabledExt_0();
    v4 = v6;
    if ( v6 == -1073741637 )
      return sub_51BA14();
    if ( v6 < 0 )
      goto LABEL_12;
    v8 = v5[19];
    v9 = v14;
    v5[18] &= v13;
    v5[19] = v9 & v8;
    v10 = v5[21];
    v11 = v16;
    v5[20] &= v15;
    v5[21] = v11 & v10;
    v5[44] = v5[44] & 0xFFFF9FFF | 0x4000;
  }
  *a2 = v5;
  if ( v4 < 0 )
LABEL_12:
    ObfDereferenceObjectWithTag(v5);
  return v4;
}
