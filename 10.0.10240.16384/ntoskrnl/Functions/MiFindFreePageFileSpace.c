// MiFindFreePageFileSpace 
 
int __fastcall MiFindFreePageFileSpace(int a1, _DWORD *a2, int a3, int a4, char a5)
{
  char v5; // lr
  unsigned int v6; // r7
  int v7; // r9
  unsigned int v8; // r1
  unsigned int v10; // r2
  unsigned int *v11; // r0
  unsigned int v12; // r5
  unsigned int v13; // r4
  int v14; // r6
  unsigned int v15; // r0
  unsigned int i; // r6
  unsigned int v17; // r5
  unsigned int v18; // lr
  int *v19; // r9
  int *v20; // r4
  unsigned int v21; // r0
  int *v22; // r4
  int v23; // t1
  int v24; // r1
  unsigned int j; // r1
  unsigned int v27; // r6
  int v28; // r0
  int v29; // r4
  unsigned int v30; // r7
  int v31; // r3
  int v32; // r4
  _DWORD *v33; // r4
  unsigned int v34; // r5
  BOOL v35; // r3
  int v36; // r2
  int *v37; // r1
  int *v38; // r0
  int v39; // r3
  int *v40; // r1
  int v41; // t1
  int v43; // r2
  int *v44; // r1
  int *v45; // r0
  int *v46; // r1
  int v47; // t1
  unsigned int v49; // r2
  unsigned int v50; // r3
  unsigned int v51; // r2
  unsigned int v52; // [sp+8h] [bp-90h]
  int v53; // [sp+Ch] [bp-8Ch]
  unsigned int v54; // [sp+10h] [bp-88h]
  int v55; // [sp+14h] [bp-84h]
  unsigned int *v56; // [sp+18h] [bp-80h]
  unsigned int v57; // [sp+1Ch] [bp-7Ch]
  char *v58; // [sp+20h] [bp-78h]
  unsigned int v59; // [sp+24h] [bp-74h] BYREF
  int v60; // [sp+28h] [bp-70h]
  int v61; // [sp+2Ch] [bp-6Ch]
  unsigned int v62; // [sp+30h] [bp-68h]
  unsigned int v63; // [sp+34h] [bp-64h]
  int v64; // [sp+38h] [bp-60h]
  _DWORD *v65; // [sp+3Ch] [bp-5Ch]
  int v66; // [sp+40h] [bp-58h]
  unsigned int v67; // [sp+44h] [bp-54h]
  int v68; // [sp+48h] [bp-50h]
  int v69; // [sp+4Ch] [bp-4Ch]
  char v70[16]; // [sp+50h] [bp-48h] BYREF
  int v71[2]; // [sp+60h] [bp-38h] BYREF
  char v72[12]; // [sp+68h] [bp-30h] BYREF
  char v73; // [sp+74h] [bp-24h] BYREF

  v5 = a5;
  v66 = a4;
  v6 = a3;
  v64 = a1;
  v65 = a2;
  v69 = a3;
  if ( (a5 & 8) != 0 )
    JUMPOUT(0x548BDA);
  v7 = *(_DWORD *)(a1 + 4 * ((*a2 >> 2) & 1) + 3600);
  v8 = *a2 >> 13;
  v52 = v8;
  v53 = v7;
  v61 = a5 & 1;
  if ( (a5 & 1) != 0 )
    return sub_548BC8();
  v10 = *(_DWORD *)(v7 + 28);
  v63 = v10;
  if ( !v10 || (*(_WORD *)(a1 + 516) & 1) != 0 && (*(_WORD *)(v7 + 96) & 0x10) == 0 )
    return 0;
  if ( v6 > v10 )
    v6 = v10;
  v62 = 0;
  v67 = v6;
  while ( 1 )
  {
    if ( (v5 & 2) != 0 )
    {
      v32 = *(_DWORD *)(v7 + 64);
      v11 = (unsigned int *)v71;
      v71[0] = *(_DWORD *)v7;
      v58 = (char *)v32;
      v71[1] = *(_DWORD *)(v32 + 16);
    }
    else
    {
      v58 = v72;
      MiRefPageFileSpaceBitmaps(v7, v72, -1);
      v5 = a5;
      v8 = v52;
      v11 = (unsigned int *)&v73;
    }
    v12 = *v11;
    v56 = v11;
    v54 = *v11;
    if ( v8 >= *v11 )
    {
      if ( (v5 & 4) != 0 )
      {
        v55 = 0;
        v27 = 0;
        goto LABEL_78;
      }
      v8 = 0;
      v52 = 0;
    }
    v13 = 0;
    v14 = v8;
    v55 = 0;
    v60 = v8;
    v57 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v15 = RtlFindNextForwardRunClearCapped(v11, v8, 0xFFFFFFFF, &v59);
        if ( !v15 )
          break;
        v8 = v59 + v15;
        v52 = v59 + v15;
        if ( v15 > v13 )
        {
          i = v59 & 0x1F;
          v68 = v59 - i;
          v17 = i + v15;
          v18 = *((_DWORD *)v58 + 2) + 4 * ((v59 - i) >> 5);
          v19 = (int *)(v18 + 4 * ((v17 - 1) >> 5));
          if ( i + v15 > i )
          {
            while ( 1 )
            {
              v20 = (int *)(v18 + 4 * (i >> 5));
              if ( v20 != v19 && (*v20 | dword_40A280[i & 0x1F]) == -1 )
              {
                ++v20;
                for ( i = i - (i & 0x1F) + 32; v20 < v19; i += 32 )
                {
                  if ( *v20 != -1 )
                    break;
                  ++v20;
                }
              }
              for ( ; i < v17; ++i )
              {
                if ( ((*(int *)(v18 + 4 * (i >> 5)) >> (i & 0x1F)) & 1) == 0 )
                  break;
              }
              v21 = 0;
              if ( v20 != v19 )
              {
                v23 = *v20;
                v22 = v20 + 1;
                v24 = i & 0x1F;
                if ( (v23 & ~dword_40A280[v24]) == 0 )
                {
                  v21 = 32 - v24;
                  if ( 32 - v24 >= v6 )
                    goto LABEL_27;
                  while ( v22 < v19 )
                  {
                    if ( *v22++ )
                      break;
                    v21 += 32;
                    if ( v21 >= v6 )
                      goto LABEL_27;
                  }
                }
              }
              for ( j = v21 + i; j < v17; ++v21 )
              {
                if ( ((*(int *)(v18 + 4 * (j >> 5)) >> (j & 0x1F)) & 1) != 0 )
                  break;
                if ( v21 >= v6 )
                  break;
                ++j;
              }
LABEL_27:
              v59 = i;
              if ( v21 > v6 )
                v21 = v6;
              v13 = v57;
              if ( !v21 )
                goto LABEL_32;
              if ( v21 > v57 )
              {
                v13 = v21;
                v57 = v21;
                v55 = v68 + i;
                if ( v21 >= v6 )
                {
                  v5 = a5;
                  goto LABEL_50;
                }
              }
              i += v21;
              if ( v17 <= i )
                goto LABEL_32;
            }
          }
          v59 &= 0x1Fu;
LABEL_32:
          v12 = v54;
          v14 = v60;
          v8 = v52;
        }
        v11 = v56;
        if ( v8 >= v12 )
        {
          v5 = a5;
          if ( v12 == v14 || !v14 || (a5 & 4) != 0 )
            goto LABEL_50;
          v12 = v14;
          v8 = 0;
          v54 = v14;
          v52 = 0;
        }
      }
      v5 = a5;
      if ( v12 == v14 || !v14 || (a5 & 4) != 0 )
        break;
      v12 = v14;
      v8 = 0;
      v11 = v56;
      v54 = v14;
      v52 = 0;
    }
