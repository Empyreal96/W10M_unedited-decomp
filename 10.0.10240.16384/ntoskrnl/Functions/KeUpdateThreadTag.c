// KeUpdateThreadTag 
 
int __fastcall KeUpdateThreadTag(int a1, int a2)
{
  unsigned int *v3; // r4
  unsigned int v4; // r2
  char v5; // r0
  unsigned __int8 *v6; // r3
  unsigned int v7; // r2
  int v8; // r3
  _DWORD *v9; // r3
  unsigned int v11; // r8
  __int64 v12; // r0
  unsigned __int64 *v13; // r6
  unsigned int v14; // lr
  __int64 v15; // kr08_8
  __int64 v16; // kr10_8
  unsigned __int64 v17; // kr20_8
  __int64 v18; // r2
  char v19; // r9
  unsigned int v20; // r6
  int v21; // r4
  unsigned __int64 *v22; // r4
  unsigned __int64 v23; // kr28_8
  unsigned __int64 v24; // kr30_8
  unsigned __int8 *v25; // r3
  unsigned int v26; // r2
  __int64 v27; // r0
  int v28; // r9
  __int64 v29; // kr38_8
  int v30; // r10
  unsigned __int64 *v31; // r3
  unsigned __int64 v32; // kr40_8
  __int64 v33; // kr48_8
  unsigned __int64 *v34; // r4
  unsigned __int64 v35; // kr50_8
  unsigned __int64 v36; // kr60_8
  unsigned __int8 *v37; // r3
  unsigned int v38; // r2
  int v39; // r3
  unsigned int v40; // r2
  int v41; // r3
  unsigned __int8 *v42; // r3
  unsigned int v43; // r2
  int v44; // r1
  int i; // r1
  unsigned int v46; // [sp+8h] [bp-38h] BYREF
  unsigned int *v47; // [sp+Ch] [bp-34h] BYREF
  int v48; // [sp+10h] [bp-30h]
  __int16 v49[2]; // [sp+18h] [bp-28h] BYREF
  int v50; // [sp+1Ch] [bp-24h]
  int v51; // [sp+20h] [bp-20h]
  int anonymous0; // [sp+48h] [bp+8h]
  int varsC; // [sp+4Ch] [bp+Ch] BYREF

  anonymous0 = a1;
  varsC = a2;
  v3 = (unsigned int *)(a1 + 44);
  v47 = (unsigned int *)(a1 + 44);
  v48 = KfRaiseIrql(2);
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
    if ( KiAcquireThreadStateLock(a1, &v47, &v46) == 2 || *(_BYTE *)(a1 + 73) )
    {
      v39 = *(_DWORD *)(a1 + 328);
      v49[0] = 1;
      v49[1] = 1;
      v50 = 0;
      v51 = 1 << v39;
      KfRaiseIrql(12);
      KiIpiSendPacket(0, v49, KiIpiUpdateThreadTag, a1, &varsC, 0);
      v40 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      while ( 1 )
      {
        v41 = *(_DWORD *)(v40 + 2944);
        __dmb(0xBu);
        if ( !v41 )
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
        v42 = (unsigned __int8 *)(a1 + 2);
        do
          v43 = __ldrex(v42);
        while ( __strex(v43 & 0xEF, v42) );
      }
      *(_BYTE *)(a1 + 84) = v5;
    }
    v8 = (int)v47;
    if ( v47 )
    {
      __dmb(0xBu);
      *(_DWORD *)(v8 + 24) = 0;
    }
    v9 = (_DWORD *)v46;
    if ( v46 )
    {
      __dmb(0xBu);
      *v9 = 0;
    }
LABEL_16:
    __dmb(0xBu);
    *v3 = 0;
    return KfLowerIrql(v48);
  }
  v11 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  __disable_irq();
  *(_BYTE *)(v11 + 16) = 1;
  LODWORD(v12) = ReadTimeStampCounter();
  v13 = (unsigned __int64 *)(a1 + 48);
  v15 = v12 - *(_QWORD *)(v11 + 2376);
  v14 = HIDWORD(v15);
  v16 = *(_QWORD *)(a1 + 48);
  v46 = HIDWORD(v15);
  __dmb(0xBu);
  do
    v17 = __ldrexd(v13);
  while ( __strexd(v16 + v15, v13) );
  __dmb(0xBu);
  v18 = v15 + *(unsigned int *)(a1 + 56);
  if ( !HIDWORD(v18) )
  {
    *(_QWORD *)(v11 + 2376) = v12;
    v19 = *(_BYTE *)(a1 + 2);
    *(_DWORD *)(a1 + 56) = v18;
    if ( (v19 & 0x3E) != 0 )
    {
      if ( (v19 & 0x10) != 0 )
      {
        v20 = v11 + 8 * *(unsigned __int8 *)(a1 + 84);
        *(_QWORD *)(v20 + 2392) = *(_QWORD *)(v20 + 2392) - *(_QWORD *)(v11 + 2384) + *(_QWORD *)(v11 + 2376);
        *(_DWORD *)(v11 + 2384) = 0;
        *(_DWORD *)(v11 + 2388) = 0;
        v19 &= 0xEFu;
      }
      if ( (v19 & 0x3E) != 0 )
      {
        if ( (v19 & 0x20) != 0 )
        {
          v21 = *(_DWORD *)(a1 + 1084);
          if ( v21 )
          {
            v14 = v46;
            v22 = (unsigned __int64 *)(v21 + 8 * (*(unsigned __int8 *)(v11 + 2986) + 2 * PoGetFrequencyBucket(v11)));
            v23 = *v22 + __PAIR64__(v46, v15);
            __dmb(0xBu);
            do
              v24 = __ldrexd(v22);
            while ( __strexd(v23, v22) );
            __dmb(0xBu);
          }
          v19 &= 0xDFu;
        }
        if ( (v19 & 0x3E) != 0 )
        {
          v44 = *(_DWORD *)(a1 + 68);
          if ( v44 )
          {
            for ( i = v44 + *(_DWORD *)(v11 + 2352); i; i = *(_DWORD *)(i + 236) )
              *(_QWORD *)i += __PAIR64__(v14, v15);
          }
          if ( (*(_BYTE *)(a1 + 2) & 8) != 0
            && (*(_DWORD *)(*(_DWORD *)(v11 + 2360) + 260) & *(_DWORD *)(a1 + 356)) != *(_DWORD *)(*(_DWORD *)(v11 + 2360)
                                                                                                 + 260) )
          {
            *(_QWORD *)(v11 + 2368) += __PAIR64__(v14, v15);
          }
          if ( *(_DWORD *)(a1 + 236) )
            KiEndCounterAccumulation(a1);
        }
      }
    }
    if ( varsC )
    {
      v37 = (unsigned __int8 *)(a1 + 2);
      do
        v38 = __ldrex(v37);
      while ( __strex(v38 | 0x10, v37) );
    }
    else
    {
      v25 = (unsigned __int8 *)(a1 + 2);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 & 0xEF, v25) );
    }
    *(_BYTE *)(a1 + 84) = varsC;
    LODWORD(v27) = ReadTimeStampCounter();
    v28 = HIDWORD(v27);
    v29 = v27 - *(_QWORD *)(v11 + 2376);
    v30 = v27;
    __dmb(0xBu);
    v31 = (unsigned __int64 *)(v11 + 2744);
    do
      v32 = __ldrexd(v31);
    while ( __strexd(v32 + v29, v31) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
    {
      v33 = v27 - *(_QWORD *)(v11 + 2376);
      v34 = (unsigned __int64 *)(v11 + 8 * (*(unsigned __int8 *)(v11 + 2986) + 2 * (PoGetFrequencyBucket(v11) + 1144)));
      v35 = *v34;
      __dmb(0xBu);
      do
        v36 = __ldrexd(v34);
      while ( __strexd(v35 + v33, v34) );
      __dmb(0xBu);
    }
    *(_DWORD *)(v11 + 2376) = v30;
    *(_DWORD *)(v11 + 2380) = v28;
    if ( (*(_BYTE *)(a1 + 2) & 0x10) != 0 )
    {
      *(_DWORD *)(v11 + 2384) = v30;
      *(_DWORD *)(v11 + 2388) = v28;
    }
    if ( (*(_BYTE *)(a1 + 2) & 2) != 0 )
      KiBeginCounterAccumulation(a1, 0);
    v3 = v47;
    *(_BYTE *)(v11 + 16) = 0;
    __enable_irq();
    goto LABEL_16;
  }
  return sub_50F44C();
}
