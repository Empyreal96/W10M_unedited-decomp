// sub_8ACD24 
 
int __fastcall sub_8ACD24(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r1
  int v9; // r0
  unsigned int v10; // r3
  int v11; // r1
  int v12; // r3
  int v13; // r0
  unsigned int v14; // r6
  unsigned int v15; // r0
  unsigned int v16; // r2
  unsigned int v17; // r1
  int v18; // r3
  int v19; // r1
  unsigned int v20; // r3
  unsigned int v21; // r2
  unsigned int v22; // r3
  unsigned int v23; // r2
  int v24; // r0
  int v25; // r6
  unsigned int v26; // r3
  unsigned int v27; // r1
  int v28; // r2
  int v29; // lr
  int v30; // r0
  int v31; // r2
  unsigned int v32; // r3
  unsigned int v33; // r1
  int v34; // r0
  int v35; // lr
  int v36; // r0
  unsigned int v38; // [sp+0h] [bp-70h] BYREF
  int v39; // [sp+4h] [bp-6Ch]
  int v40; // [sp+8h] [bp-68h]
  int v41; // [sp+Ch] [bp-64h]
  int v42; // [sp+10h] [bp-60h]
  int v43; // [sp+14h] [bp-5Ch]
  int v44; // [sp+18h] [bp-58h]
  int v45; // [sp+24h] [bp-4Ch]
  int v46; // [sp+28h] [bp-48h]
  int v47; // [sp+2Ch] [bp-44h]
  int v48; // [sp+30h] [bp-40h] BYREF
  _DWORD _38[20]; // [sp+38h] [bp-38h] BYREF

  _38[16] = a1;
  _38[18] = a3;
  _38[19] = a4;
  _38[17] = a2;
  if ( !a1 || !a2 || !a4 )
    return -1073741811;
  v7 = a1[2];
  if ( v7 && *a1 > 3u )
  {
    v8 = 0;
    while ( 1 )
    {
      v9 = *(_DWORD *)v7;
      v10 = v7 + 4;
      if ( v7 + 4 < v7 )
      {
        v10 = -1;
        v38 = -1;
        v6 = -1073741675;
      }
      else
      {
        v38 = v7 + 4;
        v6 = 0;
      }
      if ( v6 < 0 )
        break;
      v7 = v9 + v10;
      if ( v9 + v10 < v10 )
      {
        v7 = -1;
        v38 = -1;
        v6 = -1073741675;
      }
      else
      {
        v38 = v9 + v10;
        v6 = 0;
      }
      if ( v6 < 0 )
        break;
      if ( (unsigned int)++v8 >= 3 )
      {
        v11 = *(_DWORD *)v7;
        v12 = v7 + 4;
        if ( v7 + 4 < v7 )
        {
          v12 = -1;
          v38 = -1;
          v6 = -1073741675;
        }
        else
        {
          v38 = v7 + 4;
          v6 = 0;
        }
        if ( v6 < 0 )
          break;
        v44 = v11;
        if ( !v11 )
        {
          v12 = 0;
          v38 = 0;
        }
        v41 = v12;
        goto LABEL_26;
      }
    }
  }
  else
  {
    v6 = -1073741811;
  }
  v11 = v44;
  v12 = v41;
LABEL_26:
  if ( v6 < 0 )
    goto LABEL_30;
  if ( v11 != 8 )
  {
    v6 = -1073741789;
LABEL_30:
    v40 = v43;
    v39 = v42;
    goto LABEL_31;
  }
  v39 = *(_DWORD *)v12;
  v42 = v39;
  v40 = *(_DWORD *)(v12 + 4);
  v43 = v40;
LABEL_31:
  if ( v6 < 0 )
    return v6;
  KeReleaseMutex((int)&unk_619700);
  v13 = RtlUIntAdd(4u, 4, _38);
  v6 = v13;
  v14 = v13 < 0 ? _38[3] : _38[0];
  if ( v13 < 0
    || (v6 = RtlUIntAdd(4u, 8, &v48), v6 < 0)
    || ((v15 = v14 + v48, v14 + v48 < v14) ? (v15 = -1, v6 = -1073741675) : (v6 = 0), v6 < 0) )
  {
    v15 = _38[5];
    if ( v6 < 0 )
      return v6;
  }
  v16 = v15 + 8;
  if ( v15 >= 0xFFFFFFF8 )
  {
    v16 = -1;
    v6 = -1073741675;
  }
  else
  {
    v6 = 0;
  }
  if ( v6 < 0 )
    return v6;
  v6 = 0;
  v17 = 8 * ((v16 + 7) >> 3);
  if ( v17 < v16 )
  {
    v6 = -1073741675;
    v17 = _38[4];
  }
  if ( v6 < 0 )
    return v6;
  v18 = v17 + 8;
  if ( v17 + 8 < v17 )
  {
    v18 = -1;
    v6 = -1073741675;
  }
  else
  {
    v6 = 0;
  }
  if ( v6 < 0 )
    return v6;
  v19 = *(_DWORD *)(a2 + 8);
  v20 = v18 + 4;
  if ( v20 < 4 )
  {
    v20 = -1;
    v6 = -1073741675;
  }
  else
  {
    v6 = 0;
  }
  if ( v6 < 0 )
    return v6;
  v21 = v20 + 4;
  if ( v20 + 4 < v20 )
  {
    v21 = -1;
    v6 = -1073741675;
  }
  else
  {
    v6 = 0;
  }
  if ( v6 < 0 )
    return v6;
  v22 = v21 + v19;
  if ( v21 + v19 < v21 )
  {
    v22 = -1;
    v6 = -1073741675;
  }
  else
  {
    v6 = 0;
  }
  if ( v6 < 0 )
    return v6;
  v23 = v22 + 4;
  if ( v22 + 4 < v22 )
  {
    v23 = -1;
    v6 = -1073741675;
  }
  else
  {
    v6 = 0;
  }
  if ( v6 < 0 )
    return v6;
  v6 = v23 + *(_DWORD *)(a2 + 16) < v23 ? -1073741675 : 0;
  if ( v6 < 0 )
    return v6;
  a4[1] = v15;
  v6 = 0;
  if ( v15 )
  {
    v24 = ExAllocatePoolWithTag(1, v15, 542329939);
    if ( v24 )
    {
      a4[2] = v24;
      *a4 = 0;
    }
    else
    {
      v6 = -1073741801;
    }
  }
  else
  {
    v6 = -1073741762;
  }
  if ( v6 < 0 )
    return v6;
  v45 = 0;
  if ( &v38 == (unsigned int *)-36 )
  {
    v6 = -1073741811;
    goto LABEL_106;
  }
  v25 = a4[2];
  if ( !v25 )
  {
    v26 = a4[1];
    if ( v26 + 8 < v26 )
    {
      a4[1] = -1;
      v6 = -1073741675;
    }
    else
    {
      a4[1] = v26 + 8;
      v6 = 0;
    }
    if ( v6 < 0 )
      return v6;
    ++*a4;
    v6 = 0;
    goto LABEL_106;
  }
  v27 = a4[2];
  v28 = 0;
  if ( !*a4 )
  {
LABEL_98:
    v30 = v27 + 4;
    if ( v27 + 4 < v27 )
    {
      v30 = -1;
      v6 = -1073741675;
    }
    else
    {
      v6 = 0;
    }
    if ( v6 < 0 )
      return v6;
    if ( v27 + 8 <= v25 + a4[1] )
    {
      *(_DWORD *)v27 = 4;
      *(_DWORD *)v30 = v45;
      ++*a4;
    }
    else
    {
      v6 = -1073741789;
    }
LABEL_106:
    if ( v6 < 0 )
      return v6;
    v46 = v39;
    v47 = v40;
    if ( &v38 != (unsigned int *)-40 )
    {
      v31 = a4[2];
      if ( v31 )
      {
        v33 = a4[2];
        v34 = 0;
        if ( *a4 )
        {
          v35 = _38[2];
          while ( 1 )
          {
            if ( *(_DWORD *)v33 >= 0xFFFFFFFC )
            {
              v6 = -1073741675;
            }
            else
            {
              v6 = 0;
              v35 = *(_DWORD *)v33 + 4;
            }
            if ( v6 < 0 )
              break;
            if ( v33 + v35 < v33 )
            {
              v33 = -1;
              v6 = -1073741675;
            }
            else
            {
              v33 += v35;
              v6 = 0;
            }
            if ( v6 < 0 )
              break;
            if ( (unsigned int)++v34 >= *a4 )
              goto LABEL_125;
          }
        }
        else
        {
LABEL_125:
          v36 = v33 + 4;
          if ( v33 + 4 < v33 )
          {
            v36 = -1;
            v6 = -1073741675;
          }
          else
          {
            v6 = 0;
          }
          if ( v6 >= 0 )
          {
            if ( v33 + 12 <= v31 + a4[1] )
            {
              *(_DWORD *)v33 = 8;
              *(_DWORD *)v36 = v46;
              *(_DWORD *)(v36 + 4) = v47;
              ++*a4;
            }
            else
            {
              v6 = -1073741789;
            }
          }
        }
      }
      else
      {
        v32 = a4[1];
        if ( v32 + 12 < v32 )
        {
          a4[1] = -1;
          v6 = -1073741675;
        }
        else
        {
          a4[1] = v32 + 12;
          v6 = 0;
        }
        if ( v6 >= 0 )
        {
          ++*a4;
          v6 = 0;
        }
      }
      return v6;
    }
    return -1073741811;
  }
  v29 = _38[1];
  while ( 1 )
  {
    if ( *(_DWORD *)v27 >= 0xFFFFFFFC )
    {
      v6 = -1073741675;
    }
    else
    {
      v6 = 0;
      v29 = *(_DWORD *)v27 + 4;
    }
    if ( v6 < 0 )
      return v6;
    if ( v27 + v29 < v27 )
    {
      v27 = -1;
      v6 = -1073741675;
    }
    else
    {
      v27 += v29;
      v6 = 0;
    }
    if ( v6 < 0 )
      return v6;
    if ( (unsigned int)++v28 >= *a4 )
      goto LABEL_98;
  }
}
