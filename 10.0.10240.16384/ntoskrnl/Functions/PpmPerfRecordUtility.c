// PpmPerfRecordUtility 
 
int __fastcall PpmPerfRecordUtility(int result, int a2)
{
  int v2; // r6
  int v4; // r7
  __int64 v5; // r1
  __int64 v6; // r3
  int v7; // r5
  bool v8; // cf
  unsigned __int64 v9; // r8
  unsigned int v10; // r10
  unsigned int v11; // r5
  unsigned int v12; // r4
  int v13; // r0
  int v14; // lr
  int v15; // r1
  int v16; // r3
  int v17; // r2
  unsigned int v18; // r1
  int v19; // r4
  int v20; // lr
  int v21; // r2
  int v22; // r1
  BOOL v23; // r3
  BOOL v24; // r3
  unsigned int *v25; // r5
  unsigned int v26; // lr
  __int16 v27; // r9
  unsigned int v28; // r8
  unsigned int *v29; // r4
  unsigned int v30; // lr
  int v31; // r3
  int v32; // r0
  int v33; // r1
  int v34; // r0
  unsigned int v35; // r1
  unsigned int v36; // r1
  int v37; // r6
  unsigned int v38; // r1
  int v39; // r0
  unsigned int v40; // r1
  unsigned int v41; // r2
  int v42; // r5
  __int16 v43; // r3
  int v44; // r1
  int v45; // r3
  char v46; // [sp+8h] [bp-128h] BYREF
  unsigned int v47; // [sp+Ch] [bp-124h] BYREF
  int v48; // [sp+10h] [bp-120h]
  int v49; // [sp+14h] [bp-11Ch]
  int v50; // [sp+18h] [bp-118h] BYREF
  int v51; // [sp+1Ch] [bp-114h]
  unsigned int v52; // [sp+20h] [bp-110h]
  int v53; // [sp+24h] [bp-10Ch] BYREF
  unsigned __int8 *v54; // [sp+28h] [bp-108h] BYREF
  int v55; // [sp+2Ch] [bp-104h] BYREF
  unsigned __int64 v56; // [sp+30h] [bp-100h] BYREF
  int v57; // [sp+38h] [bp-F8h]
  int v58[2]; // [sp+40h] [bp-F0h] BYREF
  _DWORD v59[58]; // [sp+48h] [bp-E8h] BYREF

  v2 = *(_DWORD *)(result + 3196);
  v54 = *(unsigned __int8 **)(result + 3212);
  v4 = result;
  v50 = *(_DWORD *)(result + 3204);
  if ( v2 )
  {
    v5 = *(_QWORD *)(v2 + 8);
    v6 = *(_QWORD *)(v2 + 24);
    v7 = *(_DWORD *)(v2 + 36);
    v51 = *(_DWORD *)(v2 + 12);
    v52 = v5;
    v8 = (unsigned int)v6 >= (unsigned int)v5;
    LODWORD(v9) = v6 - v5;
    LODWORD(v6) = *(_DWORD *)v2;
    HIDWORD(v9) = HIDWORD(v6) - (HIDWORD(v5) + !v8);
    HIDWORD(v6) = *(_DWORD *)(v2 + 32);
    v48 = *(_DWORD *)(v2 + 4);
    v49 = v6;
    v8 = HIDWORD(v6) >= (unsigned int)v6;
    v10 = HIDWORD(v6) - v6;
    LODWORD(v6) = *(_DWORD *)(v2 + 16);
    LODWORD(v5) = *(_DWORD *)(v2 + 44);
    HIDWORD(v6) = *(_DWORD *)(v2 + 40);
    v11 = v7 - (v48 + !v8);
    HIDWORD(v5) = *(_DWORD *)(v2 + 20);
    v8 = HIDWORD(v6) >= (unsigned int)v6;
    v12 = HIDWORD(v6) - v6;
    v55 = v6;
    LODWORD(v56) = v12;
    v47 = v5 - (HIDWORD(v5) + !v8);
    v53 = HIDWORD(v5);
    if ( a2 )
    {
      result = sub_540CCC();
    }
    else
    {
      v14 = v48;
      v13 = v49;
      v15 = v49 + v10;
      *(_QWORD *)(v2 + 8) = __PAIR64__(v51, v52) + v9;
      v16 = v55;
      v17 = v53;
      *(_DWORD *)v2 = v15;
      v18 = v47;
      result = (__PAIR64__(v14, v13) + __PAIR64__(v11, v10)) >> 32;
      *(_QWORD *)(v2 + 16) = __PAIR64__(v17, v16) + __PAIR64__(v47, v12);
      *(_DWORD *)(v2 + 4) = result;
      if ( __PAIR64__(v11, v10) > v9 )
      {
        v11 = HIDWORD(v9);
        v10 = v9;
      }
      if ( __PAIR64__(v18, v12) > v9 )
      {
        v47 = HIDWORD(v9);
        LODWORD(v56) = v9;
      }
      if ( v9 <= 1 )
        v9 = 1i64;
      if ( v54 )
      {
        *(_DWORD *)(v4 + 3240) = v54[1] * *v54;
      }
      else
      {
        v49 = *(_DWORD *)(v4 + 3224);
        v19 = v49;
        v51 = _rt_udiv64(v9, __PAIR64__(v11, v10) * (unsigned int)(100 * v49));
        result = _rt_udiv64(v9, __PAIR64__(v11, v10) * (unsigned int)(*(_DWORD *)(v4 + 3232) * v49));
        v20 = result;
        v48 = result;
        if ( v50 )
          v21 = *(_DWORD *)(v50 + 60);
        else
          v21 = 100;
        v46 = 100;
        v50 = v21;
        v57 = (unsigned __int16)v51;
        LOWORD(v53) = v51;
        result = (unsigned __int16)result;
        v52 = (unsigned __int16)v20;
        v58[0] = v56;
        LOWORD(v55) = v20;
        v54 = (unsigned __int8 *)v49;
        v58[1] = v47;
        v59[0] = v10;
        v56 = v9 - __PAIR64__(v11, v10);
        v59[1] = v11;
        if ( PpmEtwRegistered )
        {
          if ( PpmEtwHandle )
          {
            v22 = *(_DWORD *)(PpmEtwHandle + 16);
            v23 = *(_DWORD *)(v22 + 56)
               && (*(unsigned __int8 *)(v22 + 60) >= 4u || !*(_BYTE *)(v22 + 60))
               && (*(_DWORD *)(v22 + 72) & 2) != 0
               && *(_QWORD *)(v22 + 80) == (*(_DWORD *)(v22 + 80) & 2);
            v24 = 1;
            if ( !v23 )
            {
              if ( !*(_BYTE *)(PpmEtwHandle + 52)
                || ((v44 = *(_DWORD *)(PpmEtwHandle + 20), !*(_DWORD *)(v44 + 56))
                 || *(unsigned __int8 *)(v44 + 60) < 4u && *(_BYTE *)(v44 + 60)
                 || (*(_DWORD *)(v44 + 72) & 2) == 0
                 || *(_QWORD *)(v44 + 80) != (*(_DWORD *)(v44 + 80) & 2) ? (v45 = 0) : (v45 = 1),
                    !v45) )
              {
                v24 = 0;
              }
            }
          }
          else
          {
            v24 = 0;
          }
          if ( v24 )
          {
            v59[2] = &PpmCheckTime;
            v59[3] = 0;
            v59[4] = 8;
            v59[5] = 0;
            v59[6] = &v56;
            v59[7] = 0;
            v59[8] = 8;
            v59[9] = 0;
            v59[10] = v59;
            v59[11] = 0;
            v59[12] = 8;
            v59[13] = 0;
            v59[14] = &v50;
            v59[15] = 0;
            v59[16] = 4;
            v59[17] = 0;
            LOWORD(v47) = *(unsigned __int8 *)(v4 + 1052);
            v59[18] = &v47;
            v59[19] = 0;
            v59[20] = 2;
            v59[21] = 0;
            v59[22] = v4 + 1053;
            v59[23] = 0;
            v59[24] = 1;
            v59[25] = 0;
            v59[26] = &v54;
            v59[27] = 0;
            v59[28] = 4;
            v59[29] = 0;
            v59[30] = &v53;
            v59[31] = 0;
            v59[32] = 2;
            v59[33] = 0;
            v59[34] = &v55;
            v59[35] = 0;
            v59[36] = 2;
            v59[37] = 0;
            v59[38] = &v46;
            v59[39] = 0;
            v59[40] = 1;
            v59[41] = 0;
            v59[42] = v2 + 185;
            v59[43] = 0;
            v59[44] = 1;
            v59[45] = 0;
            v59[46] = v58;
            v59[47] = 0;
            v59[48] = 8;
            v59[49] = 0;
            EtwWrite(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_RECORDED_UTILITY, 0);
            v20 = v48;
            result = v52;
          }
          else
          {
            result = (unsigned __int16)v20;
          }
        }
        v25 = *(unsigned int **)(v4 + 3216);
        if ( v25 )
        {
          v26 = v25[1];
          v27 = v57;
          v28 = *v25;
          v29 = &v25[2 * v26];
          v30 = v26 + 1;
          v25[2] += v57 - *((unsigned __int16 *)v29 + 14);
          v31 = *((unsigned __int16 *)v29 + 15);
          *((_WORD *)v29 + 14) = v27;
          v32 = result - v31;
          LOWORD(v31) = v52;
          v25[3] += v32;
          *((_WORD *)v29 + 15) = v31;
          LOBYTE(v32) = v49;
          v25[4] += (unsigned __int8)v49 - *((unsigned __int8 *)v29 + 32);
          *((_BYTE *)v29 + 32) = v32;
          v33 = v25[5] - *((unsigned __int8 *)v29 + 33);
          v25[5] = v33;
          v25[5] = v33 + *(unsigned __int8 *)(v2 + 184);
          v34 = *((unsigned __int8 *)v29 + 34);
          *((_BYTE *)v29 + 33) = *(_BYTE *)(v2 + 184);
          v35 = v25[6] - v34;
          v25[6] = v35;
          v25[6] = v35 + *(unsigned __int8 *)(v2 + 185);
          *((_BYTE *)v29 + 34) = *(_BYTE *)(v2 + 185);
          if ( v30 == v28 )
            v30 = 0;
          v36 = v25[2];
          v25[1] = v30;
          if ( !v28 )
            __brkdiv0();
          v37 = v36 / v28;
          v38 = v25[4];
          v48 = v25[3] / v28;
          v39 = v38 / v28;
          v40 = v25[6];
          v19 = v39;
          v49 = v39;
          result = v40 / v28;
          v20 = v48;
          v41 = (unsigned __int8)(v40 / v28);
        }
        else
        {
          v43 = *(_WORD *)(v2 + 184);
          v37 = v51;
          LOWORD(v50) = v43;
          v41 = HIBYTE(v43);
        }
        if ( PpmCheckCurrentPipelineId == 5 )
        {
          v42 = 1;
          if ( v41 >= 0x64 )
            LOBYTE(v41) = 100;
          result = 1374389535;
          v37 -= (unsigned int)(unsigned __int8)v41 * v37 / 0x64;
          v19 = v49;
          v20 -= (unsigned int)(unsigned __int8)v41 * v20 / 0x64;
        }
        else
        {
          v42 = 0;
        }
        *(_DWORD *)(v4 + 3240) = v37;
        *(_DWORD *)(v4 + 3244) = v20;
        *(_DWORD *)(v4 + 3228) = v19;
        if ( v42 )
          result = (int)PpmPerfResetHistory((_DWORD *)v4);
      }
    }
  }
  return result;
}
