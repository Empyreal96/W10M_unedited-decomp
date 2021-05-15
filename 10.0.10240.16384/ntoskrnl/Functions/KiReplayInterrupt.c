// KiReplayInterrupt 
 
int __fastcall KiReplayInterrupt(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r5
  unsigned int v8; // r4
  int v9; // r8
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int *v14; // r0
  unsigned int v15; // r1
  int v17; // r3
  unsigned int v18; // r0
  int v19; // r1
  unsigned int v20; // r4
  unsigned int v21; // lr
  bool v22; // cf
  unsigned int v23; // r3
  int v24; // r0
  unsigned __int64 *v25; // r6
  unsigned __int64 v26; // kr00_8
  unsigned __int64 v27; // kr08_8
  unsigned __int64 v28; // r2
  char v29; // r5
  int v30; // r4
  unsigned __int64 *v31; // r4
  unsigned __int64 v32; // kr10_8
  unsigned __int64 v33; // kr18_8
  int v34; // r1
  int v35; // r1
  unsigned int v36; // r4
  unsigned int v37; // r1
  int v38; // r4
  unsigned int v39; // r3
  unsigned int v40; // r3
  int v41; // r1
  int v42; // r2
  int v43; // r0
  int v44; // r2
  int v45; // [sp+0h] [bp-C8h]
  unsigned int v48; // [sp+10h] [bp-B8h]
  int v49; // [sp+14h] [bp-B4h]
  unsigned int v50; // [sp+18h] [bp-B0h]
  char v51[12]; // [sp+20h] [bp-A8h] BYREF
  unsigned int v52; // [sp+2Ch] [bp-9Ch]
  char v53; // [sp+30h] [bp-98h]
  char v54; // [sp+32h] [bp-96h]
  int v55; // [sp+34h] [bp-94h]
  int v56; // [sp+9Ch] [bp-2Ch]
  int v57; // [sp+A0h] [bp-28h]
  unsigned int v58; // [sp+A4h] [bp-24h]
  int vars4; // [sp+CCh] [bp+4h]

  v4 = a4;
  v5 = a2;
  v8 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v9 = v8 + 1408;
  if ( *(_BYTE *)(v8 + 1424) )
  {
    ++*(_BYTE *)(v8 + 1424);
  }
  else
  {
    v17 = *(_DWORD *)(v8 + 1412);
    *(_BYTE *)(v8 + 1424) = 1;
    v49 = v17;
    v18 = ReadTimeStampCounter();
    v20 = *(_DWORD *)(v8 + 3784);
    v21 = v18;
    v22 = v18 >= v20;
    v23 = v18 - v20;
    v24 = v49;
    v48 = v19 - (*(_DWORD *)(v9 + 2380) + !v22);
    v25 = (unsigned __int64 *)(v49 + 48);
    v50 = v23;
    v26 = *(_QWORD *)(v49 + 48) + __PAIR64__(v48, v23);
    __dmb(0xBu);
    do
      v27 = __ldrexd(v25);
    while ( __strexd(v26, v25) );
    __dmb(0xBu);
    v28 = __PAIR64__(v48, *(_DWORD *)(v49 + 56)) + v23;
    if ( HIDWORD(v28) )
      return sub_53EB8C(v49);
    *(_DWORD *)(v9 + 2376) = v21;
    *(_DWORD *)(v9 + 2380) = v19;
    v29 = *(_BYTE *)(v49 + 2);
    *(_DWORD *)(v49 + 56) = v28;
    if ( (v29 & 0x3E) != 0 )
    {
      if ( (v29 & 0x10) != 0 )
      {
        v37 = *(_DWORD *)(v9 + 2376);
        v38 = v9 + 8 * *(unsigned __int8 *)(v49 + 84);
        v39 = *(_DWORD *)(v9 + 2384);
        v29 &= 0xEFu;
        v22 = v37 >= v39;
        v40 = v37 - v39;
        v41 = *(_DWORD *)(v38 + 2392);
        v42 = *(_DWORD *)(v9 + 2380) - (*(_DWORD *)(v9 + 2388) + !v22);
        v43 = *(_DWORD *)(v38 + 2396);
        *(_DWORD *)(v38 + 2392) = v40 + v41;
        v44 = v43 + __CFADD__(v40, v41) + v42;
        v24 = v49;
        *(_DWORD *)(v38 + 2396) = v44;
        *(_DWORD *)(v9 + 2384) = 0;
        *(_DWORD *)(v9 + 2388) = 0;
      }
      if ( (v29 & 0x3E) != 0 )
      {
        if ( (v29 & 0x20) != 0 )
        {
          v30 = *(_DWORD *)(v24 + 1084);
          if ( v30 )
          {
            v31 = (unsigned __int64 *)(v30 + 8 * (*(unsigned __int8 *)(v9 + 2986) + 2 * PoGetFrequencyBucket(v9)));
            v32 = *v31 + __PAIR64__(v48, v50);
            __dmb(0xBu);
            do
              v33 = __ldrexd(v31);
            while ( __strexd(v32, v31) );
            __dmb(0xBu);
            v24 = v49;
          }
          v29 &= 0xDFu;
        }
        if ( (v29 & 0x3E) != 0 )
        {
          v34 = *(_DWORD *)(v24 + 68);
          if ( v34 && (v35 = v34 + *(_DWORD *)(v9 + 2352)) != 0 )
          {
            v36 = v48;
            do
            {
              *(_QWORD *)v35 += __PAIR64__(v48, v50);
              v35 = *(_DWORD *)(v35 + 236);
            }
            while ( v35 );
          }
          else
          {
            v36 = v48;
          }
          if ( (*(_BYTE *)(v24 + 2) & 8) != 0
            && (*(_DWORD *)(*(_DWORD *)(v9 + 2360) + 260) & *(_DWORD *)(v24 + 356)) != *(_DWORD *)(*(_DWORD *)(v9 + 2360)
                                                                                                 + 260) )
          {
            *(_QWORD *)(v9 + 2368) += __PAIR64__(v36, v50);
          }
          if ( *(_DWORD *)(v24 + 236) )
            KiEndCounterAccumulation(v24);
        }
      }
    }
    v5 = a2;
    v4 = a4;
  }
  v53 = 0;
  v58 = __get_CPSR();
  v55 = 0;
  v52 = (unsigned int)KiResetException & 0xFFFFFFFE;
  v54 = 0;
  v56 = RtlpGetFrameChain();
  v57 = vars4;
  RtlpSetFrameChain();
  v14 = KeGetCurrentStackPointer(v10, v11, v12, v13, v45);
  v15 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1574);
  if ( (unsigned int)v14 < v15 && v15 - 12288 <= (unsigned int)v14 || (KiBugCheckActive & 3) != 0 )
    KiPlayInterrupt(v51, a1, v5, a3);
  else
    KxSwitchStackAndPlayInterrupt((int)v51, a1, v5, a3, *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1574));
  return HalEndSystemInterrupt(a1, a3, v4, v51);
}
