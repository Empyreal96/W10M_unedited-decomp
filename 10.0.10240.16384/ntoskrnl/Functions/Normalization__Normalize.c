// Normalization__Normalize 
 
int __fastcall Normalization__Normalize(int a1, int a2, int a3, int a4, int a5, int *a6)
{
  unsigned __int16 *v6; // r4
  int v8; // r5
  int v9; // r1
  int v10; // r3
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v15; // [sp+0h] [bp-60h] BYREF
  int v16; // [sp+4h] [bp-5Ch]
  unsigned __int16 *v17; // [sp+8h] [bp-58h]
  int v18; // [sp+Ch] [bp-54h]
  int v19; // [sp+10h] [bp-50h]
  int v20; // [sp+14h] [bp-4Ch]
  int v21; // [sp+18h] [bp-48h]
  int v22; // [sp+1Ch] [bp-44h]
  int v23; // [sp+20h] [bp-40h]
  int v24; // [sp+24h] [bp-3Ch]
  char v25; // [sp+28h] [bp-38h]
  char v26; // [sp+29h] [bp-37h]
  int v27; // [sp+2Ch] [bp-34h]
  int v28; // [sp+30h] [bp-30h]
  char v29; // [sp+34h] [bp-2Ch]
  char v30; // [sp+35h] [bp-2Bh]
  int v31; // [sp+44h] [bp-1Ch]

  v6 = (unsigned __int16 *)a2;
  if ( !a2 || !a4 || !a6 )
    return -1073741811;
  v22 = a3;
  v15 = a2;
  v16 = a2 + 2 * a3;
  v17 = (unsigned __int16 *)a2;
  v18 = a4;
  v20 = a4;
  v21 = a5;
  v24 = a4 - 2;
  v27 = a4;
  v28 = 0;
  v23 = 0;
  v26 = 0;
  v25 = 0;
  v30 = 0;
  v29 = 0;
  *a6 = 0;
  v19 = a4 + 2 * a5;
  v31 = a1;
  v8 = 0;
  while ( !NormBuffer__EndOfInput((int)&v15) )
  {
    if ( v8 )
      goto LABEL_17;
    v9 = *v6;
    v10 = *(_DWORD *)(a1 + 16);
    v17 = v6 + 1;
    if ( v9 < v10
      || (v11 = *(_DWORD *)(a1 + 20), v12 = *(unsigned __int8 *)((v9 >> 7) + v11), !*(_BYTE *)((v9 >> 7) + v11))
      || v12 == 251 && *(_BYTE *)(a1 + 61) )
    {
      if ( !NormBuffer__Append((int)&v15, v9) )
      {
        v6 = v17;
        v8 = -1073741789;
        break;
      }
    }
    else
    {
      v8 = Normalization__NormalizeCharacter(a1, v9, v12, &v15);
    }
    v6 = v17;
  }
  if ( !v8 )
  {
    v13 = (v20 - v18) >> 1;
    goto LABEL_20;
  }
LABEL_17:
  if ( v8 == -1073741789 )
  {
    *a6 = Normalization__GuessBetterCharCount(a1, ((int)v6 - v15) >> 1, ((v16 - (int)v6) >> 1) + 1, (v20 - v18) >> 1);
    return v8;
  }
  v13 = (((int)v6 - v15) >> 1) - 1;
LABEL_20:
  *a6 = v13;
  return v8;
}
