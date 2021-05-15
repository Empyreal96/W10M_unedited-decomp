// sub_5BD1E0 
 
int __fastcall sub_5BD1E0(unsigned __int16 *a1, int a2, int a3, unsigned int a4, unsigned int a5, _BYTE *a6)
{
  _BYTE *v6; // r8
  int v8; // r5
  int v9; // r6
  BOOL v10; // r4
  bool v11; // zf
  char *v12; // r2
  unsigned int v13; // r0
  unsigned __int16 *v14; // r10
  char *j; // r2
  unsigned int v16; // r9
  int v17; // r2
  unsigned int v18; // r6
  char *v19; // r2
  unsigned int v20; // r0
  unsigned __int8 *v21; // r10
  char *i; // r2
  unsigned int v23; // r9
  int v24; // r2
  unsigned int v25; // r6
  bool v26; // zf
  unsigned int v27; // r3
  bool v28; // cc
  unsigned int v29; // r3
  bool v30; // cc
  unsigned int v31; // r3
  bool v32; // cf
  unsigned int v33; // r3
  bool v34; // cf
  unsigned int v35; // r2
  __int64 v36; // r0
  unsigned int v37; // r3
  unsigned int v38; // r3
  __int64 v39; // r0
  __int64 v40; // r2
  unsigned int v41; // r2
  int v42; // r4
  unsigned __int64 v44; // [sp+8h] [bp-38h]
  int v45; // [sp+8h] [bp-38h]
  int v46; // [sp+8h] [bp-38h]

  v6 = (_BYTE *)a4;
  if ( !a5 )
    return 0;
  v8 = 0;
  v9 = *(unsigned __int16 *)(a3 + 2);
  LOWORD(v44) = *(_WORD *)(a3 + 2);
  switch ( a2 )
  {
    case 1:
      if ( sub_5BD654(a4) )
      {
        v36 = *(_QWORD *)(a3 + 8);
        v41 = *(_DWORD *)(a3 + 16);
        v42 = *(_DWORD *)(a3 + 20);
        switch ( v9 )
        {
          case 0:
            if ( (_DWORD)v44 != (_DWORD)v36 )
              goto LABEL_141;
            v11 = HIDWORD(v44) == HIDWORD(v36);
            goto LABEL_140;
          case 1:
            if ( (_DWORD)v44 != (_DWORD)v36 )
              goto LABEL_114;
            v26 = HIDWORD(v44) == HIDWORD(v36);
LABEL_113:
            if ( !v26 )
              goto LABEL_114;
            goto LABEL_141;
          case 2:
            v35 = v44;
            if ( SHIDWORD(v44) > SHIDWORD(v36) )
              goto LABEL_141;
            if ( SHIDWORD(v44) < SHIDWORD(v36) )
              goto LABEL_114;
LABEL_100:
            v28 = v35 > (unsigned int)v36;
            goto LABEL_80;
          case 3:
            if ( SHIDWORD(v44) < SHIDWORD(v36) )
              goto LABEL_141;
            if ( SHIDWORD(v44) <= SHIDWORD(v36) )
            {
              v30 = (unsigned int)v44 > (unsigned int)v36;
LABEL_85:
              if ( !v30 )
                goto LABEL_141;
            }
            goto LABEL_114;
          case 4:
            if ( SHIDWORD(v44) > SHIDWORD(v36) )
              goto LABEL_141;
            if ( SHIDWORD(v44) < SHIDWORD(v36) )
              goto LABEL_114;
            v32 = (unsigned int)v44 >= (unsigned int)v36;
            goto LABEL_135;
          case 5:
            if ( SHIDWORD(v44) < SHIDWORD(v36) )
              goto LABEL_141;
            if ( SHIDWORD(v44) <= SHIDWORD(v36) )
            {
              v34 = (unsigned int)v44 >= (unsigned int)v36;
LABEL_94:
              if ( !v34 )
                goto LABEL_141;
            }
            goto LABEL_114;
          case 6:
            if ( v36 > (__int64)v44 || SHIDWORD(v44) > v42 )
              goto LABEL_141;
            if ( SHIDWORD(v44) < v42 )
              goto LABEL_114;
            v28 = (unsigned int)v44 > v41;
LABEL_80:
            if ( !v28 )
              goto LABEL_114;
            goto LABEL_141;
          case 7:
            if ( (__int64)v44 < v36 || v42 < SHIDWORD(v44) )
              goto LABEL_114;
            if ( v42 > SHIDWORD(v44) )
              goto LABEL_141;
            v32 = v41 >= (unsigned int)v44;
LABEL_135:
            if ( !v32 )
              goto LABEL_114;
            goto LABEL_141;
          case 8:
            if ( !v36 )
              return 0;
            _rt_sdiv64(v36, v44);
LABEL_139:
            v11 = v40 == 0;
            goto LABEL_140;
          default:
            return 0;
        }
      }
      return 0;
    case 2:
      if ( sub_5BD604(a4) )
      {
        switch ( v9 )
        {
          case 0:
            if ( (_DWORD)v44 != *(_DWORD *)(a3 + 8) )
              goto LABEL_141;
            v11 = HIDWORD(v44) == *(_DWORD *)(a3 + 12);
            goto LABEL_140;
          case 1:
            if ( (_DWORD)v44 != *(_DWORD *)(a3 + 8) )
              goto LABEL_114;
            v26 = HIDWORD(v44) == *(_DWORD *)(a3 + 12);
            goto LABEL_113;
          case 2:
            v27 = *(_DWORD *)(a3 + 12);
            if ( HIDWORD(v44) > v27 )
              goto LABEL_141;
            if ( HIDWORD(v44) < v27 )
              goto LABEL_114;
            v28 = (unsigned int)v44 > *(_DWORD *)(a3 + 8);
            goto LABEL_80;
          case 3:
            v29 = *(_DWORD *)(a3 + 12);
            if ( HIDWORD(v44) < v29 )
              goto LABEL_141;
            if ( HIDWORD(v44) > v29 )
              goto LABEL_114;
            v30 = (unsigned int)v44 > *(_DWORD *)(a3 + 8);
            goto LABEL_85;
          case 4:
            v31 = *(_DWORD *)(a3 + 12);
            if ( HIDWORD(v44) > v31 )
              goto LABEL_141;
            if ( HIDWORD(v44) < v31 )
              goto LABEL_114;
            v32 = (unsigned int)v44 >= *(_DWORD *)(a3 + 8);
            goto LABEL_135;
          case 5:
            v33 = *(_DWORD *)(a3 + 12);
            if ( HIDWORD(v44) < v33 )
              goto LABEL_141;
            if ( HIDWORD(v44) > v33 )
              goto LABEL_114;
            v34 = (unsigned int)v44 >= *(_DWORD *)(a3 + 8);
            goto LABEL_94;
          case 6:
            v35 = v44;
            if ( *(_QWORD *)(a3 + 8) > v44 )
              goto LABEL_141;
            LODWORD(v36) = *(_DWORD *)(a3 + 16);
            v37 = *(_DWORD *)(a3 + 20);
            if ( HIDWORD(v44) > v37 )
              goto LABEL_141;
            if ( HIDWORD(v44) >= v37 )
              goto LABEL_100;
            goto LABEL_114;
          case 7:
            if ( v44 < *(_QWORD *)(a3 + 8) )
              goto LABEL_114;
            v38 = *(_DWORD *)(a3 + 20);
            if ( v38 < HIDWORD(v44) )
              goto LABEL_114;
            if ( v38 > HIDWORD(v44) )
              goto LABEL_141;
            v32 = *(_DWORD *)(a3 + 16) >= (unsigned int)v44;
            goto LABEL_135;
          case 8:
            v39 = *(_QWORD *)(a3 + 8);
            if ( !v39 )
              return 0;
            _rt_udiv64(v39, v44);
            goto LABEL_139;
          default:
            return 0;
        }
      }
      return 0;
    case 3:
      v19 = (char *)a1 + a1[24];
      v20 = (unsigned int)&v19[a1[25]];
      v21 = (unsigned __int8 *)&v19[*(_DWORD *)(a3 + 8)];
      if ( (unsigned int)v21 >= v20 )
        return 0;
      for ( i = &v19[*(_DWORD *)(a3 + 8)]; *i && (unsigned int)i < v20; ++i )
        ;
      v23 = i - (char *)v21;
      if ( i == (char *)v21 )
        goto LABEL_18;
      if ( v9 != 20 )
      {
        if ( v9 != 21 )
        {
          if ( v9 != 30 )
          {
            if ( v9 != 31 )
              return 0;
            v8 = 1;
          }
          if ( v23 != a5 )
            goto LABEL_34;
          v10 = 1;
          while ( v23 )
          {
            if ( (unsigned __int8)*v6 != *v21 )
            {
              v10 = 0;
              goto LABEL_30;
            }
            ++v6;
            ++v21;
            --v23;
          }
          goto LABEL_30;
        }
        v8 = 1;
      }
      if ( v23 > a5 )
        goto LABEL_34;
      v24 = *v21;
      v46 = v24;
      v25 = a4 - v23 + a5 + 1;
      v10 = 0;
      while ( (unsigned int)v6 < v25 )
      {
        if ( (unsigned __int8)*v6 == v24 )
        {
          if ( !strncmp(v6, v21, v23) )
          {
            v10 = 1;
            break;
          }
          v24 = v46;
        }
        ++v6;
      }
LABEL_30:
      if ( v8 )
        goto LABEL_10;
      goto LABEL_142;
    case 4:
      if ( (a5 & 1) != 0 )
        return 0;
      v12 = (char *)a1 + a1[22];
      v13 = (unsigned int)&v12[2 * (a1[23] >> 1)];
      v14 = (unsigned __int16 *)&v12[2 * *(_DWORD *)(a3 + 8)];
      if ( (unsigned int)v14 >= v13 )
        return 0;
      for ( j = &v12[2 * *(_DWORD *)(a3 + 8)]; *(_WORD *)j && (unsigned int)j < v13; j += 2 )
        ;
      v16 = (j - (char *)v14) >> 1;
      if ( !v16 )
      {
LABEL_18:
        LOBYTE(v10) = 0;
        goto LABEL_142;
      }
      if ( v9 != 20 )
      {
        if ( v9 != 21 )
        {
          if ( v9 != 30 )
          {
            if ( v9 != 31 )
              return 0;
            v8 = 1;
          }
          if ( v16 == a5 >> 1 )
          {
            v10 = 1;
            while ( v16 )
            {
              if ( *v14 != *(unsigned __int16 *)v6 )
              {
                v10 = 0;
                goto LABEL_30;
              }
              v6 += 2;
              ++v14;
              --v16;
            }
            goto LABEL_30;
          }
LABEL_34:
          LOBYTE(v10) = v8 != 0;
          goto LABEL_142;
        }
        v8 = 1;
      }
      if ( v16 > a5 >> 1 )
        goto LABEL_34;
      v17 = *v14;
      v45 = v17;
      v18 = a4 + 2 * ((a5 >> 1) - v16 + 1);
      v10 = 0;
      while ( (unsigned int)v6 < v18 )
      {
        if ( *(unsigned __int16 *)v6 == v17 )
        {
          if ( !wcsncmp(v6, v14, v16) )
          {
            v10 = 1;
            goto LABEL_30;
          }
          v17 = v45;
        }
        v6 += 2;
      }
      goto LABEL_30;
  }
  if ( a2 != 5 || a5 != 16 )
    return 0;
  v10 = memcmp(a4, a3 + 8, 16) == 0;
  if ( v9 == 30 )
  {
LABEL_142:
    *a6 = v10;
    return 1;
  }
  if ( v9 == 31 )
  {
LABEL_10:
    v11 = !v10;
LABEL_140:
    if ( v11 )
LABEL_114:
      LOBYTE(v10) = 1;
    else
LABEL_141:
      LOBYTE(v10) = 0;
    goto LABEL_142;
  }
  return 0;
}
