// AuthzBasepConvertRelativeToAbsoluteTokenAttribute 
 
int __fastcall AuthzBasepConvertRelativeToAbsoluteTokenAttribute(unsigned int *a1, unsigned int a2, int a3, unsigned int *a4)
{
  int v7; // r4
  unsigned int v8; // r8
  unsigned int v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r10
  unsigned int v12; // r3
  unsigned int v13; // r6
  int v14; // r3
  unsigned int v15; // r4
  unsigned int *v16; // r0
  unsigned int v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r3
  unsigned int v20; // r3
  unsigned int *v21; // r10
  unsigned int v22; // r3
  unsigned int v23; // r3
  unsigned int v24; // r3
  unsigned int v25; // r3
  unsigned int v26; // r1
  unsigned int *v27; // r2
  unsigned int v28; // r3
  unsigned int v29; // r6
  int v30; // r3
  int v31; // r10
  unsigned int v32; // r9
  unsigned int v33; // r8
  int v34; // r0
  unsigned int v35; // r6
  unsigned int *i; // r9
  unsigned int v37; // r10
  unsigned int v38; // r3
  int v39; // r3
  unsigned int v40; // r10
  unsigned int v41; // r8
  unsigned int *v42; // r10
  int v43; // r0
  unsigned int v44; // r6
  unsigned int v45; // r3
  unsigned int v46; // r1
  unsigned int v47; // r3
  unsigned int v48; // r8
  unsigned int v49; // r0
  unsigned int *v50; // r6
  unsigned int v51; // r3
  _DWORD *v52; // r2
  int v54; // [sp+0h] [bp-30h] BYREF
  unsigned int v55; // [sp+4h] [bp-2Ch] BYREF
  unsigned int v56; // [sp+8h] [bp-28h] BYREF
  unsigned int v57; // [sp+Ch] [bp-24h]
  unsigned int *v58; // [sp+10h] [bp-20h]

  v55 = 0;
  v56 = 0;
  v58 = a4;
  if ( !a1 || !a3 || !a4 )
    return -1073741811;
  if ( a2 < 0x14 )
    return -1073741705;
  v8 = a1[3];
  if ( !v8 )
    return -1073741705;
  v9 = *a1;
  if ( a2 < *a1 )
    return -1073741705;
  v10 = a2 - v9;
  if ( a2 - v9 < 4 )
    return -1073741705;
  v7 = RtlStringCbLengthW((int)a1 + v9, v10, &v55);
  if ( v7 < 0 )
    return v7;
  v11 = v55 + 2;
  v57 = v55 + 2;
  if ( v55 + 2 < v55 )
    return -1073741675;
  if ( v55 + 5 < v55 + 2 )
    return -1073741675;
  v12 = (v55 + 5) & 0xFFFFFFFC;
  v13 = v12 + 24;
  v54 = v12;
  if ( v12 >= 0xFFFFFFE8 )
    return -1073741675;
  v7 = RtlULongLongToULong(4 * v8, (unsigned __int64)v8 >> 30, &v56);
  if ( v7 < 0 )
    return v7;
  if ( a2 < 0x10 || a2 - 16 < v56 )
    return -1073741705;
  v14 = *((unsigned __int16 *)a1 + 2);
  if ( *((_WORD *)a1 + 2) )
  {
    if ( *((unsigned __int16 *)a1 + 2) <= 2u )
      goto LABEL_46;
    switch ( v14 )
    {
      case 3:
        v7 = RtlULongLongToULong(8 * v8, (unsigned __int64)v8 >> 29, &v54);
        if ( v7 < 0 )
          return v7;
        if ( v54 + v13 >= v13 )
        {
          v13 += v54;
          v56 = 0;
          v21 = a1;
          while ( 1 )
          {
            v22 = v21[4];
            if ( a2 < v22 || a2 - v22 < 2 )
              return -1073741705;
            v7 = RtlStringCbLengthW((int)a1 + v22, a2 - v22, &v55);
            if ( v7 < 0 )
              return v7;
            if ( v55 + 2 < v55 )
              return -1073741675;
            v23 = v55 + 5;
            if ( v55 + 5 < v55 + 2 )
              return -1073741675;
            v54 = v23 & 0xFFFFFFFC;
            v24 = (v23 & 0xFFFFFFFC) + v13;
            if ( v24 < v13 )
              return -1073741675;
            v13 = v24;
            ++v21;
            if ( ++v56 >= v8 )
            {
              v11 = v57;
              goto LABEL_44;
            }
          }
        }
        return -1073741675;
      case 5:
        goto LABEL_22;
      case 6:
LABEL_46:
        v7 = RtlULongLongToULong(8 * v8, (unsigned __int64)v8 >> 29, &v54);
        if ( v7 < 0 )
          return v7;
        if ( v54 + v13 >= v13 )
        {
          v26 = 0;
          v13 += v54;
          v27 = a1;
          while ( 1 )
          {
            v28 = v27[4];
            if ( a2 < v28 || a2 - v28 < 8 )
              return -1073741705;
            ++v26;
            ++v27;
            if ( v26 >= v8 )
              goto LABEL_44;
          }
        }
        return -1073741675;
      case 16:
LABEL_22:
        v7 = RtlULongLongToULong(8 * v8, (unsigned __int64)v8 >> 29, &v54);
        if ( v7 < 0 )
          return v7;
        if ( v54 + v13 >= v13 )
        {
          v15 = 0;
          v13 += v54;
          v16 = a1;
          while ( 1 )
          {
            v17 = v16[4];
            if ( a2 < v17 || a2 - v17 < 4 )
              return -1073741705;
            v18 = *(unsigned int *)((char *)a1 + v17);
            if ( v17 + 4 < v17 )
              return -1073741675;
            if ( a2 - (v17 + 4) < v18 )
              return -1073741705;
            v19 = v18 + 3;
            if ( v18 + 3 < v18 )
              return -1073741675;
            v54 = v19 & 0xFFFFFFFC;
            v20 = (v19 & 0xFFFFFFFC) + v13;
            if ( v20 < v13 )
              return -1073741675;
            ++v15;
            ++v16;
            v13 = v20;
            if ( v15 >= v8 )
              goto LABEL_44;
          }
        }
        return -1073741675;
    }
  }
LABEL_44:
  v25 = *v58;
  *v58 = v13;
  if ( v25 < v13 )
    return -1073741789;
  memset((_BYTE *)a3, 0, v13);
  *(_WORD *)(a3 + 8) = *((_WORD *)a1 + 2);
  *(_WORD *)(a3 + 10) = *((_WORD *)a1 + 3);
  *(_DWORD *)(a3 + 12) = a1[2];
  *(_DWORD *)(a3 + 16) = a1[3];
  if ( v11 >= 0xFFFFFFE8 || v11 + 27 < v11 + 24 )
    return -1073741675;
  v29 = (v11 + 27) & 0xFFFFFFFC;
  memmove(a3 + 24, (int)a1 + *a1, v11);
  *(_WORD *)a3 = v11 - 2;
  v30 = *(unsigned __int16 *)(a3 + 8);
  *(_WORD *)(a3 + 2) = v11;
  *(_DWORD *)(a3 + 4) = a3 + 24;
  v31 = v29 + a3;
  if ( v30 <= 0 )
    return -1073741705;
  if ( v30 <= 2 )
    goto LABEL_81;
  if ( v30 != 3 )
  {
    if ( v30 == 5 )
    {
LABEL_61:
      v32 = *(_DWORD *)(a3 + 16);
      v7 = RtlULongLongToULong(8 * v32, (unsigned __int64)v32 >> 29, &v54);
      if ( v7 < 0 )
        return v7;
      v33 = v54 + v29;
      if ( v54 + v29 >= v29 )
      {
        v34 = v33 + a3;
        v7 = 0;
        v35 = 0;
        v56 = v33 + a3;
        *(_DWORD *)(a3 + 20) = v31;
        if ( !v32 )
          return v7;
        for ( i = a1; ; ++i )
        {
          v37 = *(unsigned int *)((char *)a1 + i[4]);
          v38 = v37 + v33;
          if ( v37 + v33 < v33 || v38 + 3 < v38 )
            break;
          v33 = (v38 + 3) & 0xFFFFFFFC;
          v7 = 0;
          *(_DWORD *)(*(_DWORD *)(a3 + 20) + 8 * v35) = 0;
          if ( v37 )
          {
            memmove(v34, (int)a1 + i[4] + 4, v37);
            *(_DWORD *)(*(_DWORD *)(a3 + 20) + 8 * v35) = v56;
          }
          v39 = *(_DWORD *)(a3 + 20);
          v34 = v33 + a3;
          v56 = v33 + a3;
          *(_DWORD *)(v39 + 8 * v35++ + 4) = v37;
          if ( v35 >= *(_DWORD *)(a3 + 16) )
            return v7;
        }
      }
      return -1073741675;
    }
    if ( v30 != 6 )
    {
      if ( v30 == 16 )
        goto LABEL_61;
      return -1073741705;
    }
LABEL_81:
    v48 = *(_DWORD *)(a3 + 16);
    v7 = RtlULongLongToULong(8 * v48, (unsigned __int64)v48 >> 29, &v54);
    if ( v7 < 0 )
      return v7;
    if ( v54 + v29 < v29 )
      return -1073741675;
    v7 = 0;
    v49 = 0;
    *(_DWORD *)(a3 + 20) = v31;
    if ( v48 )
    {
      v50 = a1;
      do
      {
        v51 = v50[4];
        ++v50;
        v52 = (_DWORD *)(*(_DWORD *)(a3 + 20) + 8 * v49++);
        *v52 = *(unsigned int *)((char *)a1 + v51);
        v52[1] = *(unsigned int *)((char *)a1 + v51 + 4);
      }
      while ( v49 < *(_DWORD *)(a3 + 16) );
    }
    return v7;
  }
  v40 = *(_DWORD *)(a3 + 16);
  v7 = RtlULongLongToULong(8 * v40, (unsigned __int64)v40 >> 29, &v54);
  if ( v7 < 0 )
    return v7;
  v41 = v54 + v29;
  if ( v54 + v29 < v29 )
    return -1073741675;
  *(_DWORD *)(a3 + 20) = v29 + a3;
  v7 = 0;
  v56 = 0;
  v54 = v41 + a3;
  if ( v40 )
  {
    v42 = a1;
    do
    {
      v43 = (int)a1 + v42[4];
      v58 = (unsigned int *)v42[4];
      v7 = RtlStringCbLengthW(v43, a2, &v55);
      if ( v7 < 0 )
        break;
      v44 = v55 + 2;
      if ( v55 + 2 < v55 )
        return -1073741675;
      v45 = v44 + v41;
      if ( v44 + v41 < v41 || v45 + 3 < v45 )
        return -1073741675;
      v41 = (v45 + 3) & 0xFFFFFFFC;
      v7 = 0;
      memmove(v54, (int)a1 + (_DWORD)v58, v55 + 2);
      v46 = v56;
      ++v42;
      *(_DWORD *)(*(_DWORD *)(a3 + 20) + 8 * v56 + 4) = v54;
      *(_WORD *)(*(_DWORD *)(a3 + 20) + 8 * v46) = v44 - 2;
      *(_WORD *)(*(_DWORD *)(a3 + 20) + 8 * v46 + 2) = v44;
      v54 = v41 + a3;
      v47 = *(_DWORD *)(a3 + 16);
      v56 = v46 + 1;
    }
    while ( v46 + 1 < v47 );
  }
  return v7;
}
