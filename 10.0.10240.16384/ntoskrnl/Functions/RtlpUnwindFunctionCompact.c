// RtlpUnwindFunctionCompact 
 
int __fastcall RtlpUnwindFunctionCompact(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, int a7)
{
  unsigned int v9; // r3
  unsigned int v10; // r9
  unsigned int v11; // r4
  int v12; // r8
  unsigned int v13; // r7
  unsigned int v14; // lr
  unsigned int v16; // r4
  int result; // r0
  int v18; // r5
  unsigned int v19; // r2
  int v20; // r3
  int v21; // r3
  int v22; // r3
  unsigned int v23; // r1
  unsigned int v24; // r3
  int v25; // r3
  int v26; // r3
  int v27; // r3
  unsigned int v28; // r3
  int v29; // r9
  unsigned int v30; // r3
  unsigned int v31; // r2
  unsigned int v32; // r4
  int v33; // [sp+0h] [bp-38h]
  int v34; // [sp+4h] [bp-34h]
  int v35; // [sp+4h] [bp-34h]
  unsigned int v36; // [sp+8h] [bp-30h]
  int v37; // [sp+Ch] [bp-2Ch]
  int v38; // [sp+10h] [bp-28h]
  int v39; // [sp+14h] [bp-24h]
  int v40; // [sp+14h] [bp-24h]
  unsigned int v41; // [sp+18h] [bp-20h]

  v9 = a2[1];
  *a3 |= 0x20000000u;
  v38 = (v9 >> 13) & 3;
  v39 = (v9 >> 21) & 1;
  v10 = (v9 >> 2) & 0x7FF;
  v11 = dword_40A080[HIWORD(v9) & 0x3F];
  v12 = (v9 >> 15) & 1;
  v13 = v9 >> 22;
  v14 = (unsigned __int16)v11;
  v16 = HIWORD(v11);
  result = 0;
  v18 = v14;
  if ( !v38 )
    v14 = v14 & 0xFFFF3FFF | 0x8000;
  if ( v13 >= 0x3F4 )
  {
    v18 |= (v9 >> 22) & 4;
    v14 |= (v9 >> 22) & 8;
    v13 = ((v9 >> 22) & 3) + 1;
  }
  v19 = (a1 - (*a2 & 0xFFFFFFFE)) >> 1;
  if ( v19 >= 9 || (v9 & 3) == 2 )
    goto LABEL_73;
  if ( v12 )
    return sub_547C5C(0);
  v37 = 0;
  if ( v18 )
    v20 = (v18 & 0xBF00) != 0 ? 2 : 1;
  else
    v20 = 0;
  v33 = v20;
  if ( v39 )
    v21 = (v18 & 0xFFFFB7FF) != 0 ? 2 : 1;
  else
    v21 = 0;
  v40 = v21;
  v22 = v16 ? 2 : 0;
  v34 = v22;
  if ( v13 && (v18 & 4) == 0 )
    v23 = v13 >= 0x80 ? 2 : 1;
  else
    v23 = 0;
  v36 = v23;
  v24 = v40 + v23 + v22 + v33;
  if ( v19 >= v24 || (v30 = v24 - v19, (v41 = v30) == 0) )
  {
LABEL_73:
    if ( v19 + 8 < v10 || v38 == 3 )
      goto LABEL_8;
    if ( !v13 || (v14 & 8) != 0 )
      v23 = 0;
    else
      v23 = v13 >= 0x80 ? 2 : 1;
    v36 = v23;
    v25 = v16 ? 2 : 0;
    v35 = v25;
    v40 = 0;
    if ( !v14 || v12 && !v38 && v14 == 0x8000 )
      v26 = 0;
    else
      v26 = (v14 & 0x7F00) != 0 ? 2 : 1;
    v33 = v26;
    if ( v12 )
      v27 = v38 ? 1 : 2;
    else
      v27 = 0;
    v37 = v27;
    v28 = v10 - v23 - v35 - v33 - v27 - v38;
    v29 = v35;
    if ( v19 <= v28 )
      goto LABEL_8;
    v31 = v19 - v28;
    v41 = v31;
    v18 = v14 & 0x1FFF;
    if ( !v12 )
      v18 |= (v14 >> 1) & 0x4000;
    if ( !v31 )
    {
LABEL_8:
      a3[14] += 4 * v13;
      if ( v16 )
        result = RtlpPopVfpRegisterRange(a3, 8, v16 + 7, a7);
      if ( (v18 & 0xFFF0) != 0 && !result )
        result = RtlpPopRegisterMask(a3, v18 & 0xFFF0, a7);
      if ( !v12 )
        goto LABEL_14;
      goto LABEL_18;
    }
  }
  else
  {
    v29 = v34;
    v31 = v30;
  }
  if ( v23 >= v31 && v29 )
  {
    result = RtlpPopVfpRegisterRange(a3, 8, v16 + 7, a7);
    v23 = v36;
    v31 = v41;
  }
  v32 = v40 + v23 + v29;
  if ( v32 >= v31 && v33 )
  {
    if ( !v23 )
      a3[14] += 4 * v13;
    if ( (v18 & 0xFFF0) != 0 && !result )
    {
      result = RtlpPopRegisterMask(a3, v18 & 0xFFF0, a7);
      v31 = v41;
    }
  }
  if ( v32 + v33 < v31 || !v37 )
    goto LABEL_14;
  if ( v37 == 2 && !result )
    result = RtlpPopRegisterMask(a3, 0x4000, a7);
LABEL_18:
  a3[14] += 16;
LABEL_14:
  if ( !result )
  {
    a3[16] = a3[15];
    *a4 = a3[14];
    if ( a5 )
      *a5 = 0;
    *a6 = 0;
  }
  return result;
}
