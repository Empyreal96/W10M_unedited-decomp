// PopDiagTracePerfTrackData 
 
// local variable allocation has failed, the output may be wrong!
__int64 *__fastcall PopDiagTracePerfTrackData(__int64 *result)
{
  int v1; // r4
  _QWORD *v2; // r3
  int v3; // r0
  int v4; // r1
  int v5; // r9
  __int64 v6; // kr00_8
  __int64 v7; // r2
  __int64 v8; // r2
  __int64 v9; // r2
  int *v10; // r2
  unsigned __int64 v11; // r0
  __int64 v12; // r0
  __int64 v13; // r2
  __int64 v14; // r2
  int v15; // r3
  int v16; // r3
  __int64 v17; // r0
  unsigned __int64 v18; // r0
  __int64 v19; // r0
  unsigned __int64 v20; // r0
  __int16 v21; // r3
  __int16 v22; // r3
  __int16 v23; // r3
  unsigned int v24; // r1
  unsigned int v25; // r3
  unsigned __int64 v26; // r0
  int v27; // r3
  int v28; // r3
  int **v29; // r3
  int v30; // r2 OVERLAPPED
  int *v31; // r1 OVERLAPPED
  int v32; // r4
  unsigned int v33; // r6
  __int64 v34; // r2
  int v35; // r3
  int v36; // r3
  __int64 v37; // r0
  unsigned __int64 v38; // r0
  __int64 v39; // r0
  unsigned __int64 v40; // r0
  __int16 v41; // r3
  __int16 v42; // r3
  unsigned int v43; // r3
  int v44; // r6
  __int64 v45; // r0
  unsigned __int64 v46; // r0
  int v47; // r3
  int v48; // r3
  int **v49; // r3
  int v50; // r2 OVERLAPPED
  int *v51; // r1 OVERLAPPED
  int v52; // r4
  int v53; // [sp+8h] [bp-E0h]
  int v54; // [sp+8h] [bp-E0h]
  int v55; // [sp+8h] [bp-E0h]
  int v56; // [sp+14h] [bp-D4h] BYREF
  __int64 *v57; // [sp+18h] [bp-D0h] BYREF
  int v58; // [sp+1Ch] [bp-CCh] BYREF
  int v59[2]; // [sp+20h] [bp-C8h] BYREF
  int v60; // [sp+28h] [bp-C0h] BYREF
  unsigned int v61; // [sp+2Ch] [bp-BCh]
  unsigned int v62; // [sp+34h] [bp-B4h]
  __int64 v63; // [sp+38h] [bp-B0h] BYREF
  __int64 *v64; // [sp+40h] [bp-A8h] BYREF
  int v65; // [sp+44h] [bp-A4h] BYREF
  int v66; // [sp+48h] [bp-A0h] BYREF
  int v67; // [sp+50h] [bp-98h] BYREF
  __int16 v68; // [sp+54h] [bp-94h]
  __int16 v69; // [sp+56h] [bp-92h]
  __int16 v70; // [sp+58h] [bp-90h]
  __int16 v71; // [sp+5Ah] [bp-8Eh]
  __int16 v72; // [sp+5Ch] [bp-8Ch]
  __int16 v73; // [sp+5Eh] [bp-8Ah]
  int v74; // [sp+60h] [bp-88h]
  __int16 v75; // [sp+64h] [bp-84h]
  __int16 v76; // [sp+66h] [bp-82h]
  int *v77; // [sp+68h] [bp-80h] BYREF
  int v78; // [sp+6Ch] [bp-7Ch]
  int v79; // [sp+70h] [bp-78h]
  int v80; // [sp+74h] [bp-74h]
  int *v81; // [sp+78h] [bp-70h]
  int v82; // [sp+7Ch] [bp-6Ch]
  int v83; // [sp+80h] [bp-68h]
  int v84; // [sp+84h] [bp-64h]
  int *v85; // [sp+88h] [bp-60h]
  int v86; // [sp+8Ch] [bp-5Ch]
  int v87; // [sp+90h] [bp-58h]
  int v88; // [sp+94h] [bp-54h]
  int *v89; // [sp+98h] [bp-50h]
  int v90; // [sp+9Ch] [bp-4Ch]
  int v91; // [sp+A0h] [bp-48h]
  int v92; // [sp+A4h] [bp-44h]
  int *v93; // [sp+A8h] [bp-40h]
  int v94; // [sp+ACh] [bp-3Ch]
  int v95; // [sp+B0h] [bp-38h]
  int v96; // [sp+B4h] [bp-34h]

  v57 = result;
  if ( PopDiagHandleRegistered )
  {
    v1 = dword_61E154;
    v53 = dword_61E154;
    v60 = PopDiagHandle;
    result = (__int64 *)EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_TRANSITIONTIMES);
    if ( result )
    {
      if ( KeNumberProcessors_0 )
        v2 = KiProcessorBlock;
      else
        v2 = 0;
      v3 = _rt_udiv64(1000000i64, v2[121]);
      v5 = v4;
      v6 = 1000i64 * (unsigned int)v3;
      v65 = PopQpcTimeInMs(&dword_61EF90, &dword_61EF98, v7);
      result = (__int64 *)PopQpcTimeInMs(&dword_61EF80, &dword_61EF88, v8);
      v64 = result;
      if ( qword_61EF78 )
      {
        v63 = 0i64;
        v57 = (__int64 *)PopQpcTimeInMs(&v63, &qword_61EF78, (unsigned int)qword_61EF78);
        v56 = (int)v57 + PopQpcTimeInMs(&dword_61EF58, &dword_61EF60, v9);
        v77 = &dword_61F118;
        v78 = 0;
        v79 = 4;
        v80 = 0;
        v81 = &v56;
        v82 = 0;
        v83 = 4;
        v84 = 0;
        v85 = (int *)&v57;
        v86 = 0;
        v87 = 4;
        v88 = 0;
        v89 = (int *)&v64;
        v90 = 0;
        v91 = 4;
        v92 = 0;
        v93 = &v65;
        v94 = 0;
        v95 = 4;
        v96 = 0;
        v10 = POP_ETW_EVENT_PERFTRACK_STANDBY;
        v11 = __PAIR64__(v53, v60);
      }
      else
      {
        if ( !dword_61F160 )
          return result;
        v58 = (4 * dword_61F160) & 0x3FFFFF;
        HIDWORD(v12) = HIDWORD(v6) + 1000 * v5;
        v54 = dword_61EFE0;
        LODWORD(v63) = dword_61EFE0;
        LODWORD(v12) = v6;
        if ( !__PAIR64__(HIDWORD(v12), v6) )
          __brkdiv0();
        v59[0] = _rt_udiv64(v12, qword_61EFB8);
        v56 = qword_61F170;
        if ( ((unsigned __int8)v57 & 8) != 0 )
        {
          result = &PopShutdownButtonPressTime;
          LODWORD(v13) = PopShutdownButtonPressTime;
          if ( !PopShutdownButtonPressTime )
            return result;
          HIDWORD(v13) = HIDWORD(PopShutdownButtonPressTime) | PopShutdownButtonPressTime;
          v66 = v54 + PopQpcTimeInMs(&PopShutdownButtonPressTime, &dword_61EF48, v13);
          v77 = &v58;
          v78 = 0;
          v79 = 4;
          v80 = 0;
          v81 = &v66;
          v82 = 0;
          v83 = 4;
          v84 = 0;
          v85 = v59;
          v86 = 0;
          v87 = 4;
          v88 = 0;
          EtwWrite(v60, v1, (int)POP_ETW_EVENT_PERFTRACK_HYBRID_SHUTDOWN, 0);
          HIDWORD(v14) = HIDWORD(v6) + 1000 * v5;
          LODWORD(v14) = v6;
          PopComputeDerivedHiberStats((int)&qword_61EFA0, v14, &v60);
          v67 = v56;
          v15 = *(__int64 *)&dword_61F148 >> 8;
          if ( *(_QWORD *)&dword_61F148 >> 8 > 0xFFFFui64 )
            LOWORD(v15) = -1;
          v68 = v15;
          v16 = qword_61F150 >> 8;
          if ( (unsigned __int64)qword_61F150 >> 8 > 0xFFFF )
            LOWORD(v16) = -1;
          v69 = v16;
          HIDWORD(v17) = HIDWORD(v6) + 1000 * v5;
          LODWORD(v17) = v6;
          if ( !__PAIR64__(HIDWORD(v17), v6) )
            __brkdiv0();
          LODWORD(v18) = _rt_udiv64(v17, qword_61EFF8);
          if ( v18 > 0xFFFF )
            LOWORD(v18) = -1;
          HIDWORD(v18) = HIDWORD(v6) + 1000 * v5;
          v70 = v18;
          LODWORD(v18) = v6;
          if ( !__PAIR64__(HIDWORD(v18), v6) )
            __brkdiv0();
          LODWORD(v20) = _rt_udiv64(v19, qword_61F0D8);
          if ( v20 > 0xFFFF )
            LOWORD(v20) = -1;
          v21 = dword_61EFE8;
          if ( (unsigned int)dword_61EFE8 > 0xFFFF )
            v21 = -1;
          v72 = v21;
          v22 = dword_61F118;
          v71 = v20;
          LODWORD(v20) = v6;
          if ( (unsigned int)dword_61F118 > 0xFFFF )
            v22 = -1;
          v73 = v22;
          v23 = 1023;
          if ( v61 <= 0x3FF )
            v23 = v61;
          v24 = v74 & 0xFFFFFC00 | v23 & 0x3FF;
          v25 = 511;
          if ( v62 <= 0x1FF )
            v25 = v62;
          v55 = (v24 ^ (v25 << 10)) & 0x7FC00 ^ v24;
          HIDWORD(v20) = HIDWORD(v6) + 1000 * v5;
          if ( !(_DWORD)v6 && !HIDWORD(v20) )
            __brkdiv0();
          LODWORD(v26) = _rt_udiv64(v20, qword_61F070 - qword_61F0A0);
          if ( v26 > 0x1FFF )
          {
            LODWORD(v26) = 0x1FFF;
            v61 = 0;
          }
          else
          {
            v61 = HIDWORD(v26);
          }
          v74 = v55 & 0x7FFFF | ((_DWORD)v26 << 19);
          v27 = qword_61F128 >> 8;
          if ( (unsigned __int64)qword_61F128 >> 8 > 0xFFFF )
            LOWORD(v27) = -1;
          v75 = v27;
          v28 = qword_61F130 >> 8;
          if ( (unsigned __int64)qword_61F130 >> 8 > 0xFFFF )
            LOWORD(v28) = -1;
          v76 = v28;
          v29 = &v77;
          v30 = 0;
          v31 = &v67;
          v32 = 6;
          do
          {
            *(_QWORD *)v29 = *(_QWORD *)&v31;
            v29[2] = (int *)4;
            v29[3] = 0;
            v29 += 4;
            ++v31;
            --v32;
          }
          while ( v32 );
          v10 = POP_ETW_EVENT_PERFTRACK_HYBRID_RESUME;
        }
        else
        {
          v77 = &v58;
          v78 = 0;
          v79 = 4;
          v80 = 0;
          v81 = (int *)&v63;
          v82 = 0;
          v83 = 4;
          v84 = 0;
          v85 = v59;
          v86 = 0;
          v87 = 4;
          v88 = 0;
          result = (__int64 *)EtwWrite(v60, v1, (int)POP_ETW_EVENT_PERFTRACK_HIBERNATE, 0);
          v33 = dword_61EFE8;
          if ( !dword_61EFE8 )
            return result;
          LODWORD(v34) = v6;
          HIDWORD(v34) = HIDWORD(v6) + 1000 * v5;
          PopComputeDerivedHiberStats((int)&qword_61EFA0, v34, &v60);
          v67 = v56;
          v35 = *(__int64 *)&dword_61F148 >> 8;
          if ( *(_QWORD *)&dword_61F148 >> 8 >= 0xFFFFui64 )
            LOWORD(v35) = -1;
          v68 = v35;
          v36 = qword_61F150 >> 8;
          if ( (unsigned __int64)qword_61F150 >> 8 >= 0xFFFF )
            LOWORD(v36) = -1;
          v69 = v36;
          HIDWORD(v37) = HIDWORD(v6) + 1000 * v5;
          LODWORD(v37) = v6;
          if ( !__PAIR64__(HIDWORD(v37), v6) )
            __brkdiv0();
          LODWORD(v38) = _rt_udiv64(v37, qword_61EFF8);
          if ( v38 >= 0xFFFF )
            LOWORD(v38) = -1;
          v70 = v38;
          HIDWORD(v39) = HIDWORD(v6) + 1000 * v5;
          LODWORD(v39) = v6;
          if ( !__PAIR64__(HIDWORD(v39), v6) )
            __brkdiv0();
          LODWORD(v40) = _rt_udiv64(v39, qword_61F0D8);
          if ( v40 >= 0xFFFF )
            LOWORD(v40) = -1;
          v41 = dword_61F118;
          if ( v33 >= 0xFFFF )
            LOWORD(v33) = -1;
          if ( (unsigned int)dword_61F118 >= 0xFFFF )
            v41 = -1;
          v73 = v41;
          v42 = 1023;
          if ( v61 <= 0x3FF )
            v42 = v61;
          HIDWORD(v40) = v74 & 0xFFFFFC00 | v42 & 0x3FF;
          v43 = 511;
          if ( v62 <= 0x1FF )
            v43 = v62;
          v72 = v33;
          v71 = v40;
          v44 = (HIDWORD(v40) ^ (v43 << 10)) & 0x7FC00 ^ HIDWORD(v40);
          LODWORD(v45) = v6;
          HIDWORD(v45) = HIDWORD(v6) + 1000 * v5;
          if ( !__PAIR64__(HIDWORD(v45), v6) )
            __brkdiv0();
          LODWORD(v46) = _rt_udiv64(v45, qword_61F070 - qword_61F0A0);
          if ( v46 > 0x1FFF )
            LODWORD(v46) = 0x1FFF;
          v74 = v44 & 0x7FFFF | ((_DWORD)v46 << 19);
          v47 = qword_61F128 >> 8;
          if ( (unsigned __int64)qword_61F128 >> 8 >= 0xFFFF )
            LOWORD(v47) = -1;
          v75 = v47;
          v48 = qword_61F130 >> 8;
          if ( (unsigned __int64)qword_61F130 >> 8 >= 0xFFFF )
            LOWORD(v48) = -1;
          v76 = v48;
          v49 = &v77;
          v50 = 0;
          v51 = &v67;
          v52 = 6;
          do
          {
            *(_QWORD *)v49 = *(_QWORD *)&v51;
            v49[2] = (int *)4;
            v49[3] = 0;
            v49 += 4;
            ++v51;
            --v52;
          }
          while ( v52 );
          v10 = POP_ETW_EVENT_PERFTRACK_RESUME_FROM_HIBERNATE;
        }
        v11 = *(_QWORD *)&PopDiagHandle;
      }
      result = (__int64 *)EtwWrite(v11, SHIDWORD(v11), (int)v10, 0);
    }
  }
  return result;
}
