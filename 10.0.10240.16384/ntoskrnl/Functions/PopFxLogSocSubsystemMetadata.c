// PopFxLogSocSubsystemMetadata 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopFxLogSocSubsystemMetadata(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r0
  int v6; // r9
  int v7; // r3
  unsigned int v8; // r2
  _DWORD *v9; // r8
  unsigned int v10; // r4
  _BYTE *v11; // r0
  unsigned int v12; // r7
  unsigned int v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r2
  unsigned int v16; // r4
  _BYTE *v17; // r0
  _DWORD *v18; // r6
  unsigned int v19; // r0
  _DWORD *v20; // r2
  unsigned int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r4
  __int64 v26; // r2
  unsigned __int16 *v27; // lr
  unsigned int v28; // r9
  int v29; // r0
  int v30; // r4 OVERLAPPED
  int v31; // r2
  int v32; // r3
  unsigned __int16 *v33; // r3
  int v34; // r2
  int v35; // r3
  __int64 v36; // kr00_8
  unsigned int v37; // r3
  unsigned int v39; // [sp+8h] [bp-48h] BYREF
  int v40; // [sp+Ch] [bp-44h]
  unsigned int v41; // [sp+10h] [bp-40h]
  _DWORD *v42; // [sp+14h] [bp-3Ch]
  int v43; // [sp+18h] [bp-38h]
  unsigned int v44; // [sp+1Ch] [bp-34h]
  int v45; // [sp+20h] [bp-30h]
  _DWORD *v46; // [sp+24h] [bp-2Ch]
  _BYTE *v47; // [sp+28h] [bp-28h]
  unsigned int v48; // [sp+2Ch] [bp-24h]
  int varg_r0[4]; // [sp+58h] [bp+8h] BYREF

  varg_r0[0] = a1;
  varg_r0[1] = a2;
  varg_r0[2] = a3;
  varg_r0[3] = a4;
  v43 = a2;
  v4 = 0;
  v5 = PopFxLookupSocSubsystemsByPlatformIdleState();
  v6 = v5;
  v40 = v5;
  if ( v5 )
  {
    v7 = *(_DWORD *)(v5 + 12);
    v8 = 0;
    v41 = 0;
    if ( !v7 )
      return v4;
    v9 = (_DWORD *)(v5 + 16);
    v42 = (_DWORD *)(v5 + 16);
    while ( 1 )
    {
      v10 = v9[15];
      v39 = v10;
      if ( !v10 )
        goto LABEL_36;
      v11 = (_BYTE *)ExAllocatePoolWithTag(1, 280 * v10, 1297630800);
      v12 = (unsigned int)v11;
      v47 = v11;
      if ( !v11 )
        return -1073741670;
      memset(v11, 0, 280 * v10);
      v13 = v39;
      v14 = 0;
      if ( v39 )
      {
        v15 = v12;
        do
        {
          *(_DWORD *)(v15 + 4) = v15 + 16;
          *(_DWORD *)(v15 + 12) = v15 + 148;
          *(_WORD *)(v15 + 2) = 128;
          *(_WORD *)(v15 + 10) = 128;
          *(_DWORD *)(v15 + 144) = -1430541637;
          *(_DWORD *)(v15 + 276) = -1430541637;
          v13 = v39;
          ++v14;
          v15 += 280;
        }
        while ( v14 < v39 );
      }
      v16 = v13 + 5;
      v17 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * (v13 + 5), 1297630800);
      v18 = v17;
      v46 = v17;
      if ( v17 )
      {
        memset(v17, 0, 4 * v16);
        v19 = 0;
        *v18 = v43;
        v18[1] = v9[6];
        v18[2] = v9 + 2;
        v18[3] = 0;
        v18[4] = v39;
        if ( v39 )
        {
          v20 = v18;
          v21 = v12;
          do
          {
            v20[5] = v21;
            ++v19;
            ++v20;
            v21 += 280;
          }
          while ( v19 < v39 );
        }
        if ( !PopPluginQuerySocSubsystemMetadata(PopFxProcessorPlugin, v9[5], v18) )
        {
          v4 = -1073741595;
          goto LABEL_32;
        }
        v22 = 0;
        if ( v39 )
        {
          v23 = v12;
          do
          {
            if ( *(_DWORD *)(v23 + 144) != -1430541637 )
              PopFxBugCheck(1798, 40, 1264941344, *(unsigned __int16 *)(v23 + 2));
            if ( *(_DWORD *)(v23 + 276) != -1430541637 )
              PopFxBugCheck(1798, 40, 1449225333, *(unsigned __int16 *)(v23 + 10));
            ++v22;
            v23 += 280;
          }
          while ( v22 < v39 );
        }
        v48 = 5 * v39 + 2;
        v24 = ExAllocatePoolWithTag(1, 16 * v48, 1297630800);
        v25 = v24;
        v45 = v24;
        if ( v24 )
        {
          *(_DWORD *)v24 = varg_r0;
          *(_DWORD *)(v24 + 8) = 1;
          LODWORD(v26) = 0;
          HIDWORD(v26) = &v39;
          *(_DWORD *)(v24 + 4) = 0;
          *(_QWORD *)(v24 + 12) = v26;
          HIDWORD(v26) = 4;
          *(_QWORD *)(v24 + 20) = v26;
          v44 = 0;
          *(_DWORD *)(v24 + 28) = 0;
          if ( v39 )
          {
            v27 = (unsigned __int16 *)v12;
            v28 = v44;
            v29 = v24 + 32;
            v30 = 0;
            do
            {
              *(_DWORD *)(v29 + 4) = 0;
              *(_DWORD *)(v29 + 8) = 16;
              *(_DWORD *)v29 = v9 + 7;
              *(_DWORD *)(v29 + 12) = 0;
              ++v28;
              *((_DWORD *)v27 + 36) = *v27 >> 1;
              *(_DWORD *)(v29 + 16) = v27 + 72;
              *(_DWORD *)(v29 + 20) = 0;
              *(_DWORD *)(v29 + 24) = 4;
              *(_DWORD *)(v29 + 28) = 0;
              v31 = *v27;
              v32 = *((_DWORD *)v27 + 1);
              *(_QWORD *)(v29 + 32) = *(_QWORD *)(&v30 - 1);
              *(_DWORD *)(v29 + 40) = v31;
              *(_DWORD *)(v29 + 44) = 0;
              *((_DWORD *)v27 + 69) = v27[4] >> 1;
              v33 = v27 + 138;
              *(_QWORD *)(v29 + 48) = *(_QWORD *)(&v30 - 1);
              *(_DWORD *)(v29 + 56) = 4;
              *(_DWORD *)(v29 + 60) = 0;
              v34 = v27[4];
              v35 = *((_DWORD *)v27 + 3);
              *(_QWORD *)(v29 + 64) = *(_QWORD *)(&v30 - 1);
              *(_DWORD *)(v29 + 72) = v34;
              *(_DWORD *)(v29 + 76) = 0;
              v29 += 80;
              v27 += 140;
            }
            while ( v28 < v39 );
            v25 = v45;
            v18 = v46;
            v12 = (unsigned int)v47;
            v9 = v42;
            v6 = v40;
          }
          if ( PopDiagSleepStudyHandleRegistered )
          {
            v36 = *(_QWORD *)&PopDiagSleepStudyHandle;
            if ( EtwEventEnabled(PopDiagSleepStudyHandle, unk_61E24C, (int)SLEEPSTUDY_EVT_SCENARIO_BLOCKER_DATA) )
              EtwWrite(v36, SHIDWORD(v36), (int)SLEEPSTUDY_EVT_SCENARIO_BLOCKER_DATA, 0);
            v6 = v40;
          }
          ExFreePoolWithTag(v25);
          goto LABEL_32;
        }
      }
      v4 = -1073741670;
LABEL_32:
      ExFreePoolWithTag(v12);
      if ( v18 )
        ExFreePoolWithTag((unsigned int)v18);
      if ( v4 < 0 )
        return v4;
      v8 = v41;
LABEL_36:
      v37 = *(_DWORD *)(v6 + 12);
      ++v8;
      v9 += 80;
      v41 = v8;
      v42 = v9;
      if ( v8 >= v37 )
        return v4;
    }
  }
  return -1073741584;
}
