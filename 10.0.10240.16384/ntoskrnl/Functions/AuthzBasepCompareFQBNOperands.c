// AuthzBasepCompareFQBNOperands 
 
int __fastcall AuthzBasepCompareFQBNOperands(int a1, int a2, int *a3, int a4)
{
  int v6; // r8
  int v7; // r3
  unsigned int v8; // r9
  int v9; // r6
  int v10; // r10
  int *v11; // r2
  _DWORD *v12; // r1
  int *v13; // r1
  int *v14; // r2
  _DWORD *v15; // r2
  int *v16; // r1
  _DWORD *v17; // r0
  int v18; // r0
  int v19; // r6
  int v20; // r1
  unsigned int v21; // r4
  _DWORD *v22; // r5
  unsigned __int8 v24; // [sp+9h] [bp-67h] BYREF
  _BYTE v25[2]; // [sp+Ah] [bp-66h] BYREF
  int v26; // [sp+Ch] [bp-64h] BYREF
  int v27; // [sp+10h] [bp-60h]
  int v28; // [sp+14h] [bp-5Ch]
  int v29; // [sp+18h] [bp-58h] BYREF
  int v30; // [sp+1Ch] [bp-54h]
  int v31; // [sp+20h] [bp-50h]
  int v32; // [sp+24h] [bp-4Ch]
  _DWORD v33[2]; // [sp+28h] [bp-48h] BYREF
  _DWORD v34[2]; // [sp+30h] [bp-40h] BYREF
  _DWORD v35[6]; // [sp+38h] [bp-38h] BYREF
  _DWORD *v36; // [sp+50h] [bp-20h]
  int varg_r0; // [sp+78h] [bp+8h]
  int varg_r1; // [sp+7Ch] [bp+Ch]
  int *varg_r2; // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v27 = a2;
  v28 = a1;
  LOBYTE(varg_r0) = a1;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v25[0] = 0;
  v25[1] = 0;
  v24 = 0;
  *a3 = 0;
  v33[1] = 0;
  v34[1] = 0;
  v6 = AuthzBasepGetOperandStringCaseForEvaluation(a2, &v24);
  if ( v6 < 0 )
  {
LABEL_2:
    v7 = -1;
LABEL_3:
    *a3 = v7;
    goto LABEL_32;
  }
  v8 = 0;
  v9 = a2;
  v10 = v24;
  do
  {
    if ( *(_DWORD *)(v9 + 12) == 1 )
    {
      if ( !*(_BYTE *)(v9 + 4) )
      {
        v6 = -1073741406;
        goto LABEL_2;
      }
      v6 = AuthzBasepGetConstantOperand(*(_DWORD *)(v9 + 24), *(_DWORD *)(v9 + 20), v35, &v26);
      if ( v6 < 0 )
        goto LABEL_2;
      if ( LOWORD(v35[0]) != 3 )
        goto LABEL_2;
      v6 = AuthzBasepUnicodeStringFromOperandValue(v35, v10 == 0, (unsigned __int16 *)&v33[2 * v8], &v25[v8]);
      if ( v6 < 0 )
        goto LABEL_2;
      v6 = AuthzBasepGetConstantOperand(*(_DWORD *)(v9 + 24) + v26, *(_DWORD *)(v9 + 20) - v26, v35, &v26);
      if ( v6 < 0 )
        goto LABEL_2;
      if ( LOWORD(v35[0]) != 2 )
        goto LABEL_2;
      v11 = &v29 + 2 * v8;
      v12 = v36;
      *v11 = *v36;
      v11[1] = v12[1];
      if ( *((_BYTE *)v12 + 8) == 2 )
        goto LABEL_2;
    }
    else
    {
      v13 = *(int **)(*(_DWORD *)(v9 + 16) + 24);
      v14 = &v29 + 2 * v8;
      *v14 = *v13;
      v14[1] = v13[1];
      v15 = &v33[2 * v8];
      *v15 = v13[2];
      v15[1] = v13[3];
    }
    ++v8;
    v9 += 28;
  }
  while ( v8 < 2 );
  if ( *(_DWORD *)(v27 + 40) == 1 )
  {
    v16 = v33;
    v17 = v34;
  }
  else
  {
    v16 = v34;
    v17 = v33;
  }
  v18 = RtlIsNameInExpression((int)v17, v16, v10 == 0, 0);
  v19 = v28;
  v20 = v29;
  *a3 = v29 == v31 && v30 == v32 && v18;
  if ( v19 == 129 )
  {
    v7 = *a3 != 1;
    goto LABEL_3;
  }
  if ( v19 != 128 )
  {
    if ( v18 )
      *a3 = AuthzBasepCompareUnsigned(v19, v20, v20);
    else
      *a3 = 0;
  }
LABEL_32:
  v21 = 0;
  v22 = v33;
  do
  {
    if ( v25[v21] )
      ExFreePoolWithTag(v22[1]);
    ++v21;
    v22 += 2;
  }
  while ( v21 < 2 );
  return v6;
}
