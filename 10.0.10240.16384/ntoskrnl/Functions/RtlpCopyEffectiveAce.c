// RtlpCopyEffectiveAce 
 
int __fastcall RtlpCopyEffectiveAce(char *a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, unsigned int *a9, unsigned int a10, int *a11, unsigned int *a12, int a13, _BYTE *a14, _BYTE *a15, _BYTE *a16)
{
  char *v16; // r8
  unsigned int *v17; // r10
  _BYTE *v18; // r1
  unsigned int v20; // r3
  unsigned int v21; // r4
  int v22; // r10
  int v23; // r0
  int v24; // r2
  int v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r9
  _BYTE *v30; // r3
  char *v31; // r1
  int v32; // r8
  int v33; // r8
  int v34; // r8
  unsigned int v35; // r3
  int v36; // r3
  int v37; // r3
  unsigned __int8 *v38; // r2
  int v39; // r3
  int v40; // r3
  int v41; // lr
  int v42; // r2
  int v43; // r0
  int v44; // r3
  unsigned int v45; // r3
  unsigned int *v46; // r0
  unsigned int v47; // r9
  unsigned int v48; // [sp+4h] [bp-BCh]
  int v49; // [sp+8h] [bp-B8h]
  unsigned int *v50; // [sp+10h] [bp-B0h]
  char *v51; // [sp+1Ch] [bp-A4h]
  int v52; // [sp+20h] [bp-A0h]
  unsigned int v53; // [sp+2Ch] [bp-94h]
  unsigned int v54; // [sp+30h] [bp-90h]
  signed int v56; // [sp+38h] [bp-88h]
  int v57; // [sp+3Ch] [bp-84h]
  int v58; // [sp+40h] [bp-80h]
  char v61[2]; // [sp+50h] [bp-70h] BYREF
  int v62; // [sp+52h] [bp-6Eh]
  __int16 v63; // [sp+56h] [bp-6Ah]
  int v64; // [sp+58h] [bp-68h]
  char v65[8]; // [sp+80h] [bp-40h] BYREF
  int v66; // [sp+88h] [bp-38h]

  v16 = a1;
  v58 = 0;
  v61[0] = 1;
  v17 = a12;
  v18 = a15;
  v61[1] = 1;
  v52 = a6;
  v62 = 0;
  v64 = 0;
  v63 = 768;
  if ( !a6 )
    v52 = a4;
  if ( !a7 )
    return sub_7FB4F4();
  *a15 = 0;
  if ( a14 )
    *a14 = 0;
  *a16 = 0;
  v20 = (unsigned __int8)*a1;
  v21 = *((unsigned __int16 *)a1 + 1);
  if ( v20 <= 8 || v20 <= 0xA || v20 <= 0xE && v20 >= 0xD )
  {
    v49 = 0;
    v57 = 0;
    v51 = a1;
    v56 = 0;
    if ( v20 <= 3 )
    {
      v48 = 8;
      v22 = (int)(a1 + 8);
      goto LABEL_10;
    }
    if ( v20 >= 9 && v20 <= 0xA || v20 >= 0xD )
    {
      v22 = (int)(a1 + 8);
      v48 = 8;
      v57 = (int)&a1[RtlLengthSid((int)(a1 + 8)) + 8];
      v56 = v21 - RtlLengthSid((int)(v16 + 8)) - 8;
    }
    else if ( v20 == 4 )
    {
      v22 = (int)&a1[RtlLengthSid((int)(a1 + 12)) + 12];
      v48 = 12;
      v49 = (int)(v16 + 12);
      if ( RtlEqualPrefixSid(v16 + 12, v61) )
      {
        switch ( *((_DWORD *)v16 + 5) )
        {
          case 0:
            v37 = a4;
            goto LABEL_79;
          case 1:
            v18 = a15;
            if ( !a5 )
              goto LABEL_84;
            v38 = (unsigned __int8 *)a5;
            v39 = *(unsigned __int8 *)(a5 + 1);
            v49 = a5;
            *a15 = 1;
            v21 = v21 + 4 * v39 - 4;
            break;
          case 2:
            v37 = v52;
            goto LABEL_79;
          case 3:
            v37 = a7;
LABEL_79:
            v38 = (unsigned __int8 *)v37;
            v18 = a15;
            v21 = v21 + 4 * *(unsigned __int8 *)(v37 + 1) - 4;
            v49 = v37;
            *a15 = 1;
            break;
          default:
            v18 = a15;
LABEL_84:
            v38 = (unsigned __int8 *)(v16 + 12);
            break;
        }
        if ( !*v18 )
        {
          v48 = 4 * (v38[1] + 5);
          v49 = 0;
        }
LABEL_10:
        if ( !v21 )
        {
LABEL_35:
          v17 = a12;
          goto LABEL_36;
        }
        v23 = *((_DWORD *)v16 + 1);
        v24 = v23;
        if ( v23 < 0 )
          v24 = *a8 | v23;
        if ( (v24 & 0x40000000) != 0 )
          v24 |= a8[1];
        if ( (v24 & 0x20000000) != 0 )
          v24 |= a8[2];
        if ( (v24 & 0x10000000) != 0 )
          v24 |= a8[3];
        v25 = (unsigned __int8)*v16;
        v26 = v24 & 0xFFFFFFF;
        if ( !*v16 || v25 == 9 || v25 == 1 || v25 == 4 || v25 == 5 || v25 == 6 || v25 == 10 )
          v27 = a8[3];
        else
          v27 = a8[3] | 0x1000000;
        v28 = v26 & v27;
        if ( v28 != v23 )
          *v18 = 1;
        v29 = v28 & 0x11FFFFF;
        if ( (v28 & 0x11FFFFF) == 0 && !RtlEqualPrefixSid(v22, v61) )
        {
LABEL_57:
          v21 = 0;
          goto LABEL_35;
        }
        if ( RtlEqualPrefixSid(v22, v61) )
        {
          v36 = *(_DWORD *)(v22 + 8);
          switch ( v36 )
          {
            case 0:
              v22 = a4;
              v21 = v21 + 4 * *(unsigned __int8 *)(a4 + 1) - 4;
              v30 = a15;
              *a15 = 1;
              goto LABEL_26;
            case 1:
              if ( a5 )
              {
                v22 = a5;
                v21 = v21 + 4 * *(unsigned __int8 *)(a5 + 1) - 4;
                v30 = a15;
                *a15 = 1;
                goto LABEL_26;
              }
              break;
            case 2:
              v22 = v52;
              v21 = v21 + 4 * *(unsigned __int8 *)(v52 + 1) - 4;
              v30 = a15;
              *a15 = 1;
              goto LABEL_26;
            case 3:
              v22 = a7;
              v21 = v21 + 4 * *(unsigned __int8 *)(a7 + 1) - 4;
              v30 = a15;
              *a15 = 1;
              goto LABEL_26;
          }
        }
        v30 = a15;
LABEL_26:
        if ( v58 && *v30 )
        {
          if ( (*((_DWORD *)v16 + 2) & 1) != 0 )
          {
            v21 -= 16;
            v48 -= 16;
            memmove((int)v65, (int)v16, v48);
            v31 = v65;
            v66 &= 0xFFFFFFFD;
          }
          else
          {
            v48 -= 20;
            v21 -= 20;
            memmove((int)v65, (int)v16, v48);
            v31 = v65;
            v65[0] = *((_BYTE *)RtlBaseAceType + (unsigned __int8)*v16);
          }
        }
        else
        {
          v31 = v51;
        }
        v32 = *a11;
        if ( *a11 && v21 <= (unsigned int)*(unsigned __int16 *)(a13 + 2) - v32 + a13 )
        {
          memmove(*a11, (int)v31, v48);
          v33 = v32 + v48;
          if ( v49 )
          {
            memmove(v33, v49, 4 * (*(unsigned __int8 *)(v49 + 1) + 2));
            v33 += 4 * (*(unsigned __int8 *)(v49 + 1) + 2);
          }
          memmove(v33, v22, 4 * (*(unsigned __int8 *)(v22 + 1) + 2));
          v34 = v33 + 4 * (*(unsigned __int8 *)(v22 + 1) + 2);
          if ( v57 && v56 > 0 )
          {
            memmove(v34, v57, v56);
            v34 += v56;
          }
          v35 = v34 - *a11;
          if ( v21 < v35 )
            return 0;
          v21 = v34 - *a11;
          *(_WORD *)(*a11 + 2) = v35;
          *(_DWORD *)(*a11 + 4) = v29;
        }
        else
        {
          *a16 = 1;
        }
        goto LABEL_35;
      }
      v48 = 4 * ((unsigned __int8)v16[13] + 5);
      v49 = 0;
    }
    else
    {
      v40 = *((_DWORD *)a1 + 2);
      v41 = v40 & 1;
      if ( (v40 & 1) != 0 )
        v42 = 16;
      else
        v42 = 0;
      v43 = v40 & 2;
      if ( (v40 & 2) != 0 )
        v44 = 16;
      else
        v44 = 0;
      v22 = (int)&v16[v44 + 12 + v42];
      v48 = v44 + v42 + 12;
      if ( v43 )
      {
        if ( v41 )
          v45 = (unsigned int)(v16 + 28);
        else
          v45 = (unsigned int)(v16 + 12);
      }
      else
      {
        v45 = 0;
      }
      v53 = v45;
      if ( !a14 || !v45 )
        goto LABEL_10;
      v46 = a9;
      if ( !a9 )
        goto LABEL_57;
      v54 = 0;
      if ( !a10 )
        goto LABEL_57;
      while ( 1 )
      {
        v50 = v46 + 1;
        if ( !memcmp(v45, *v46, 16) )
          break;
        v46 = v50;
        ++v54;
        v45 = v53;
        if ( v54 >= a10 )
          goto LABEL_57;
      }
      *a14 = 1;
      if ( a3 )
      {
        v58 = 1;
      }
      else
      {
        v47 = v48;
        *a15 = 1;
        if ( (*((_DWORD *)v16 + 2) & 1) != 0 )
        {
          v21 -= 16;
          v48 -= 16;
          memmove((int)v65, (int)v16, v47 - 16);
          v51 = v65;
          v66 &= 0xFFFFFFFD;
        }
        else
        {
          v48 -= 20;
          v21 -= 20;
          memmove((int)v65, (int)v16, v47 - 20);
          v51 = v65;
          v65[0] = *((_BYTE *)RtlBaseAceType + (unsigned __int8)*v16);
        }
      }
    }
    v18 = a15;
    goto LABEL_10;
  }
  if ( v21 > (unsigned int)*(unsigned __int16 *)(a13 + 2) - *a11 + a13 )
    *a16 = 1;
  else
    memmove(*a11, (int)a1, *((unsigned __int16 *)a1 + 1));
LABEL_36:
  if ( !*a16 && v21 )
  {
    *(_BYTE *)(*a11 + 1) &= 0xE0u;
    if ( a2 )
      *(_BYTE *)(*a11 + 1) |= 0x10u;
    ++*(_WORD *)(a13 + 4);
  }
  if ( v21 > 0xFFFF )
    return 0;
  if ( !*a16 )
    *a11 += v21;
  *v17 = v21;
  return 1;
}
