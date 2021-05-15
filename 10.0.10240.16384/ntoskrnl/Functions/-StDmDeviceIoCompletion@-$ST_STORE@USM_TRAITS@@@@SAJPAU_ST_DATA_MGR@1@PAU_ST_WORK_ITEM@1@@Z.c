// -StDmDeviceIoCompletion@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_ST_WORK_ITEM@1@@Z 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ST_STORE<SM_TRAITS>::StDmDeviceIoCompletion(int a1, _DWORD *a2)
{
  int v4; // r10
  int v5; // r8
  int *v6; // r2
  int v7; // r3
  int *v8; // r4
  int v9; // r1
  unsigned int v10; // r0
  int v11; // r3
  int v12; // t1
  int v13; // r0
  int v14; // r3
  int v15; // r7
  _DWORD *v16; // r2
  __int16 v17; // r2
  int v18; // r9
  int v19; // r1 OVERLAPPED
  int v20; // r2 OVERLAPPED
  int v21; // r2
  _DWORD *v22; // r4
  int v23; // r1
  unsigned int v24; // r3
  int v25; // r3
  int v26; // r8
  int v27; // r3
  int v28; // r0
  _DWORD *v29; // r2
  int v30; // r0
  unsigned __int64 v31; // kr00_8
  unsigned int *v32; // r2
  unsigned int v33; // lr
  __int64 v35[5]; // [sp+10h] [bp-28h] BYREF

  v4 = *(_DWORD *)(a1 + 304);
  v5 = a2[3] >> *(_DWORD *)(a1 + 100);
  if ( a2[2] )
  {
    v24 = a2[4];
    if ( (v24 & 8) != 0 )
      StEtaIoComplete(*(_DWORD *)(a1 + 276), v24 >> 5, 0, a2 + 1);
    v25 = a2[4];
    if ( (v25 & 4) != 0 )
      v26 = 0;
    else
      v26 = a2[1];
    if ( (v25 & 1) != 0 )
    {
      v27 = a2[2];
      if ( v27 )
        v15 = *(_DWORD *)(v27 + 4);
      else
        v15 = a2[1];
      ST_STORE<SM_TRAITS>::StDmDeviceError(a1, 1, v15);
    }
    else
    {
      v28 = ST_STORE<SM_TRAITS>::StDmDeviceIoTransfer(a1, v26, a2 + 1);
      v29 = *(_DWORD **)(a1 + 680);
      v15 = v28;
      if ( v29 )
      {
        if ( v28 >= 0 )
          ++*v29;
        if ( (a2[4] & 4) == 0 )
        {
          KeQueryPerformanceCounter(v35, 0);
          v30 = *(_DWORD *)(a1 + 680);
          v31 = v35[0] - *(_QWORD *)(a2[2] + 4);
          v32 = *(unsigned int **)(v30 + 1320);
          if ( *(_QWORD *)v32 < v31 || v32 != *(unsigned int **)(v30 + 1328) && *((_QWORD *)v32 - 2) >= v31 )
          {
            v32 = *(unsigned int **)(v30 + 1328);
            v33 = *v32;
            if ( v32[1] <= HIDWORD(v31) )
            {
              if ( v32[1] >= HIDWORD(v31) )
                goto LABEL_69;
              do
              {
                do
                {
                  v32 += 4;
                  v33 = *v32;
                }
                while ( v32[1] < HIDWORD(v31) );
                if ( v32[1] > HIDWORD(v31) )
                  break;
LABEL_69:
                ;
              }
              while ( v33 < (unsigned int)v31 );
            }
            *(_DWORD *)(v30 + 1320) = v32;
          }
          ++v32[2];
        }
      }
    }
    ST_STORE<SM_TRAITS>::StDeviceWorkItemCleanup(a1, a2);
    if ( v26 )
      SmWatchDogDeviceIoComplete(*(_DWORD *)(a1 + 92), v26, v15);
  }
  else
  {
    v6 = (int *)(a1 + 320);
    v7 = *(_DWORD *)(a1 + 320);
    v8 = (int *)(a1 + 320);
    while ( v7 != v5 )
    {
      v8 += 3;
      v7 = *v8;
    }
    v9 = 0;
    if ( *(_BYTE *)(a1 + 72) )
    {
      v10 = a1 + 392;
      if ( v6 < v6 + 18 )
      {
        do
        {
          v12 = *v6;
          v6 += 3;
          v11 = v12;
          if ( v12 != -1 && (*(_WORD *)(v4 + 2 * v11) & 0x8000) != 0 )
            ++v9;
        }
        while ( (unsigned int)v6 < v10 );
        if ( v9 == 1 )
        {
          v13 = ST_STORE<SM_TRAITS>::StDmPickRandomRegion(a1);
          if ( v13 != -1 )
            ST_STORE<SM_TRAITS>::StDmEtaPerformIo(a1, v13, 4096);
        }
      }
    }
    StEtaIoComplete(*(_DWORD *)(a1 + 276), *(_DWORD *)(a1 + 80), 1, a2 + 1);
    if ( (a2[4] & 1) != 0 )
    {
      v14 = a2[2];
      if ( v14 )
        v15 = *(_DWORD *)(v14 + 4);
      else
        v15 = a2[1];
      ST_STORE<SM_TRAITS>::StDmDeviceError(a1, 1, v15);
    }
    else
    {
      v16 = *(_DWORD **)(a1 + 680);
      v15 = 0;
      if ( v16 )
        ++*v16;
    }
    if ( (*(_WORD *)(v4 + 2 * v5) & 0x8000) != 0 )
    {
      v17 = *(_WORD *)(v4 + 2 * v5) & 0x7FFF;
      *(_WORD *)(v4 + 2 * v5) = v17;
      v18 = 1;
      if ( (dword_636E9C & 0x10) != 0 )
        SmEtwLogRegionOp(&unk_636E90, 4, a1, v5, v15, v17 & 0x1FFF, *(unsigned __int8 *)(*(_DWORD *)(a1 + 312) + v5));
      if ( (a2[4] & 1) != 0 )
      {
        ++*(_DWORD *)(a1 + 748);
        if ( (*(_WORD *)(v4 + 2 * v5) & 0x1FFF) != 0 )
          v18 = 0;
      }
    }
    else
    {
      if ( (a2[4] & 1) != 0 )
      {
        v18 = 1;
        ++*(_DWORD *)(a1 + 752);
      }
      else
      {
        v18 = 0;
      }
      *(_QWORD *)&v19 = *(_QWORD *)(a1 + 304);
      if ( *(_BYTE *)(v20 + v5) )
        --*(_BYTE *)(v20 + v5);
      else
        *(_WORD *)(v19 + 2 * v5) &= 0xBFFFu;
    }
    a2[1] = 0;
    a2[2] = 0;
    a2[3] = 0;
    a2[4] = 0;
    if ( v18 )
    {
      if ( *v8 != -1 )
      {
        ExFreePoolWithTag(v8[1], 0);
        ExFreePoolWithTag(v8[2], 0);
      }
      *v8 = 0;
      v8[1] = 0;
      v8[2] = 0;
      *v8 = -1;
      if ( *(_BYTE *)(a1 + 72) )
        v21 = 0;
      else
        v21 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 304) + 2 * v5) >> 13;
      if ( v5 != *(_DWORD *)(a1 + 12 * v21 + 392) )
        v21 = 8;
      if ( v21 != 8 )
      {
        v22 = (_DWORD *)(a1 + 12 * v21);
        if ( v22[98] != -1 )
        {
          if ( !*(_BYTE *)(a1 + 72) )
            ST_STORE<SM_TRAITS>::StUnlockAndUnmapRegion(a1);
          v23 = v22[98];
          if ( (*(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * v23) & 0x1FFF) == 0 )
            ST_STORE<SM_TRAITS>::StReleaseRegion(a1, v23);
        }
        v22[99] = -1;
        v22[100] = 0;
        v22[98] = -1;
      }
    }
  }
  return v15;
}
