// AuthzBasepCompareUnicodeStringOperands 
 
int __fastcall AuthzBasepCompareUnicodeStringOperands(int a1, int a2, int *a3, int a4)
{
  int v7; // r10
  _DWORD *v8; // r8
  unsigned __int16 *v9; // r9
  int v10; // r5
  _DWORD *v11; // r2
  int v12; // r1
  int v13; // r8
  unsigned __int16 *v14; // r1
  unsigned __int16 *v15; // r0
  int v16; // r0
  int v17; // r3
  int v18; // r4
  unsigned __int16 *v19; // r5
  char v21[2]; // [sp+0h] [bp-40h] BYREF
  char v22[2]; // [sp+2h] [bp-3Eh] BYREF
  int v23; // [sp+4h] [bp-3Ch]
  int v24; // [sp+8h] [bp-38h]
  unsigned __int16 v25; // [sp+10h] [bp-30h] BYREF
  int v26; // [sp+14h] [bp-2Ch]
  unsigned __int16 v27; // [sp+18h] [bp-28h] BYREF
  int v28; // [sp+1Ch] [bp-24h]
  int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  int *varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v24 = a2;
  LOBYTE(varg_r0) = a1;
  v22[0] = 0;
  v22[1] = 0;
  v26 = 0;
  v28 = 0;
  *a3 = 0;
  v23 = AuthzBasepGetOperandStringCaseForEvaluation(a2, v21);
  if ( v23 < 0 )
  {
LABEL_40:
    v17 = -1;
    goto LABEL_41;
  }
  v7 = 0;
  v8 = (_DWORD *)a2;
  v9 = &v25;
  v10 = (unsigned __int8)v21[0];
  do
  {
    if ( v8[3] != 1 )
    {
      if ( v10 )
      {
        v11 = *(_DWORD **)(v8[4] + 24);
        *(_DWORD *)v9 = *v11;
        *((_DWORD *)v9 + 1) = v11[1];
        goto LABEL_10;
      }
LABEL_7:
      v12 = 1;
      goto LABEL_9;
    }
    if ( !v10 )
      goto LABEL_7;
    v12 = 0;
LABEL_9:
    v23 = AuthzBasepUnicodeStringFromOperandValue(v8, v12, v9, &v22[v7]);
    if ( v23 < 0 )
      goto LABEL_40;
LABEL_10:
    ++v7;
    v9 += 4;
    v8 += 7;
  }
  while ( v7 < 2 );
  if ( (unsigned int)(a1 - 128) > 1 )
  {
    if ( v10 )
      v16 = AuthzBasepCompareUnicodeStringCaseSensitive(&v25, &v27);
    else
      v16 = RtlCompareUnicodeString(&v25, &v27, 1);
    *a3 = v16;
    switch ( a1 )
    {
      case 130:
        if ( v16 < 0 )
        {
LABEL_29:
          v17 = 1;
LABEL_41:
          *a3 = v17;
          goto LABEL_42;
        }
        break;
      case 131:
        if ( *a3 <= 0 )
          goto LABEL_29;
        break;
      case 132:
        if ( *a3 > 0 )
          goto LABEL_29;
        break;
      case 133:
        if ( *a3 >= 0 )
          goto LABEL_29;
        break;
      default:
LABEL_42:
        v13 = v23;
        goto LABEL_43;
    }
    v17 = 0;
    goto LABEL_41;
  }
  if ( *(_DWORD *)(v24 + 12) == 2 || *(_DWORD *)(v24 + 40) == 2 )
  {
    if ( *(_DWORD *)(v24 + 40) == 1 )
    {
      v14 = &v25;
      v15 = &v27;
    }
    else
    {
      v14 = &v27;
      v15 = &v25;
    }
    *a3 = RtlIsNameInExpression((int)v15, (int *)v14, v10 == 0, 0);
    v13 = v23;
  }
  else
  {
    if ( v10 )
      *a3 = AuthzBasepEqualUnicodeStringCaseSensitive(&v25, &v27);
    else
      *a3 = RtlEqualUnicodeString(&v25, &v27, 1);
    v13 = v23;
  }
  if ( a1 == 129 )
    *a3 = *a3 != 1;
LABEL_43:
  v18 = 0;
  v19 = &v25;
  do
  {
    if ( v22[v18] )
      ExFreePoolWithTag(*((_DWORD *)v19 + 1));
    ++v18;
    v19 += 4;
  }
  while ( v18 < 2 );
  return v13;
}
