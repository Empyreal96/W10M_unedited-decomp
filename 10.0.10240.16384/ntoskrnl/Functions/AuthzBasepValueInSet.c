// AuthzBasepValueInSet 
 
int __fastcall AuthzBasepValueInSet(int *a1, int a2, int *a3, int a4)
{
  int *v4; // r0
  int v5; // r4
  int v6; // r5
  int v7; // r6
  int v8; // r7
  int v9; // r4
  int v10; // r5
  int v11; // r6
  int v15; // r5
  int v16; // r0
  int v17; // r4
  int v18; // r0
  int v19; // r0
  int v20; // r3
  int v21; // r0
  int v22; // r0
  int v24; // [sp+0h] [bp-78h] BYREF
  _DWORD v25[7]; // [sp+20h] [bp-58h] BYREF
  __int16 v26; // [sp+3Ch] [bp-3Ch] BYREF
  char v27; // [sp+40h] [bp-38h]
  int v28; // [sp+44h] [bp-34h]
  int v29; // [sp+4Ch] [bp-2Ch]
  int v30; // [sp+50h] [bp-28h]
  int v31; // [sp+54h] [bp-24h]

  v5 = *a1;
  v6 = a1[1];
  v7 = a1[2];
  v8 = a1[3];
  v4 = a1 + 4;
  v25[0] = v5;
  v25[1] = v6;
  v25[2] = v7;
  v25[3] = v8;
  v9 = *v4;
  v10 = v4[1];
  v11 = v4[2];
  *a3 = 0;
  v25[4] = v9;
  v25[5] = v10;
  v25[6] = v11;
  while ( 1 )
  {
    v15 = *(_DWORD *)(a2 + 8);
    v16 = AuthzBasepGetNextValue(a2, (int)&v26);
    v17 = v16;
    if ( v16 == -2147483622 )
      break;
    if ( v16 < 0 )
      goto LABEL_12;
    if ( LOWORD(v25[0]) == 4 )
    {
      v18 = AuthzBasepGetNextValue(a2, (int)&v24);
      v17 = v18;
      if ( v18 == -2147483622 )
        break;
      if ( v18 < 0 )
        goto LABEL_12;
      v27 = *(_BYTE *)(a2 + 4);
      v26 = *(_WORD *)a2;
      v29 = *(_DWORD *)(a2 + 16);
      v28 = 0;
      v30 = *(_DWORD *)(a2 + 8);
      v31 = *(_DWORD *)(a2 + 24) + v15;
    }
    if ( AuthzBasepOperandValueTypesCompatible((unsigned __int16 *)v25) )
    {
      v19 = AuthzBasepGetOperandTypeForEvaluation((unsigned __int16 *)v25);
      if ( v19 )
      {
        if ( v19 <= 2 )
          goto LABEL_25;
        switch ( v19 )
        {
          case 3:
            v22 = AuthzBasepCompareUnicodeStringOperands(128, (int)v25, a3, v20);
LABEL_23:
            v17 = v22;
            if ( v22 < 0 )
              goto LABEL_12;
            break;
          case 4:
            v22 = AuthzBasepCompareFQBNOperands(128, (int)v25, a3, v20);
            goto LABEL_23;
          case 5:
LABEL_20:
            v21 = AuthzBasepCompareOctetStringOperands(128, v25);
LABEL_26:
            *a3 = v21;
            break;
          case 6:
LABEL_25:
            v21 = AuthzBasepCompareIntegerOperands(128, v25);
            goto LABEL_26;
          case 16:
            goto LABEL_20;
        }
      }
      if ( *a3 == 1 )
        goto LABEL_11;
    }
    else if ( !a4 )
    {
      v17 = -1073741406;
LABEL_11:
      if ( v17 >= 0 )
        goto LABEL_30;
LABEL_12:
      *a3 = -1;
      goto LABEL_30;
    }
  }
  v17 = 0;
LABEL_30:
  AuthzBasepRestartOperandValueEnumeration((_DWORD *)a2);
  return v17;
}
