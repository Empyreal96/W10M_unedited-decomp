// ExpScanSystemLookasideList 
 
unsigned int ExpScanSystemLookasideList()
{
  unsigned int result; // r0
  int v1; // r7
  int v2; // r6
  unsigned int v3; // r9
  int v4; // r4
  int v5; // r2
  int v6; // r3
  int v7; // r8
  int v8; // r1
  int v9; // r2
  int v10; // r3
  unsigned int v11; // r0
  int v12; // r5
  int v13; // r5
  int v14; // r8
  int v15; // r4
  unsigned int v16; // r7
  unsigned int v17; // r9
  unsigned int v18; // r10
  int v19; // r2
  int v20; // r3
  int v21; // r6
  int v22; // r1
  int v23; // r2
  int v24; // r3
  unsigned int v25; // r0
  int v26; // r3
  int v27; // r5
  int v28; // r5
  int v29; // r6
  int v30; // r2
  int v31; // r3
  int v32; // r5
  __int64 v33; // r1
  int v34; // r3
  int v35; // r7
  unsigned int v36; // r3
  int v37; // r5
  int v38; // r5
  int v39; // r2
  unsigned int v40; // r1
  unsigned int v41; // r0
  unsigned int v42; // r3
  unsigned int v43; // r1
  unsigned int v44; // r3
  unsigned int v45; // r0
  unsigned int v46; // r3
  unsigned int v47; // r6
  int v48; // r7
  unsigned int v49; // r9
  int v50; // r4
  int v51; // r2
  int v52; // r3
  int v53; // r8
  int v54; // r1
  int v55; // r2
  int v56; // r3
  int v57; // r5
  int v58; // r5
  unsigned int v59; // r1
  unsigned int v60; // r3
  int v61; // [sp+0h] [bp-28h]
  int v62; // [sp+4h] [bp-24h]
  int v63; // [sp+4h] [bp-24h]
  int v64; // [sp+8h] [bp-20h]

  result = (unsigned int)&KeNumberProcessors_0;
  v62 = 3 * KeNumberProcessors_0;
  v64 = ExpPoolScanCount;
  if ( ExpPoolScanCount == KeNumberProcessors_0 )
  {
    v47 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v48 = 9;
    v49 = 75 * KeNumberProcessors_0;
    do
    {
      v50 = *(_DWORD *)(v47 + 1412);
      if ( v50 )
      {
        v51 = *(_DWORD *)(v50 + 16);
        v52 = *(_DWORD *)(v50 + 60);
        v53 = *(unsigned __int16 *)(v50 + 10);
        *(_DWORD *)(v50 + 60) = v51;
        v54 = v51 - v52;
        v55 = *(_DWORD *)(v50 + 12);
        v56 = *(_DWORD *)(v50 + 56);
        *(_DWORD *)(v50 + 56) = v55;
        result = v55 - v56;
        if ( v53 != 0xFFFF )
        {
          v57 = *(unsigned __int16 *)(v50 + 8);
          if ( result >= v49 )
          {
            v59 = 1000 * v54;
            if ( !result )
              __brkdiv0();
            result = v59 / result;
            if ( result < 5 )
            {
              v58 = v57 - 1;
              if ( v58 < 4 )
                LOWORD(v58) = 4;
            }
            else
            {
              v60 = (v53 - v57) * result / 0x7D0 + 5;
              if ( v60 > 0x1E )
                v60 = 30;
              v58 = v57 + v60;
              if ( v58 > v53 )
                LOWORD(v58) = v53;
            }
          }
          else
          {
            v58 = v57 - 10;
            if ( v58 < 4 )
              LOWORD(v58) = 4;
          }
          *(_WORD *)(v50 + 8) = v58;
        }
      }
      v47 += 8;
      --v48;
    }
    while ( v48 );
    v39 = ExpPoolScanCount;
  }
  else
  {
    v1 = 9;
    v61 = (int)*(&KiProcessorBlock + ExpPoolScanCount);
    v2 = v61;
    v3 = 75 * KeNumberProcessors_0;
    do
    {
      v4 = *(_DWORD *)(v2 + 1408);
      if ( v4 )
      {
        v5 = *(_DWORD *)(v4 + 16);
        v6 = *(_DWORD *)(v4 + 60);
        v7 = *(unsigned __int16 *)(v4 + 10);
        *(_DWORD *)(v4 + 60) = v5;
        v8 = v5 - v6;
        v9 = *(_DWORD *)(v4 + 12);
        v10 = *(_DWORD *)(v4 + 56);
        *(_DWORD *)(v4 + 56) = v9;
        v11 = v9 - v10;
        if ( v7 != 0xFFFF )
        {
          v12 = *(unsigned __int16 *)(v4 + 8);
          if ( v11 >= v3 )
          {
            v40 = 1000 * v8;
            if ( !v11 )
              __brkdiv0();
            v41 = v40 / v11;
            if ( v41 >= 5 )
            {
              v42 = (v7 - v12) * v41 / 0x7D0 + 5;
              if ( v42 > 0x1E )
                v42 = 30;
              v13 = v12 + v42;
              if ( v13 > v7 )
                LOWORD(v13) = v7;
            }
            else
            {
              v13 = v12 - 1;
              if ( v13 < 4 )
                LOWORD(v13) = 4;
            }
          }
          else
          {
            v13 = v12 - 10;
            if ( v13 < 4 )
              LOWORD(v13) = 4;
          }
          *(_WORD *)(v4 + 8) = v13;
        }
      }
      v2 += 8;
      --v1;
    }
    while ( v1 );
    v14 = 32;
    v15 = v61 + 10496;
    v16 = 25 * v62;
    v17 = 25 * v62;
    v18 = 25 * v62;
    v63 = 25 * v62;
    do
    {
      v19 = *(_DWORD *)(v15 + 16);
      v20 = *(_DWORD *)(v15 + 60);
      v21 = *(unsigned __int16 *)(v15 + 10);
      *(_DWORD *)(v15 + 60) = v19;
      v22 = v19 - v20;
      v23 = *(_DWORD *)(v15 + 12);
      v24 = *(_DWORD *)(v15 + 56);
      *(_DWORD *)(v15 + 56) = v23;
      v25 = v23 - v24;
      v26 = v23 - v24 - v22;
      if ( v21 != 0xFFFF )
      {
        v27 = *(unsigned __int16 *)(v15 + 8);
        if ( v25 >= v17 )
        {
          if ( !v25 )
            __brkdiv0();
          v45 = 1000 * v26 / v25;
          if ( v45 < 5 )
          {
            v28 = v27 - 1;
            if ( v28 < 4 )
              LOWORD(v28) = 4;
          }
          else
          {
            v46 = (v21 - v27) * v45 / 0x7D0 + 5;
            if ( v46 > 0x1E )
              v46 = 30;
            v28 = v27 + v46;
            if ( v28 > v21 )
              LOWORD(v28) = v21;
          }
        }
        else
        {
          v28 = v27 - 10;
          if ( v28 < 4 )
            LOWORD(v28) = 4;
        }
        *(_WORD *)(v15 + 8) = v28;
      }
      v29 = *(unsigned __int16 *)(v15 + 2314);
      *(_DWORD *)(v15 + 2364) = *(_DWORD *)(v15 + 2320);
      v30 = *(_DWORD *)(v15 + 2316);
      v31 = *(_DWORD *)(v15 + 2360);
      *(_DWORD *)(v15 + 2360) = v30;
      if ( v29 != 0xFFFF )
      {
        if ( v30 - v31 >= v16 )
          return sub_51DBB0();
        v32 = *(unsigned __int16 *)(v15 + 2312) - 10;
        if ( v32 < 4 )
          LOWORD(v32) = 4;
        *(_WORD *)(v15 + 2312) = v32;
      }
      v33 = *(_QWORD *)(v15 + 4620);
      v34 = *(_DWORD *)(v15 + 4668);
      v35 = *(unsigned __int16 *)(v15 + 4618);
      *(_DWORD *)(v15 + 4668) = HIDWORD(v33);
      result = HIDWORD(v33) - v34;
      HIDWORD(v33) = *(_DWORD *)(v15 + 4664);
      *(_DWORD *)(v15 + 4664) = v33;
      v36 = v33 - HIDWORD(v33);
      if ( v35 != 0xFFFF )
      {
        v37 = *(unsigned __int16 *)(v15 + 4616);
        if ( v36 >= v18 )
        {
          v43 = 1000 * (v36 - result);
          if ( !v36 )
            __brkdiv0();
          result = v43 / v36;
          if ( v43 / v36 < 5 )
          {
            v38 = v37 - 1;
            if ( v38 < 4 )
              LOWORD(v38) = 4;
          }
          else
          {
            v44 = (v35 - v37) * result / 0x7D0 + 5;
            if ( v44 > 0x1E )
              v44 = 30;
            v38 = v37 + v44;
            if ( v38 > v35 )
              LOWORD(v38) = v35;
          }
        }
        else
        {
          v38 = v37 - 10;
          if ( v38 < 4 )
            LOWORD(v38) = 4;
        }
        *(_WORD *)(v15 + 4616) = v38;
      }
      v16 = v63;
      v15 += 72;
      --v14;
    }
    while ( v14 );
    v39 = v64;
  }
  ExpPoolScanCount = v39 + 1;
  if ( v39 + 1 > (unsigned int)KeNumberProcessors_0 )
    ExpPoolScanCount = 0;
  return result;
}
