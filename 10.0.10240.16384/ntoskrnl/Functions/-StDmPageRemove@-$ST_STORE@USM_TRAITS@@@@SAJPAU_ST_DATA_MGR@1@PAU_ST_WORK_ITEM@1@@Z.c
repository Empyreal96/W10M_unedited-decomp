// -StDmPageRemove@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_ST_WORK_ITEM@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmPageRemove(int a1, int a2)
{
  int v2; // r5
  unsigned int v4; // r8
  int v5; // r3
  int v6; // r9
  int v7; // r3
  int v8; // r5
  int v9; // r0
  unsigned int v10; // r6
  unsigned __int16 *v11; // r7
  int v12; // r5
  unsigned int v13; // r3
  _DWORD **v14; // r3
  _DWORD **v15; // r3
  int v16; // r2
  unsigned int v17; // r10
  int v18; // r8
  int v19; // r2
  unsigned __int16 **v20; // r5
  int v21; // r3
  int v22; // r2
  int v23; // r3
  _DWORD *v24; // r2
  int v25; // r0
  int v26; // r2
  _DWORD *v27; // r3
  int v28; // r5
  unsigned int v29; // r2
  unsigned int v30; // r1
  int v31; // r0
  unsigned int v32; // r2
  int v33; // r0
  int v34; // r2
  unsigned int *v35; // r5
  unsigned int v36; // r1
  __int16 v37; // r3
  int v38; // r5
  int v39; // r6
  unsigned int v40; // r2
  unsigned __int8 *v41; // r7
  int v42; // r0
  int v43; // r6
  unsigned int v44; // r2
  int v45; // r3
  int *v46; // r1
  int v47; // r2
  unsigned int *v48; // r5
  unsigned int v49; // r1
  unsigned int v50; // r1
  __int16 v51; // r3
  int v52; // r5
  int v53; // r6
  unsigned int v54; // r2
  unsigned __int8 *v55; // r7
  int v56; // r0
  int v57; // r6
  unsigned int v58; // r2
  int v59; // r3
  int v60; // r0
  int v61; // r1
  unsigned int v62; // r2
  unsigned int v63; // r5
  char v64; // r3
  int v65; // r0
  unsigned int v67; // [sp+0h] [bp-60h]
  int v68; // [sp+4h] [bp-5Ch]
  int v69; // [sp+8h] [bp-58h]
  int v70; // [sp+Ch] [bp-54h]
  int v71[2]; // [sp+10h] [bp-50h] BYREF
  unsigned __int16 *v72; // [sp+18h] [bp-48h] BYREF
  int v73; // [sp+1Ch] [bp-44h]
  unsigned int v74; // [sp+20h] [bp-40h]
  int v75; // [sp+24h] [bp-3Ch]
  int v76; // [sp+28h] [bp-38h]
  unsigned int v77; // [sp+2Ch] [bp-34h]
  void *v78; // [sp+30h] [bp-30h]
  unsigned int v79; // [sp+38h] [bp-28h] BYREF
  int v80; // [sp+3Ch] [bp-24h]

  v72 = 0;
  v73 = 0;
  v2 = a2;
  v75 = a2;
  if ( (dword_636E9C & 0x10) != 0 )
    v78 = &unk_636E90;
  else
    v78 = 0;
  v4 = *(_DWORD *)(a2 + 4) + *(_DWORD *)(a2 + 8) - 1;
  v5 = *(_DWORD *)(a1 + 32);
  v77 = v4;
  if ( (v5 & 1) != 0 )
    B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1, a1 + 12);
  *(_DWORD *)(a1 + 32) &= 0xFFFFFFFE;
  if ( (*(_DWORD *)(a1 + 68) & 1) != 0 )
    B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(
      a1 + 36,
      a1 + 48);
  v6 = 0;
  *(_DWORD *)(a1 + 68) &= 0xFFFFFFFE;
  v7 = 0;
  v71[0] = 0;
  v76 = 0;
  while ( 1 )
  {
    v8 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
           (unsigned __int16 **)a1,
           *(_DWORD *)(v2 + 4),
           a1 + 12,
           v7);
    if ( v8 == -1073741818 )
      break;
    v9 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeIteratorFromSearchResult(
           a1,
           &v72,
           a1 + 12);
    v11 = v72;
    v10 = v73;
    v12 = v75;
    while ( 1 )
    {
      if ( !v11 )
      {
LABEL_94:
        if ( v6 )
        {
          v47 = *(_DWORD *)(a1 + 92);
          if ( (*(_BYTE *)(v47 + 3517) & 4) != 0 )
          {
            v48 = (unsigned int *)(v47 + 3520);
            __dmb(0xBu);
            do
              v49 = __ldrex(v48);
            while ( __strex(v49 - 1, v48) );
            if ( (v49 & 2) != 0 && (v49 & 4) == 0 )
              ExfTryToWakePushLock(v48);
            v9 = KeAbPostRelease((unsigned int)v48);
            v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v51 = *(_WORD *)(v50 + 0x136) + 1;
            *(_WORD *)(v50 + 310) = v51;
            if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 )
              v9 = KiCheckForKernelApcDelivery(v9);
          }
          SMKM_STORE_MGR<SM_TRAITS>::SmEvictKeys(v9, v71, v6, *(_DWORD *)(a1 + 92), v67, v68, v69, v70);
          v52 = *(_DWORD *)(a1 + 92);
          if ( (*(_BYTE *)(v52 + 3517) & 4) != 0 )
          {
            v53 = 20;
            v79 = -150000;
            v80 = -1;
            while ( *(_DWORD *)(v52 + 3868) && v53 && *(unsigned __int8 *)(v52 + 3518) >= 3u )
            {
              KeDelayExecutionThread(0, 0, &v79);
              --v53;
            }
            v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v54 + 310);
            v55 = (unsigned __int8 *)(v52 + 3520);
            v56 = KeAbPreAcquire(v52 + 3520, 0, 0);
            v57 = v56;
            do
              v58 = __ldrex(v55);
            while ( __strex(v58 | 1, v55) );
            __dmb(0xBu);
            if ( (v58 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx((_DWORD *)(v52 + 3520), v56, v52 + 3520);
            if ( v57 )
              *(_BYTE *)(v57 + 14) |= 1u;
            v59 = *(_DWORD *)(v52 + 3528);
            *(_DWORD *)(v52 + 3524) = 1;
            *(_DWORD *)(v52 + 3528) = v59 + 1;
          }
        }
        if ( !*(_BYTE *)(a1 + 72) && (*(_BYTE *)(a1 + 756) & 3) != 3 )
        {
          v60 = ST_STORE<SM_TRAITS>::StDmCheckForCompaction(a1, 0);
          if ( v60 )
          {
            v61 = (*(_DWORD *)(a1 + 116) & 2) != 0;
            if ( v60 == 1 )
            {
              if ( *(_BYTE *)(a1 + 72) )
                v62 = 400;
              else
                v62 = 30;
              v63 = -2;
              v64 = *(_BYTE *)(a1 + 756) & 0xFC | 1;
            }
            else
            {
              v64 = *(_BYTE *)(a1 + 756) & 0xFC | 2;
              v62 = 0;
              v63 = 0;
            }
            v65 = *(_DWORD *)(a1 + 760);
            *(_BYTE *)(a1 + 756) = v64;
            ST_STORE<SM_TRAITS>::StLazyWorkMgrQueueWork(v65, v61, v62, v63);
          }
        }
        v8 = 0;
        goto LABEL_128;
      }
      v10 += 16;
      v13 = (unsigned int)&v11[8 * *v11 + 4];
      v73 = v10;
      if ( v10 >= v13 )
      {
        v14 = (_DWORD **)(a1 + 8);
        if ( !a1 )
          v14 = 0;
        if ( **v14 == -1 )
        {
          v15 = (_DWORD **)(a1 + 8);
          if ( !a1 )
            v15 = 0;
          if ( **v15 == -1 )
            v9 = *((_DWORD *)v11 + 1);
          else
            v9 = 3358;
        }
        else
        {
          v9 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeFindLeafSibling(a1, v11);
          if ( v9 == -1 )
          {
            v16 = -1;
            goto LABEL_28;
          }
        }
        if ( !v9 )
        {
          v16 = 0;
          goto LABEL_28;
        }
        v10 = v9 + 8;
        v72 = (unsigned __int16 *)v9;
        v73 = v9 + 8;
        v11 = (unsigned __int16 *)v9;
      }
      v16 = v10;
LABEL_28:
      if ( v16 == -1 )
      {
        v8 = -1073741818;
        goto LABEL_128;
      }
      if ( !v16 || v4 < *(_DWORD *)v16 )
        goto LABEL_94;
      v74 = *(_DWORD *)v16;
      v17 = *(_DWORD *)(v16 + 4);
      v18 = *(_DWORD *)(v16 + 8) & 0xFFF;
      if ( !v18 )
        v18 = 4096;
      if ( (*(_DWORD *)(v12 + 12) & 2) == 0 || (*(_BYTE *)(v16 + 11) & 1) != 0 )
        break;
      v4 = v77;
    }
    v19 = *(_DWORD *)(a1 + 24);
    if ( v19 == -1 || !v19 )
      v20 = (unsigned __int16 **)(a1 + 16);
    else
      v20 = (unsigned __int16 **)(*(_DWORD *)(a1 + 12) + 8 * v19 - 8);
    if ( *v20 == v11 )
    {
LABEL_42:
      v20[1] = (unsigned __int16 *)v10;
    }
    else
    {
      B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1, a1 + 12);
      v21 = *(_DWORD *)(a1 + 24);
      if ( v21 == -1 )
      {
        *v20 = v11;
        goto LABEL_42;
      }
      B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
        (unsigned __int16 **)a1,
        *((_DWORD *)v11 + 2),
        a1 + 12,
        v21);
      v22 = *(_DWORD *)(a1 + 24);
      if ( v22 == -1 || !v22 )
        v23 = a1 + 16;
      else
        v23 = *(_DWORD *)(a1 + 12) + 8 * v22 - 8;
      *(_DWORD *)(v23 + 4) = v10;
    }
    B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeIteratorCleanup(&v72, a1);
    v72 = 0;
    v73 = 0;
    v8 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeDeleteEx(
           a1,
           (_DWORD *)(a1 + 12),
           v24,
           0);
    if ( v8 < 0 )
      break;
    v25 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
            (unsigned __int16 **)(a1 + 36),
            v17,
            a1 + 48);
    v8 = v25;
    if ( v25 >= 0 )
    {
      v8 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteEx(
             a1 + 36,
             (_DWORD *)(a1 + 48),
             v26,
             v27);
      if ( v8 < 0 )
        break;
      v28 = *(_DWORD *)(a1 + 304);
      v29 = (unsigned int)(*(_DWORD *)(a1 + 112) + v18 + 15) >> 4;
      v30 = v17 >> *(_DWORD *)(a1 + 100);
      if ( *(_BYTE *)(a1 + 72) )
        v31 = 0;
      else
        v31 = *(unsigned __int16 *)(v28 + 2 * v30) >> 13;
      *(_WORD *)(v28 + 2 * v30) -= v29;
      *(_DWORD *)(a1 + 8 * v31 + 688) -= v29;
      if ( (*(_WORD *)(v28 + 2 * v30) & 0x1FFF) == 0 && v30 != *(_DWORD *)(a1 + 12 * v31 + 392) )
        ST_STORE<SM_TRAITS>::StReleaseRegion(a1, v30);
      v7 = *(_DWORD *)(v75 + 12);
      if ( (v7 & 1) != 0 )
      {
        v32 = v74;
        if ( v6 )
        {
          v33 = v76;
          if ( v74 - v76 != v6 )
          {
            v34 = *(_DWORD *)(a1 + 92);
            if ( (*(_BYTE *)(v34 + 3517) & 4) != 0 )
            {
              v35 = (unsigned int *)(v34 + 3520);
              __dmb(0xBu);
              do
                v36 = __ldrex(v35);
              while ( __strex(v36 - 1, v35) );
              if ( (v36 & 2) != 0 && (v36 & 4) == 0 )
                ExfTryToWakePushLock(v35);
              KeAbPostRelease((unsigned int)v35);
              v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v37 = *(_WORD *)(v33 + 0x136) + 1;
              *(_WORD *)(v33 + 310) = v37;
              if ( !v37 && *(_DWORD *)(v33 + 100) != v33 + 100 )
                v33 = KiCheckForKernelApcDelivery(v33);
            }
            SMKM_STORE_MGR<SM_TRAITS>::SmEvictKeys(v33, v71, v6, *(_DWORD *)(a1 + 92), v67, v68, v69, v70);
            v38 = *(_DWORD *)(a1 + 92);
            if ( (*(_BYTE *)(v38 + 3517) & 4) != 0 )
            {
              v39 = 20;
              v79 = -150000;
              v80 = -1;
              while ( *(_DWORD *)(v38 + 3868) && v39 && *(unsigned __int8 *)(v38 + 3518) >= 3u )
              {
                KeDelayExecutionThread(0, 0, &v79);
                --v39;
              }
              v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              --*(_WORD *)(v40 + 310);
              v41 = (unsigned __int8 *)(v38 + 3520);
              v42 = KeAbPreAcquire(v38 + 3520, 0, 0);
              v43 = v42;
              do
                v44 = __ldrex(v41);
              while ( __strex(v44 | 1, v41) );
              __dmb(0xBu);
              if ( (v44 & 1) != 0 )
                ExfAcquirePushLockExclusiveEx((_DWORD *)(v38 + 3520), v42, v38 + 3520);
              if ( v43 )
                *(_BYTE *)(v43 + 14) |= 1u;
              v45 = *(_DWORD *)(v38 + 3528);
              *(_DWORD *)(v38 + 3524) = 1;
              *(_DWORD *)(v38 + 3528) = v45 + 1;
            }
            v32 = v74;
            v6 = 0;
            v76 = v71[0];
          }
        }
        v46 = *(int **)(a1 + 764);
        v7 = *v46;
        if ( !*v46 || v7 == 3 && (v7 = v32 < v46[1]) != 0 )
        {
          if ( !v6 )
          {
            v76 = v32;
            v71[0] = v32;
          }
          ++v6;
        }
      }
    }
    else
    {
      v7 = -1073741275;
      if ( v25 != -1073741275 )
        break;
    }
    v4 = v77;
    v2 = v75;
    if ( v78 )
    {
      v70 = 0;
      v69 = 0;
      v68 = a1;
      v67 = v17;
      SmEtwLogStoreOp(v78, 1);
    }
  }
LABEL_128:
  B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeIteratorCleanup(&v72, a1);
  return v8;
}
