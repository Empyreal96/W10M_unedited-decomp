// sub_5C4E60 
 
int __fastcall sub_5C4E60(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  _DWORD *v5; // r2
  int v7; // r7
  int v9; // r4
  _DWORD *v10; // r3
  unsigned int i; // r1
  unsigned int v12; // r0
  int v13; // r4
  __int64 *v14; // r1
  int v15; // r0
  unsigned int j; // r3
  unsigned int v17; // r1
  int v18; // r0
  unsigned int *v19; // r3
  int v20; // r1
  unsigned int v21; // r8
  int v22; // r4
  int v23; // r0
  int v24; // r9
  int v25; // r0
  unsigned int v26; // r6
  unsigned int v27; // r3
  unsigned int v28; // r6
  unsigned int v29; // r7
  unsigned int v30; // r0
  unsigned int v31; // r3
  unsigned int v32; // r2
  unsigned int v33; // r3
  int v34; // r1
  unsigned int v35; // r2
  unsigned int v36; // r3
  int v37; // r7
  int v38; // r0
  unsigned int v39; // r2
  unsigned int v40; // r3
  int v41; // r9
  unsigned int v43; // r0
  _DWORD *v44; // r1
  int v45; // r3
  unsigned int v46; // r2
  unsigned int v47; // r3
  unsigned int v48; // r0
  unsigned int v49; // r1
  unsigned int v50; // r2
  unsigned int v51; // r3
  unsigned int v52; // r6
  unsigned int v53; // r3
  unsigned int v54; // r2
  unsigned int v55; // r2
  unsigned int *v56; // r1
  unsigned int v57; // r0
  _DWORD *v58; // r1
  int v59; // r3
  int v60; // [sp+0h] [bp-58h] BYREF
  int v61; // [sp+4h] [bp-54h] BYREF
  __int64 v62; // [sp+8h] [bp-50h]
  unsigned int v63; // [sp+10h] [bp-48h]
  int v64; // [sp+14h] [bp-44h]
  int v65; // [sp+18h] [bp-40h] BYREF
  int v66; // [sp+1Ch] [bp-3Ch] BYREF
  int v67[2]; // [sp+20h] [bp-38h] BYREF
  __int64 v68; // [sp+28h] [bp-30h]
  __int64 v69; // [sp+30h] [bp-28h]

  v5 = (_DWORD *)a1[2];
  v7 = 0;
  v60 = 0;
  v61 = 0;
  v64 = 0;
  if ( v5 && *a1 > 3u )
  {
    v10 = v5;
    for ( i = 0; i < 3; ++i )
    {
      v12 = (unsigned int)(v10 + 1);
      v13 = *v10;
      if ( v10 + 1 < v10 )
        goto LABEL_14;
      v10 = (_DWORD *)(v13 + v12);
      if ( v13 + v12 < v12 )
        goto LABEL_14;
    }
    v14 = (__int64 *)(v10 + 1);
    v15 = *v10;
    if ( v10 + 1 < v10 )
    {
LABEL_14:
      v9 = -1073741675;
      v62 = v68;
      goto LABEL_15;
    }
    v9 = 0;
    if ( !v15 )
      v14 = 0;
    if ( v15 == 8 )
    {
      v62 = *v14;
      goto LABEL_15;
    }
    return -1073741789;
  }
  v9 = -1073741811;
  v62 = v68;
LABEL_15:
  if ( v9 >= 0 )
  {
    if ( v5 && *a1 > 4u )
    {
      for ( j = 0; j < 4; ++j )
      {
        v17 = (unsigned int)(v5 + 1);
        v18 = *v5;
        if ( v5 + 1 < v5 )
          goto LABEL_28;
        v5 = (_DWORD *)(v18 + v17);
        if ( v18 + v17 < v17 )
          goto LABEL_28;
      }
      v19 = v5 + 1;
      v20 = *v5;
      if ( v5 + 1 < v5 )
      {
LABEL_28:
        v9 = -1073741675;
        goto LABEL_29;
      }
      v9 = 0;
      if ( !v20 )
        v19 = 0;
      if ( v20 == 4 )
      {
        v21 = *v19;
        goto LABEL_30;
      }
      return -1073741789;
    }
    v9 = -1073741811;
LABEL_29:
    v21 = v63;
LABEL_30:
    if ( v9 >= 0 )
    {
      if ( v21 )
      {
        v22 = 0;
        v7 = ExAllocatePoolWithTag(1, v21);
        v60 = v7;
        if ( !v7 )
          return -1073741801;
        v64 = v61;
      }
      else
      {
        v22 = 1;
      }
      if ( off_9204D0 )
      {
        if ( v22 )
          v23 = 0;
        else
          v23 = v7;
        v24 = off_9204D0(v23, v21, &v61);
        v64 = v61;
      }
      else
      {
        v24 = -1073741637;
      }
      v25 = RtlUIntAdd(4u, 4, v67);
      v9 = v25;
      if ( v25 < 0 )
        v26 = v67[1];
      else
        v26 = v67[0];
      if ( v25 >= 0 )
      {
        v9 = RtlUIntAdd(4u, 8, v67);
        if ( v9 >= 0 )
        {
          v27 = v67[0] + v26;
          if ( v67[0] + v26 < v26 )
            goto LABEL_83;
          v28 = v21 + 4;
          if ( v21 >= 0xFFFFFFFC )
          {
            v9 = -1073741675;
          }
          else
          {
            v29 = v28 + v27;
            if ( v28 + v27 < v27 )
              goto LABEL_83;
            v9 = RtlUIntAdd(4u, 4, v67);
            if ( v9 >= 0 )
            {
              v30 = v67[0] + v29;
              if ( v67[0] + v29 < v29 )
                goto LABEL_83;
              v9 = 0;
              goto LABEL_55;
            }
          }
        }
      }
      v30 = v67[0];
LABEL_55:
      if ( v9 < 0 )
        goto LABEL_84;
      if ( v30 < 0xFFFFFFF8 )
      {
        v31 = (v30 + 15) & 0xFFFFFFF8;
        if ( v31 >= v30 + 8 )
        {
          v32 = v31 + 8;
          if ( v31 + 8 < v31 )
            goto LABEL_68;
          v9 = 0;
        }
        else
        {
          v9 = -1073741675;
          v32 = v67[0];
        }
        if ( v9 < 0 )
          goto LABEL_84;
        v33 = v32 + 4;
        v34 = *(_DWORD *)(a2 + 8);
        if ( v32 < 0xFFFFFFFC )
        {
          v35 = v32 + 8;
          if ( v33 + 4 >= v33 )
          {
            v36 = v35 + v34;
            if ( v35 + v34 >= v35 && v36 + 4 >= v36 && v36 + 4 + *(_DWORD *)(a2 + 16) >= v36 + 4 )
            {
              v9 = 0;
              goto LABEL_69;
            }
          }
        }
LABEL_68:
        v9 = -1073741675;
LABEL_69:
        if ( v9 >= 0 )
        {
          if ( !a4 )
          {
            v9 = -1073741811;
            goto LABEL_84;
          }
          v9 = 0;
          a4[1] = v30;
          if ( v30 )
          {
            v38 = ExAllocatePoolWithTag(1, v30);
            v37 = v61;
            if ( v38 )
            {
              a4[2] = v38;
              *a4 = 0;
            }
            else
            {
              v9 = -1073741801;
            }
          }
          else
          {
            v9 = -1073741762;
            v37 = v64;
          }
          if ( v9 < 0 )
            goto LABEL_84;
          v65 = v24 | 0x10000000;
          if ( &v65 )
          {
            v39 = a4[2];
            if ( !v39 )
            {
              v40 = a4[1];
              if ( v40 + 8 < v40 )
              {
LABEL_82:
                a4[1] = -1;
                goto LABEL_83;
              }
              a4[1] = v40 + 8;
              ++*a4;
              goto LABEL_99;
            }
            v43 = 0;
            v44 = (_DWORD *)a4[2];
            if ( *a4 )
            {
              while ( *v44 < 0xFFFFFFFC )
              {
                if ( (_DWORD *)((char *)v44 + *v44 + 4) < v44 )
                  goto LABEL_83;
                ++v43;
                v44 = (_DWORD *)((char *)v44 + *v44 + 4);
                if ( v43 >= *a4 )
                  goto LABEL_92;
              }
              v9 = -1073741675;
            }
            else
            {
LABEL_92:
              if ( v44 + 1 < v44 )
                goto LABEL_83;
              v9 = 0;
              if ( (unsigned int)(v44 + 2) > v39 + a4[1] )
                goto LABEL_94;
              v45 = v65;
              *v44 = 4;
              v44[1] = v45;
              v37 = v61;
              ++*a4;
            }
          }
          else
          {
            v9 = -1073741811;
          }
          if ( v9 < 0 )
            goto LABEL_84;
LABEL_99:
          v69 = v62;
          if ( &v60 == (int *)-48 )
          {
            v9 = -1073741811;
            goto LABEL_112;
          }
          v46 = a4[2];
          if ( !v46 )
          {
            v47 = a4[1];
            if ( v47 + 12 >= v47 )
            {
              a4[1] = v47 + 12;
              ++*a4;
              goto LABEL_113;
            }
            goto LABEL_82;
          }
          v48 = 0;
          v49 = a4[2];
          if ( *a4 )
          {
            while ( *(_DWORD *)v49 < 0xFFFFFFFC )
            {
              if ( *(_DWORD *)v49 + 4 + v49 < v49 )
                goto LABEL_83;
              ++v48;
              v49 += *(_DWORD *)v49 + 4;
              if ( v48 >= *a4 )
                goto LABEL_107;
            }
            v9 = -1073741675;
LABEL_112:
            if ( v9 < 0 )
              goto LABEL_84;
LABEL_113:
            v41 = v60;
            if ( v60 )
            {
              if ( !v21 )
                goto LABEL_115;
            }
            else if ( v21 )
            {
LABEL_115:
              v9 = -1073741811;
              goto LABEL_116;
            }
            v52 = a4[2];
            if ( v52 )
            {
              v55 = 0;
              v56 = (unsigned int *)a4[2];
              if ( !*a4 )
              {
LABEL_133:
                if ( v56 + 1 < v56 )
                  goto LABEL_127;
                v9 = 0;
                if ( (unsigned int)v56 + v21 + 4 > a4[1] + v52 )
                  goto LABEL_135;
                *v56 = v21;
                if ( v41 )
                  memmove((int)(v56 + 1), v41, v21);
                v37 = v61;
                ++*a4;
                goto LABEL_116;
              }
              while ( *v56 < 0xFFFFFFFC )
              {
                if ( (unsigned int *)((char *)v56 + *v56 + 4) < v56 )
                  goto LABEL_127;
                ++v55;
                v56 = (unsigned int *)((char *)v56 + *v56 + 4);
                if ( v55 >= *a4 )
                  goto LABEL_133;
              }
            }
            else if ( v21 < 0xFFFFFFFC )
            {
              v53 = a4[1];
              v54 = v21 + 4 + v53;
              if ( v54 < v53 )
              {
LABEL_126:
                a4[1] = -1;
                goto LABEL_127;
              }
              a4[1] = v54;
              ++*a4;
              goto LABEL_117;
            }
            v9 = -1073741675;
LABEL_116:
            if ( v9 < 0 )
              goto LABEL_85;
LABEL_117:
            v66 = v37;
            if ( !&v66 )
            {
              v9 = -1073741811;
LABEL_85:
              if ( v41 )
                ExFreePoolWithTag(v41);
              return v9;
            }
            v50 = a4[2];
            if ( !v50 )
            {
              v51 = a4[1];
              if ( v51 + 8 >= v51 )
              {
                a4[1] = v51 + 8;
                ++*a4;
                v9 = 0;
                goto LABEL_85;
              }
              goto LABEL_126;
            }
            v57 = 0;
            v58 = (_DWORD *)a4[2];
            if ( *a4 )
            {
              while ( *v58 < 0xFFFFFFFC && (_DWORD *)((char *)v58 + *v58 + 4) >= v58 )
              {
                ++v57;
                v58 = (_DWORD *)((char *)v58 + *v58 + 4);
                if ( v57 >= *a4 )
                  goto LABEL_143;
              }
              goto LABEL_127;
            }
LABEL_143:
            if ( v58 + 1 < v58 )
            {
LABEL_127:
              v9 = -1073741675;
              goto LABEL_85;
            }
            v9 = 0;
            if ( (unsigned int)(v58 + 2) <= v50 + a4[1] )
            {
              v59 = v66;
              *v58 = 4;
              v58[1] = v59;
              ++*a4;
              goto LABEL_85;
            }
LABEL_135:
            v9 = -1073741789;
            goto LABEL_85;
          }
LABEL_107:
          if ( v49 + 4 < v49 )
            goto LABEL_83;
          v9 = 0;
          if ( v49 + 12 <= v46 + a4[1] )
          {
            *(_DWORD *)v49 = 8;
            *(_QWORD *)(v49 + 4) = v69;
            v37 = v61;
            ++*a4;
            goto LABEL_112;
          }
LABEL_94:
          v9 = -1073741789;
        }
LABEL_84:
        v41 = v60;
        goto LABEL_85;
      }
LABEL_83:
      v9 = -1073741675;
      goto LABEL_84;
    }
  }
  return v9;
}
