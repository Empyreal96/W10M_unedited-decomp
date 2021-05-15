// KeUpdateThreadTag 
 
void __fastcall KeUpdateThreadTag(int a1, int a2)
{
  unsigned int *v3; // r4
  unsigned int v4; // r2
  char v5; // r0
  unsigned __int8 *v6; // r3
  unsigned int v7; // r2
  int v8; // r3
  unsigned int *v9; // r3
  int v10; // r8
  __int64 v11; // r0
  unsigned __int64 *v12; // r6
  unsigned int *v13; // lr
  __int64 v14; // kr08_8
  __int64 v15; // kr10_8
  unsigned __int64 v16; // kr20_8
  __int64 v17; // r2
  char v18; // r9
  int v19; // r6
  int v20; // r4
  unsigned __int64 *v21; // r4
  unsigned __int64 v22; // kr28_8
  unsigned __int64 v23; // kr30_8
  unsigned __int8 *v24; // r3
  unsigned int v25; // r2
  __int64 v26; // r0
  int v27; // r9
  __int64 v28; // kr38_8
  int v29; // r10
  unsigned __int64 *v30; // r3
  unsigned __int64 v31; // kr40_8
  __int64 v32; // kr48_8
  unsigned __int64 *v33; // r4
  unsigned __int64 v34; // kr50_8
  unsigned __int64 v35; // kr60_8
  unsigned __int8 *v36; // r3
  unsigned int v37; // r2
  int v38; // r3
  unsigned int v39; // r2
  int v40; // r3
  unsigned __int8 *v41; // r3
  unsigned int v42; // r2
  int v43; // r1
  int i; // r1
  unsigned int *v45; // [sp+8h] [bp-38h] BYREF
  unsigned int *v46; // [sp+Ch] [bp-34h] BYREF
  int v47; // [sp+10h] [bp-30h]
  __int16 v48[2]; // [sp+18h] [bp-28h] BYREF
  int v49; // [sp+1Ch] [bp-24h]
  int v50; // [sp+20h] [bp-20h]
  int anonymous0; // [sp+48h] [bp+8h]
  int varsC; // [sp+4Ch] [bp+Ch] BYREF

  anonymous0 = a1;
  varsC = a2;
  v3 = (unsigned int *)(a1 + 44);
  v46 = (unsigned int *)(a1 + 44);
  v47 = KfRaiseIrql(2);
  while ( 1 )
  {
    do
      v4 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( !v4 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v3 );
  }
  if ( *(unsigned __int8 *)(a1 + 84) == varsC )
    goto LABEL_16;
  if ( a1 != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
  {
    if ( KiAcquireThreadStateLock(a1, &v46, &v45) == 2 || *(_BYTE *)(a1 + 73) )
    {
      v38 = *(_DWORD *)(a1 + 328);
      v48[0] = 1;
      v48[1] = 1;
      v49 = 0;
      v50 = 1 << v38;
      KfRaiseIrql(12);
      KiIpiSendPacket(0, (int)v48, (int)KiIpiUpdateThreadTag, a1, (int)&varsC, 0);
      v39 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      while ( 1 )
      {
        v40 = *(_DWORD *)(v39 + 2944);
        __dmb(0xBu);
        if ( !v40 )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    else
    {
      v5 = varsC;
      if ( varsC )
      {
        v6 = (unsigned __int8 *)(a1 + 2);
        do
          v7 = __ldrex(v6);
        while ( __strex(v7 | 0x10, v6) );
      }
      else
      {
        v41 = (unsigned __int8 *)(a1 + 2);
        do
          v42 = __ldrex(v41);
        while ( __strex(v42 & 0xEF, v41) );
      }
      *(_BYTE *)(a1 + 84) = v5;
    }
    v8 = (int)v46;
    if ( v46 )
    {
      __dmb(0xBu);
      *(_DWORD *)(v8 + 24) = 0;
    }
    v9 = v45;
    if ( v45 )
    {
      __dmb(0xBu);
      *v9 = 0;
    }
LABEL_16:
    __dmb(0xBu);
    *v3 = 0;
    KfLowerIrql(v47);
    return;
  }
  v10 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  __disable_irq();
  *(_BYTE *)(v10 + 16) = 1;
  LODWORD(v11) = ReadTimeStampCounter();
  v12 = (unsigned __int64 *)(a1 + 48);
  v14 = v11 - *(_QWORD *)(v10 + 2376);
  v13 = (unsigned int *)HIDWORD(v14);
  v15 = *(_QWORD *)(a1 + 48);
  v45 = (unsigned int *)HIDWORD(v14);
  __dmb(0xBu);
  do
    v16 = __ldrexd(v12);
  while ( __strexd(v15 + v14, v12) );
  __dmb(0xBu);
  v17 = v14 + *(unsigned int *)(a1 + 56);
  if ( !HIDWORD(v17) )
  {
    *(_QWORD *)(v10 + 2376) = v11;
    v18 = *(_BYTE *)(a1 + 2);
    *(_DWORD *)(a1 + 56) = v17;
    if ( (v18 & 0x3E) != 0 )
    {
      if ( (v18 & 0x10) != 0 )
      {
        v19 = v10 + 8 * *(unsigned __int8 *)(a1 + 84);
        *(_QWORD *)(v19 + 2392) = *(_QWORD *)(v19 + 2392) - *(_QWORD *)(v10 + 2384) + *(_QWORD *)(v10 + 2376);
        *(_DWORD *)(v10 + 2384) = 0;
        *(_DWORD *)(v10 + 2388) = 0;
        v18 &= 0xEFu;
      }
      if ( (v18 & 0x3E) != 0 )
      {
        if ( (v18 & 0x20) != 0 )
        {
          v20 = *(_DWORD *)(a1 + 1084);
          if ( v20 )
          {
            v13 = v45;
            v21 = (unsigned __int64 *)(v20 + 8 * (*(unsigned __int8 *)(v10 + 2986) + 2 * PoGetFrequencyBucket(v10)));
            v22 = *v21 + __PAIR64__((unsigned int)v45, v14);
            __dmb(0xBu);
            do
              v23 = __ldrexd(v21);
            while ( __strexd(v22, v21) );
            __dmb(0xBu);
          }
          v18 &= 0xDFu;
        }
        if ( (v18 & 0x3E) != 0 )
        {
          v43 = *(_DWORD *)(a1 + 68);
          if ( v43 )
          {
            for ( i = v43 + *(_DWORD *)(v10 + 2352); i; i = *(_DWORD *)(i + 236) )
              *(_QWORD *)i += __PAIR64__((unsigned int)v13, v14);
          }
          if ( (*(_BYTE *)(a1 + 2) & 8) != 0
            && (*(_DWORD *)(*(_DWORD *)(v10 + 2360) + 260) & *(_DWORD *)(a1 + 356)) != *(_DWORD *)(*(_DWORD *)(v10 + 2360)
                                                                                                 + 260) )
          {
            *(_QWORD *)(v10 + 2368) += __PAIR64__((unsigned int)v13, v14);
          }
          if ( *(_DWORD *)(a1 + 236) )
            KiEndCounterAccumulation(a1);
        }
      }
    }
    if ( varsC )
    {
      v36 = (unsigned __int8 *)(a1 + 2);
      do
        v37 = __ldrex(v36);
      while ( __strex(v37 | 0x10, v36) );
    }
    else
    {
      v24 = (unsigned __int8 *)(a1 + 2);
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 & 0xEF, v24) );
    }
    *(_BYTE *)(a1 + 84) = varsC;
    LODWORD(v26) = ReadTimeStampCounter();
    v27 = HIDWORD(v26);
    v28 = v26 - *(_QWORD *)(v10 + 2376);
    v29 = v26;
    __dmb(0xBu);
    v30 = (unsigned __int64 *)(v10 + 2744);
    do
      v31 = __ldrexd(v30);
    while ( __strexd(v31 + v28, v30) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
    {
      v32 = v26 - *(_QWORD *)(v10 + 2376);
      v33 = (unsigned __int64 *)(v10 + 8 * (*(unsigned __int8 *)(v10 + 2986) + 2 * (PoGetFrequencyBucket(v10) + 1144)));
      v34 = *v33;
      __dmb(0xBu);
      do
        v35 = __ldrexd(v33);
      while ( __strexd(v34 + v32, v33) );
      __dmb(0xBu);
    }
    *(_DWORD *)(v10 + 2376) = v29;
    *(_DWORD *)(v10 + 2380) = v27;
    if ( (*(_BYTE *)(a1 + 2) & 0x10) != 0 )
    {
      *(_DWORD *)(v10 + 2384) = v29;
      *(_DWORD *)(v10 + 2388) = v27;
    }
    if ( (*(_BYTE *)(a1 + 2) & 2) != 0 )
      KiBeginCounterAccumulation(a1, 0);
    v3 = v46;
    *(_BYTE *)(v10 + 16) = 0;
    __enable_irq();
    goto LABEL_16;
  }
  sub_50F44C();
}
