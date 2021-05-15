// sub_8AD880 
 
int __fastcall sub_8AD880(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int v6; // r4
  int *v7; // r2
  int *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r4
  int *v12; // r1
  int v13; // r0
  int v14; // r9
  int v15; // r10
  unsigned int j; // r3
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r8
  int v20; // r4
  unsigned int v21; // r7
  unsigned int v22; // r6
  unsigned int v23; // r1
  unsigned int v24; // r3
  unsigned int v25; // r2
  int v26; // r0
  unsigned int v27; // r3
  unsigned int v28; // r2
  unsigned int v29; // r3
  _DWORD *v30; // r0
  unsigned int v31; // r2
  unsigned int v32; // r3
  unsigned int v34; // r0
  _DWORD *v35; // r1
  unsigned int v36; // r2
  unsigned int v37; // r3
  unsigned int v38; // r0
  _DWORD *v39; // r1
  int v40[4]; // [sp+0h] [bp-148h] BYREF
  int v41; // [sp+10h] [bp-138h]
  int v42; // [sp+14h] [bp-134h]
  int v43; // [sp+18h] [bp-130h]
  int v44; // [sp+1Ch] [bp-12Ch]
  int v45; // [sp+20h] [bp-128h]
  char v46[288]; // [sp+28h] [bp-120h] BYREF

  v41 = a2;
  if ( !a1 || !a2 || !a4 )
    return -1073741811;
  v7 = (int *)a1[2];
  if ( !v7 || *a1 <= 3u )
  {
    v6 = -1073741811;
LABEL_19:
    v15 = v40[2];
    v14 = v40[3];
    goto LABEL_20;
  }
  v8 = (int *)a1[2];
  for ( i = 0; i < 3; ++i )
  {
    v10 = (unsigned int)(v8 + 1);
    v11 = *v8;
    if ( v8 + 1 < v8 )
      goto LABEL_18;
    v8 = (int *)(v11 + v10);
    if ( v11 + v10 < v10 )
      goto LABEL_18;
  }
  v12 = v8 + 1;
  v13 = *v8;
  if ( v8 + 1 < v8 )
  {
LABEL_18:
    v6 = -1073741675;
    goto LABEL_19;
  }
  v6 = 0;
  if ( !v13 )
    v12 = 0;
  if ( v13 != 8 )
    return -1073741789;
  v14 = v12[1];
  v15 = *v12;
LABEL_20:
  if ( v6 < 0 )
    return v6;
  if ( !v7 || *a1 <= 4u )
    return -1073741811;
  for ( j = 0; j < 4; ++j )
  {
    v17 = (unsigned int)(v7 + 1);
    v18 = *v7;
    if ( v7 + 1 < v7 )
      return -1073741675;
    v7 = (int *)(v18 + v17);
    if ( v18 + v17 < v17 )
      return -1073741675;
  }
  if ( v7 + 1 < v7 )
    return -1073741675;
  if ( off_920490 )
    v19 = off_920490();
  else
    v19 = -1073741637;
  v6 = v19;
  if ( v19 >= 0 )
  {
    if ( RtlUIntAdd(4u, 4, v40) < 0 )
      v20 = v45;
    else
      v20 = v40[0];
    v21 = v20;
    if ( RtlUIntAdd(4u, 8, v40) >= 0 )
      v20 = v40[0];
    v22 = v20 + v21;
    if ( v20 + v21 < v21 )
      return -1073741675;
    if ( RtlUIntAdd(4u, 256, v40) >= 0 )
      v20 = v40[0];
    v23 = v20 + v22;
    if ( v20 + v22 < v22 || v23 >= 0xFFFFFFF8 )
      return -1073741675;
    v24 = (v23 + 15) & 0xFFFFFFF8;
    if ( v24 >= v23 + 8 )
    {
      v25 = v24 + 8;
      if ( v24 + 8 < v24 )
        goto LABEL_53;
      v6 = 0;
    }
    else
    {
      v6 = -1073741675;
      v25 = v41;
    }
    if ( v6 < 0 )
      return v6;
    v26 = *(_DWORD *)(v41 + 8);
    v27 = v25 + 4;
    if ( v25 < 0xFFFFFFFC )
    {
      v28 = v25 + 8;
      if ( v27 + 4 >= v27 )
      {
        v29 = v28 + v26;
        if ( v28 + v26 >= v28 && v29 + 4 >= v29 && v29 + 4 + *(_DWORD *)(v41 + 16) >= v29 + 4 )
        {
          v6 = 0;
          goto LABEL_54;
        }
      }
    }
LABEL_53:
    v6 = -1073741675;
LABEL_54:
    if ( v6 < 0 )
      return v6;
    a4[1] = v23;
    if ( !v23 )
      return -1073741762;
    v30 = (_DWORD *)ExAllocatePoolWithTag(1, v23, 542329939);
    if ( !v30 )
      return -1073741801;
    a4[2] = (unsigned int)v30;
    *a4 = 0;
    v42 = v19 | 0x10000000;
    if ( v40 == (int *)-20 )
    {
      v6 = -1073741811;
    }
    else
    {
      if ( v30 + 1 < v30 )
        return -1073741675;
      v6 = 0;
      if ( v30 + 2 > (_DWORD *)((char *)v30 + a4[1]) )
        return -1073741789;
      *v30 = 4;
      v30[1] = v42;
      ++*a4;
    }
    if ( v6 < 0 )
      return v6;
    v43 = v15;
    v44 = v14;
    if ( v40 == (int *)-24 )
    {
      v6 = -1073741811;
    }
    else
    {
      v31 = a4[2];
      if ( !v31 )
      {
        v32 = a4[1];
        if ( v32 + 12 < v32 )
        {
LABEL_69:
          a4[1] = -1;
          return -1073741675;
        }
        a4[1] = v32 + 12;
        ++*a4;
LABEL_82:
        if ( v46 )
        {
          v36 = a4[2];
          if ( !v36 )
          {
            v37 = a4[1];
            if ( v37 + 260 >= v37 )
            {
              a4[1] = v37 + 260;
              ++*a4;
              return 0;
            }
            goto LABEL_69;
          }
          v38 = 0;
          v39 = (_DWORD *)a4[2];
          if ( *a4 )
          {
            while ( *v39 < 0xFFFFFFFC && (_DWORD *)((char *)v39 + *v39 + 4) >= v39 )
            {
              ++v38;
              v39 = (_DWORD *)((char *)v39 + *v39 + 4);
              if ( v38 >= *a4 )
                goto LABEL_90;
            }
          }
          else
          {
LABEL_90:
            if ( v39 + 1 >= v39 )
            {
              v6 = 0;
              if ( (unsigned int)(v39 + 65) <= v36 + a4[1] )
              {
                *v39 = 256;
                memmove((int)(v39 + 1), (int)v46, 0x100u);
                ++*a4;
                return v6;
              }
              return -1073741789;
            }
          }
          return -1073741675;
        }
        return -1073741811;
      }
      v34 = 0;
      v35 = (_DWORD *)a4[2];
      if ( *a4 )
      {
        while ( *v35 < 0xFFFFFFFC )
        {
          if ( (_DWORD *)((char *)v35 + *v35 + 4) < v35 )
            return -1073741675;
          ++v34;
          v35 = (_DWORD *)((char *)v35 + *v35 + 4);
          if ( v34 >= *a4 )
            goto LABEL_76;
        }
        v6 = -1073741675;
      }
      else
      {
LABEL_76:
        if ( v35 + 1 < v35 )
          return -1073741675;
        v6 = 0;
        if ( (unsigned int)(v35 + 3) > v31 + a4[1] )
          return -1073741789;
        *v35 = 8;
        v35[1] = v43;
        v35[2] = v44;
        ++*a4;
      }
    }
    if ( v6 < 0 )
      return v6;
    goto LABEL_82;
  }
  return v6;
}
