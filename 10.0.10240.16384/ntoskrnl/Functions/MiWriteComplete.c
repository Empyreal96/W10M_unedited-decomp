// MiWriteComplete 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiWriteComplete(_DWORD *a1, int *a2, int a3)
{
  _DWORD *v3; // r4
  int v4; // r5
  int v6; // r10
  char v7; // r9
  int v8; // r7
  int v9; // r1
  int result; // r0
  int v11; // r2
  int *v12; // r7
  int v13; // r6
  unsigned int v14; // r8
  int v15; // r6
  int v16; // r0
  int v17; // r6
  int v18; // r2
  int v19; // r4
  int v20; // r2
  unsigned int v21; // r6
  unsigned int v22; // r9
  unsigned int v23; // r3
  int *v24; // r1
  int v25; // r2
  int v26; // t1
  int v27; // r4
  int v28; // r10
  unsigned __int8 *v29; // r3
  unsigned int v30; // r1
  int v31; // r8
  unsigned int *v32; // r2
  unsigned int v33; // r4
  int v34; // r1
  int v35; // r4
  int v36; // r9
  int v37; // r7
  int v38; // r8
  int v39; // r0
  unsigned int *v40; // r2
  unsigned int v41; // r1
  int v42; // r0
  int *v43; // r2
  int v44; // r3
  int *v45; // r1
  int v46; // r10
  unsigned __int8 *v47; // r1
  int v48; // r3
  unsigned int v49; // r2
  BOOL v50; // r0
  char v51; // r3
  char v52; // r3
  int v53; // r4 OVERLAPPED
  int v54; // r0
  int (*v55)(); // r3
  int *v56; // r1
  int v57; // [sp+8h] [bp-48h]
  int v58; // [sp+Ch] [bp-44h]
  int v60; // [sp+14h] [bp-3Ch]
  int v61; // [sp+18h] [bp-38h]
  unsigned int v62; // [sp+1Ch] [bp-34h] BYREF
  int *v63; // [sp+20h] [bp-30h]
  int v64[2]; // [sp+28h] [bp-28h] BYREF
  int v65; // [sp+30h] [bp-20h]

  v3 = (_DWORD *)a1[31];
  v4 = 0;
  v65 = a3;
  v6 = (int)a1;
  v7 = 0;
  if ( !v3 )
    v3 = a1 + 32;
  v8 = a1[30];
  v9 = a1[19];
  v58 = v8;
  v61 = v9;
  if ( (*((_WORD *)v3 + 3) & 0x200) != 0 )
    return sub_531030();
  if ( (*((_WORD *)v3 + 3) & 1) != 0 )
  {
    MmUnmapLockedPages(v3[3], v3);
    v9 = v61;
  }
  v11 = *a2;
  v57 = *a2;
  v60 = *(_DWORD *)(v6 + 92);
  if ( v60 )
  {
    v63 = (int *)(v8 + 592);
  }
  else
  {
    KeQuerySystemTime(v64);
    MI_PAGEFILE_WRITE(v6, v64, 5, 0, v57);
    v9 = v61;
    v63 = (int *)(v8 + 588);
    v11 = v57;
  }
  v12 = v3 + 7;
  v13 = *(_DWORD *)(v6 + 96);
  v14 = (unsigned int)&v3[((v9 & 0xFFF) != 0) + 7 + (v9 >> 12)];
  if ( v13 )
  {
    v46 = *(_DWORD *)(v6 + 88);
    if ( (v13 & 1) != 0 )
      v13 &= 0xFFFFFFFE;
    else
      CcNotifyOfMappedWriteComplete(*(_DWORD *)(v46 + 20), v9, a1[26], a1[27], v9, v11);
    FsRtlReleaseFileForModWrite(v46, v13);
    v15 = v60;
    MI_DEREFERENCE_CONTROL_AREA_FILE(v60, v46);
    v6 = (int)a1;
    v11 = v57;
  }
  else
  {
    v15 = v60;
  }
  if ( v11 >= 0 )
  {
    v19 = v58;
    goto LABEL_17;
  }
  v16 = v15 != 0;
  v17 = (*(_DWORD *)(v6 + 20) >> 1) & 1;
  if ( !MmIsWriteErrorFatal(v16, v17, v11) )
  {
    v18 = v57;
LABEL_14:
    v4 = 1;
    goto LABEL_15;
  }
  if ( !v60 )
    KeBugCheck2(122, 32, v57, v3, 0, 0);
  v18 = v57;
  if ( (*(_DWORD *)(v60 + 28) & 0x10) != 0 )
    goto LABEL_15;
  if ( v57 == -1073741670
    || v57 == -1073741663
    || v57 == -1073741801
    || v61 > 4096 && (v50 = FsRtlIsTotalDeviceFailure(v57), v18 = v57, !v50) )
  {
    if ( v17 && v14 > (unsigned int)(v3 + 8) )
      goto LABEL_14;
  }
  v7 = 1;
LABEL_15:
  v15 = v60;
  v19 = v58;
  if ( v60 )
    *(_DWORD *)(v58 + 388) = v18;
  else
    *(_DWORD *)(v58 + 384) = v18;
LABEL_17:
  v64[0] = v7 & 1;
  if ( (v7 & 1) != 0 )
    MiSetDeleteOnClose(v15, 1);
  v20 = *(_DWORD *)(v6 + 84);
  if ( v20 )
  {
    v62 = 0;
    MI_SET_PAGING_FILE_INFO(&v62, &v62, v20, *(__int64 *)(v6 + 104) >> 12, 1);
    v21 = v62;
  }
  else
  {
    v21 = 0;
  }
  v22 = 0;
  if ( (unsigned int)v12 > v14 )
    v23 = 0;
  else
    v23 = (v14 - (unsigned int)v12 + 3) >> 2;
  v62 = v23;
  if ( v23 )
  {
    v24 = MiState;
    do
    {
      v26 = *v12++;
      v25 = v26;
      if ( v26 == v24[1949] )
      {
        if ( (*(_DWORD *)(v6 + 20) & 0x20) == 0 )
          MiReleasePageFileInfo(v19, v21, 0);
      }
      else
      {
        v27 = MmPfnDatabase + 24 * v25;
        v28 = KfRaiseIrql(2);
        v29 = (unsigned __int8 *)(v27 + 15);
        do
          v30 = __ldrex(v29);
        while ( __strex(v30 | 0x80, v29) );
        __dmb(0xBu);
        if ( v30 >> 7 )
        {
          v47 = (unsigned __int8 *)(v27 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v48 = *(_DWORD *)(v27 + 12);
              __dmb(0xBu);
            }
            while ( v48 < 0 );
            do
              v49 = __ldrex(v47);
            while ( __strex(v49 | 0x80, v47) );
            __dmb(0xBu);
          }
          while ( v49 >> 7 );
        }
        if ( (v4 & 1) == 0 )
        {
          if ( (*(_BYTE *)(v27 + 18) & 0x10) == 0 || (*(_DWORD *)(v27 + 8) & 0x400) != 0 )
            v4 &= 0xFFFFFFFD;
          else
            v4 |= 2u;
        }
        v4 &= 0xFFFFFFFB;
        if ( (a1[5] & 0x20) != 0 && (v4 & 2) == 0 && (*(_DWORD *)(v27 + 12) & 0x40000000) == 0 )
        {
          v51 = *(_BYTE *)(v27 + 18);
          if ( *(unsigned __int16 *)(v27 + 16) > 1u )
          {
            v52 = v51 | 0x10;
            v4 |= 2u;
          }
          else
          {
            v52 = v51 & 0xF8 | 2;
            v4 |= 4u;
          }
          *(_BYTE *)(v27 + 18) = v52;
        }
        v31 = MiWriteCompletePfn(v27, v4);
        __dmb(0xBu);
        v32 = (unsigned int *)(v27 + 12);
        do
          v33 = __ldrex(v32);
        while ( __strex(v33 & 0x7FFFFFFF, v32) );
        KfLowerIrql(v28);
        if ( v31 )
          MiReleasePageFileInfo(v58, v31, 0);
        v6 = (int)a1;
      }
      v21 = v21 & 0x1FFF ^ ((v21 & 0xFFFFE000) + 0x2000);
      ++v22;
      v24 = MiState;
      v19 = v58;
    }
    while ( v22 < v62 );
  }
  v34 = *(_DWORD *)(v6 + 80);
  v35 = v58;
  if ( v34 )
    MiReleaseWriteInProgressCharges(v58, v34, *(_DWORD *)(v6 + 84) == 0);
  if ( !*(_DWORD *)(v6 + 84) )
    goto LABEL_42;
  if ( (*(_DWORD *)(v6 + 20) & 0x1Cu) < 8 )
    --*(_DWORD *)(v58 + 400);
  v45 = *(int **)(v58 + 540);
  *(_DWORD *)v6 = v58 + 536;
  *(_DWORD *)(v6 + 4) = v45;
  if ( *v45 != v58 + 536 )
    __fastfail(3u);
  *v45 = v6;
  *(_DWORD *)(v58 + 540) = v6;
  if ( *(_BYTE *)(v58 + 381) == 1 )
    v36 = v58 + 544;
  else
