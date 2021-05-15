// FilterEvalStrict 
 
int __fastcall FilterEvalStrict(int (__fastcall *a1)(int, int *, int *, int *, int *), int a2, unsigned int a3, _DWORD *a4, _DWORD *a5)
{
  int v7; // r7
  int v8; // r8
  int v9; // r4
  int v10; // r2
  int *v11; // r5
  unsigned int v12; // r6
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // t1
  int v17; // r1
  int v18; // r3
  bool v19; // zf
  int v21; // r7
  int v22; // r0
  int v23; // [sp+0h] [bp-50h]
  int v24; // [sp+4h] [bp-4Ch]
  int v25; // [sp+8h] [bp-48h]
  int v26; // [sp+10h] [bp-40h] BYREF
  int v27; // [sp+14h] [bp-3Ch] BYREF
  int v28; // [sp+18h] [bp-38h] BYREF
  int v29; // [sp+1Ch] [bp-34h] BYREF
  int (__fastcall *v30)(int, int *, int *, int *, int *); // [sp+20h] [bp-30h]
  int v31; // [sp+24h] [bp-2Ch]
  int v32; // [sp+28h] [bp-28h]
  int *v33; // [sp+2Ch] [bp-24h]
  unsigned int v34; // [sp+30h] [bp-20h]

  v26 = 0;
  v32 = 1;
  v7 = a2;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = a1;
  v31 = a2;
  if ( a3 < 3 )
    return -1073741811;
  v8 = *a4 & 0xFF00000;
  if ( !v8 )
    return -1073741811;
  *a5 = 0;
  v9 = FindFilterOperatorClose(a3, a4, &v26);
  if ( v9 )
    return v9;
  v10 = (int)&a4[11 * v26];
  v11 = a4 + 11;
  v33 = (int *)v10;
  v34 = a3 - v26;
  v12 = a3 - 1;
  if ( v8 == 0x100000 || v8 == 3145728 )
  {
    if ( v12 <= 1 )
    {
LABEL_13:
      v17 = 0;
      goto LABEL_14;
    }
    while ( 1 )
    {
      v26 = 0;
      *a5 = 0;
      if ( (*v11 & 0xFF00000) != 0 )
      {
        v9 = FindFilterOperatorClose(v12, v11, &v26);
        v21 = v26 + 1;
        if ( v9 )
          return v9;
        v22 = FilterEvalStrict(v30, v31, v26 + 1, v11, a5);
        v9 = v22;
        if ( v22 == -1073741823 )
        {
          v32 = 0;
        }
        else if ( v22 )
        {
          return v9;
        }
        v11 += 11 * v21;
        v12 -= v21;
        v7 = v31;
      }
      else
      {
        v9 = v30(v7, v11 + 1, &v28, &v29, &v27);
        if ( v9 == -1073741275 )
        {
          v9 = 0;
          if ( (*v11 & 0xFFF) != 1 )
          {
            v11 += 11;
            v32 = 0;
            --v12;
            goto LABEL_12;
          }
          v13 = 0;
          v15 = 0;
          v14 = 0;
          v27 = 0;
          v28 = 0;
          v29 = 0;
        }
        else
        {
          v14 = v27;
          v13 = v28;
          v15 = v29;
        }
        if ( v9 )
          return v9;
        v25 = v11[9];
        v24 = v11[10];
        v23 = v11[8];
        v16 = *v11;
        v11 += 11;
        PropertyEval(v13, v14, v15, v16, v23, v24, v25, a5);
        --v12;
      }
      if ( *a5 == (v8 == 3145728) )
      {
        v11 = v33;
        v12 = v34;
        v17 = 1;
        if ( !v12 )
          return -1073741811;
LABEL_14:
        v18 = *v11 & 0xFF00000;
        if ( v18 == 0x200000 )
        {
          v19 = v8 == 0x100000;
          goto LABEL_17;
        }
        if ( v18 == 0x400000 )
        {
          v19 = v8 == 3145728;
          goto LABEL_17;
        }
        if ( v18 != 6291456 )
          return -1073741811;
        v19 = v8 == 5242880;
LABEL_17:
        if ( !v19 )
          return -1073741811;
        if ( !v17 && !v32 && !v9 )
          v9 = -1073741823;
        return v9;
      }
LABEL_12:
      if ( v12 <= 1 )
        goto LABEL_13;
    }
  }
  return sub_7EBE14(-1073741823);
}