LABEL_50:
    v27 = v57;
    if ( v57 )
    {
LABEL_51:
      v7 = v53;
      if ( (v5 & 2) != 0 )
        goto LABEL_55;
      goto LABEL_52;
    }
    v7 = v53;
LABEL_78:
    if ( (v5 & 4) != 0 )
      goto LABEL_51;
    if ( (v5 & 2) == 0 )
    {
      KeAcquireInStackQueuedSpinLock((unsigned int *)(v7 + 116), (unsigned int)v70);
      v5 = a5;
    }
    if ( *(_DWORD *)v58 == *(_DWORD *)(v7 + 64) && *((_DWORD *)v58 + 1) == *(_DWORD *)v7 && *(_DWORD *)(v7 + 28) <= v63 )
    {
      *(_DWORD *)(v7 + 28) = 0;
      ++*(_DWORD *)(v7 + 80);
    }
    if ( (v5 & 2) == 0 )
    {
      KeReleaseInStackQueuedSpinLock((int)v70);
LABEL_52:
      v28 = MiDerefPageFileSpaceBitmaps(v7, v58, 0);
      if ( v28 )
        ExFreePoolWithTag(v28, 0);
      v5 = a5;
    }
LABEL_55:
    if ( !v27 )
      return 0;
    v29 = v61;
    if ( !v61 )
    {
      v30 = v55;
      goto LABEL_58;
    }
    if ( (v5 & 2) != 0 )
      break;
    KeAcquireInStackQueuedSpinLock((unsigned int *)(v7 + 116), (unsigned int)v70);
    v30 = v55;
    v33 = *(_DWORD **)(v7 + 64);
    v34 = v27 + v55 - 1;
    if ( v34 >= v33[3] )
      goto LABEL_116;
    if ( v27 > 1 )
    {
      v36 = v33[4];
      v37 = (int *)(v36 + 4 * ((unsigned int)v55 >> 5));
      v38 = (int *)(v36 + 4 * (v34 >> 5));
      if ( v37 == v38 )
      {
        if ( (*v37 & (0xFFFFFFFF >> (32 - v27) << (v55 & 0x1F))) == 0 )
          goto LABEL_106;
      }
      else
      {
        v41 = *v37;
        v40 = v37 + 1;
        if ( (v41 & (-1 << (v55 & 0x1F))) != 0 )
          goto LABEL_116;
        while ( v40 != v38 )
        {
          if ( *v40++ )
            goto LABEL_116;
        }
        if ( (*v40 & (0xFFFFFFFF >> (31 - (v34 & 0x1F)))) == 0 )
        {
LABEL_106:
          v35 = 1;
          goto LABEL_94;
        }
      }
      v35 = 0;
    }
    else
    {
      v35 = ((*(unsigned __int8 *)((v55 >> 3) + v33[4]) >> (v55 & 7)) & 1) == 0;
    }
