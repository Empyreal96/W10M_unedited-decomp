// PopCalculateCsSummary 
 
void __fastcall PopCalculateCsSummary(int a1, int a2)
{
  __int64 v3; // r0
  unsigned int v4; // r7
  unsigned int v5; // r8
  unsigned int v6; // r4
  int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r9
  int v10; // r10
  int v11; // r0
  int v12; // r1
  unsigned int v13; // r0
  unsigned __int64 v14; // r0
  int v15; // r0
  int v16; // r1
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
  int v27; // r0
  int v28; // r1
  unsigned int v29; // r0
  char v30; // r2
  int v31; // r3
  char v32; // r2
  int v33; // r0
  int v34; // r1
  unsigned int v35; // [sp+8h] [bp-B0h]
  int v36; // [sp+8h] [bp-B0h]
  int v37; // [sp+Ch] [bp-ACh]
  int v38; // [sp+Ch] [bp-ACh]
  unsigned __int64 v39; // [sp+10h] [bp-A8h]
  int v40; // [sp+10h] [bp-A8h]
  int v41; // [sp+14h] [bp-A4h]
  __int64 v42; // [sp+18h] [bp-A0h] BYREF
  int v43; // [sp+20h] [bp-98h]
  int v44; // [sp+24h] [bp-94h]
  int v45; // [sp+28h] [bp-90h]
  int v46; // [sp+2Ch] [bp-8Ch]
  int v47; // [sp+30h] [bp-88h]
  int v48; // [sp+34h] [bp-84h]
  __int64 v49; // [sp+38h] [bp-80h] BYREF
  int v50; // [sp+40h] [bp-78h]
  int v51; // [sp+44h] [bp-74h]
  int v52; // [sp+48h] [bp-70h]
  int v53; // [sp+4Ch] [bp-6Ch]
  int v54; // [sp+50h] [bp-68h]
  int v55; // [sp+54h] [bp-64h]
  int v56; // [sp+58h] [bp-60h]
  int v57; // [sp+5Ch] [bp-5Ch]
  int v58; // [sp+60h] [bp-58h]
  int v59; // [sp+64h] [bp-54h]
  int v60; // [sp+68h] [bp-50h]
  int v61; // [sp+6Ch] [bp-4Ch]
  int v62; // [sp+70h] [bp-48h]
  int v63; // [sp+74h] [bp-44h]
  int v64; // [sp+78h] [bp-40h] BYREF
  __int64 v65; // [sp+80h] [bp-38h] BYREF
  __int64 v66; // [sp+88h] [bp-30h]
  int v67; // [sp+90h] [bp-28h]
  int anonymous0; // [sp+C0h] [bp+8h]
  int varsC; // [sp+C4h] [bp+Ch]

  anonymous0 = a1;
  varsC = a2;
  v43 = 0;
  PopCalculateIdleInformation((int)&v65);
  LODWORD(v3) = RtlGetInterruptTimePrecise(&v64);
  v4 = HIDWORD(v3);
  v5 = v3;
  v6 = HIDWORD(qword_635388);
  v35 = qword_635388;
  v7 = _rt_udiv64(10i64, v3 - qword_635388);
  v9 = v8;
  v10 = v7;
  if ( PopPdcLastCsExitTime <= __PAIR64__(v6, v35) )
  {
    sub_50F7A0();
  }
  else
  {
    v11 = _rt_udiv64(10i64, __PAIR64__(v4, v5) - PopPdcLastCsExitTime);
    v36 = v12;
    v46 = v11;
    v37 = dword_61ED98;
    if ( v10 | v9 && (dword_61ED98 & 0x40000000) == 0 && dword_61ED88 < (unsigned int)PopCsConsumption )
      v47 = PopBatteryCapacityToRate(PopCsConsumption - dword_61ED88, __SPAIR64__(v9, v10));
    else
      v47 = 0;
    v44 = dword_61EDA8;
    v52 = dword_61EDA4;
    if ( dword_61EDA4 )
      v48 = (unsigned __int8)(100 * dword_61EDA8 / (unsigned int)dword_61EDA4);
    else
      v48 = 0;
    if ( (v37 & 0x40000000) != 0 )
      v44 = 0;
    v58 = (unsigned __int64)(v66 - qword_635390) >> 32;
    v61 = v66 - qword_635390;
    v13 = dword_635500;
    v54 = v67 - dword_6353A0;
    __dmb(0xBu);
    LODWORD(v14) = PpmQueryPlatformStateResidency(v13);
    v15 = PopCalculateTotalHwDripsResidency(*(unsigned __int64 *)&dword_6353F8, v14, __PAIR64__(v9, v10));
    v51 = v16;
    v59 = v15;
    v17 = __CFADD__(qword_635398 - v65, v10);
    v62 = (qword_635398 - v65 + __PAIR64__(v9, v10)) >> 32;
    v50 = qword_635398 - v65 + v10;
    do
    {
      v18 = __ldrexd((unsigned __int64 *)&algn_635412[110]);
      v19 = v17 + HIDWORD(v18);
      v17 = 1;
    }
    while ( __strexd(__PAIR64__(v19, v18), (unsigned __int64 *)&algn_635412[110]) );
    v38 = v19;
    v45 = v18;
    v39 = qword_635388;
    if ( (unsigned int)v18 | v19 )
    {
      v33 = _rt_udiv64(10i64, __PAIR64__(v19, v18) - qword_635388);
      v38 = v34;
      v45 = v33;
    }
    LODWORD(v20) = PpmConvertTimeTo(qword_6353C0, SHIDWORD(qword_6353C0));
    v21 = HIDWORD(qword_6353E0);
    v22 = qword_6353E0;
    v56 = (unsigned __int64)(qword_6353D0 - v20) >> 32;
    v60 = qword_6353D0 - v20;
    if ( *(_QWORD *)algn_6353D8 )
    {
      if ( v39 <= *(_QWORD *)algn_6353D8 )
      {
        v21 = (qword_6353E0 - *(_QWORD *)algn_6353D8 + __PAIR64__(v4, v5)) >> 32;
        v22 = qword_6353E0 - *(_DWORD *)algn_6353D8 + v5;
      }
      else
      {
        v21 = (qword_6353E0 - v39 + __PAIR64__(v4, v5)) >> 32;
        v22 = qword_6353E0 - v39 + v5;
      }
    }
    v23 = _rt_udiv64(10i64, __PAIR64__(v21, v22));
    v25 = v24;
    v26 = v23;
    v27 = PpmConvertTimeTo(dword_6353F0, unk_6353F4);
    v40 = v28;
    v41 = v27;
    v57 = PopPdcLastCsExitReason;
    v63 = byte_635410 & 1;
    v42 = 0i64;
    v49 = 0i64;
    v29 = dword_635500;
    __dmb(0xBu);
    PpmGetPlatformSelectionVetoCounts(v29, &v42, &v49);
    v55 = (unsigned __int64)(v42 - *(_QWORD *)&dword_635400) >> 32;
    v53 = v42 - dword_635400;
    LODWORD(v42) = (unsigned __int64)(v49 - *(_QWORD *)&dword_635408) >> 32;
    v64 = v49 - dword_635408;
    if ( qword_6353A8 )
      v43 = (unsigned __int8)_rt_udiv64(qword_6353A8, 100i64 * *(_QWORD *)&dword_6353B0);
    v31 = v47;
    v30 = v48;
    *(_DWORD *)(a1 + 16) = v10;
    *(_DWORD *)(a1 + 20) = v9;
    *(_DWORD *)(a1 + 64) = v26;
    *(_DWORD *)(a1 + 68) = v25;
    *(_DWORD *)a1 = v31;
    *(_DWORD *)(a1 + 4) = v52;
    *(_DWORD *)(a1 + 8) = v44;
    *(_DWORD *)(a1 + 24) = v61;
    *(_DWORD *)(a1 + 28) = v58;
    *(_DWORD *)(a1 + 32) = v50;
    *(_DWORD *)(a1 + 36) = v62;
    *(_DWORD *)(a1 + 40) = v54;
    *(_DWORD *)(a1 + 48) = v45;
    *(_DWORD *)(a1 + 52) = v38;
    *(_DWORD *)(a1 + 56) = v60;
    *(_DWORD *)(a1 + 60) = v56;
    *(_DWORD *)(a1 + 72) = v41;
    *(_DWORD *)(a1 + 76) = v40;
    *(_DWORD *)(a1 + 84) = v57;
    *(_DWORD *)(a1 + 88) = varsC;
    *(_DWORD *)(a1 + 96) = v59;
    *(_DWORD *)(a1 + 100) = v51;
    *(_DWORD *)(a1 + 104) = v53;
    *(_DWORD *)(a1 + 108) = v55;
    *(_DWORD *)(a1 + 112) = v64;
    *(_DWORD *)(a1 + 116) = v42;
    *(_BYTE *)(a1 + 128) = v43;
    *(_BYTE *)(a1 + 92) = v63 & 1 ^ (2 * v30);
    v32 = *(_BYTE *)(a1 + 93);
    *(_DWORD *)(a1 + 120) = v46;
    *(_DWORD *)(a1 + 124) = v36;
    *(_BYTE *)(a1 + 93) ^= (byte_635411 ^ v32) & 3;
  }
}
