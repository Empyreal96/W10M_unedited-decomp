// MiScanLeafNonPagedPool 
 
int __fastcall MiScanLeafNonPagedPool(unsigned int a1, int a2, int a3, _DWORD *a4, unsigned int a5, unsigned int a6, int a7)
{
  int v7; // lr
  unsigned int v8; // r10
  _DWORD *v10; // r5
  unsigned int v11; // r1
  unsigned int v13; // r2
  unsigned int v14; // r9
  int v15; // r7
  unsigned int v16; // r0
  int v17; // r6
  unsigned int v18; // r5
  unsigned int v19; // lr
  unsigned int *v20; // r1
  int v21; // r2
  unsigned int v22; // r4
  bool v23; // cc
  int v24; // r9
  unsigned int v25; // r7
  unsigned int v26; // r0
  int v27; // r4
  int v28; // r5
  _DWORD *v29; // r10
  int v30; // r9
  int v31; // r4
  int v32; // r0
  int v33; // r4
  unsigned int *v34; // r7
  unsigned int v35; // r0
  unsigned int v36; // r4
  unsigned int v37; // r0
  int v38; // r2
  unsigned int v39; // r3
  int v40; // t1
  unsigned int v41; // r3
  int v42; // r2
  char v43; // r0
  unsigned int *v44; // r2
  unsigned int v45; // r0
  unsigned int v46; // r2
  unsigned int v47; // r3
  int v48; // r2
  unsigned int v49; // r0
  int v50; // t1
  unsigned int v51; // r5
  unsigned int v52; // r0
  _DWORD *v54; // [sp+14h] [bp-44h]
  int v55; // [sp+18h] [bp-40h]
  unsigned int v56; // [sp+1Ch] [bp-3Ch]
  unsigned int v58; // [sp+28h] [bp-30h] BYREF
  int v59; // [sp+2Ch] [bp-2Ch]
  char v60[40]; // [sp+30h] [bp-28h] BYREF

  v54 = a4;
  v7 = dword_6337E8 + 176 * a2;
  v8 = a5;
  v58 = a6;
  v59 = *(_DWORD *)(v7 + 164) + 4 * (a5 >> 5);
  v10 = a4;
  v55 = v7;
  v11 = a7 - a5;
  if ( *a4 == 2 )
    return sub_548EC4();
  v13 = v58;
  if ( v11 >= v58 )
    v14 = 0;
  else
    v14 = a7 - a5;
  v15 = v59;
  v16 = v58 - 1;
  v17 = -1;
  if ( !a1 )
  {
    v22 = v14 & 0xFFFFFFF8;
    goto LABEL_17;
  }
  while ( v16 - v14 + 1 < a1 )
  {
    v22 = -1;
LABEL_39:
    if ( !v14 )
      goto LABEL_16;
    v52 = a1 + v11;
    if ( a1 + v11 > v13 )
      v52 = v13;
    v15 = v59;
    v16 = v52 - 1;
    v14 = 0;
  }
  v18 = v16 - a1 + 1;
  v19 = v15 + 4 * (v18 >> 5);
  v20 = (unsigned int *)(v15 + 4 * (v14 >> 5));
  v56 = v18;
  v21 = ((1 << (v14 & 0x1F)) - 1) | *v20;
  if ( a1 > 0x3F )
  {
    if ( (v18 & 0x1F) != 0 )
      v19 += 4;
    if ( !v21 )
    {
      v42 = 0;
      goto LABEL_72;
    }
    if ( !*++v20 )
    {
      v41 = __clz(v21);
      goto LABEL_70;
    }
LABEL_67:
    while ( (unsigned int)v20 <= v19 )
    {
      if ( !*++v20 )
      {
        v41 = __clz(*(v20 - 1));
LABEL_70:
        if ( 1 == (unsigned __int8)(v41 >> 5) )
          v42 = 32;
        else
          v42 = v41;
LABEL_72:
        v22 = 32 * (((int)v20 - v15) >> 2) - v42;
        if ( v22 > v18 )
          break;
        v43 = a1 - v42;
        v44 = &v20[(a1 - v42) >> 5];
        while ( ++v20 != v44 )
        {
          if ( *v20 )
            goto LABEL_67;
        }
        v45 = v43 & 0x1F;
        if ( !v45 )
          goto LABEL_15;
        v46 = __clz(__rbit(*v20));
        if ( 1 == (unsigned __int8)(v46 >> 5) )
          v46 = 32;
        if ( v46 >= v45 )
          goto LABEL_15;
      }
    }
    v22 = -1;
LABEL_38:
    v11 = a7 - a5;
    v13 = v58;
    goto LABEL_39;
  }
  if ( a1 >= 0x20 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( (v21 & 0x80000000) != 0 )
        {
          if ( (unsigned int)++v20 > v19 )
            goto LABEL_37;
          v21 = *v20;
        }
        v47 = __clz(v21);
        if ( 1 == (unsigned __int8)(v47 >> 5) )
          v48 = 32;
        else
          v48 = v47;
        v22 = 32 * ((((int)v20 - v15) >> 2) + 1) - v48;
        if ( v22 > v18 )
          goto LABEL_37;
        v49 = a1 - v48;
        if ( a1 == v48 )
          goto LABEL_15;
        v50 = v20[1];
        ++v20;
        v21 = v50;
        if ( v49 >= 0x20 )
          break;
LABEL_91:
        v51 = __clz(__rbit(v21));
        if ( 1 == (unsigned __int8)(v51 >> 5) )
          v51 = 32;
        if ( v51 >= v49 )
          goto LABEL_15;
        v18 = v56;
      }
      if ( !v21 )
      {
        v49 -= 32;
        if ( !v49 )
          goto LABEL_15;
        v21 = *++v20;
        goto LABEL_91;
      }
    }
  }
  if ( a1 > 1 )
  {
    v33 = 0;
    v34 = (unsigned int *)(v15 + 4 * (v16 >> 5));
    while ( v21 != -1 )
    {
LABEL_43:
      v35 = __clz(__rbit(v21));
      if ( 1 == (unsigned __int8)(v35 >> 5) )
        v35 = 32;
      if ( v35 + v33 >= a1 )
      {
        v38 = -v33;
LABEL_50:
        v22 = v38 + 32 * (((int)v20 - v59) >> 2);
        v23 = v22 > v18;
        goto LABEL_14;
      }
      v36 = ~v21;
      v37 = a1;
      while ( 1 )
      {
        v36 &= v36 >> (v37 >> 1);
        if ( !v36 )
          break;
        v37 -= v37 >> 1;
        if ( v37 <= 1 )
        {
          v38 = __clz(__rbit(v36));
          goto LABEL_50;
        }
      }
      if ( v20 == v34 )
        goto LABEL_37;
      v39 = __clz(v21);
      if ( 1 == (unsigned __int8)(v39 >> 5) )
        v33 = 32;
      else
        v33 = v39;
      v40 = v20[1];
      ++v20;
      v21 = v40;
    }
    while ( 1 )
    {
      if ( (unsigned int)++v20 > v19 )
        goto LABEL_37;
      v21 = *v20;
      if ( *v20 != -1 )
      {
        v33 = 0;
        goto LABEL_43;
      }
    }
  }
  while ( v21 == -1 )
  {
    if ( (unsigned int)++v20 > v19 )
      goto LABEL_37;
    v21 = *v20;
  }
  v22 = __clz(__rbit(~v21)) + 32 * (((int)v20 - v15) >> 2);
  v23 = v22 > v18;
