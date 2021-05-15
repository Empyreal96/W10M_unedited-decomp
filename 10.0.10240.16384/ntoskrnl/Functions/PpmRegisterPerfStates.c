// PpmRegisterPerfStates 
 
int __fastcall PpmRegisterPerfStates(_DWORD *a1)
{
  int v1; // r6
  unsigned int v2; // r9
  unsigned int v3; // r7
  unsigned int v4; // r0
  int *v5; // r3
  unsigned int v6; // r2
  int v7; // r1
  int *v9; // r1
  int v10; // r2
  int v11; // r10
  int v12; // t1
  unsigned int v13; // r8
  unsigned int v14; // r7
  _BYTE *v15; // r0
  int v16; // r5
  int v17; // r3
  unsigned int v18; // r1
  int *v19; // lr
  int v20; // r7
  int v21; // r2
  int v22; // t1
  int v23; // r0
  int v24; // r1
  int v25; // r4
  int v26; // lr
  _DWORD *v27; // r0
  unsigned int v28; // r2
  int v29; // r1
  int v30; // r7
  _DWORD **v31; // r10
  int v32; // r8
  int v33; // r2
  int v34; // r3
  int v35; // r3
  int v36; // r3
  unsigned int v37; // r0
  int v38; // r2
  int v39; // r0
  int v40; // r8
  unsigned int v41; // r7
  int v42; // r3
  __int64 v43; // r0
  int v44; // r2
  int v45; // r3
  unsigned int v46; // r3
  unsigned int v47; // r2
  int v48; // r6
  int **v49; // r1
  unsigned int v50; // [sp+0h] [bp-68h]
  int v51; // [sp+4h] [bp-64h]
  int v52[2]; // [sp+8h] [bp-60h] BYREF
  int v53[2]; // [sp+10h] [bp-58h] BYREF
  int v54; // [sp+18h] [bp-50h] BYREF
  int v55; // [sp+1Ch] [bp-4Ch]
  unsigned int v56; // [sp+20h] [bp-48h]
  int v57[2]; // [sp+28h] [bp-40h] BYREF
  unsigned int v58; // [sp+30h] [bp-38h]
  _DWORD *v59; // [sp+34h] [bp-34h]
  unsigned int v60; // [sp+38h] [bp-30h] BYREF
  int v61; // [sp+3Ch] [bp-2Ch]
  unsigned int v62; // [sp+40h] [bp-28h]

  v1 = (int)a1;
  v2 = a1[3];
  v55 = a1[4];
  v60 = 65537;
  v3 = a1[8];
  v61 = 0;
  v62 = 0;
  v58 = v2;
  v59 = a1;
  v4 = PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  v5 = v53;
  do
    *v5++ = -1;
  while ( v5 != &v54 );
  v6 = 0;
  if ( v3 )
  {
    v7 = *(_DWORD *)(v1 + 152);
    do
    {
      v4 = *(_DWORD *)(v7 + 8);
      if ( v4 >= 2 )
LABEL_93:
        JUMPOUT(0x8171F4);
      if ( v53[v4] == -1 )
        v53[v4] = v6;
      ++v6;
      v7 += 16;
    }
    while ( v6 < v3 );
  }
  if ( v53[0] != -1 )
  {
    v9 = v53;
    v10 = 2;
    v11 = 0;
    do
    {
      v12 = *v9++;
      if ( v12 != -1 )
        ++v11;
      --v10;
    }
    while ( v10 );
    v13 = (80 * v2 + 191) & 0xFFFFFFF8;
    v14 = (v13 + 40 * v11 * v2 + 7) & 0xFFFFFFF8;
    v57[0] = v13;
    v52[0] = v14;
    v15 = (_BYTE *)ExAllocatePoolWithTag(512, v14 + 192 * v2, 1884115024);
    v16 = (int)v15;
    if ( !v15 )
      JUMPOUT(0x8171F6);
    memset(v15, 0, v14 + 192 * v2);
    v56 = 0;
    v26 = v16 + 184;
    if ( v2 )
    {
      v51 = 0;
      v24 = 0;
      v50 = v13 + v16;
      v54 = 0;
      v25 = v16 + 184;
      do
      {
        v40 = v24 + *(_DWORD *)(v1 + 156);
        if ( *(_BYTE *)(v40 + 3) )
          goto LABEL_93;
        if ( *(_WORD *)v40 || (v41 = *(unsigned __int8 *)(v40 + 2), v41 >= KeNumberProcessors_0) )
          v41 = -1;
        if ( v41 == -1 || (((unsigned int)dword_6174A8 >> v41) & 1) != 0 )
          goto LABEL_93;
        if ( v41 >= KeNumberProcessors_0 )
          v42 = 0;
        else
          v42 = (int)*(&KiProcessorBlock + v41);
        *(_DWORD *)(v25 + 8) = 100;
        *(_DWORD *)v25 = v42;
        *(_DWORD *)(v25 + 4) = *(_DWORD *)(v40 + 4);
        *(_DWORD *)(v25 + 16) = *(_DWORD *)(v40 + 8);
        *(_DWORD *)(v25 + 20) = *(_DWORD *)(v40 + 12);
        v17 = *(_DWORD *)(v40 + 16);
        *(_DWORD *)(v25 + 40) = 100;
        *(_DWORD *)(v25 + 44) = 100;
        *(_DWORD *)(v25 + 60) = 100;
        *(_DWORD *)(v25 + 24) = v17;
        *(_DWORD *)(v25 + 48) = v55;
        v62 |= 1 << v41;
        if ( *(_DWORD *)(v40 + 8) < 0x64u )
        {
          LODWORD(v43) = KeQueryInterruptTime();
          *(_QWORD *)(v25 + 32) = v43;
          PopDiagTraceProcessorThrottlePerfTrack(100 - *(_DWORD *)(v40 + 8), v41);
        }
        v18 = v50;
        v19 = v53;
        v20 = 2;
        do
        {
          v22 = *v19++;
          v21 = v22;
          if ( v22 != -1 )
          {
            v23 = *(_DWORD *)(v1 + 152) + 16 * v21;
            *(_DWORD *)(v18 + 36) = *(_DWORD *)(*(_DWORD *)(v1 + 160) + 4 * (v21 + v51));
            *(_BYTE *)(v18 + 33) = *(_BYTE *)(v23 + 13);
            *(_BYTE *)(v18 + 32) = *(_BYTE *)(v23 + 12);
            *(_BYTE *)(v18 + 34) = *(_DWORD *)(v23 + 4);
            *(_DWORD *)v18 = *(_DWORD *)v23;
            v18 += 40;
          }
          --v20;
        }
        while ( v20 );
        v2 = v58;
        v51 += v11;
        v24 = v54 + 20;
        v25 += 80;
        v50 += 40 * v11;
        ++v56;
        v54 += 20;
      }
      while ( v56 < v58 );
      v13 = v57[0];
      v26 = v16 + 184;
    }
    v44 = v61;
    v45 = v62;
    *(_DWORD *)(v16 + 12) = v60;
    *(_DWORD *)(v16 + 16) = v44;
    *(_DWORD *)(v16 + 20) = v45;
    v46 = v62;
    if ( v62 || (v46 = v60) != 0 )
      v47 = __clz(__rbit(v46));
    else
      v47 = -1;
    if ( v47 >= KeNumberProcessors_0 )
      v34 = 0;
    else
      v34 = (int)*(&KiProcessorBlock + v47);
    *(_DWORD *)(v16 + 8) = v34;
    *(_DWORD *)(v16 + 36) = *(_DWORD *)(v1 + 80);
    *(_DWORD *)(v16 + 44) = *(_DWORD *)(v1 + 88);
    *(_DWORD *)(v16 + 48) = *(_DWORD *)(v1 + 92);
    *(_DWORD *)(v16 + 52) = *(_DWORD *)(v1 + 96);
    *(_DWORD *)(v16 + 56) = *(_DWORD *)(v1 + 100);
    *(_DWORD *)(v16 + 60) = *(_DWORD *)(v1 + 104);
    v35 = *(_DWORD *)(v1 + 84);
    *(_DWORD *)(v16 + 32) = v26;
    *(_DWORD *)(v16 + 40) = v35;
    KeQueryPerformanceCounter(v57, 0);
    v36 = v57[0];
    *(_DWORD *)(v16 + 24) = v2;
    *(_DWORD *)(v16 + 168) = v36;
    v37 = PpmCheckMinimumPeriod;
    *(_DWORD *)(v16 + 172) = v57[1];
    *(_DWORD *)(v16 + 80) = v55;
    *(_DWORD *)(v16 + 84) = *(_DWORD *)(v1 + 20);
    *(_DWORD *)(v16 + 88) = *(_DWORD *)(v1 + 24);
    *(_DWORD *)(v16 + 92) = *(_DWORD *)(v1 + 28);
    *(_BYTE *)(v16 + 112) = *(_WORD *)(v1 + 4);
    *(_DWORD *)(v16 + 72) = *(_DWORD *)(v1 + 124);
    *(_DWORD *)(v16 + 64) = *(_DWORD *)(v1 + 116);
    *(_DWORD *)(v16 + 68) = *(_DWORD *)(v1 + 120);
    *(_BYTE *)(v16 + 116) = *(_BYTE *)(v1 + 40);
    *(_DWORD *)(v16 + 120) = 100;
    *(_BYTE *)(v16 + 113) = *(_BYTE *)(v1 + 6);
    *(_BYTE *)(v16 + 114) = *(_BYTE *)(v1 + 7);
    *(_BYTE *)(v16 + 115) = *(_BYTE *)(v1 + 8);
    *(_BYTE *)(v16 + 28) = *(_BYTE *)(*(_DWORD *)(v16 + 8) + 2986);
    *(_DWORD *)(v16 + 96) = *(_DWORD *)(v1 + 48);
    *(_DWORD *)(v16 + 100) = *(_DWORD *)(v1 + 52);
    *(_DWORD *)(v16 + 104) = *(_DWORD *)(v1 + 56);
    *(_DWORD *)(v16 + 108) = *(_DWORD *)(v1 + 60);
    if ( __PAIR64__(HIDWORD(PpmCheckMinimumPeriod), v37) <= *(unsigned int *)(v1 + 36) )
    {
      LODWORD(PpmCheckMinimumPeriod) = *(_DWORD *)(v1 + 36);
      PpmCheckMinimumPeriod = (unsigned int)PpmCheckMinimumPeriod;
    }
    if ( *(_DWORD *)(v16 + 48) )
    {
      v38 = PpmAllowedActions | 0x100;
      PpmAllowedActions |= 0x100u;
    }
    else
    {
      v38 = PpmAllowedActions;
    }
    if ( *(_DWORD *)(v16 + 44) )
    {
      v38 |= 0x80u;
      PpmAllowedActions = v38;
    }
    if ( *(_DWORD *)(v16 + 40) )
    {
      v38 |= 0x800u;
      PpmAllowedActions = v38;
    }
    if ( *(_DWORD *)(v16 + 52) )
    {
      v38 |= 0x40u;
      PpmAllowedActions = v38;
    }
    if ( *(_DWORD *)(v16 + 60) )
    {
      v38 |= 0x200u;
      PpmAllowedActions = v38;
    }
    if ( *(_DWORD *)(v16 + 56) )
      PpmAllowedActions = v38 | 0x400;
    __dmb(0xFu);
    if ( v2 )
    {
      v32 = v13 + v16;
      v30 = v52[0] + v16;
      v52[0] = 5 * v11;
      v48 = 5 * v11;
      v31 = (_DWORD **)(v16 + 184);
      do
      {
        v27 = *v31;
        v28 = 0;
        v27[809] = 0x10000;
        v52[0] = 0;
        v52[1] = 0;
        v27[800] = v16;
        v27[799] = v30;
        v27[801] = v31;
        v29 = v32;
        do
        {
          if ( v53[v28] != -1 )
          {
            v52[v28] = v29;
            v29 += 40;
          }
          ++v28;
        }
        while ( v28 < 2 );
        PpmInstallFeedbackCounters((int)v27, v52);
        v30 += 192;
        --v2;
        v31 += 20;
        v32 += 8 * v48;
      }
      while ( v2 );
      v1 = (int)v59;
    }
    if ( !PpmPerfGlobalContext )
      PpmPerfGlobalContext = *(_DWORD *)(v1 + 64);
    v33 = PpmPerfControlReadFeedback;
    if ( !PpmPerfControlReadFeedback )
    {
      v33 = *(_DWORD *)(v1 + 128);
      PpmPerfControlReadFeedback = v33;
    }
    if ( !PpmPerfControlAcquirePerformance )
      PpmPerfControlAcquirePerformance = *(_DWORD *)(v1 + 132);
    if ( !PpmPerfControlCommitPerformance )
      PpmPerfControlCommitPerformance = *(_DWORD *)(v1 + 136);
    if ( !PpmParkPreferenceHandler )
      PpmParkPreferenceHandler = *(int (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(v1 + 140);
    if ( !PpmParkMaskHandler )
      PpmParkMaskHandler = *(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(v1 + 144);
    if ( !PpmCheckCompleteHandler )
      PpmCheckCompleteHandler = *(int (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(v1 + 148);
    if ( !PpmPerfControlStartPolicyUpdate )
      PpmPerfControlStartPolicyUpdate = *(int (__fastcall **)(_DWORD))(v1 + 108);
    if ( !PpmPerfControlCompletePolicyUpdate )
      PpmPerfControlCompletePolicyUpdate = *(int (__fastcall **)(_DWORD))(v1 + 112);
    if ( v33 )
      PpmCheckPollForFeedback = 1;
    v49 = (int **)dword_68252C;
    ++PpmPerfDomainCount;
    *(_DWORD *)v16 = &PpmPerfDomainHead;
    *(_DWORD *)(v16 + 4) = v49;
    if ( *v49 != &PpmPerfDomainHead )
      __fastfail(3u);
    *v49 = (int *)v16;
    dword_68252C = v16;
    PpmHeteroComputeRelativePerformance();
    PpmPerfCalculateMinMaxStates(v16);
    word_6174A2 = 1;
    PpmPerfStatesRegistered = 1;
    *(_DWORD *)algn_6174A4 = 0;
    dword_6174A8 |= v62;
    dword_61749C |= 1 << *(_DWORD *)(*(_DWORD *)(v16 + 8) + 20);
    v39 = PopExecuteOnTargetProcessors((int)&v60, (int)PpmUpdateProcessorPolicyCallback, (int)&PpmAllowedActions, 0);
    if ( (v62 & 1) != 0 )
      PpmParkApplyPolicy();
    PpmCheckReInit(v39);
    PpmCheckApplyPerfConstraints(1);
    JUMPOUT(0x7AEA70);
  }
  return sub_8171EC(v4);
}
