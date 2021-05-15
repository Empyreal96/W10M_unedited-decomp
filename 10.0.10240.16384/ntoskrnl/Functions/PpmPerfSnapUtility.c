// PpmPerfSnapUtility 
 
int __fastcall PpmPerfSnapUtility(int a1)
{
  int v1; // r7
  BOOL v2; // r10
  int v3; // r3
  __int64 *v4; // r8
  __int64 *v5; // r6
  int v6; // r5
  __int64 v7; // kr10_8
  __int64 v8; // kr20_8
  __int64 v10; // kr30_8
  __int64 v11; // kr38_8
  __int64 v12; // r0
  int v13; // r4
  unsigned int v14; // r5
  __int64 *v15; // r4
  unsigned __int8 v16; // r2
  int v17; // r3
  int v18; // r8
  int v19; // r4
  unsigned int v20; // r3
  __int64 v21; // r0
  int v22; // r0
  int v23; // r1
  int v24; // r2
  int v25; // r3
  _DWORD *v26; // r8
  int v27; // r1
  int v28; // r2
  int v29; // r3
  int v30; // r1
  int v31; // r2
  int v32; // r3
  int v33; // r1
  int v34; // r2
  int v35; // r3
  int v36; // r1
  int v37; // r2
  int v38; // r3
  unsigned int v39; // r0
  unsigned int v40; // kr18_4
  int v41; // r1
  __int64 v42; // kr50_8
  int v43; // r0
  _DWORD *v44; // r4
  void (__fastcall *v45)(int *); // r2
  __int64 v46; // r0
  __int64 v47; // r0
  int v48; // r4
  int v49; // r8
  int v50; // r3
  int v51; // r0
  int v52; // r1
  __int64 v53; // [sp+8h] [bp-58h]
  int v54; // [sp+10h] [bp-50h]
  unsigned int v55; // [sp+14h] [bp-4Ch]
  unsigned __int64 v56; // [sp+18h] [bp-48h]
  int v57; // [sp+28h] [bp-38h]
  _DWORD *v59; // [sp+30h] [bp-30h]
  int v60; // [sp+38h] [bp-28h] BYREF
  int v61; // [sp+3Ch] [bp-24h]

  v1 = a1;
  v2 = a1 != ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  v3 = *(_DWORD *)(a1 + 3196);
  v57 = v3;
  if ( v3 )
  {
    v4 = (__int64 *)(v3 + 24);
    v5 = (__int64 *)(v3 + 104);
    v60 = v3 + 24;
    v59 = (_DWORD *)(v3 + 104);
    v6 = PpmSnapPerformanceAccumulation(a1, 0, v2, 1, v3 + 104);
    if ( !v6 )
      return v6;
    v7 = *v5;
    v8 = *v4;
    LODWORD(v56) = *(_DWORD *)v5 - *(_DWORD *)v4;
    HIDWORD(v56) = v56;
    v53 = v5[1] - v4[1];
    if ( *((_DWORD *)v5 + 1) <= *((_DWORD *)v4 + 1)
      && (HIDWORD(v7) < HIDWORD(v8) || (unsigned int)v7 <= (unsigned int)v8)
      || v5[1] - v4[1] > v56 && v2 )
    {
      return sub_541414();
    }
    v10 = v5[6] - v4[6];
    v11 = v5[7] - v4[7];
    if ( HIDWORD(v53) )
    {
      LODWORD(v12) = *((_DWORD *)v5 + 2) - *((_DWORD *)v4 + 2);
    }
    else
    {
      LODWORD(v12) = *((_DWORD *)v5 + 2) - *((_DWORD *)v4 + 2);
      if ( !(_DWORD)v53 )
      {
        v12 = 1i64;
LABEL_11:
        if ( !v12 )
          __brkdiv0();
        v13 = _rt_udiv64(v12, v5[4] - v4[4]);
        v54 = v13;
        if ( v10 )
          v47 = v10;
        else
          v47 = 1i64;
        v55 = (unsigned __int8)_rt_udiv64(v47, 100 * v11);
        if ( v55 > 0x64 )
          v55 = 100;
        if ( !v13 )
        {
          v13 = *(_DWORD *)(v1 + 3224);
          v54 = v13;
        }
        if ( v13 != *(_DWORD *)(v1 + 3224) )
          PpmEventTraceDeliveredPerfChange(v1, v13);
        v14 = 0;
        v15 = v4;
        do
        {
          if ( v10 )
            v46 = v10;
          else
            v46 = 1i64;
          v16 = _rt_udiv64(v46, 100 * (*(__int64 *)((char *)v15 + (char *)v5 - (char *)v4 + 64) - v15[8]));
          if ( v16 > 0x64u )
            v16 = 100;
          v17 = v14 + v57;
          ++v14;
          ++v15;
          *(_BYTE *)(v17 + 184) = v16;
        }
        while ( v14 < 2 );
        v18 = v60;
        v19 = *(_DWORD *)(a1 + 3204);
        *(_DWORD *)(a1 + 3224) = v54;
        *(_DWORD *)(a1 + 3232) = v55;
        if ( !v19 )
        {
LABEL_38:
          v23 = v59[1];
          v24 = v59[2];
          v25 = v59[3];
          *(_DWORD *)v18 = *v59;
          *(_DWORD *)(v18 + 4) = v23;
          *(_DWORD *)(v18 + 8) = v24;
          *(_DWORD *)(v18 + 12) = v25;
          v26 = (_DWORD *)(v18 + 16);
          v27 = v59[5];
          v28 = v59[6];
          v29 = v59[7];
          *v26 = v59[4];
          v26[1] = v27;
          v26[2] = v28;
          v26[3] = v29;
          v26 += 4;
          v30 = v59[9];
          v31 = v59[10];
          v32 = v59[11];
          v6 = 1;
          *v26 = v59[8];
          v26[1] = v30;
          v26[2] = v31;
          v26[3] = v32;
          v26 += 4;
          v33 = v59[13];
          v34 = v59[14];
          v35 = v59[15];
          *v26 = v59[12];
          v26[1] = v33;
          v26[2] = v34;
          v26[3] = v35;
          v26 += 4;
          v36 = v59[17];
          v37 = v59[18];
          v38 = v59[19];
          *v26 = v59[16];
          v26[1] = v36;
          v26[2] = v37;
          v26[3] = v38;
          v39 = *(_DWORD *)(a1 + 3260);
          v40 = *(_DWORD *)(a1 + 3256);
          v41 = *(_DWORD *)(a1 + 3264);
          *(_DWORD *)(a1 + 3256) = v53 + v40;
          v42 = v53 + __PAIR64__(v39, v40);
          v43 = *(_DWORD *)(a1 + 3268);
          *(_DWORD *)(a1 + 3260) = HIDWORD(v42);
          *(_DWORD *)(a1 + 3264) = v56 + v41;
          *(_DWORD *)(a1 + 3268) = v43 + __CFADD__((_DWORD)v56, v41) + (_DWORD)v56;
          if ( v2 )
            return v6;
          v44 = *(_DWORD **)(a1 + 3200);
          if ( !PopProcessorThrottleLogInterval )
            return v6;
          if ( !v44 )
            return v6;
          v45 = (void (__fastcall *)(int *))v44[9];
          if ( !v45 || !*(_BYTE *)(a1 + 3128) )
            return v6;
          v45(&v60);
          if ( v44[30] >= v44[22] )
          {
            v49 = v60;
            v48 = v61;
            if ( !*(_BYTE *)(a1 + 3136) )
            {
              *(_BYTE *)(a1 + 3136) = 1;
LABEL_63:
              *(_DWORD *)(a1 + 3144) = v49;
              *(_DWORD *)(a1 + 3148) = v48;
              return v6;
            }
            if ( *(_DWORD *)(a1 + 3144) == v60 && *(_DWORD *)(a1 + 3148) == v61 )
              goto LABEL_63;
            v50 = *(_DWORD *)(a1 + 3132);
            *(_DWORD *)(a1 + 3132) = v50 + 1;
            if ( !PopProcessorThrottleLogInterval )
              __brkdiv0();
            if ( (v50 + 1) % (unsigned int)PopProcessorThrottleLogInterval && v50 )
              goto LABEL_63;
            v51 = KeGetCurrentProcessorNumberEx(0);
            PopDiagTraceIllegalProcessorThrottle(v51, v52, v60, v61, a1 + 3152);
          }
          else
          {
            *(_BYTE *)(a1 + 3136) = 0;
          }
          v49 = v60;
          v48 = v61;
          goto LABEL_63;
        }
        if ( HIDWORD(v53) )
        {
          v20 = v53;
        }
        else
        {
          v20 = v53;
          if ( !(_DWORD)v53 )
          {
            v21 = 1i64;
            goto LABEL_33;
          }
        }
        v21 = __PAIR64__(HIDWORD(v53), v20);
LABEL_33:
        if ( !v21 )
          __brkdiv0();
        v22 = _rt_udiv64(v21, *((_QWORD *)v59 + 3) - *(_QWORD *)(v18 + 24));
        if ( !v22 )
          v22 = *(_DWORD *)(v19 + 60);
        *(_DWORD *)(v19 + 60) = v22;
        goto LABEL_38;
      }
    }
    HIDWORD(v12) = (unsigned __int64)(v5[1] - v4[1]) >> 32;
    goto LABEL_11;
  }
  return 1;
}
