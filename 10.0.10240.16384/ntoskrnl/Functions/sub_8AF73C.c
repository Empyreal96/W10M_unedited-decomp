// sub_8AF73C 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall sub_8AF73C(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  _DWORD *v5; // r2
  int result; // r0
  unsigned int i; // r3
  unsigned int v8; // r1
  int v9; // r0
  _QWORD *v10; // r3
  int v11; // r1
  int v12; // r1 OVERLAPPED
  int v13; // r2 OVERLAPPED
  unsigned int v14; // r2
  unsigned int v15; // r3
  unsigned int v16; // r0
  _DWORD *v17; // r1
  int v18; // r3
  int v19; // r1
  unsigned int v20; // r0
  _DWORD *v21; // r1
  int *v22; // r5
  int v23; // r3
  unsigned int v24; // r2
  unsigned int v25; // r3
  unsigned int v26; // r0
  _DWORD *v27; // r1
  int v28; // r3
  int v29; // r1
  unsigned int v30; // r0
  unsigned int v31; // r2
  unsigned int v32; // r3
  unsigned int v33; // r0
  _DWORD *v34; // r1
  int v35; // r3
  int v36; // r1
  unsigned int v37; // r0
  int v38; // [sp+0h] [bp-30h] BYREF
  int v39; // [sp+4h] [bp-2Ch] BYREF
  int v40; // [sp+8h] [bp-28h]
  int v41; // [sp+Ch] [bp-24h] BYREF
  int v42; // [sp+10h] [bp-20h]
  int v43; // [sp+14h] [bp-1Ch]
  int v44; // [sp+18h] [bp-18h]
  int v45; // [sp+1Ch] [bp-14h]

  if ( !a1 || !a4 )
    goto LABEL_88;
  v5 = (_DWORD *)a1[2];
  if ( v5 && *a1 > 3u )
  {
    for ( i = 0; i < 3; ++i )
    {
      v8 = (unsigned int)(v5 + 1);
      v9 = *v5;
      if ( v5 + 1 < v5 )
        goto LABEL_15;
      v5 = (_DWORD *)(v9 + v8);
      if ( v9 + v8 < v8 )
        goto LABEL_15;
    }
    v10 = v5 + 1;
    v11 = *v5;
    if ( v5 + 1 < v5 )
    {
LABEL_15:
      result = -1073741675;
      goto LABEL_16;
    }
    result = 0;
    if ( !v11 )
      v10 = 0;
    if ( v11 == 8 )
    {
      *(_QWORD *)&v12 = *v10;
      goto LABEL_17;
    }
    return -1073741789;
  }
  result = -1073741811;
LABEL_16:
  v12 = v44;
  v13 = v45;