LABEL_94:
    if ( !v35 || v34 >= v33[1] )
      goto LABEL_116;
    if ( v27 > 1 )
    {
      v43 = v33[2];
      v44 = (int *)(v43 + 4 * ((unsigned int)v55 >> 5));
      v45 = (int *)(v43 + 4 * (v34 >> 5));
      if ( v44 == v45 )
      {
        if ( ((0xFFFFFFFF >> (32 - v27) << (v55 & 0x1F)) & *v44) != 0 )
          goto LABEL_98;
      }
      else
      {
        v47 = *v44;
        v46 = v44 + 1;
        if ( ((-1 << (v55 & 0x1F)) & v47) != 0 )
          goto LABEL_116;
        while ( v46 != v45 )
        {
          if ( *v46++ )
            goto LABEL_116;
        }
        if ( ((0xFFFFFFFF >> (31 - (v34 & 0x1F))) & *v46) != 0 )
        {
LABEL_98:
          v39 = 0;
          goto LABEL_99;
        }
      }
    }
    else if ( ((*(unsigned __int8 *)((v55 >> 3) + v33[2]) >> (v55 & 7)) & 1) != 0 )
    {
      goto LABEL_98;
    }
    v39 = 1;
LABEL_99:
    if ( v39 )
    {
      v29 = v61;
      goto LABEL_119;
    }
LABEL_116:
    KeReleaseInStackQueuedSpinLock((int)v70);
    v5 = a5;
    v8 = v52;
    ++v62;
    v6 = v27;
    if ( v62 >= 0x19 )
      return 0;
  }
  v30 = v55;
LABEL_119:
  RtlSetBits((_BYTE *)(*(_DWORD *)(v7 + 64) + 12), v30, v27);
  v49 = *(_DWORD *)(v7 + 24) - v27;
  *(_DWORD *)(v7 + 72) = v27 + v30;
  v50 = *(_DWORD *)(v7 + 12);
  *(_DWORD *)(v7 + 24) = v49;
  if ( v50 >= v49 )
    v50 = v49;
  v51 = v67;
  *(_DWORD *)(v7 + 28) = v50;
  if ( v51 > v27 && v50 > v27 && v50 <= v63 )
    *(_DWORD *)(v7 + 28) = v27;
  if ( (a5 & 2) == 0 )
    KeReleaseInStackQueuedSpinLock((int)v70);
LABEL_58:
  if ( v29 )
    v31 = 2;
  else
    v31 = 0;
  MI_SET_PAGING_FILE_INFO(v65, v65, v7, v30, v31);
  if ( v27 != v69 )
  {
    if ( v66 )
      MiUpdateReserveClusterInfo(v64, v66, v27);
  }
  return v27;
}
