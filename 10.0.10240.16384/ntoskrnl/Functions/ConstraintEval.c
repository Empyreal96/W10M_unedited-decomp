// ConstraintEval 
 
int __fastcall ConstraintEval(unsigned int a1, _DWORD *a2, _DWORD *a3, int a4, int a5)
{
  _BYTE *v9; // r0
  int v11; // r0
  unsigned int v12; // r8
  unsigned int v13; // r5
  _DWORD *v14; // r4
  int v15; // r0
  unsigned __int16 *v16; // r1
  int *v17; // r5
  int v18; // r2
  unsigned int v19; // r6
  int *v20; // r4
  int v21; // r4
  int v22; // r1
  _DWORD *v23; // r5
  void *v24; // r3
  int v25; // r0
  unsigned __int16 *v26; // r1
  int v27; // r9
  int v28; // r2
  int v29; // [sp+8h] [bp-60h] BYREF
  unsigned int v30; // [sp+Ch] [bp-5Ch] BYREF
  int v31; // [sp+10h] [bp-58h] BYREF
  int *v32; // [sp+14h] [bp-54h]
  _DWORD *v33; // [sp+18h] [bp-50h]
  int v34; // [sp+20h] [bp-48h] BYREF
  int v35[9]; // [sp+24h] [bp-44h] BYREF

  v33 = (_DWORD *)a5;
  v34 = 0;
  v9 = memset(v35, 0, sizeof(v35));
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  if ( (a4 & 0xFF00000) != 0 )
    return sub_7EBEDC(v9);
  if ( !a1 )
    return -1073741823;
  v11 = ExAllocatePoolWithTag(1, 44 * a1, 1381256262);
  v12 = v11;
  if ( !v11 )
    return -1073741801;
  if ( (*a2 & 0xFF00000) != 0 )
  {
    SimplifyFilter(a1, a2, &v30, v11);
    a1 = v30;
  }
  else
  {
    memmove(v11, (int)a2, 44 * a1);
  }
  v13 = 0;
  if ( !a1 )
    goto LABEL_29;
  v14 = (_DWORD *)v12;
  while ( 1 )
  {
    if ( v14[5] == a3[4] && !memcmp((unsigned int)(v14 + 1), (unsigned int)a3, 16) && v14[6] == a3[5] )
    {
      v15 = v14[7];
      v16 = (unsigned __int16 *)a3[6];
      if ( ((unsigned __int16 *)v15 == v16 || v15 && v16 && !wcsicmp(v15, v16)) && *v14 == a4 )
        break;
    }
    ++v13;
    v14 += 11;
    if ( v13 >= a1 )
      goto LABEL_29;
  }
  v17 = (int *)(44 * v13 + v12);
  if ( !v17 )
    goto LABEL_29;
  memmove((int)&v34, (int)(v17 + 1), 0x28u);
  switch ( a4 )
  {
    case 2:
      goto LABEL_20;
    case 1:
      v35[6] = 7;
      v35[7] = 4;
      v24 = &unk_653584;
LABEL_47:
      v35[8] = (int)v24;
      goto LABEL_20;
    case 65538:
      if ( v35[6] != 17 )
      {
LABEL_29:
        v21 = -1073741823;
        goto LABEL_26;
      }
      if ( *(char *)v35[8] == -1 )
        v24 = &unk_653582;
      else
        v24 = &unk_618D48;
      goto LABEL_47;
  }
  if ( a4 != 131074 )
    goto LABEL_29;
  v18 = v17[8];
  if ( v18 != 18 && v18 != 25 && v18 != 8210 )
    goto LABEL_29;
LABEL_20:
  v19 = 0;
  v20 = (int *)v12;
  do
  {
    if ( v20 != v17
      && v20[5] == v17[5]
      && !memcmp((unsigned int)(v20 + 1), (unsigned int)(v17 + 1), 16)
      && v20[6] == v17[6] )
    {
      v25 = v20[7];
      v26 = (unsigned __int16 *)v17[7];
      if ( (unsigned __int16 *)v25 == v26 || v25 && v26 && !wcsicmp(v25, v26) )
      {
        v27 = *v20;
        if ( *v20 != *v17 )
          goto LABEL_29;
        if ( v20[8] != v17[8] )
          goto LABEL_29;
        v28 = v20[9];
        if ( v28 != v17[9] || memcmp(v20[10], v17[10], v28) )
          goto LABEL_29;
        *v20 = v27 ^ 0x10000;
      }
    }
    ++v19;
    v20 += 11;
  }
  while ( v19 < a1 );
  *v17 ^= 0x10000u;
  v31 = 1;
  v32 = &v34;
  v21 = FilterEval(GetPropertyFromPropArray, &v31, a1, v12, &v29);
  if ( v21 < 0 )
    goto LABEL_26;
  if ( v29 )
    goto LABEL_29;
  v22 = (int)v17;
  v23 = v33;
  memmove((int)v33, v22, 0x2Cu);
  *v23 ^= 0x10000u;
LABEL_26:
  ExFreePoolWithTag(v12);
  return v21;
}
