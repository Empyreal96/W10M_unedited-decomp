// KiProcessInterrupt 
 
int __fastcall KiProcessInterrupt(int a1)
{
  int v1; // r9
  unsigned int v2; // r3
  int v3; // r8
  int v4; // r1
  int v5; // r5
  int v6; // r9
  __int64 v7; // r0
  unsigned __int64 *v8; // r6
  __int64 v9; // kr08_8
  __int64 v10; // kr10_8
  unsigned __int64 v11; // kr20_8
  __int64 v12; // r2
  __int64 v13; // r0
  char v14; // r7
  int v15; // r1
  int v16; // r2
  int v17; // r3
  unsigned int v18; // r0
  unsigned int v19; // r2
  unsigned __int64 *v20; // r4
  unsigned int v21; // r5
  unsigned __int64 v22; // kr30_8
  unsigned __int64 v23; // kr38_8
  int v24; // r3
  int v25; // r6
  int v26; // r2
  int v27; // r3
  int v28; // r4
  unsigned int v29; // r5
  int v30; // r6
  int v31; // r7
  int v32; // r5
  int *v33; // r0
  unsigned int v34; // r2
  int v35; // r1
  int i; // r1
  int v37; // r3
  int v38; // r6
  int v39; // r7
  int v40; // r9
  __int64 v41; // kr40_8
  int v42; // r10
  unsigned __int64 *v43; // r3
  unsigned __int64 v44; // kr48_8
  __int64 v45; // kr50_8
  unsigned int v46; // r5
  unsigned __int64 v47; // kr68_8
  int v49; // [sp+0h] [bp-58h]
  unsigned __int8 v50; // [sp+8h] [bp-50h] BYREF
  char v51[3]; // [sp+9h] [bp-4Fh] BYREF
  unsigned int v52; // [sp+Ch] [bp-4Ch]
  int v53; // [sp+10h] [bp-48h]
  int v54; // [sp+14h] [bp-44h]
  int v55; // [sp+18h] [bp-40h]
  int v56; // [sp+1Ch] [bp-3Ch] BYREF
  _DWORD v57[14]; // [sp+20h] [bp-38h] BYREF

  v1 = a1;
  v54 = a1;
  v2 = (unsigned int)KeGetPcr();
  v3 = (v2 & 0xFFFFF000) + 1408;
  v4 = *(unsigned __int8 *)((v2 & 0xFFFFF000) + 0x590);
  v5 = 0;
  ++*(_DWORD *)((v2 & 0xFFFFF000) + 0xE80);
  if ( v4 )
  {
    *(_BYTE *)((v2 & 0xFFFFF000) + 0x590) = v4 + 1;
    v25 = 0;
    v24 = 0;
  }
  else
  {
    v6 = *(_DWORD *)((v2 & 0xFFFFF000) + 0x584);
    *(_BYTE *)((v2 & 0xFFFFF000) + 0x590) = 1;
    LODWORD(v7) = ReadTimeStampCounter();
    v8 = (unsigned __int64 *)(v6 + 48);
    v9 = v7 - *(_QWORD *)(v3 + 2376);
    v10 = *(_QWORD *)(v6 + 48);
    v52 = HIDWORD(v9);
    v53 = HIDWORD(v7);
    v55 = v7;
    __dmb(0xBu);
    do
      v11 = __ldrexd(v8);
    while ( __strexd(v10 + v9, v8) );
    __dmb(0xBu);
    v12 = v9 + *(unsigned int *)(v6 + 56);
    if ( HIDWORD(v12) )
    {
      LODWORD(v13) = sub_53FB30();
      return v13;
    }
    *(_QWORD *)(v3 + 2376) = v7;
    v14 = *(_BYTE *)(v6 + 2);
    *(_DWORD *)(v6 + 56) = v12;
    if ( (v14 & 0x3E) != 0 )
    {
      if ( (v14 & 0x10) != 0 )
      {
        v38 = v3 + 8 * *(unsigned __int8 *)(v6 + 84);
        *(_QWORD *)(v38 + 2392) = *(_QWORD *)(v38 + 2392) - *(_QWORD *)(v3 + 2384) + *(_QWORD *)(v3 + 2376);
        *(_DWORD *)(v3 + 2384) = 0;
        *(_DWORD *)(v3 + 2388) = 0;
        v14 &= 0xEFu;
      }
      if ( (v14 & 0x3E) != 0 )
      {
        if ( (v14 & 0x20) != 0 )
        {
          v15 = *(_DWORD *)(v6 + 1084);
          if ( v15 )
          {
            v16 = *(_DWORD *)(v3 + 3200);
            v17 = *(_DWORD *)(v3 + 3204);
            if ( v16 && v17 )
            {
              v18 = *(_DWORD *)(v17 + 44);
              if ( v18 >= *(_DWORD *)(v16 + 148) )
                v18 = *(_DWORD *)(v16 + 148);
            }
            else
            {
              v18 = 100;
            }
            v19 = v18 / 0x19;
            if ( v18 / 0x19 >= 3 )
              v19 = 3;
            v20 = (unsigned __int64 *)(v15 + 8 * (*(unsigned __int8 *)(v3 + 2986) + 2 * v19));
            v21 = v52;
            v22 = *v20 + __PAIR64__(v52, v9);
            __dmb(0xBu);
            do
              v23 = __ldrexd(v20);
            while ( __strexd(v22, v20) );
            __dmb(0xBu);
          }
          else
          {
            v21 = v52;
          }
          v14 &= 0xDFu;
        }
        else
        {
          v21 = v52;
        }
        if ( (v14 & 0x3E) != 0 )
        {
          v35 = *(_DWORD *)(v6 + 68);
          if ( v35 )
          {
            for ( i = v35 + *(_DWORD *)(v3 + 2352); i; i = *(_DWORD *)(i + 236) )
              *(_QWORD *)i += __PAIR64__(v21, v9);
          }
          if ( (*(_BYTE *)(v6 + 2) & 8) != 0
            && (*(_DWORD *)(*(_DWORD *)(v3 + 2360) + 260) & *(_DWORD *)(v6 + 356)) != *(_DWORD *)(*(_DWORD *)(v3 + 2360)
                                                                                                + 260) )
          {
            *(_QWORD *)(v3 + 2368) += __PAIR64__(v21, v9);
          }
          if ( *(_DWORD *)(v6 + 236) )
            KiEndCounterAccumulation(v6);
        }
      }
    }
    v24 = v53;
    v1 = v54;
    v25 = v55;
    v5 = 1;
  }
  v57[3] = v24;
  LODWORD(v13) = HalBeginSystemInterruptUnspecified(v57, &v50, v51, &v56);
  if ( (_DWORD)v13 )
  {
    if ( v5 )
    {
      v28 = v50;
      if ( v50 >= 0xFu )
      {
LABEL_30:
        v31 = v56;
        v30 = v57[0];
        v32 = (unsigned __int8)v51[0];
        v33 = KeGetCurrentStackPointer(v13, SHIDWORD(v13), v26, v27, v49);
        v34 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1574);
        if ( (unsigned int)v33 < v34 && v34 - 12288 <= (unsigned int)v33 || (KiBugCheckActive & 3) != 0 )
          KiPlayInterrupt(v1, v30, v28, v32);
        else
          KxSwitchStackAndPlayInterrupt(
            v1,
            v30,
            v28,
            v32,
            *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1574));
        LODWORD(v13) = HalEndSystemInterrupt(v30, v32, v31, v1);
        return v13;
      }
      v29 = *(_DWORD *)(v3 + 2424);
      v27 = ((v29 >> 5) & 0x3F) + 1;
      v26 = *(_DWORD *)(v3 + 2424 + 4 * v27);
      ++v29;
      HIDWORD(v13) = v25 ^ __ROR4__(v26, 5);
      *(_DWORD *)(v3 + 2424 + 4 * v27) = HIDWORD(v13);
      *(_DWORD *)(v3 + 2424) = v29;
      if ( (v29 & 0x3FF) == 0 )
        LODWORD(v13) = KiEntropyQueueDpc(v3);
    }
    v28 = v50;
    goto LABEL_30;
  }
  v37 = *(unsigned __int8 *)(v3 + 16);
  if ( v37 == 1 )
  {
    v39 = *(_DWORD *)(v3 + 4);
    LODWORD(v13) = ReadTimeStampCounter();
    v40 = HIDWORD(v13);
    v41 = v13 - *(_QWORD *)(v3 + 2376);
    v42 = v13;
    __dmb(0xBu);
    v43 = (unsigned __int64 *)(v3 + 2744);
    do
      v44 = __ldrexd(v43);
    while ( __strexd(v44 + v41, v43) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(v39 + 2) & 0x20) != 0 )
    {
      v45 = v13 - *(_QWORD *)(v3 + 2376);
      v46 = v3 + 8 * (*(unsigned __int8 *)(v3 + 2986) + 2 * (PoGetFrequencyBucket(v3) + 1144));
      LODWORD(v13) = *(_DWORD *)(v46 + 4);
      HIDWORD(v13) = *(_DWORD *)v46;
      __dmb(0xBu);
      do
        v47 = __ldrexd((unsigned __int64 *)v46);
      while ( __strexd(__PAIR64__(v13, HIDWORD(v13)) + v45, (unsigned __int64 *)v46) );
      __dmb(0xBu);
    }
    *(_DWORD *)(v3 + 2376) = v42;
    *(_DWORD *)(v3 + 2380) = v40;
    if ( (*(_BYTE *)(v39 + 2) & 0x10) != 0 )
    {
      *(_DWORD *)(v3 + 2384) = v42;
      *(_DWORD *)(v3 + 2388) = v40;
    }
    if ( (*(_BYTE *)(v39 + 2) & 2) != 0 )
      LODWORD(v13) = KiBeginCounterAccumulation(v39, 0);
    *(_BYTE *)(v3 + 16) = 0;
  }
  else
  {
    *(_BYTE *)(v3 + 16) = v37 - 1;
  }
  return v13;
}
