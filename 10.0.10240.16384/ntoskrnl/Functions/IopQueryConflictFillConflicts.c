// IopQueryConflictFillConflicts 
 
int __fastcall IopQueryConflictFillConflicts(int a1, unsigned int a2, int a3, int a4, unsigned int a5, int a6)
{
  unsigned int v6; // r6
  unsigned int v7; // r5
  int v8; // r9
  int *v9; // r8
  int v10; // r9
  unsigned int v11; // r10
  int *v12; // r7
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r3
  unsigned int v18; // r3
  int v19; // r2
  int *i; // r4
  unsigned int v21; // r7
  unsigned int v22; // r5
  int *v23; // r10
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int *v27; // r4
  int v28; // r3
  int *v29; // lr
  int *v30; // r5
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r3
  int v35; // r1
  int v36; // r2
  int v37; // r3
  _DWORD *v38; // lr
  int v39; // r3
  int v40; // r10
  int *v41; // r2
  int v42; // t1
  unsigned int v43; // r7
  unsigned int v44; // r2
  int *v45; // lr
  unsigned int v46; // r1
  int *v47; // r9
  int v48; // r1
  int v49; // r2
  int v50; // r3
  int v51; // r3
  int *v52; // r5
  int v53; // r1
  int v54; // r2
  int v55; // r3
  int v56; // r3
  __int64 v57; // r0
  int v58; // r2
  int v59; // r4
  unsigned int v60; // r7
  int v61; // r5
  unsigned int v62; // r9
  int *v63; // r4
  unsigned int v64; // r10
  int v65; // t1
  _DWORD *v66; // r10
  int v68; // r6
  unsigned int v69; // r2
  _DWORD *v70; // r4
  unsigned int v71; // r7
  int v72; // t1
  int v74; // [sp+0h] [bp-38h] BYREF
  unsigned int v75; // [sp+4h] [bp-34h]
  int v76; // [sp+8h] [bp-30h]
  int v77; // [sp+Ch] [bp-2Ch]
  int v78; // [sp+10h] [bp-28h]
  int v79; // [sp+14h] [bp-24h]
  int *v80; // [sp+18h] [bp-20h]

  v6 = a2;
  v7 = 0;
  v75 = 0;
  v76 = a4;
  v8 = a4;
  v9 = (int *)a3;
  v79 = a1;
  v80 = (int *)a3;
  if ( a2 )
  {
    v10 = a3 + 24 * a2;
    v11 = 1;
    v12 = (int *)a3;
    do
    {
      if ( IopEliminateBogusConflict(a1, *v12) )
      {
        if ( v11 < v6 )
        {
          v14 = *(_DWORD *)(v10 - 20);
          v15 = *(_DWORD *)(v10 - 16);
          v16 = *(_DWORD *)(v10 - 12);
          *v12 = *(_DWORD *)(v10 - 24);
          v12[1] = v14;
          v12[2] = v15;
          v12[3] = v16;
          v17 = *(_DWORD *)(v10 - 4);
          v12[4] = *(_DWORD *)(v10 - 8);
          v12[5] = v17;
          v7 = v75;
        }
        --v6;
        --v7;
        v12 -= 6;
        v10 -= 24;
        --v11;
      }
      ++v7;
      v12 += 6;
      v75 = v7;
      ++v11;
    }
    while ( v7 < v6 );
    v9 = v80;
    v8 = v76;
  }
LABEL_9:
  v18 = 0;
  v19 = 2;
  for ( i = v9; ; i += 6 )
  {
    v78 = v19;
    v79 = (int)i;
    v75 = v18;
    if ( v18 >= v6 )
      break;
    if ( *i )
    {
      v21 = v19 - 1;
      if ( v19 - 1 < v6 )
      {
        v22 = v19;
        v74 = (int)&v9[6 * v6];
        v77 = v19;
        v23 = i + 6;
        while ( 1 )
        {
          if ( IopEliminateBogusConflict(*i, *v23) )
          {
            if ( v22 < v6 )
            {
              v24 = *(_DWORD *)(v74 - 20);
              v25 = *(_DWORD *)(v74 - 16);
              v26 = *(_DWORD *)(v74 - 12);
              v27 = (int *)(v74 - 8);
              *v23 = *(_DWORD *)(v74 - 24);
              v23[1] = v24;
              v23[2] = v25;
              v23[3] = v26;
              v28 = v27[1];
              v23[4] = *v27;
              v23[5] = v28;
              i = (int *)v79;
              v22 = v77;
            }
            --v6;
            --v21;
            v74 -= 24;
            --v22;
            v23 -= 6;
          }
          else if ( IopEliminateBogusConflict(*v23, *i) )
          {
            v29 = &v9[6 * v21];
            v30 = &v9[6 * v75];
            v31 = v29[1];
            v32 = v29[2];
            v33 = v29[3];
            *v30 = *v29;
            v30[1] = v31;
            v30[2] = v32;
            v30[3] = v33;
            v30 += 4;
            v34 = v29[5];
            *v30 = v29[4];
            v30[1] = v34;
            if ( v21 + 1 < v6 )
            {
              v35 = v9[6 * v6 - 5];
              v36 = v9[6 * v6 - 4];
              v37 = v9[6 * v6 - 3];
              *v29 = v9[6 * v6 - 6];
              v29[1] = v35;
              v29[2] = v36;
              v29[3] = v37;
              v38 = v29 + 4;
              v39 = v9[6 * v6 - 1];
              *v38 = v9[6 * v6 - 2];
              v38[1] = v39;
            }
            --v6;
            goto LABEL_9;
          }
          ++v21;
          v77 = ++v22;
          v23 += 6;
          if ( v21 >= v6 )
          {
            v19 = v78;
            break;
          }
        }
      }
    }
    ++v19;
    v18 = v75 + 1;
  }
  v40 = 0;
  if ( v6 )
  {
    v41 = v9;
    while ( 1 )
    {
      v42 = *v41;
      v41 += 6;
      if ( !v42 )
        break;
      if ( ++v40 >= v6 )
        goto LABEL_42;
    }
    v43 = v40 + 1;
    v44 = v40 + 1;
    v79 = v40 + 1;
    if ( v40 + 1 < v6 )
    {
      v45 = &v9[6 * v43];
      v46 = v40 + 2;
      v47 = &v9[6 * v6];
      v78 = v40 + 2;
      do
      {
        if ( !*v45 )
        {
          if ( v46 < v6 )
          {
            v48 = *(v47 - 5);
            v49 = *(v47 - 4);
            v50 = *(v47 - 3);
            *v45 = *(v47 - 6);
            v45[1] = v48;
            v45[2] = v49;
            v45[3] = v50;
            v51 = *(v47 - 1);
            v45[4] = *(v47 - 2);
            v45[5] = v51;
            v46 = v78;
            v44 = v79;
          }
          --v6;
          --v44;
          --v46;
          v47 -= 6;
          v45 -= 6;
        }
        ++v44;
        v78 = ++v46;
        v79 = v44;
        v45 += 6;
      }
      while ( v44 < v6 );
      v8 = v76;
    }
    if ( v6 != 1 )
    {
      if ( v43 < v6 )
      {
        v52 = &v9[6 * v40];
        v53 = v9[6 * v6 - 5];
        v54 = v9[6 * v6 - 4];
        v55 = v9[6 * v6 - 3];
        *v52 = v9[6 * v6 - 6];
        v52[1] = v53;
        v52[2] = v54;
        v52[3] = v55;
        v52 += 4;
        v56 = v9[6 * v6 - 1];
        *v52 = v9[6 * v6 - 2];
        v52[1] = v56;
      }
      --v6;
    }
  }
LABEL_42:
  HIDWORD(v57) = a6;
  v58 = 32;
  v59 = 0;
  v60 = 0;
  v61 = 0;
  v74 = 32;
  v79 = 0;
  if ( a6 )
  {
    if ( a5 >= 0x4A )
    {
      v59 = 1;
      v60 = 1;
      v79 = 1;
      v61 = 1;
    }
    v58 = 74;
    v74 = 74;
  }
  if ( v6 )
  {
    v62 = v74;
    v63 = v9;
    v64 = v6;
    do
    {
      v65 = *v63;
      v63 += 6;
      v74 = 0;
      IopQueryConflictFillString(v65, 0, &v74);
      v62 += 2 * (v74 + 20);
      if ( v62 <= a5 )
      {
        ++v60;
        v61 += v74;
      }
      --v64;
    }
    while ( v64 );
    v59 = v79;
    v9 = v80;
    HIDWORD(v57) = a6;
    v74 = v62;
    v8 = v76;
    v58 = v74;
  }
  *(_DWORD *)(v8 + 8) = v59 + v6;
  *(_DWORD *)(v8 + 12) = v60;
  v66 = (_DWORD *)(v8 + 40 * v60 + 24);
  *(_DWORD *)(v8 + 16) = v58;
  if ( (unsigned int)v66 > a5 + v8 - 8 )
    return -1073741789;
  v68 = 0;
  LODWORD(v57) = 0;
  *v66 = -1;
  if ( v59 )
  {
    *(_QWORD *)(v8 + 24) = v57;
    *(_DWORD *)(v8 + 32) = 0;
    *(_DWORD *)(v8 + 40) = 0;
    *(_DWORD *)(v8 + 44) = 0;
    *(_DWORD *)(v8 + 48) = 0;
    *(_DWORD *)(v8 + 52) = 0;
    *(_DWORD *)(v8 + 56) = 0;
    --v61;
    v68 = 1;
    *(_WORD *)(v8 + 40 * v60 + 28) = 0;
    v69 = 1;
  }
  else
  {
    v69 = 0;
  }
  if ( v69 < v60 )
  {
    v70 = (_DWORD *)(v8 + 40 * v69);
    v71 = v60 - v69;
    do
    {
      v70[6] = v68;
      v70[7] = 0;
      v70[8] = 0;
      v70[10] = 1;
      v70[11] = 0;
      v70 += 10;
      v70[2] = 0;
      v70[3] = 0;
      v70[4] = 0;
      v72 = *v9;
      v9 += 6;
      v74 = v61;
      IopQueryConflictFillString(v72, (char *)v66 + 2 * v68 + 4, &v74);
      v61 -= v74;
      v68 += v74;
      --v71;
    }
    while ( v71 );
  }
  *((_WORD *)v66 + v68 + 2) = 0;
  return 0;
}
