// ExpQueryProcessorInformationCounters 
 
int __fastcall ExpQueryProcessorInformationCounters(int a1, int a2, int a3, int a4, int a5)
{
  int result; // r0
  int v9; // r1
  int v10; // r4
  int v11; // r3
  int v12; // r1
  __int64 v13; // r2
  int v14; // r1
  unsigned __int64 v15; // kr10_8
  unsigned __int64 v16; // kr18_8
  unsigned int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r0
  unsigned __int64 v20; // kr40_8
  unsigned int v21; // r1
  int v22; // r0
  unsigned int v23; // r1
  int v24; // r1
  int v25; // r4
  int v26; // r6
  int v27; // r7
  int v28; // lr
  int *v29; // r2
  int v30; // r3
  int v31; // r3
  __int16 v32; // [sp+0h] [bp-A0h] BYREF
  char v33; // [sp+2h] [bp-9Eh]
  char v34; // [sp+3h] [bp-9Dh]
  int v35[8]; // [sp+8h] [bp-98h] BYREF
  int v36; // [sp+28h] [bp-78h] BYREF
  int v37; // [sp+2Ch] [bp-74h]
  int v38; // [sp+30h] [bp-70h]
  int v39; // [sp+34h] [bp-6Ch]
  int v40; // [sp+38h] [bp-68h]
  int v41; // [sp+3Ch] [bp-64h]
  int v42[4]; // [sp+40h] [bp-60h] BYREF
  char v43[8]; // [sp+50h] [bp-50h] BYREF
  int v44; // [sp+58h] [bp-48h]
  int v45; // [sp+5Ch] [bp-44h]
  int v46; // [sp+60h] [bp-40h]
  int v47; // [sp+64h] [bp-3Ch]
  int v48; // [sp+68h] [bp-38h]
  int v49; // [sp+6Ch] [bp-34h]
  int v50; // [sp+70h] [bp-30h]
  int v51; // [sp+74h] [bp-2Ch]
  int v52; // [sp+78h] [bp-28h]

  v32 = *(unsigned __int8 *)(a1 + 1052);
  v33 = *(_BYTE *)(a1 + 1053);
  v34 = 0;
  if ( !a2 )
    return sub_7F3304();
  PoGetIdleTimes((int)&v32, (int)v43, (int)v42);
  v9 = v44;
  v10 = KeMaximumIncrement;
  *(_DWORD *)(a5 + 80) = v46;
  v11 = v47;
  *(_DWORD *)(a5 + 72) = v9;
  v12 = v45;
  *(_DWORD *)(a5 + 84) = v11;
  HIDWORD(v13) = v51;
  LODWORD(v13) = 0;
  *(_DWORD *)(a5 + 76) = v12;
  *(_QWORD *)(a5 + 100) = v13;
  HIDWORD(v13) = v48;
  v14 = v50;
  *(_DWORD *)(a5 + 108) = 0;
  *(_DWORD *)(a5 + 88) = HIDWORD(v13);
  HIDWORD(v13) = v49;
  *(_DWORD *)(a5 + 116) = 0;
  *(_DWORD *)(a5 + 92) = HIDWORD(v13);
  *(_DWORD *)(a5 + 96) = v14;
  *(_DWORD *)(a5 + 112) = v52;
  *(_DWORD *)(a5 + 120) = v42[2];
  *(_DWORD *)(a5 + 124) = v42[3];
  v15 = (unsigned int)v10 * (unsigned __int64)(unsigned int)v42[0];
  *(_QWORD *)a5 = v15;
  v16 = (unsigned int)v10 * (unsigned __int64)*(unsigned int *)(a1 + 2348);
  *(_DWORD *)(a5 + 8) = v16 + v15;
  HIDWORD(v13) = v42[1];
  *(_DWORD *)(a5 + 12) = (v16 + v15) >> 32;
  *(_QWORD *)(a5 + 24) = (unsigned int)v10 * (unsigned __int64)HIDWORD(v13) - v15;
  v17 = *(_DWORD *)(a5 + 92);
  v18 = *(_DWORD *)(a5 + 88);
  *(_QWORD *)(a5 + 16) = (unsigned int)v10 * (unsigned __int64)*(unsigned int *)(a1 + 2312);
  *(_DWORD *)(a5 + 32) = *(_DWORD *)(a1 + 2304);
  *(_QWORD *)(a5 + 48) = (unsigned int)v10 * (unsigned __int64)*(unsigned int *)(a1 + 2320);
  *(_DWORD *)(a5 + 60) = *(_DWORD *)(a1 + 1696);
  *(_DWORD *)(a5 + 64) = *(_DWORD *)(a1 + 1740);
  *(_QWORD *)(a5 + 40) = (unsigned int)v10 * (unsigned __int64)*(unsigned int *)(a1 + 2316);
  LODWORD(v13) = *(_DWORD *)(a5 + 84);
  *(_DWORD *)(a5 + 56) = *(_DWORD *)(a1 + 1768);
  v20 = __PAIR64__(v17, v18) + __PAIR64__(v13, *(_DWORD *)(a5 + 80));
  v19 = (__PAIR64__(v17, v18) + __PAIR64__(v13, *(_DWORD *)(a5 + 80))) >> 32;
  v21 = *(_DWORD *)(a5 + 112);
  *(_QWORD *)(a5 + 168) = *(_QWORD *)(a5 + 72) + __PAIR64__(v19, v20);
  HIDWORD(v13) = *(_DWORD *)(a5 + 96);
  v22 = (__PAIR64__(*(_DWORD *)(a5 + 116), v21) + *(_QWORD *)(a5 + 104)) >> 32;
  v23 = v21 + *(_DWORD *)(a5 + 104);
  LODWORD(v13) = *(_DWORD *)(a5 + 100);
  *(_DWORD *)(a5 + 176) = HIDWORD(v13) + v23;
  *(_DWORD *)(a5 + 180) = v22 + __CFADD__(HIDWORD(v13), v23) + (_DWORD)v13;
  memset(v35, 0, sizeof(v35));
  v24 = 0;
  result = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v28 = 0;
  if ( a4 )
    v29 = &v36;
  else
    v29 = 0;
  if ( a3 || v29 )
  {
    PoGetPerfStateAndParkingInfo((int)&v32, (int)v35, v29, 0);
    v27 = v40;
    v28 = v41;
    v25 = v38;
    v26 = v39;
    v24 = v36;
    result = v37;
  }
  v30 = BYTE1(v35[7]);
  *(_DWORD *)(a5 + 144) = v24;
  *(_DWORD *)(a5 + 148) = result;
  *(_DWORD *)(a5 + 152) = v25;
  *(_DWORD *)(a5 + 156) = v26;
  *(_DWORD *)(a5 + 128) = v30;
  v31 = v35[1];
  *(_DWORD *)(a5 + 160) = v27;
  *(_DWORD *)(a5 + 164) = v28;
  *(_DWORD *)(a5 + 132) = v31;
  *(_DWORD *)(a5 + 136) = v35[2];
  *(_DWORD *)(a5 + 140) = v35[0];
  *(_DWORD *)(a5 + 184) = v35[5];
  *(_DWORD *)(a5 + 188) = v35[6];
  return result;
}
