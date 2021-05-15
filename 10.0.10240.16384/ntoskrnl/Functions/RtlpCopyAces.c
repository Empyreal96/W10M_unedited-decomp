// RtlpCopyAces 
 
int __fastcall RtlpCopyAces(int a1, _DWORD *a2, int a3, int a4, unsigned __int8 a5, int a6, int a7, int a8, int a9, char a10, char a11, int a12, unsigned int *a13, unsigned __int8 *a14)
{
  int v14; // r8
  unsigned int v15; // r4
  int v16; // r10
  _DWORD *v17; // lr
  int v18; // r2
  int v19; // r1
  unsigned __int8 *v20; // r4
  int result; // r0
  unsigned __int8 *v22; // r6
  int v23; // r3
  unsigned int v24; // r7
  unsigned int v25; // r9
  int v26; // r5
  int v27; // r0
  int v28; // r3
  int v29; // r7
  unsigned int v30; // r5
  int v31; // r8
  int v32; // r10
  BOOL v33; // r9
  int v34; // r1
  int v35; // r3
  unsigned int v36; // r3
  int v37; // r2
  _DWORD *v38; // r1
  int v39; // r2
  int v40; // r2
  int v41; // r2
  int v42; // r3
  int v43; // r2
  BOOL v44; // r2
  signed int v45; // r2
  char v46[4]; // [sp+30h] [bp-70h] BYREF
  int v47; // [sp+34h] [bp-6Ch]
  unsigned int v48; // [sp+38h] [bp-68h]
  unsigned int v49; // [sp+3Ch] [bp-64h]
  int v50; // [sp+40h] [bp-60h]
  char v51[4]; // [sp+44h] [bp-5Ch] BYREF
  unsigned __int8 *v52; // [sp+48h] [bp-58h]
  _DWORD *v53; // [sp+4Ch] [bp-54h]
  int v54; // [sp+50h] [bp-50h]
  unsigned __int8 *v55; // [sp+54h] [bp-4Ch] BYREF
  int v56; // [sp+58h] [bp-48h]
  unsigned int v57; // [sp+5Ch] [bp-44h] BYREF
  int v58; // [sp+60h] [bp-40h]
  int v59; // [sp+64h] [bp-3Ch]
  int v60; // [sp+68h] [bp-38h]
  unsigned int *v61; // [sp+6Ch] [bp-34h]
  int v62; // [sp+70h] [bp-30h]
  char v63[40]; // [sp+78h] [bp-28h] BYREF

  v53 = a2;
  v54 = a4;
  v50 = a3;
  v14 = (int)a14;
  v59 = a6;
  v15 = *a14;
  v16 = a3;
  v62 = a7;
  v17 = a2;
  v18 = a1;
  v60 = a8;
  v19 = 0;
  v56 = a1;
  v58 = a9;
  v52 = a14;
  v61 = a13;
  v47 = 0;
  if ( v15 < 2 || v15 > 4 )
    return -1073741736;
  v20 = 0;
  if ( *((_WORD *)a14 + 2) )
    return sub_7FB448();
  v22 = (unsigned __int8 *)(a1 + 8);
  v23 = *(unsigned __int16 *)(a1 + 4);
  if ( a14 + 8 <= &a14[*((unsigned __int16 *)a14 + 1)] )
    v20 = a14 + 8;
  v24 = 0;
  v48 = 0;
  v49 = 0;
  v25 = 0;
  if ( !v23 )
  {
LABEL_55:
    *v61 = v24;
    if ( v19 )
      result = -1073741789;
    else
      result = 0;
    return result;
  }
  v26 = a12;
  while ( 1 )
  {
    v27 = a5;
    if ( *v22 != 17 )
    {
      if ( v26 == 3 )
        goto LABEL_31;
      goto LABEL_11;
    }
    if ( v26 != 3 )
      goto LABEL_31;
    if ( RtlFindAceByType(v14, 17, 0) )
      break;
    v18 = v56;
    v19 = v47;
    v27 = a5;
    v17 = v53;
LABEL_11:
    switch ( v16 )
    {
      case 1:
        v24 = v48;
        if ( (v22[1] & 0x10) == 0 )
        {
LABEL_13:
          v28 = 1;
          goto LABEL_14;
        }
LABEL_75:
        v28 = 0;
LABEL_14:
        if ( !v28 )
          break;
LABEL_15:
        if ( !v27 )
        {
          v30 = *((unsigned __int16 *)v22 + 1);
          if ( v20 && v30 <= *(unsigned __int16 *)(v14 + 2) - (unsigned int)v20 + v14 )
          {
            if ( !v19 )
            {
              memmove((int)v20, (int)v22, *((unsigned __int16 *)v22 + 1));
              v36 = *v20;
              if ( (v36 <= 8 || v36 <= 0xA || v36 <= 0xE && v36 >= 0xD) && (v20[1] & 8) == 0 )
              {
                v37 = *((_DWORD *)v20 + 1);
                v38 = v53;
                if ( v37 < 0 )
                  *((_DWORD *)v20 + 1) = *v53 | v37;
                v39 = *((_DWORD *)v20 + 1);
                if ( (v39 & 0x40000000) != 0 )
                  *((_DWORD *)v20 + 1) = v38[1] | v39;
                v40 = *((_DWORD *)v20 + 1);
                if ( (v40 & 0x20000000) != 0 )
                  *((_DWORD *)v20 + 1) = v38[2] | v40;
                v41 = *((_DWORD *)v20 + 1);
                if ( (v41 & 0x10000000) != 0 )
                  *((_DWORD *)v20 + 1) = v38[3] | v41;
                *((_DWORD *)v20 + 1) &= 0xFFFFFFFu;
                v42 = *v20;
                if ( !*v20 || v42 == 1 || v42 == 4 || v42 == 5 || v42 == 6 || v42 == 9 || v42 == 10 )
                  v43 = v38[3];
                else
                  v43 = v38[3] | 0x1000000;
                *((_DWORD *)v20 + 1) &= v43;
              }
              v19 = v47;
              v20[1] &= ~(_BYTE)v54;
              ++*(_WORD *)(v14 + 4);
              goto LABEL_29;
            }
          }
          else
          {
            v19 = 1;
            v47 = 1;
          }
          goto LABEL_61;
        }
        v29 = 0;
        v30 = 0;
        v57 = 0;
        v31 = 0;
        v46[0] = 0;
        v32 = (int)v20;
        v55 = v20;
        v33 = a10 && (v22[1] & 3) != 0;
        if ( (v22[1] & 8) == 0 )
        {
          v34 = 0;
          if ( a11 && (v22[1] & 0x10) != 0 )
            v34 = 1;
          if ( !RtlpCopyEffectiveAce(v22, v34, v33, v59, v62, v60, v58, v17, 0, 0, &v55, &v57, v52, 0, v46, v51) )
            return -1073741699;
          if ( v51[0] )
          {
            v19 = 1;
            v47 = 1;
          }
          else
          {
            v19 = v47;
          }
          v29 = v57;
          v30 = v57;
          if ( !v19 && v57 )
            v20[1] &= ~(_BYTE)v54;
          v32 = (int)v55;
          v31 = (unsigned __int8)v46[0];
        }
        if ( v33 )
        {
          v63[2] = 0;
          v63[5] = 3;
          v63[1] = 0;
          v63[4] = 0;
          v63[0] = 0;
          v63[3] = 0;
          v44 = memcmp((unsigned int)(v22 + 10), (unsigned int)v63, 6) == 0;
          if ( v29 && !v31 )
          {
            v19 = v47;
            v24 = v48;
            v14 = (int)v52;
            v25 = v49;
            v16 = v50;
            if ( !v47 )
            {
              v20[1] = (v20[1] | v22[1] & 0x1F) & ~(_BYTE)v54;
              goto LABEL_29;
            }
            goto LABEL_61;
          }
          if ( *v22 > 8u || *((_DWORD *)v22 + 1) || v44 )
          {
            v45 = *((unsigned __int16 *)v22 + 1);
            v30 += v45;
            if ( v30 > 0xFFFF )
              return -1073741699;
            v14 = (int)v52;
            if ( v45 > (int)&v52[*((unsigned __int16 *)v52 + 1) - v32] )
            {
              v19 = 1;
              v47 = 1;
            }
            else
            {
              v19 = v47;
              if ( !v47 )
              {
                memmove(v32, (int)v22, v45);
                v24 = v48;
                v25 = v49;
                *(_BYTE *)(v32 + 1) = (*(_BYTE *)(v32 + 1) | 8) & ~(_BYTE)v54;
                v16 = v50;
                v19 = v47;
                ++*(_WORD *)(v14 + 4);
                goto LABEL_29;
              }
            }
            v25 = v49;
            v16 = v50;
            v24 = v48;
LABEL_61:
            v20 = (unsigned __int8 *)(*(unsigned __int16 *)(v14 + 2) + v14);
            goto LABEL_30;
          }
          v19 = v47;
        }
        v14 = (int)v52;
        v24 = v48;
        v25 = v49;
        v16 = v50;
        if ( !v19 )
        {
LABEL_29:
          v20 += v30;
LABEL_30:
          v24 += v30;
          v18 = v56;
          v26 = a12;
          v48 = v24;
          break;
        }
        goto LABEL_61;
      case 0:
        v25 = v49;
        if ( (v22[1] & 0x10) != 0 )
          goto LABEL_13;
        goto LABEL_75;
      case 2:
        goto LABEL_15;
    }
LABEL_31:
    v35 = *((unsigned __int16 *)v22 + 1);
    v49 = ++v25;
    v22 += v35;
    if ( v25 >= *(unsigned __int16 *)(v18 + 4) )
      break;
    v17 = v53;
  }
  if ( v24 <= 0xFFFF )
  {
    v19 = v47;
    goto LABEL_55;
  }
  return -1073741699;
}
