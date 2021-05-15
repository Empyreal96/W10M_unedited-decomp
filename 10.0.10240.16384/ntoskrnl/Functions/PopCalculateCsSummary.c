// PopCalculateCsSummary 
 
int __fastcall PopCalculateCsSummary(int a1, int a2)
{
  __int64 v3; // r0
  unsigned int v4; // r7
  unsigned int v5; // r8
  unsigned int v6; // r4
  int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r9
  int v10; // r10
  int result; // r0
  int v12; // r0
  int v13; // r1
  int v14; // r0
  __int64 v15; // r0
  __int64 v16; // r0
  bool v17; // cf
  unsigned __int64 v18; // kr20_8
  int v19; // r1
  __int64 v20; // r0
  unsigned int v21; // r2
  unsigned int v22; // r4
  int v23; // r0
  int v24; // r1
  int v25; // r7
  int v26; // r8
  __int64 v27; // r0
  char v28; // r2
  int v29; // r3
  char v30; // r2
  int v31; // r0
  int v32; // r1
  unsigned int v33; // [sp+8h] [bp-B0h]
  int v34; // [sp+8h] [bp-B0h]
  int v35; // [sp+Ch] [bp-ACh]
  int v36; // [sp+Ch] [bp-ACh]
  unsigned __int64 v37; // [sp+10h] [bp-A8h]
  int v38; // [sp+10h] [bp-A8h]
  int v39; // [sp+14h] [bp-A4h]
  __int64 v40; // [sp+18h] [bp-A0h] BYREF
  int v41; // [sp+20h] [bp-98h]
  int v42; // [sp+24h] [bp-94h]
  int v43; // [sp+28h] [bp-90h]
  int v44; // [sp+2Ch] [bp-8Ch]
  int v45; // [sp+30h] [bp-88h]
  int v46; // [sp+34h] [bp-84h]
  __int64 v47; // [sp+38h] [bp-80h] BYREF
  int v48; // [sp+40h] [bp-78h]
  int v49; // [sp+44h] [bp-74h]
  int v50; // [sp+48h] [bp-70h]
  int v51; // [sp+4Ch] [bp-6Ch]
  int v52; // [sp+50h] [bp-68h]
  int v53; // [sp+54h] [bp-64h]
  int v54; // [sp+58h] [bp-60h]
  int v55; // [sp+5Ch] [bp-5Ch]
  int v56; // [sp+60h] [bp-58h]
  int v57; // [sp+64h] [bp-54h]
  int v58; // [sp+68h] [bp-50h]
  int v59; // [sp+6Ch] [bp-4Ch]
  int v60; // [sp+70h] [bp-48h]
  int v61; // [sp+74h] [bp-44h]
  int v62; // [sp+78h] [bp-40h] BYREF
  __int64 v63; // [sp+80h] [bp-38h] BYREF
  __int64 v64; // [sp+88h] [bp-30h]
  int v65; // [sp+90h] [bp-28h]
  int anonymous0; // [sp+C0h] [bp+8h]
  int varsC; // [sp+C4h] [bp+Ch]

  anonymous0 = a1;
  varsC = a2;
  v41 = 0;
  PopCalculateIdleInformation(&v63);
  v3 = RtlGetInterruptTimePrecise(&v62);
  v4 = HIDWORD(v3);
  v5 = v3;
  v6 = HIDWORD(qword_635388);
  v33 = qword_635388;
  v7 = _rt_udiv64(10i64, v3 - qword_635388);
  v9 = v8;
  v10 = v7;
  if ( PopPdcLastCsExitTime <= __PAIR64__(v6, v33) )
    return sub_50F7A0();
  v12 = _rt_udiv64(10i64, __PAIR64__(v4, v5) - PopPdcLastCsExitTime);
  v34 = v13;
  v44 = v12;
  v35 = dword_61ED98;
  if ( v10 | v9 && (dword_61ED98 & 0x40000000) == 0 && dword_61ED88 < (unsigned int)PopCsConsumption )
    v45 = PopBatteryCapacityToRate(PopCsConsumption - dword_61ED88, v13, v10, v9);
  else
    v45 = 0;
  v42 = dword_61EDA8;
  v50 = dword_61EDA4;
  if ( dword_61EDA4 )
    v46 = (unsigned __int8)(100 * dword_61EDA8 / (unsigned int)dword_61EDA4);
  else
    v46 = 0;
  if ( (v35 & 0x40000000) != 0 )
    v42 = 0;
  v56 = (unsigned __int64)(v64 - qword_635390) >> 32;
  v59 = v64 - qword_635390;
  v14 = dword_635500;
  v52 = v65 - dword_6353A0;
  __dmb(0xBu);
  v15 = PpmQueryPlatformStateResidency(v14);
  v16 = PopCalculateTotalHwDripsResidency(dword_6353F8, dword_6353FC, v15, HIDWORD(v15), v10, v9);
  v49 = HIDWORD(v16);
  v57 = v16;
  v17 = __CFADD__(qword_635398 - v63, v10);
  v60 = (qword_635398 - v63 + __PAIR64__(v9, v10)) >> 32;
  v48 = qword_635398 - v63 + v10;
  do
  {
    v18 = __ldrexd((unsigned __int64 *)&algn_635412[110]);
    v19 = v17 + HIDWORD(v18);
    v17 = 1;
  }
  while ( __strexd(__PAIR64__(v19, v18), (unsigned __int64 *)&algn_635412[110]) );
  v36 = v19;
  v43 = v18;
  v37 = qword_635388;
  if ( (unsigned int)v18 | v19 )
  {
    v31 = _rt_udiv64(10i64, __PAIR64__(v19, v18) - qword_635388);
    v36 = v32;
    v43 = v31;
  }
  v20 = PpmConvertTimeTo(dword_6353C0, dword_6353C4, 1000000, 0);
  v21 = HIDWORD(qword_6353E0);
  v22 = qword_6353E0;
  v54 = (unsigned __int64)(qword_6353D0 - v20) >> 32;
  v58 = qword_6353D0 - v20;
  if ( *(_QWORD *)algn_6353D8 )
  {
    if ( v37 <= *(_QWORD *)algn_6353D8 )
    {
      v21 = (qword_6353E0 - *(_QWORD *)algn_6353D8 + __PAIR64__(v4, v5)) >> 32;
      v22 = qword_6353E0 - *(_DWORD *)algn_6353D8 + v5;
    }
    else
    {
      v21 = (qword_6353E0 - v37 + __PAIR64__(v4, v5)) >> 32;
      v22 = qword_6353E0 - v37 + v5;
    }
  }
  v23 = _rt_udiv64(10i64, __PAIR64__(v21, v22));
  v25 = v24;
  v26 = v23;
  v27 = PpmConvertTimeTo(dword_6353F0, unk_6353F4, 1000000, 0);
  v38 = HIDWORD(v27);
  v39 = v27;
  v55 = PopPdcLastCsExitReason;
  v61 = byte_635410 & 1;
  v40 = 0i64;
  v47 = 0i64;
  LODWORD(v27) = dword_635500;
  __dmb(0xBu);
  PpmGetPlatformSelectionVetoCounts(v27, &v40, &v47);
  result = dword_6353A8;
  v53 = (unsigned __int64)(v40 - *(_QWORD *)&dword_635400) >> 32;
  v51 = v40 - dword_635400;
  LODWORD(v40) = (unsigned __int64)(v47 - *(_QWORD *)&dword_635408) >> 32;
  v62 = v47 - dword_635408;
  if ( dword_6353A8 )
  {
    result = _rt_udiv64(dword_6353A8, 100i64 * *(_QWORD *)&dword_6353B0);
    v41 = (unsigned __int8)result;
  }
  v29 = v45;
  v28 = v46;
  *(_DWORD *)(a1 + 16) = v10;
  *(_DWORD *)(a1 + 20) = v9;
  *(_DWORD *)(a1 + 64) = v26;
  *(_DWORD *)(a1 + 68) = v25;
  *(_DWORD *)a1 = v29;
  *(_DWORD *)(a1 + 4) = v50;
  *(_DWORD *)(a1 + 8) = v42;
  *(_DWORD *)(a1 + 24) = v59;
  *(_DWORD *)(a1 + 28) = v56;
  *(_DWORD *)(a1 + 32) = v48;
  *(_DWORD *)(a1 + 36) = v60;
  *(_DWORD *)(a1 + 40) = v52;
  *(_DWORD *)(a1 + 48) = v43;
  *(_DWORD *)(a1 + 52) = v36;
  *(_DWORD *)(a1 + 56) = v58;
  *(_DWORD *)(a1 + 60) = v54;
  *(_DWORD *)(a1 + 72) = v39;
  *(_DWORD *)(a1 + 76) = v38;
  *(_DWORD *)(a1 + 84) = v55;
  *(_DWORD *)(a1 + 88) = varsC;
  *(_DWORD *)(a1 + 96) = v57;
  *(_DWORD *)(a1 + 100) = v49;
  *(_DWORD *)(a1 + 104) = v51;
  *(_DWORD *)(a1 + 108) = v53;
  *(_DWORD *)(a1 + 112) = v62;
  *(_DWORD *)(a1 + 116) = v40;
  *(_BYTE *)(a1 + 128) = v41;
  *(_BYTE *)(a1 + 92) = v61 & 1 ^ (2 * v28);
  v30 = *(_BYTE *)(a1 + 93);
  *(_DWORD *)(a1 + 120) = v44;
  *(_DWORD *)(a1 + 124) = v34;
  *(_BYTE *)(a1 + 93) ^= (byte_635411 ^ v30) & 3;
  return result;
}