LABEL_42:
    v36 = 0;
  v37 = v64[0];
  if ( !v60 )
  {
    v38 = v57;
    goto LABEL_54;
  }
  if ( !v64[0] )
    goto LABEL_45;
  v53 = ExAllocatePoolWithTag(512, 32, 1885629773);
  if ( !v53 )
  {
    v35 = v58;
LABEL_45:
    v38 = v57;
    goto LABEL_46;
  }
  v54 = MI_REFERENCE_CONTROL_AREA_FILE(v60);
  v38 = v57;
  *(_BYTE *)(v53 + 28) = 1;
  v55 = MiLdwPopupWorker;
  *(_DWORD *)(v53 + 16) = v54;
  *(_DWORD *)(v53 + 20) = v57;
  *(_QWORD *)(v53 + 8) = *(_QWORD *)(&v53 - 1);
  *(_DWORD *)v53 = 0;
  ExQueueWorkItem((_DWORD *)v53, 1);
  v35 = v58;
LABEL_46:
  v39 = MiDecrementModifiedWriteCount(v60, 0);
  if ( v39 )
    MiReleaseControlAreaWaiters(v39);
  v40 = (unsigned int *)(v35 + 348);
  do
    v41 = __ldrex(v40);
  while ( __strex(v41 - 1, v40) );
  v42 = *(_DWORD *)(v6 + 124);
  if ( v42 )
    ExFreePoolWithTag(v42, 0);
  result = 1;
  if ( (*(_DWORD *)(v6 + 20) & 1) == 0 )
  {
    MiFreeModWriterEntry(v6, 1);
LABEL_54:
    result = 1;
    goto LABEL_55;
  }
  v56 = *(int **)(v35 + 360);
  *(_DWORD *)v6 = v35 + 356;
  *(_DWORD *)(v6 + 4) = v56;
  if ( *v56 != v35 + 356 )
    __fastfail(3u);
  *v56 = v6;
  *(_DWORD *)(v35 + 360) = v6;
  if ( *(_BYTE *)(v35 + 380) == 1 )
  {
    *(_BYTE *)(v35 + 380) = 0;
    KeSignalGate(v35 + 364, 1);
    goto LABEL_54;
  }
LABEL_55:
  if ( v38 >= 0 )
  {
    if ( v60 )
      *(_BYTE *)(v35 + 596) = 0;
    v43 = v63;
    if ( !*v63 )
      goto LABEL_59;
    v44 = *v63 - 1;
  }
  else
  {
    if ( v65 )
    {
      if ( !v37 )
        *(_BYTE *)(v35 + 596) = 1;
      goto LABEL_59;
    }
    if ( v38 != -1073741670
      && v38 != -1073741663
      && v38 != -1073741801
      && (v61 <= 4096 || (result = FsRtlIsTotalDeviceFailure(v38)) != 0)
      && v38 != -1073741740 )
    {
      goto LABEL_59;
    }
    v43 = v63;
    v44 = 10;
  }
  *v43 = v44;
LABEL_59:
  if ( v36 )
    result = KeSetEvent(v36, 0, 0);
  return result;
}
