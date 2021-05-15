// MiUpdateWsle 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiUpdateWsle(unsigned int a1, unsigned int a2, int *a3, int a4, int a5)
{
  unsigned int *v7; // r10
  unsigned int v10; // r4
  _DWORD *v11; // r2
  unsigned int v12; // r3
  unsigned int v13; // r7
  int result; // r0
  int v15; // r0
  unsigned int v16; // r4
  int v17; // r1
  unsigned int v18; // r3
  int v19; // r1
  unsigned int v20; // r2
  unsigned int v21; // r3
  int v22; // r1
  unsigned int v23; // r0
  int v24; // r2
  unsigned int *v25; // r6
  unsigned int v26; // r4 OVERLAPPED
  int v27; // r3
  unsigned int v28; // r0
  unsigned int v29; // r3
  _DWORD *v30; // r2
  unsigned int v31; // r4
  unsigned int v32; // r0
  unsigned int v33; // r2
  unsigned int v34; // r9
  unsigned int *v35; // r3
  unsigned int v36; // r6
  unsigned int v37; // r1
  unsigned int v38; // r0
  _DWORD *v39; // r7
  unsigned int v40; // r7
  int v41; // r6
  unsigned int v42; // r2
  unsigned int v43; // r3
  unsigned int v44; // r1
  unsigned int v45; // r6
  unsigned int v46; // r3
  int *v47; // r1
  int v48; // r2
  _DWORD *v49; // r1
  unsigned __int8 *v50; // r1
  unsigned int v51; // r2
  unsigned int *v52; // r2
  unsigned int v53; // r0
  unsigned int v54; // r3
  unsigned int v55; // r4 OVERLAPPED
  int v56; // r3
  unsigned int v57; // r4
  int v58; // r1
  unsigned int *v59; // r7
  unsigned int v60; // r0
  unsigned int v61; // r6
  int v62; // r2
  unsigned int *v63; // r7
  unsigned int v64; // r0
  __int64 v65; // kr00_8
  unsigned int v66; // r6
  int v67; // r2
  int v68; // r3
  unsigned int v69; // r2
  int v70; // r6
  unsigned int v71; // r0
  int v72; // r1
  int v73; // r3
  unsigned int v74; // r3
  unsigned int v75; // [sp+Ch] [bp-34h]
  int v76; // [sp+1Ch] [bp-24h]
  unsigned int varg_r0; // [sp+48h] [bp+8h]
  unsigned int varg_r1; // [sp+4Ch] [bp+Ch]
  int *varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v7 = (unsigned int *)a3[23];
  if ( a3 == &dword_634F00 )
  {
    if ( PsNtosImageBase && (a2 >= PsNtosImageBase && a2 < PsNtosImageEnd || a2 >= PsHalImageBase && a2 < PsHalImageEnd) )
    {
      ++dword_632F50;
    }
    else if ( a2 >= dword_63389C
           && *((_BYTE *)&MiState[2423]
              + ((int)(((a2 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 12 )
    {
      ++dword_632F54;
    }
  }
  v10 = a2 & 0xFFFFF000 | 1;
  v11 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v12 = v11[242];
  if ( (v12 & 0x100) != 0 )
  {
    v13 = (v12 >> 9) & 7;
  }
  else
  {
    v13 = (v11[240] >> 12) & 7;
    if ( (*(_DWORD *)(v11[84] + 192) & 0x100000) != 0 && v13 >= 2 )
      v13 = 2;
  }
  if ( a2 >= 0xC0000000 && a2 <= 0xC03FFFFF && v13 <= 5 )
    v13 = 5;
  if ( (*(_BYTE *)(a4 + 19) & 8) != 0 )
    return sub_536574();
  if ( (*(_BYTE *)(a4 + 19) & 7u) < v13 )
  {
    v50 = (unsigned __int8 *)(a4 + 15);
    do
      v51 = __ldrex(v50);
    while ( __strex(v51 | 0x80, v50) );
    __dmb(0xBu);
    if ( v51 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v68 = *(_DWORD *)(a4 + 12);
          __dmb(0xBu);
        }
        while ( v68 < 0 );
        do
          v69 = __ldrex(v50);
        while ( __strex(v69 | 0x80, v50) );
        __dmb(0xBu);
      }
      while ( v69 >> 7 );
    }
    *(_BYTE *)(a4 + 19) ^= (*(_BYTE *)(a4 + 19) ^ v13) & 7;
    __dmb(0xBu);
    v52 = (unsigned int *)(a4 + 12);
    do
      v53 = __ldrex(v52);
    while ( __strex(v53 & 0x7FFFFFFF, v52) );
  }
  v15 = a5;
  if ( v13 < 5 )
    v16 = a2 & 0xFFFFF000 | 0xE01;
  else
    v16 = v10 ^ ((unsigned __int16)a5 ^ (unsigned __int16)v10) & 0xE00;
  v17 = (v16 >> 9) & 7;
  if ( v17 )
  {
    ++a3[v17 + 4];
    if ( v17 == 7 )
    {
      MiVolunteerForTrimFirst(a3, 1);
      v15 = a5;
    }
  }
  if ( (*(_DWORD *)(a4 + 20) & 0x8000000) == 0 )
  {
    *(_DWORD *)a4 = a1;
    ++a3[16];
    if ( a2 < 0xC0000000 || a2 > 0xC03FFFFF )
      ++a3[14];
    *(_DWORD *)(v7[9] * a1 + v7[63]) = v15 | v16 | 8;
    v18 = v7[9];
    v19 = v7[63] + v18 * a1;
    if ( v18 == 16 )
    {
      v23 = (int)(16 * a1) >> 4;
      if ( v23 >= v7[1] )
      {
        v24 = 2 * ((*(_DWORD *)v19 >> 9) & 7);
        if ( *(_DWORD *)v19 < 0xC0000000 || *(_DWORD *)v19 > 0xC03FFFFF )
          ++v24;
        v25 = &v7[2 * v24];
        v55 = v25[32];
        v56 = 0xFFFFF;
        *(_QWORD *)(v19 + 4) = *(_QWORD *)(&v55 - 1);
        if ( v55 != 0xFFFFF )
        {
          *(_DWORD *)(v7[63] + 16 * v55 + 4) = v23;
LABEL_75:
          v25[32] = v23;
          result = a1;
          ++v7[v24 + 15];
          return result;
        }
LABEL_119:
        v25[31] = v23;
        goto LABEL_75;
      }
    }
    return a1;
  }
  if ( !*(_DWORD *)a4 )
  {
    do
      v20 = __ldrex((unsigned int *)a4);
    while ( !v20 && __strex(a1, (unsigned int *)a4) );
    if ( !v20 )
    {
      *(_DWORD *)(v7[9] * a1 + v7[63]) = a5 | v16 | 8;
      v21 = v7[9];
      v22 = v7[63] + v21 * a1;
      if ( v21 == 16 )
      {
        v23 = (int)(16 * a1) >> 4;
        if ( v23 >= v7[1] )
        {
          v24 = 2 * ((*(_DWORD *)v22 >> 9) & 7);
          if ( *(_DWORD *)v22 < 0xC0000000 || *(_DWORD *)v22 > 0xC03FFFFF )
            ++v24;
          v25 = &v7[2 * v24];
          v26 = v25[32];
          v27 = 0xFFFFF;
          *(_QWORD *)(v22 + 4) = *(_QWORD *)(&v26 - 1);
          if ( v26 != 0xFFFFF )
          {
            *(_DWORD *)(v7[63] + 16 * v26 + 4) = v23;
            v25[32] = v23;
            result = a1;
            ++v7[v24 + 15];
            return result;
          }
          goto LABEL_119;
        }
      }
      return a1;
    }
    v15 = a5;
  }
  v76 = v15 | v16;
  *(_DWORD *)(v7[9] * a1 + v7[63]) = v15 | v16;
  v28 = v7[9];
  v29 = v7[63];
  v30 = (_DWORD *)(v29 + v28 * a1);
  if ( v28 == 16 )
  {
    v57 = (int)(16 * a1) >> 4;
    if ( v57 >= v7[1] )
    {
      v58 = 2 * ((*v30 >> 9) & 7);
      if ( *v30 < 0xC0000000 || *v30 > 0xC03FFFFF )
        ++v58;
      v59 = &v7[2 * v58];
      v60 = v59[32];
      v30[1] = 0xFFFFF;
      v30[2] = v60;
      if ( v60 == 0xFFFFF )
        v59[31] = v57;
      else
        *(_DWORD *)(v7[63] + 16 * v60 + 4) = v57;
      v59[32] = v57;
      ++v7[v58 + 15];
    }
  }
  v31 = *(_DWORD *)a4;
  if ( *(_DWORD *)a4 == a1 )
    return a1;
  v32 = v7[4];
  v75 = v32;
  if ( v31 > v32 || v31 < v7[1] )
  {
    MiUpdateWsleHash(a2, a1, (int)a3, 0);
    return a1;
  }
  v33 = v7[9];
  v34 = v7[63];
  v35 = (unsigned int *)(v34 + v33 * v31);
  v36 = *v35;
  if ( (*v35 & 1) != 0 )
  {
    MiSwapWslEntries(v31, a1, (int)a3);
    goto LABEL_33;
  }
  if ( *v7 == v31 )
  {
    v38 = 2047;
  }
  else
  {
    if ( !v31 || (v37 = *(unsigned int *)((char *)v35 - v33), (v37 & 1) != 0) )
    {
      if ( v31 == v32 || (v54 = *(unsigned int *)((char *)v35 + v33), (v54 & 1) != 0) || v54 >> 12 != v31 )
      {
LABEL_40:
        v38 = (v36 >> 1) & 0x7FF;
        v39 = (_DWORD *)(v7[63] + v33 * v38);
        do
        {
          if ( (*v39 & 1) == 0 && *v39 >> 12 == v31 )
            break;
          v38 += 2048;
          v39 += 512 * v7[9];
        }
        while ( v38 <= v75 );
        v34 = v7[63];
        goto LABEL_44;
      }
      v38 = v31 + 1;
    }
    else
    {
      if ( v37 >> 12 != v31 )
        goto LABEL_40;
      v38 = v31 - 1;
    }
    if ( v38 == 0xFFFFF )
      goto LABEL_40;
  }
LABEL_44:
  v40 = v36 >> 12;
  if ( *v7 == v31 )
  {
    *v7 = a1;
  }
  else
  {
    v41 = v33 * v38;
    v42 = *(_DWORD *)(v33 * v38 + v34);
    if ( v42 >> 12 != v31 )
      KeBugCheckEx(26, 20485, v7);
    *(_DWORD *)(v41 + v34) = v42 & 0xFFF | (a1 << 12);
  }
  v43 = v7[9];
  v44 = v7[63];
  v45 = v44 + v43 * a1;
  if ( v43 == 16 && (int)(16 * a1) >> 4 >= v7[1] )
  {
    v65 = *(_QWORD *)(v45 + 4);
    v66 = *(_DWORD *)v45;
    v67 = 2 * ((v66 >> 9) & 7);
    if ( v66 < 0xC0000000 || v66 > 0xC03FFFFF )
      ++v67;
    if ( HIDWORD(v65) == 0xFFFFF )
      v7[2 * v67 + 31] = v65;
    else
      *(_DWORD *)(v44 + 16 * HIDWORD(v65) + 4) = v65;
    if ( (_DWORD)v65 == 0xFFFFF )
      *(_DWORD *)(v65 + 128) = HIDWORD(v65);
    else
      *(_DWORD *)(v44 + 16 * v65 + 8) = HIDWORD(v65);
    --v7[v67 + 15];
  }
  *(_DWORD *)(v7[9] * a1 + v7[63]) = 2 * (v38 & 0x7FF | (v40 << 11));
  if ( v40 != 0xFFFFF )
    *(_DWORD *)(v7[9] * v40 + v7[63]) ^= (*(_DWORD *)(v7[9] * v40 + v7[63]) ^ (2 * a1)) & 0xFFE;
  *(_DWORD *)(v7[9] * v31 + v7[63]) = v76;
  v46 = v7[9];
  v47 = (int *)(v7[63] + v46 * v31);
  if ( v46 == 16 )
  {
    v61 = (int)(16 * v31) >> 4;
    if ( v61 >= v7[1] )
    {
      v62 = 2 * (((unsigned int)*v47 >> 9) & 7);
      if ( (unsigned int)*v47 < 0xC0000000 || (unsigned int)*v47 > 0xC03FFFFF )
        ++v62;
      v63 = &v7[2 * v62];
      v64 = v63[32];
      v47[1] = 0xFFFFF;
      v47[2] = v64;
      if ( v64 == 0xFFFFF )
        v63[31] = v61;
      else
        *(_DWORD *)(v7[63] + 16 * v64 + 4) = v61;
      v63[32] = v61;
      ++v7[v62 + 15];
    }
  }
  v48 = *v47;
  v49 = (_DWORD *)a3[23];
  if ( (v48 & 4) != 0 )
  {
    v70 = v49[12];
    if ( v70 && (v70 & 1) == 0 )
    {
      if ( (v48 & 1) != 0 )
        v71 = v48 & 0xFFFFF000 | 1;
      else
        v71 = 0;
      v72 = (v71 >> 12) & 0x1FF;
      while ( 1 )
      {
        v73 = *(_DWORD *)(v70 + 8 * v72);
        if ( v71 )
        {
          if ( (v73 & 1) != 0 )
            v74 = v73 & 0xFFFFF000 | 1;
          else
            v74 = 0;
          if ( v74 == v71 )
          {
LABEL_146:
            *(_DWORD *)(v70 + 8 * v72 + 4) = v31;
            goto LABEL_33;
          }
        }
        else if ( !v73 )
        {
          goto LABEL_146;
        }
        if ( (unsigned int)++v72 >= 0x200 )
          v72 = 0;
        if ( v72 == ((v71 >> 12) & 0x1FF) )
          KeBugCheckEx(26, 266882, a3);
      }
    }
    *(_DWORD *)(v49[13] + 4 * ((unsigned int)(v48 - v49[11]) >> 12)) = v31;
  }
LABEL_33:
  if ( v31 > v7[2] )
    v7[2] = v31;
  return v31;
}