LABEL_17:
  if ( result >= 0 )
  {
    if ( v12 | v13 && qword_920418 )
    {
      if ( __PAIR64__(v13, v12) == qword_920418 )
      {
        result = ExReArmFastCache();
        if ( result < 0 )
          return result;
        v38 = 0;
        if ( &v38 )
        {
          v14 = a4[2];
          if ( !v14 )
          {
            v15 = a4[1];
            if ( v15 + 8 >= v15 )
            {
              a4[1] = v15 + 8;
              ++*a4;
              goto LABEL_36;
            }
LABEL_66:
            a4[1] = -1;
            return -1073741675;
          }
          v16 = 0;
          v17 = (_DWORD *)a4[2];
          if ( *a4 )
          {
            while ( *v17 < 0xFFFFFFFC )
            {
              if ( (_DWORD *)((char *)v17 + *v17 + 4) < v17 )
                return -1073741675;
              ++v16;
              v17 = (_DWORD *)((char *)v17 + *v17 + 4);
              if ( v16 >= *a4 )
                goto LABEL_30;
            }
            result = -1073741675;
          }
          else
          {
LABEL_30:
            if ( v17 + 1 < v17 )
              return -1073741675;
            result = 0;
            if ( (unsigned int)(v17 + 2) > v14 + a4[1] )
              return -1073741789;
            v18 = v38;
            *v17 = 4;
            v17[1] = v18;
            ++*a4;
          }
        }
        else
        {
          result = -1073741811;
        }
        if ( result < 0 )
          return result;
LABEL_36:
        v19 = a4[1];
        if ( v19 )
        {
          v20 = ExAllocatePoolWithTag(1, v19, 542329939);
          v21 = (_DWORD *)v20;
          if ( v20 )
          {
            a4[2] = v20;
            *a4 = 0;
            v39 = 0;
            if ( &v39 )
            {
              v22 = (int *)(v20 + 4);
              if ( v20 + 4 >= v20 )
              {
                result = 0;
                if ( v21 + 2 <= (_DWORD *)((char *)v21 + a4[1]) )
                {
                  v23 = v39;
LABEL_87:
                  *v21 = 4;
                  *v22 = v23;
                  ++*a4;
                  return result;
                }
                return -1073741789;
              }
              return -1073741675;
            }
            goto LABEL_88;
          }
          return -1073741801;
        }
        return -1073741762;
      }
      v40 = -2147467259;
      if ( &v38 == (int *)-8 )
      {
        result = -1073741811;
      }
      else
      {
        v24 = a4[2];
        if ( !v24 )
        {
          v25 = a4[1];
          if ( v25 + 8 < v25 )
            goto LABEL_66;
          a4[1] = v25 + 8;
          ++*a4;
LABEL_56:
          v29 = a4[1];
          if ( v29 )
          {
            v30 = ExAllocatePoolWithTag(1, v29, 542329939);
            v21 = (_DWORD *)v30;
            if ( v30 )
            {
              a4[2] = v30;
              *a4 = 0;
              v41 = -2147467259;
              if ( &v41 )
              {
                v22 = (int *)(v30 + 4);
                if ( v30 + 4 >= v30 )
                {
                  result = 0;
                  if ( v21 + 2 <= (_DWORD *)((char *)v21 + a4[1]) )
                  {
                    v23 = -2147467259;
                    goto LABEL_87;
                  }
                  return -1073741789;
                }
                return -1073741675;
              }
              goto LABEL_88;
            }
            return -1073741801;
          }
          return -1073741762;
        }
        v26 = 0;
        v27 = (_DWORD *)a4[2];
        if ( *a4 )
        {
          while ( *v27 < 0xFFFFFFFC )
          {
            if ( (_DWORD *)((char *)v27 + *v27 + 4) < v27 )
              return -1073741675;
            ++v26;
            v27 = (_DWORD *)((char *)v27 + *v27 + 4);
            if ( v26 >= *a4 )
              goto LABEL_50;
          }
          result = -1073741675;
        }
        else
        {
LABEL_50:
          if ( v27 + 1 < v27 )
            return -1073741675;
          result = 0;
          if ( (unsigned int)(v27 + 2) > v24 + a4[1] )
            return -1073741789;
          v28 = v40;
          *v27 = 4;
          v27[1] = v28;
          ++*a4;
        }
      }
      if ( result < 0 )
        return result;
      goto LABEL_56;
    }
    v42 = -2147467259;
    if ( &v38 == (int *)-16 )
    {
      result = -1073741811;
    }
    else
    {
      v31 = a4[2];
      if ( !v31 )
      {
        v32 = a4[1];
        if ( v32 + 8 < v32 )
          goto LABEL_66;
        a4[1] = v32 + 8;
        ++*a4;
        goto LABEL_78;
      }
      v33 = 0;
      v34 = (_DWORD *)a4[2];
      if ( *a4 )
      {
        while ( *v34 < 0xFFFFFFFC )
        {
          if ( (_DWORD *)((char *)v34 + *v34 + 4) < v34 )
            return -1073741675;
          ++v33;
          v34 = (_DWORD *)((char *)v34 + *v34 + 4);
          if ( v33 >= *a4 )
            goto LABEL_72;
        }
        result = -1073741675;
      }
      else
      {
LABEL_72:
        if ( v34 + 1 < v34 )
          return -1073741675;
        result = 0;
        if ( (unsigned int)(v34 + 2) > v31 + a4[1] )
          return -1073741789;
        v35 = v42;
        *v34 = 4;
        v34[1] = v35;
        ++*a4;
      }
    }
    if ( result < 0 )
      return result;
LABEL_78:
    v36 = a4[1];
    if ( !v36 )
      return -1073741762;
    v37 = ExAllocatePoolWithTag(1, v36, 542329939);
    v21 = (_DWORD *)v37;
    if ( !v37 )
      return -1073741801;
    a4[2] = v37;
    *a4 = 0;
    v43 = -2147467259;
    if ( &v38 != (int *)-20 )
    {
      v22 = (int *)(v37 + 4);
      if ( v37 + 4 >= v37 )
      {
        result = 0;
        if ( v21 + 2 <= (_DWORD *)((char *)v21 + a4[1]) )
        {
          v23 = v43;
          goto LABEL_87;
        }
        return -1073741789;
      }
      return -1073741675;
    }
LABEL_88:
    result = -1073741811;
  }
  return result;
}
