// EtwTraceAppStateChange 
 
int __fastcall EtwTraceAppStateChange(int a1, int a2)
{
  int result; // r0
  unsigned __int64 v5; // kr00_8
  int v6; // r3
  int v7; // r6
  __int64 v8; // r7
  unsigned int v9; // r1
  int v10; // r3
  int v11; // r0
  int v12; // r1
  unsigned __int64 v13; // kr10_8
  int v14; // r0
  int v15; // r1
  int v16; // r0
  int v17; // r1
  int v18; // r7
  int v19; // r8
  int v20; // r0
  int v21; // r1
  int v22; // r1
  int v23; // r5
  int v24; // r4
  int v25; // r3
  unsigned int v26; // r3
  unsigned __int64 v27; // kr18_8
  unsigned int v28; // r3
  int v29; // r2
  unsigned __int64 v30; // kr08_8
  int v31; // r3
  bool v32; // r8
  __int64 v33; // kr28_8
  int v34; // r3
  int v35; // r5
  int v36; // r6
  int v37; // r3
  int v38; // r4
  int v39; // r3
  int v40; // r3
  int v41; // r3
  char v42; // [sp+8h] [bp-4A8h] BYREF
  char v43; // [sp+9h] [bp-4A7h] BYREF
  char v44; // [sp+Ah] [bp-4A6h] BYREF
  char v45; // [sp+Bh] [bp-4A5h] BYREF
  char v46; // [sp+Ch] [bp-4A4h] BYREF
  char v47; // [sp+Dh] [bp-4A3h] BYREF
  char v48; // [sp+Eh] [bp-4A2h] BYREF
  char v49; // [sp+Fh] [bp-4A1h] BYREF
  char v50; // [sp+10h] [bp-4A0h] BYREF
  char v51; // [sp+11h] [bp-49Fh] BYREF
  char v52; // [sp+12h] [bp-49Eh] BYREF
  char v53; // [sp+13h] [bp-49Dh] BYREF
  bool v54; // [sp+14h] [bp-49Ch] BYREF
  int v55; // [sp+18h] [bp-498h] BYREF
  int v56; // [sp+1Ch] [bp-494h]
  int v57; // [sp+20h] [bp-490h] BYREF
  int v58; // [sp+24h] [bp-48Ch] BYREF
  int v59; // [sp+28h] [bp-488h] BYREF
  int v60; // [sp+2Ch] [bp-484h] BYREF
  int v61; // [sp+30h] [bp-480h] BYREF
  int v62; // [sp+34h] [bp-47Ch]
  int v63; // [sp+38h] [bp-478h]
  int v64; // [sp+3Ch] [bp-474h] BYREF
  int v65; // [sp+40h] [bp-470h] BYREF
  int v66; // [sp+44h] [bp-46Ch]
  int v67; // [sp+48h] [bp-468h] BYREF
  int v68; // [sp+4Ch] [bp-464h] BYREF
  int v69; // [sp+50h] [bp-460h]
  int v70; // [sp+54h] [bp-45Ch]
  int v71[2]; // [sp+58h] [bp-458h] BYREF
  int v72[2]; // [sp+60h] [bp-450h] BYREF
  int v73[2]; // [sp+68h] [bp-448h] BYREF
  int v74[2]; // [sp+70h] [bp-440h] BYREF
  int v75[2]; // [sp+78h] [bp-438h] BYREF
  _DWORD v76[2]; // [sp+80h] [bp-430h] BYREF
  int v77[2]; // [sp+88h] [bp-428h] BYREF
  int v78[2]; // [sp+90h] [bp-420h] BYREF
  int v79[2]; // [sp+98h] [bp-418h] BYREF
  int v80[2]; // [sp+A0h] [bp-410h] BYREF
  int v81[2]; // [sp+A8h] [bp-408h] BYREF
  _DWORD v82[2]; // [sp+B0h] [bp-400h] BYREF
  int v83[2]; // [sp+B8h] [bp-3F8h] BYREF
  int v84[2]; // [sp+C0h] [bp-3F0h] BYREF
  int v85[2]; // [sp+C8h] [bp-3E8h] BYREF
  int v86[2]; // [sp+D0h] [bp-3E0h] BYREF
  int v87[2]; // [sp+D8h] [bp-3D8h] BYREF
  char v88[16]; // [sp+E0h] [bp-3D0h] BYREF
  int v89; // [sp+F0h] [bp-3C0h]
  int v90; // [sp+F4h] [bp-3BCh]
  __int64 v91; // [sp+100h] [bp-3B0h]
  __int64 v92; // [sp+108h] [bp-3A8h]
  __int64 v93; // [sp+118h] [bp-398h]
  __int64 v94; // [sp+120h] [bp-390h]
  int v95[24]; // [sp+130h] [bp-380h] BYREF
  _DWORD v96[124]; // [sp+190h] [bp-320h] BYREF
  _DWORD v97[76]; // [sp+380h] [bp-130h] BYREF

  v61 = a2;
  result = TraceLoggingProviderEnabled(&dword_616438);
  if ( result )
  {
    __dmb(0xBu);
    do
      v5 = __ldrexd(EtwpAppStateChangeSequenceNumber);
    while ( __strexd(v5 + 1, EtwpAppStateChangeSequenceNumber) );
    v60 = (v5 + 1) >> 32;
    v58 = v5 + 1;
    __dmb(0xBu);
    memset(v95, 0, sizeof(v95));
    v6 = *(_DWORD *)(a1 + 820);
    v69 = *(_DWORD *)(a1 + 816);
    v7 = v6 | (MEMORY[0xFFFF92C4] << 16);
    v70 = v7;
    EtwpGetProcessAppSessionGuid(a1, &v95[6]);
    v8 = *(_QWORD *)a2;
    v9 = *(_DWORD *)(a2 + 20);
    v95[2] = v95[6];
    v95[3] = v95[7];
    v95[4] = v69;
    v95[5] = v95[9];
    v10 = *(_DWORD *)(a2 + 52);
    v95[5] = v7;
    v68 = v10;
    v95[0] = v10;
    v65 = *(_DWORD *)(a2 + 48);
    v95[1] = v65;
    v11 = _rt_udiv64(10000i64, v8 - __PAIR64__(v9, *(_DWORD *)(a2 + 16)));
    v67 = v12;
    v95[10] = v11;
    v95[11] = v12;
    v64 = v11;
    v13 = *(_QWORD *)(a2 + 32);
    v14 = _rt_udiv64(10000i64, v13 - *(_QWORD *)(a2 + 24));
    v59 = v15;
    v95[12] = v14;
    v95[13] = v15;
    v57 = v14;
    v16 = _rt_udiv64(10000i64, v8 - *(_QWORD *)(a1 + 824));
    v18 = v17;
    v95[14] = v16;
    v95[15] = v17;
    v19 = v16;
    v20 = _rt_udiv64(10000i64, v13);
    v63 = v21;
    v95[16] = v20;
    v95[17] = v21;
    v66 = v20;
    result = _rt_udiv64(10000i64, *(_QWORD *)(v61 + 40));
    v61 = result;
    v62 = v22;
    v95[18] = result;
    v95[19] = v22;
    v23 = v60;
    v24 = v58;
    v60 = *(_DWORD *)(a1 + 816);
    v95[21] = v23;
    v95[22] = v60;
    v25 = *(_DWORD *)(a1 + 820);
    v95[20] = v58;
    v58 = v25;
    v95[23] = v25;
    if ( v68 == 3 )
    {
      PsQueryStatisticsProcess(a1, (int)v88);
      result = ObGetProcessHandleCount(a1, 0);
      v26 = *(_DWORD *)(a1 + 484);
      v62 = result;
      __dmb(0xBu);
      v27 = (unsigned __int64)v26 << 12;
      v63 = v26 << 12;
      v28 = *(_DWORD *)(a1 + 488);
      v66 = HIDWORD(v27);
      __dmb(0xBu);
      v30 = (unsigned __int64)v28 << 12;
      v29 = HIDWORD(v30);
      v59 = v30;
      v31 = *(_DWORD *)(a1 + 736);
      v57 = v29;
      v32 = (v31 & 0x10) != 0;
      v33 = v91;
      if ( v91 >= 0xFFFFFFFFi64 )
      {
        result = sub_7C2DC4();
      }
      else
      {
        v56 = HIDWORD(v91);
        v34 = HIDWORD(v92);
        v35 = v92;
        if ( v92 >= 0xFFFFFFFFi64 )
        {
          v35 = -1;
          v34 = 0;
        }
        v56 = v34;
        v55 = v93 >> 9;
        v36 = v93 / 1024;
        v37 = (unsigned __int64)(v93 / 1024) >> 32;
        if ( v37 > 0 || v37 >= 0 && v36 == -1 )
        {
          v36 = -1;
          v37 = 0;
        }
        v56 = v37;
        v55 = v94 >> 9;
        v38 = v94 / 1024;
        v39 = (unsigned __int64)(v94 / 1024) >> 32;
        if ( v39 > 0 || v39 >= 0 && v38 == -1 )
        {
          v38 = -1;
          v39 = 0;
        }
        v56 = v39;
        if ( (unsigned int)dword_616438 > 5 )
        {
          result = TlgKeywordOn((int)&dword_616438, 0x400000000003i64);
          if ( result )
          {
            v54 = v32;
            v60 = v36;
            v43 = v95[0];
            v58 = v38;
            v44 = v95[1];
            v46 = 1;
            v42 = 1;
            v50 = 1;
            v71[0] = v95[10];
            v71[1] = v95[11];
            v87[0] = v95[12];
            v87[1] = v95[13];
            v80[0] = v95[14];
            v80[1] = v95[15];
            v86[0] = v95[16];
            v86[1] = v95[17];
            v72[0] = v95[18];
            v72[1] = v95[19];
            v52 = 1;
            v73[0] = v95[20];
            v73[1] = v95[21];
            v75[0] = v95[22];
            v75[1] = v95[23];
            v67 = *(_DWORD *)(a1 + 176);
            v77[0] = v69;
            v77[1] = v70;
            v64 = *(_DWORD *)(a1 + 632);
            v65 = *(unsigned __int8 *)(a1 + 735);
            v68 = v62;
            v79[0] = v63;
            v79[1] = v66;
            v40 = v59;
            v59 = v33;
            v81[0] = v40;
            v41 = v57;
            v57 = v35;
            v81[1] = v41;
            v83[0] = v89;
            v83[1] = v90;
            v61 = *(_DWORD *)(a1 + 580);
            v96[8] = &v43;
            v96[9] = 0;
            v96[10] = 1;
            v96[11] = 0;
            v96[12] = &v44;
            v96[13] = 0;
            v96[14] = 1;
            v96[15] = 0;
            v96[16] = &v95[2];
            v96[17] = 0;
            v96[18] = 16;
            v96[19] = 0;
            v96[20] = &v46;
            v96[21] = 0;
            v96[22] = 1;
            v96[23] = 0;
            v96[24] = &v42;
            v96[25] = 0;
            v96[26] = 1;
            v96[27] = 0;
            v96[28] = &v50;
            v96[29] = 0;
            v96[30] = 1;
            v96[31] = 0;
            v96[32] = &v95[6];
            v96[33] = 0;
            v96[34] = 16;
            v96[35] = 0;
            v96[36] = v71;
            v96[37] = 0;
            v96[38] = 8;
            v96[39] = 0;
            v96[40] = v87;
            v96[41] = 0;
            v96[42] = 8;
            v96[43] = 0;
            v96[44] = v80;
            v96[45] = 0;
            v96[46] = 8;
            v96[47] = 0;
            v96[48] = v86;
            v96[49] = 0;
            v96[50] = 8;
            v96[51] = 0;
            v96[52] = v72;
            v96[53] = 0;
            v96[54] = 8;
            v96[55] = 0;
            v96[56] = &v52;
            v96[57] = 0;
            v96[58] = 1;
            v96[59] = 0;
            v96[60] = v73;
            v96[61] = 0;
            v96[62] = 8;
            v96[63] = 0;
            v96[64] = v75;
            v96[65] = 0;
            v96[66] = 8;
            v96[67] = 0;
            v96[68] = &v67;
            v96[69] = 0;
            v96[70] = 4;
            v96[71] = 0;
            v96[72] = v77;
            v96[73] = 0;
            v96[74] = 8;
            v96[75] = 0;
            v96[76] = &v64;
            v96[77] = 0;
            v96[78] = 4;
            v96[79] = 0;
            v96[80] = &v54;
            v96[81] = 0;
            v96[82] = 1;
            v96[83] = 0;
            v96[84] = &v65;
            v96[85] = 0;
            v96[86] = 4;
            v96[87] = 0;
            v96[88] = &v68;
            v96[89] = 0;
            v96[90] = 4;
            v96[91] = 0;
            v96[92] = v79;
            v96[93] = 0;
            v96[94] = 8;
            v96[95] = 0;
            v96[96] = v81;
            v96[97] = 0;
            v96[98] = 8;
            v96[99] = 0;
            v96[100] = v83;
            v96[101] = 0;
            v96[102] = 8;
            v96[103] = 0;
            v96[104] = &v59;
            v96[105] = 0;
            v96[106] = 4;
            v96[107] = 0;
            v96[108] = &v57;
            v96[109] = 0;
            v96[110] = 4;
            v96[111] = 0;
            v96[112] = &v60;
            v96[113] = 0;
            v96[114] = 4;
            v96[115] = 0;
            v96[116] = &v58;
            v96[117] = 0;
            v96[118] = 4;
            v96[119] = 0;
            v96[120] = &v61;
            v96[121] = 0;
            v96[122] = 4;
            v96[123] = 0;
            result = TlgWrite(&dword_616438, (unsigned __int8 *)&byte_414CE5[1], 0, 0, 31, v96);
          }
        }
      }
    }
    else if ( (unsigned int)dword_616438 > 5 )
    {
      result = TlgKeywordOn((int)&dword_616438, 0x400000000001i64);
      if ( result )
      {
        v49 = v68;
        v82[0] = v19;
        v82[1] = v18;
        v48 = v65;
        v45 = 1;
        v53 = 1;
        v47 = 1;
        v76[0] = v24;
        v76[1] = v23;
        v84[0] = v64;
        v84[1] = v67;
        v78[0] = v57;
        v78[1] = v59;
        v74[0] = v66;
        v74[1] = v63;
        v85[0] = v61;
        v85[1] = v62;
        v51 = 1;
        v55 = v60;
        v56 = v58;
        v97[8] = &v49;
        v97[9] = 0;
        v97[10] = 1;
        v97[11] = 0;
        v97[12] = &v48;
        v97[13] = 0;
        v97[14] = 1;
        v97[15] = 0;
        v97[16] = &v95[2];
        v97[17] = 0;
        v97[18] = 16;
        v97[19] = 0;
        v97[20] = &v45;
        v97[21] = 0;
        v97[22] = 1;
        v97[23] = 0;
        v97[24] = &v53;
        v97[25] = 0;
        v97[26] = 1;
        v97[27] = 0;
        v97[28] = &v47;
        v97[29] = 0;
        v97[30] = 1;
        v97[31] = 0;
        v97[32] = &v95[6];
        v97[33] = 0;
        v97[34] = 16;
        v97[35] = 0;
        v97[36] = v84;
        v97[37] = 0;
        v97[38] = 8;
        v97[39] = 0;
        v97[40] = v78;
        v97[41] = 0;
        v97[42] = 8;
        v97[43] = 0;
        v97[44] = v82;
        v97[45] = 0;
        v97[46] = 8;
        v97[47] = 0;
        v97[48] = v74;
        v97[49] = 0;
        v97[50] = 8;
        v97[51] = 0;
        v97[52] = v85;
        v97[53] = 0;
        v97[54] = 8;
        v97[55] = 0;
        v97[56] = &v51;
        v97[57] = 0;
        v97[58] = 1;
        v97[59] = 0;
        v97[60] = v76;
        v97[61] = 0;
        v97[62] = 8;
        v97[63] = 0;
        v97[64] = &v55;
        v97[65] = 0;
        v97[66] = 8;
        v97[67] = 0;
        result = TlgWrite(&dword_616438, (unsigned __int8 *)&word_414BA2 + 1, 0, 0, 17, v97);
      }
    }
  }
  return result;
}
