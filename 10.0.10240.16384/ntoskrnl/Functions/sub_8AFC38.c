// sub_8AFC38 
 
int __fastcall sub_8AFC38(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int v6; // r4
  unsigned int *v7; // r2
  int *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r4
  int *v12; // r1
  int v13; // r0
  int v14; // r9
  int v15; // r10
  unsigned int j; // r1
  unsigned int v17; // r3
  unsigned int v18; // r0
  int v19; // r5
  unsigned int v20; // r6
  int *v21; // r2
  unsigned int v22; // r3
  unsigned int v23; // r3
  unsigned int v24; // r6
  int v25; // r0
  unsigned int v26; // r4
  unsigned int v27; // r5
  unsigned int k; // r1
  unsigned int v29; // r3
  int v30; // r0
  int *v31; // r3
  int v32; // r1
  int v33; // r1
  int v34; // r8
  int v35; // r0
  unsigned int v36; // r5
  unsigned int v37; // r1
  unsigned int v38; // r3
  unsigned int v39; // r2
  int v40; // r0
  unsigned int v41; // r3
  unsigned int v42; // r2
  unsigned int v43; // r3
  _DWORD *v44; // r0
  unsigned int v45; // r2
  unsigned int v46; // r3
  unsigned int v48; // r0
  _DWORD *v49; // r1
  _DWORD v50[3]; // [sp+0h] [bp-50h] BYREF
  int v51; // [sp+Ch] [bp-44h]
  unsigned int v52; // [sp+10h] [bp-40h]
  unsigned int v53; // [sp+14h] [bp-3Ch] BYREF
  int v54; // [sp+18h] [bp-38h]
  unsigned int v55; // [sp+1Ch] [bp-34h]
  int v56; // [sp+20h] [bp-30h]
  int v57; // [sp+24h] [bp-2Ch]
  int v58; // [sp+28h] [bp-28h]
  int v59; // [sp+2Ch] [bp-24h]

  v52 = 0;
  v54 = a2;
  if ( !a2 || !a4 )
    return -1073741811;
  v7 = (unsigned int *)a1[2];
  if ( v7 && *a1 > 3u )
  {
    v8 = (int *)a1[2];
    for ( i = 0; i < 3; ++i )
    {
      v10 = (unsigned int)(v8 + 1);
      v11 = *v8;
      if ( v8 + 1 < v8 )
        goto LABEL_17;
      v8 = (int *)(v11 + v10);
      if ( v11 + v10 < v10 )
        goto LABEL_17;
    }
    v12 = v8 + 1;
    v13 = *v8;
    if ( v8 + 1 < v8 )
    {
LABEL_17:
      v6 = -1073741675;
      goto LABEL_18;
    }
    v6 = 0;
    if ( !v13 )
      v12 = 0;
    if ( v13 != 8 )
      return -1073741789;
    v14 = v12[1];
    v15 = *v12;
  }
  else
  {
    v6 = -1073741811;
LABEL_18:
    v15 = v56;
    v14 = v57;
  }
  if ( v6 >= 0 )
  {
    if ( v7 && *a1 > 4u )
    {
      for ( j = 0; j < 4; ++j )
      {
        v17 = (unsigned int)(v7 + 1);
        v18 = *v7;
        if ( v7 + 1 < v7 )
          goto LABEL_37;
        v7 = (unsigned int *)(v18 + v17);
        if ( v18 + v17 < v17 )
          goto LABEL_37;
      }
      v19 = (int)(v7 + 1);
      v20 = *v7;
      if ( v7 + 1 < v7 )
      {
LABEL_37:
        v6 = -1073741675;
        goto LABEL_38;
      }
      v6 = 0;
      if ( v20
        && (v20 & 1) == 0
        && !*(_WORD *)(v19 + 2 * (v20 >> 1) - 2)
        && StringCbLengthW(v19, v20, &v53) >= 0
        && v53 + 2 == v20 )
      {
        v22 = v53 >> 1;
        goto LABEL_39;
      }
      return -1073741762;
    }
    v6 = -1073741811;
LABEL_38:
    v22 = v50[0];
    v19 = v50[1];
LABEL_39:
    if ( v6 >= 0 )
    {
      v23 = v22 + 1;
      v24 = 2 * v23;
      if ( !(2 * v23) )
        return -1073741762;
      v25 = ExAllocatePoolWithTag(1, 2 * v23, 542329939);
      v26 = v25;
      if ( !v25 )
        return -1073741801;
      memmove(v25, v19, v24);
      v27 = v26;
      v52 = v26;
      v21 = (int *)a1[2];
      if ( v21 && *a1 > 5u )
      {
        for ( k = 0; k < 5; ++k )
        {
          v29 = (unsigned int)(v21 + 1);
          v30 = *v21;
          if ( v21 + 1 < v21 )
            goto LABEL_55;
          v21 = (int *)(v30 + v29);
          if ( v30 + v29 < v29 )
            goto LABEL_55;
        }
        v31 = v21 + 1;
        v32 = *v21;
        if ( v21 + 1 < v21 )
        {
LABEL_55:
          v6 = -1073741675;
          goto LABEL_56;
        }
        v6 = 0;
        if ( !v32 )
          v31 = 0;
        if ( v32 == 4 )
        {
          v33 = *v31;
          goto LABEL_57;
        }
        goto LABEL_53;
      }
      v6 = -1073741811;
LABEL_56:
      v33 = v50[2];
LABEL_57:
      if ( v6 < 0 )
        goto LABEL_100;
      if ( off_9204B8 )
        v34 = off_9204B8(v27, v33);
      else
        v34 = -1073700223;
      v35 = RtlUIntAdd(4u, 4, &v53);
      v6 = v35;
      if ( v35 < 0 )
        v36 = v55;
      else
        v36 = v53;
      if ( v35 < 0 || (v6 = RtlUIntAdd(4u, 8, &v53), v6 < 0) )
      {
        v37 = v54;
      }
      else
      {
        v37 = v36 + v53;
        if ( v36 + v53 < v36 )
          goto LABEL_99;
        v6 = 0;
      }
      if ( v6 < 0 )
        goto LABEL_100;
      if ( v37 >= 0xFFFFFFF8 )
        goto LABEL_99;
      v38 = (v37 + 15) & 0xFFFFFFF8;
      if ( v38 >= v37 + 8 )
      {
        v39 = v38 + 8;
        if ( v38 + 8 < v38 )
          goto LABEL_82;
        v6 = 0;
      }
      else
      {
        v6 = -1073741675;
        v39 = v54;
      }
      if ( v6 < 0 )
        goto LABEL_100;
      v40 = *(_DWORD *)(v54 + 8);
      v41 = v39 + 4;
      if ( v39 < 0xFFFFFFFC )
      {
        v42 = v39 + 8;
        if ( v41 + 4 >= v41 )
        {
          v43 = v42 + v40;
          if ( v42 + v40 >= v42 && v43 + 4 >= v43 && v43 + 4 + *(_DWORD *)(v54 + 16) >= v43 + 4 )
          {
            v6 = 0;
LABEL_83:
            if ( v6 < 0 )
              goto LABEL_100;
            a4[1] = v37;
            if ( !v37 )
            {
              v6 = -1073741762;
              goto LABEL_100;
            }
            v44 = (_DWORD *)ExAllocatePoolWithTag(1, v37, 542329939);
            if ( !v44 )
            {
              v6 = -1073741801;
              goto LABEL_100;
            }
            a4[2] = (unsigned int)v44;
            *a4 = 0;
            v51 = v34 | 0x10000000;
            if ( v50 == (_DWORD *)-12 )
            {
              v6 = -1073741811;
            }
            else
            {
              if ( v44 + 1 < v44 )
                goto LABEL_99;
              v6 = 0;
              if ( v44 + 2 > (_DWORD *)((char *)v44 + a4[1]) )
                goto LABEL_53;
              *v44 = 4;
              v44[1] = v51;
              ++*a4;
            }
            if ( v6 < 0 )
              goto LABEL_100;
            v58 = v15;
            v59 = v14;
            if ( v50 == (_DWORD *)-40 )
            {
              v6 = -1073741811;
LABEL_100:
              if ( v52 )
                ExFreePoolWithTag(v52);
              return v6;
            }
            v45 = a4[2];
            if ( !v45 )
            {
              v46 = a4[1];
              if ( v46 + 12 >= v46 )
              {
                a4[1] = v46 + 12;
                ++*a4;
                v6 = 0;
                goto LABEL_100;
              }
              a4[1] = -1;
              goto LABEL_99;
            }
            v48 = 0;
            v49 = (_DWORD *)a4[2];
            if ( *a4 )
            {
              while ( *v49 < 0xFFFFFFFC && (_DWORD *)((char *)v49 + *v49 + 4) >= v49 )
              {
                ++v48;
                v49 = (_DWORD *)((char *)v49 + *v49 + 4);
                if ( v48 >= *a4 )
                  goto LABEL_107;
              }
              goto LABEL_99;
            }
LABEL_107:
            if ( v49 + 1 >= v49 )
            {
              v6 = 0;
              if ( (unsigned int)(v49 + 3) <= v45 + a4[1] )
              {
                *v49 = 8;
                v49[1] = v58;
                v49[2] = v59;
                ++*a4;
                goto LABEL_100;
              }
LABEL_53:
              v6 = -1073741789;
              goto LABEL_100;
            }
LABEL_99:
            v6 = -1073741675;
            goto LABEL_100;
          }
        }
      }
LABEL_82:
      v6 = -1073741675;
      goto LABEL_83;
    }
  }
  return v6;
}
