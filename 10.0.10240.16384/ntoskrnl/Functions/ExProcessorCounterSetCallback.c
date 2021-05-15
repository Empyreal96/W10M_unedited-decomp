// ExProcessorCounterSetCallback 
 
int __fastcall ExProcessorCounterSetCallback(int a1, __int64 *a2)
{
  int v2; // r10
  int v3; // r7
  BOOL v4; // r3
  int v5; // r8
  int v7; // r9
  __int64 v8; // r0
  int result; // r0
  unsigned __int16 *v10; // r0
  int v11; // r0
  unsigned int v12; // r6
  unsigned int v13; // r4
  unsigned int v14; // r5
  unsigned int v15; // r6
  unsigned int v16; // r7
  unsigned int v17; // r9
  unsigned __int64 v18; // r2
  int v19; // r8
  int v20; // r3
  unsigned int v21; // r4
  unsigned int v22; // r4
  unsigned int v23; // r6
  int v24; // r4
  unsigned int v25; // [sp+8h] [bp-360h] BYREF
  int v26; // [sp+Ch] [bp-35Ch] BYREF
  unsigned __int16 v27; // [sp+10h] [bp-358h] BYREF
  unsigned int v28; // [sp+14h] [bp-354h]
  unsigned int v29; // [sp+18h] [bp-350h]
  int v30; // [sp+1Ch] [bp-34Ch]
  unsigned int v31; // [sp+20h] [bp-348h]
  unsigned int v32; // [sp+24h] [bp-344h]
  unsigned int v33; // [sp+28h] [bp-340h]
  int v34; // [sp+2Ch] [bp-33Ch]
  unsigned int v35; // [sp+30h] [bp-338h]
  int v36; // [sp+34h] [bp-334h]
  unsigned int v37; // [sp+38h] [bp-330h]
  unsigned __int64 v38; // [sp+3Ch] [bp-32Ch]
  unsigned int v39; // [sp+44h] [bp-324h]
  unsigned int v40; // [sp+48h] [bp-320h]
  unsigned int v41; // [sp+4Ch] [bp-31Ch]
  unsigned int v42; // [sp+50h] [bp-318h]
  unsigned int v43; // [sp+54h] [bp-314h]
  unsigned int v44; // [sp+58h] [bp-310h]
  unsigned int v45; // [sp+5Ch] [bp-30Ch]
  unsigned int v46; // [sp+60h] [bp-308h]
  unsigned int v47; // [sp+64h] [bp-304h]
  unsigned int v48; // [sp+68h] [bp-300h]
  unsigned int v49; // [sp+6Ch] [bp-2FCh]
  unsigned int v50; // [sp+70h] [bp-2F8h]
  unsigned int v51; // [sp+74h] [bp-2F4h]
  unsigned int v52; // [sp+78h] [bp-2F0h]
  unsigned int v53; // [sp+7Ch] [bp-2ECh]
  unsigned int v54; // [sp+80h] [bp-2E8h]
  unsigned int v55; // [sp+84h] [bp-2E4h]
  unsigned int v56; // [sp+88h] [bp-2E0h]
  unsigned int v57; // [sp+8Ch] [bp-2DCh]
  unsigned int v58; // [sp+90h] [bp-2D8h]
  int v59; // [sp+94h] [bp-2D4h]
  char v60[8]; // [sp+98h] [bp-2D0h] BYREF
  __int64 *v61; // [sp+A0h] [bp-2C8h]
  int v62; // [sp+A4h] [bp-2C4h]
  __int64 *v63; // [sp+A8h] [bp-2C0h]
  int v64; // [sp+ACh] [bp-2BCh]
  unsigned int v65; // [sp+B0h] [bp-2B8h]
  int v66; // [sp+B4h] [bp-2B4h]
  unsigned int v67; // [sp+B8h] [bp-2B0h]
  unsigned int v68; // [sp+BCh] [bp-2ACh]
  __int64 v69; // [sp+C0h] [bp-2A8h]
  unsigned int v70; // [sp+C8h] [bp-2A0h]
  __int64 *v71; // [sp+D0h] [bp-298h]
  int v72; // [sp+D4h] [bp-294h]
  unsigned int v73[4]; // [sp+D8h] [bp-290h] BYREF
  __int64 v74[24]; // [sp+E8h] [bp-280h] BYREF
  __int64 v75[24]; // [sp+1A8h] [bp-1C0h] BYREF
  __int64 v76; // [sp+268h] [bp-100h] BYREF
  __int64 v77; // [sp+270h] [bp-F8h]
  __int64 v78; // [sp+278h] [bp-F0h]
  __int64 v79; // [sp+280h] [bp-E8h]
  int v80; // [sp+288h] [bp-E0h]
  __int64 v81; // [sp+290h] [bp-D8h]
  __int64 v82; // [sp+298h] [bp-D0h]
  int v83; // [sp+2A0h] [bp-C8h]
  int v84; // [sp+2A4h] [bp-C4h]
  int v85; // [sp+2A8h] [bp-C0h]
  __int64 v86; // [sp+2B0h] [bp-B8h]
  __int64 v87; // [sp+2B8h] [bp-B0h]
  __int64 v88; // [sp+2C0h] [bp-A8h]
  __int64 v89; // [sp+2C8h] [bp-A0h]
  __int64 v90; // [sp+2D0h] [bp-98h]
  __int64 v91; // [sp+2D8h] [bp-90h]
  __int64 v92; // [sp+2E0h] [bp-88h]
  int v93; // [sp+2ECh] [bp-7Ch]
  int v94; // [sp+2F0h] [bp-78h]
  unsigned int v95; // [sp+2F8h] [bp-70h]
  unsigned int v96; // [sp+2FCh] [bp-6Ch]
  __int64 v97; // [sp+300h] [bp-68h]
  __int64 v98; // [sp+308h] [bp-60h]
  __int64 v99; // [sp+310h] [bp-58h]
  __int64 v100; // [sp+318h] [bp-50h]
  int v101; // [sp+320h] [bp-48h]
  int v102; // [sp+324h] [bp-44h]
  unsigned __int16 v103[32]; // [sp+328h] [bp-40h] BYREF

  v2 = 0;
  v3 = 0;
  v4 = 0;
  v59 = 0;
  v34 = 0;
  v5 = 0;
  v36 = 0;
  v25 = 0;
  v26 = 0;
  if ( a1 == 3 )
  {
    v7 = *((_DWORD *)a2 + 5);
    v8 = *a2;
    v30 = v7;
    if ( !(BYTE4(v8) & 1 | v8 & 0xE0FF05) )
      return sub_7F30EC();
    v2 = 1;
    v59 = 1;
    v3 = (v8 & 0xC00F0000) != 0;
    v34 = v3;
    v5 = (v8 & 0x3F000000) != 0;
    v10 = *(unsigned __int16 **)(*((_DWORD *)a2 + 2) + 4);
    v36 = v5;
    v4 = swscanf_s(v10, (int)L"%u,%u", &v25, &v26) == 2;
  }
  else
  {
    if ( a1 != 2 )
      return 0;
    v7 = *((_DWORD *)a2 + 5);
    v30 = v7;
  }
  if ( !v4 )
  {
    memset(v75, 0, sizeof(v75));
    v22 = KeNumberProcessors_0;
    v37 = 0;
    v35 = 0;
    v33 = 0;
    v31 = 0;
    v20 = (unsigned __int16)KeNumberNodes;
    v14 = 0;
    v63 = (__int64 *)KeNumberProcessors_0;
    v28 = (unsigned __int16)KeNumberNodes;
    v25 = 0;
    if ( !KeNumberNodes )
    {
LABEL_19:
      if ( v22 > 1 )
      {
        v75[0] = (unsigned int)_rt_udiv64(v22, v75[0]);
        v75[1] = (unsigned int)_rt_udiv64(v22, v75[1]);
        v75[2] = (unsigned int)_rt_udiv64(v22, v75[2]);
        v75[3] = (unsigned int)_rt_udiv64(v22, v75[3]);
        v75[6] = (unsigned int)_rt_udiv64(v22, v75[6]);
        v75[5] = (unsigned int)_rt_udiv64(v22, v75[5]);
        v75[9] = (unsigned int)_rt_udiv64(v22, v75[9]);
        v75[10] = (unsigned int)_rt_udiv64(v22, v75[10]);
        v75[11] = (unsigned int)_rt_udiv64(v22, v75[11]);
        v75[15] = (unsigned int)_rt_udiv64(v22, v75[15]);
        HIDWORD(v75[16]) /= v22;
        LODWORD(v75[17]) /= v22;
      }
      if ( v5 )
      {
        if ( !v22 )
          __brkdiv0();
        LODWORD(v75[18]) = _rt_udiv64(v22, __PAIR64__(v31, v33));
        HIDWORD(v75[18]) = _rt_udiv64(v22, __PAIR64__(v35, v37));
        v75[19] = (unsigned int)_rt_udiv64(v22, v75[19]);
        v75[20] = (unsigned int)_rt_udiv64(v22, v75[20]);
      }
      if ( v3 )
      {
        if ( !v22 )
          __brkdiv0();
        LODWORD(v75[23]) /= v22;
      }
      RtlStringCbPrintfW(v103, 0x1Au, (int)L"_Total", v20);
      RtlInitUnicodeString((unsigned int)v60, v103);
      v61 = v75;
      v62 = 192;
      return PcwAddInstance(v7, (int)v60, (unsigned __int16)KeNumberNodes + KeMaximumProcessors, 1);
    }
    v21 = (unsigned __int16)KeNumberNodes;
    while ( 1 )
    {
      KeQueryNodeActiveAffinity((unsigned __int16)v14, v73, &v27);
      v12 = v73[0];
      if ( v73[0] )
      {
        memset(v74, 0, sizeof(v74));
        v13 = v27;
        v29 = 0;
        v32 = 0;
        v38 = 0i64;
        v26 = 0;
        if ( v27 )
        {
          while ( 1 )
          {
            v24 = v12 ? __clz(__rbit(v12)) : -1;
            v11 = (int)*(&KiProcessorBlock + v24);
            v65 = v12 & ~*(_DWORD *)(v11 + 1048);
            v73[0] = v65;
            ExpQueryProcessorInformationCounters(v11, v59, v3, v5, &v76);
            RtlStringCbPrintfW(v103, 0x1Au, (int)L"%u,%u", v25);
            RtlInitUnicodeString((unsigned int)v60, v103);
            v71 = &v76;
            v72 = 192;
            result = PcwAddInstance(v7, (int)v60, v24, 1);
            if ( result < 0 )
              return result;
            v70 = LODWORD(v74[0]) + v76;
            v68 = (unsigned __int64)(v74[0] + v76) >> 32;
            v74[0] += v76;
            v66 = LODWORD(v74[1]) + v77;
            v43 = (unsigned __int64)(v74[1] + v77) >> 32;
            v74[1] += v77;
            v42 = LODWORD(v74[2]) + v78;
            v52 = (unsigned __int64)(v74[2] + v78) >> 32;
            v74[2] += v78;
            v44 = LODWORD(v74[3]) + v79;
            v54 = (unsigned __int64)(v74[3] + v79) >> 32;
            v74[3] += v79;
            LODWORD(v74[4]) += v80;
            v58 = LODWORD(v74[6]) + v82;
            v56 = (unsigned __int64)(v74[6] + v82) >> 32;
            v74[6] += v82;
            HIDWORD(v74[7]) += v84;
            LODWORD(v74[8]) += v85;
            v55 = LODWORD(v74[5]) + v81;
            v47 = (unsigned __int64)(v74[5] + v81) >> 32;
            v74[5] += v81;
            LODWORD(v74[7]) += v83;
            v39 = LODWORD(v74[9]) + v86;
            v49 = (unsigned __int64)(v74[9] + v86) >> 32;
            v74[9] += v86;
            v74[12] += v89;
            v57 = LODWORD(v74[10]) + v87;
            v51 = (unsigned __int64)(v74[10] + v87) >> 32;
            v74[10] += v87;
            v74[13] += v90;
            v45 = LODWORD(v74[11]) + v88;
            v53 = (unsigned __int64)(v74[11] + v88) >> 32;
            v74[11] += v88;
            v74[14] += v91;
            v74[21] += v99;
            v74[22] += v100;
            v48 = LODWORD(v74[15]) + v92;
            v46 = (unsigned __int64)(v74[15] + v92) >> 32;
            v74[15] += v92;
            v50 = HIDWORD(v74[16]) + v93;
            HIDWORD(v74[16]) += v93;
            v40 = LODWORD(v74[17]) + v94;
            LODWORD(v74[17]) += v94;
            v38 += v95;
            v32 = (__PAIR64__(v32, v29) + v96) >> 32;
            v29 += v96;
            v69 = v74[19] + v97;
            v74[19] += v97;
            v28 = LODWORD(v74[20]) + v98;
            v41 = (unsigned __int64)(v74[20] + v98) >> 32;
            v74[20] += v98;
            v67 = LODWORD(v74[23]) + v101;
            LODWORD(v74[23]) += v101;
            HIDWORD(v74[23]) |= v102;
            v75[0] += v76;
            v75[1] += v77;
            v75[2] += v78;
            v75[3] += v79;
            LODWORD(v75[4]) += v80;
            v75[6] += v82;
            HIDWORD(v75[7]) += v84;
            LODWORD(v75[8]) += v85;
            v75[5] += v81;
            LODWORD(v75[7]) += v83;
            v75[9] += v86;
            v75[12] += v89;
            v75[10] += v87;
            v75[13] += v90;
            v75[11] += v88;
            v75[14] += v91;
            v75[21] += v99;
            v75[22] += v100;
            v75[15] += v92;
            HIDWORD(v75[16]) += v93;
            v7 = v30;
            LODWORD(v75[17]) += v94;
            v5 = v36;
            v31 = (__PAIR64__(v31, v33) + v95) >> 32;
            v33 += v95;
            v3 = v34;
            v35 = (__PAIR64__(v35, v37) + v96) >> 32;
            v37 += v96;
            v12 = v65;
            v75[19] += v97;
            v13 = v27;
            v75[20] += v98;
            LODWORD(v75[23]) += v101;
            HIDWORD(v75[23]) |= v102;
            if ( ++v26 >= (unsigned int)v27 )
            {
              v14 = v25;
              v15 = v67;
              v17 = HIDWORD(v69);
              v16 = v69;
              v18 = __PAIR64__(v68, v70);
              v19 = v66;
              goto LABEL_11;
            }
          }
        }
        v15 = v74[23];
        v17 = HIDWORD(v74[19]);
        v16 = v74[19];
        v41 = HIDWORD(v74[20]);
        v19 = v74[1];
        v18 = v74[0];
        v28 = v74[20];
        v40 = v74[17];
        v50 = HIDWORD(v74[16]);
        v46 = HIDWORD(v74[15]);
        v48 = v74[15];
        v53 = HIDWORD(v74[11]);
        v45 = v74[11];
        v51 = HIDWORD(v74[10]);
        v57 = v74[10];
        v49 = HIDWORD(v74[9]);
        v39 = v74[9];
        v56 = HIDWORD(v74[6]);
        v58 = v74[6];
        v47 = HIDWORD(v74[5]);
        v55 = v74[5];
        v54 = HIDWORD(v74[3]);
        v44 = v74[3];
        v52 = HIDWORD(v74[2]);
        v42 = v74[2];
        v43 = HIDWORD(v74[1]);
LABEL_11:
        if ( v13 > 1 )
        {
          v74[0] = (unsigned int)_rt_udiv64(v13, v18);
          v74[1] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v43, v19));
          v74[2] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v52, v42));
          v74[3] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v54, v44));
          v74[6] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v56, v58));
          v74[5] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v47, v55));
          v74[9] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v49, v39));
          v74[10] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v51, v57));
          v74[11] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v53, v45));
          v74[15] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v46, v48));
          HIDWORD(v74[16]) = v50 / v13;
          LODWORD(v74[17]) = v40 / v13;
        }
        v5 = v36;
        if ( v36 )
        {
          if ( !v13 )
            __brkdiv0();
          LODWORD(v74[18]) = _rt_udiv64(v13, v38);
          HIDWORD(v74[18]) = _rt_udiv64(v13, __PAIR64__(v32, v29));
          v74[19] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v17, v16));
          v74[20] = (unsigned int)_rt_udiv64(v13, __PAIR64__(v41, v28));
        }
        v3 = v34;
        if ( v34 )
        {
          if ( !v13 )
            __brkdiv0();
          LODWORD(v74[23]) = v15 / v13;
        }
        RtlStringCbPrintfW(v103, 0x1Au, (int)L"%u,_Total", v14);
        RtlInitUnicodeString((unsigned int)v60, v103);
        v61 = v74;
        v62 = 192;
        v7 = v30;
        result = PcwAddInstance(v30, (int)v60, KeMaximumProcessors + v25, 1);
        if ( result < 0 )
          return result;
        v14 = v25;
        v21 = (unsigned __int16)KeNumberNodes;
      }
      v25 = ++v14;
      if ( v14 >= v21 )
      {
        v22 = (unsigned int)v63;
        goto LABEL_19;
      }
    }
  }
  v23 = *((_DWORD *)a2 + 3);
  if ( v23 >= KeNumberProcessors_0 )
    return -1073741275;
  ExpQueryProcessorInformationCounters(*(&KiProcessorBlock + v23), v2, v3, v5, &v76);
  v63 = &v76;
  v64 = 192;
  result = PcwAddInstance(v7, *((_DWORD *)a2 + 2), v23, 1);
  if ( result >= 0 )
    return 0;
  return result;
}
