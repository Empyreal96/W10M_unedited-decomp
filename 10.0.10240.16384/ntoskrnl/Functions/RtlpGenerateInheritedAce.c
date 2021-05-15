// RtlpGenerateInheritedAce 
 
int __fastcall RtlpGenerateInheritedAce(char *a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, unsigned int *a9, unsigned int a10, unsigned int *a11, int a12, unsigned int *a13, _BYTE *a14)
{
  int v14; // r10
  int v15; // r6
  unsigned int v16; // r9
  int v17; // r8
  unsigned int v18; // r2
  unsigned int v19; // r4
  int result; // r0
  int v21; // r3
  unsigned int v22; // r2
  int v23; // r1
  char v24; // r3
  int v25; // r2
  bool v26; // zf
  signed int v27; // r2
  int v28; // r0
  unsigned int v29; // r3
  __int16 v30; // r3
  unsigned __int8 v31; // [sp+30h] [bp-40h] BYREF
  char v32[3]; // [sp+31h] [bp-3Fh] BYREF
  int v33; // [sp+34h] [bp-3Ch]
  int v34; // [sp+38h] [bp-38h] BYREF
  unsigned int v35; // [sp+3Ch] [bp-34h] BYREF
  int v36; // [sp+40h] [bp-30h]
  char *v37; // [sp+44h] [bp-2Ch]
  int v38; // [sp+48h] [bp-28h]
  int v39; // [sp+4Ch] [bp-24h]

  v39 = a4;
  v33 = 0;
  v34 = 0;
  v37 = a1;
  v38 = 0;
  v14 = 0;
  v32[0] = 0;
  v36 = a3;
  v15 = 0;
  *a14 = 0;
  v16 = 0;
  v31 = 0;
  v17 = a2 && (a1[1] & 4) == 0 && ((a1[1] & 1) != 0 || (a1[1] & 2) != 0);
  v18 = 0;
  v19 = a12 + 8;
  if ( *(_WORD *)(a12 + 4) )
  {
    while ( v19 < (unsigned int)*(unsigned __int16 *)(a12 + 2) + a12 )
    {
      ++v18;
      v19 += *(unsigned __int16 *)(v19 + 2);
      if ( v18 >= *(unsigned __int16 *)(a12 + 4) )
      {
        a1 = v37;
        goto LABEL_8;
      }
    }
    return sub_7FB7C4();
  }
LABEL_8:
  if ( v19 > (unsigned int)*(unsigned __int16 *)(a12 + 2) + a12 )
    return sub_7FB7C4();
  v35 = v19;
  if ( !v19 )
    return sub_7FB7C4();
  if ( a2 )
  {
    if ( (a1[1] & 2) == 0 )
      goto LABEL_12;
  }
  else if ( (a1[1] & 1) == 0 )
  {
LABEL_12:
    v21 = 0;
    goto LABEL_13;
  }
  v38 = v19;
  if ( !RtlpCopyEffectiveAce(
          a1,
          v36,
          v17,
          v39,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          (int *)&v35,
          (unsigned int *)&v34,
          a12,
          a14,
          v32,
          &v31) )
    return -1073741699;
  v15 = v31;
  v14 = v34;
  if ( !v31 && v34 && RtlpIsDuplicateAce(a12, (unsigned __int8 *)v19) )
  {
    v30 = *(_WORD *)(a12 + 4);
    v33 = v14;
    v14 = 0;
    a1 = v37;
    *(_WORD *)(a12 + 4) = v30 - 1;
    v21 = (unsigned __int8)v32[0];
    v16 = 0;
  }
  else
  {
    v19 = v35;
    v21 = (unsigned __int8)v32[0];
    a1 = v37;
    v16 = v14;
  }
LABEL_13:
  if ( !v17 )
    goto LABEL_14;
  if ( v21 || !v14 )
  {
    if ( (unsigned __int8)*a1 <= 8u && !*((_DWORD *)a1 + 1) )
      goto LABEL_14;
    v27 = *((unsigned __int16 *)a1 + 1);
    v16 += v27;
    if ( v16 <= 0xFFFF )
    {
      if ( v27 > (int)(*(unsigned __int16 *)(a12 + 2) - v19 + a12) )
      {
        v15 = 1;
      }
      else if ( !v15 )
      {
        memmove(v19, (int)a1, v27);
        *(_BYTE *)(v19 + 1) |= 8u;
        ++*(_WORD *)(a12 + 4);
        if ( v36 )
        {
          *(_BYTE *)(v19 + 1) |= 0x10u;
          v28 = RtlpIsDuplicateAce(a12, (unsigned __int8 *)v19);
          v22 = v33;
          if ( v28 )
          {
            --*(_WORD *)(a12 + 4);
            v29 = *((unsigned __int16 *)v37 + 1);
            if ( v22 <= v29 )
              v22 = *((unsigned __int16 *)v37 + 1);
            v16 -= v29;
          }
          goto LABEL_15;
        }
      }
      goto LABEL_14;
    }
    return -1073741699;
  }
  if ( !v15 )
  {
    v23 = v38;
    v24 = *(_BYTE *)(v38 + 1) | a1[1] & 3;
    v25 = v36;
    *(_BYTE *)(v38 + 1) = v24;
    v26 = v25 == 0;
    v22 = v33;
    if ( !v26 )
      *(_BYTE *)(v23 + 1) = v24 | 0x10;
    goto LABEL_15;
  }
LABEL_14:
  v22 = v33;
LABEL_15:
  *a11 = v16;
  *a13 = v22;
  if ( v15 )
    result = -1073741789;
  else
    result = 0;
  return result;
}