LABEL_14:
  if ( v23 )
  {
LABEL_37:
    v22 = -1;
    goto LABEL_38;
  }
LABEL_15:
  if ( v22 == -1 )
    goto LABEL_38;
LABEL_16:
  v8 = a5;
  v10 = v54;
  v7 = v55;
  v11 = a7 - a5;
LABEL_17:
  if ( v22 == -1 || *((_BYTE *)v10 + 24) == 1 && v22 < v11 )
    return v17;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(v7 + 128), (unsigned int)v60);
  v24 = v55 + 4 * a3;
  v25 = *(_DWORD *)(v24 + 168);
  if ( v25 < v8 || *((_BYTE *)v10 + 24) == 1 || v25 >= a6 + v8 )
  {
    v25 = -1;
  }
  else if ( v22 + v8 < v25 )
  {
    v22 = v25 - v8;
  }
  if ( *v10 == 1 )
  {
    v30 = a2;
    v28 = MiCheckPoolForContiguousPages(&v58, a1, v22, v10, v8, a2);
    if ( v28 != -1 )
    {
      v29 = v54;
      v27 = -1;
      goto LABEL_32;
    }
  }
  else
  {
    v26 = RtlFindClearBitsAndSet(&v58, a1, v22);
    v27 = v26;
    if ( v26 != -1 )
    {
      if ( *((_BYTE *)v10 + 24) == 1 && v26 < a7 - a5 )
      {
        RtlClearBits(&v58, v26, a1);
        goto LABEL_113;
      }
      v28 = v26 + v8;
      v29 = v54;
      if ( a1 == 1 && v25 != -1 && !*v54 )
        *(_DWORD *)(v24 + 168) = v28 + 1;
      v30 = a2;
LABEL_32:
      MiAllocatingNonPagedPoolVa(v55, a3, v28, a1);
      if ( !a3 && a1 <= 3 && !*v29 )
        MiReplenishNonPagedSlists(&v58, v30, v28 - v27, v27, a1);
      v31 = MiIncreaseNonPagedPoolUsage(v55);
      v32 = KeReleaseInStackQueuedSpinLock((int)v60);
      if ( v31 == 1 )
        MiTrimSegmentCache(v32);
      return v28;
    }
  }
LABEL_113:
  KeReleaseInStackQueuedSpinLock((int)v60);
  return v17;
}
