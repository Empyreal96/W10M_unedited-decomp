// MiInPageSingleKernelStack 
 
int *__fastcall MiInPageSingleKernelStack(int a1, _DWORD *a2)
{
  _DWORD *v2; // r8
  unsigned int v3; // r9
  unsigned int v4; // r5
  int v5; // r3
  int v6; // r1
  int v7; // r3
  int *result; // r0
  unsigned int v9; // r2
  int *v10; // r1
  int v11; // r3
  int v12; // r7
  int v13; // r10
  int v14; // r3
  int v15; // r4
  int v16; // lr
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  unsigned int *v19; // r2
  unsigned int v20; // r4
  unsigned __int8 *v21; // r1
  int v22; // r3
  unsigned int v23; // r2
  unsigned int *v24; // r2
  unsigned int v25; // r0
  int v27; // [sp+Ch] [bp-DCh]
  int v28; // [sp+Ch] [bp-DCh]
  int v29; // [sp+10h] [bp-D8h]
  int v30; // [sp+14h] [bp-D4h]
  char v32[3]; // [sp+21h] [bp-C7h] BYREF
  int *v33; // [sp+24h] [bp-C4h]
  int v34; // [sp+28h] [bp-C0h]
  int v35; // [sp+2Ch] [bp-BCh]
  int v36; // [sp+30h] [bp-B8h]
  char v37; // [sp+34h] [bp-B4h]
  int v38[38]; // [sp+50h] [bp-98h] BYREF

  v2 = a2;
  v3 = ((a2[1] >> 10) & 0x3FFFFC) - 0x40000000;
  v4 = (((unsigned int)(*a2 - 4096) >> 10) & 0x3FFFFC) - 0x40000000;
  v5 = a2[2];
  v6 = a1;
  v7 = *(_DWORD *)((((unsigned int)(v5 - 4) >> 10) & 0x3FFFFC) - 0x40000000);
  result = 0;
  v29 = 0;
  if ( v7 != 128 && (v7 & 0x800) == 0 )
    v29 = 1;
  v9 = v3;
  if ( v3 <= v4 )
  {
    v10 = v38;
    do
    {
      v11 = *(_DWORD *)v9;
      if ( *(_DWORD *)v9 != 992 && v11 != 128 && v11 != 768 && (v11 & 0x800) == 0 )
      {
        *v10 = v9 << 10;
        v10[1] = 4096;
        result = (int *)((char *)result + 1);
        v10 += 2;
        if ( result == (int *)15 )
          break;
      }
      v9 += 4;
    }
    while ( v9 <= v4 );
    if ( (unsigned int)result > 1 )
      return (int *)sub_520F5C();
    v6 = a1;
  }
  v12 = v4 << 10;
  v13 = 0;
  v38[1] = 4096;
  if ( v4 >= v3 )
  {
    v30 = v6 | 1;
    do
    {
      if ( (*(_DWORD *)v4 & 0x3E0) != 992 )
        KeBugCheck2(26, 13393, v4, v6, 0, 0);
      v32[0] = 0;
      v33 = v38;
      v34 = 1;
      v35 = 0;
      v36 = 0;
      v14 = *(_DWORD *)(v6 + 364);
      v38[0] = v12;
      v37 = *(_WORD *)(*((_DWORD *)*(&KiProcessorBlock + v14) + 590) + 266) + 1;
      MmAccessFault(1, v12, 0, v32);
      if ( (*(_DWORD *)v4 & 2) != 0 )
      {
        while ( 1 )
        {
          v27 = *(_DWORD *)v4;
          v15 = MmPfnDatabase + 24 * (*(_DWORD *)v4 >> 12);
          v16 = KfRaiseIrql(2);
          v17 = (unsigned __int8 *)(v15 + 15);
          do
            v18 = __ldrex(v17);
          while ( __strex(v18 | 0x80, v17) );
          __dmb(0xBu);
          if ( v18 >> 7 )
          {
            v21 = (unsigned __int8 *)(v15 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v22 = *(_DWORD *)(v15 + 12);
                __dmb(0xBu);
              }
              while ( v22 < 0 );
              do
                v23 = __ldrex(v21);
              while ( __strex(v23 | 0x80, v21) );
              __dmb(0xBu);
            }
            while ( v23 >> 7 );
          }
          if ( v27 == *(_DWORD *)v4 )
            break;
          __dmb(0xBu);
          v24 = (unsigned int *)(v15 + 12);
          do
            v25 = __ldrex(v24);
          while ( __strex(v25 & 0x7FFFFFFF, v24) );
          KfLowerIrql(v16);
        }
        *(_DWORD *)v15 = v30;
        *(_DWORD *)(v15 + 20) = *(_DWORD *)(v15 + 20) & 0xF8FFFFFF | 0x2000000;
        *(_BYTE *)(v15 + 19) = *(_BYTE *)(v15 + 19) & 0xF8 | 5;
        v28 = MiReleaseWsSwapReservationPfn(v15);
        __dmb(0xBu);
        v19 = (unsigned int *)(v15 + 12);
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 & 0x7FFFFFFF, v19) );
        KfLowerIrql(v16);
        v2 = a2;
        if ( v28 )
          MiReleasePageFileInfo(MiSystemPartition, v28, 0);
        v4 -= 4;
        v12 -= 4096;
        ++v13;
      }
      v6 = a1;
      result = v38;
    }
    while ( v4 >= v3 );
  }
  if ( (dword_682604 & 1) != 0 )
    result = (int *)MiLogKernelStackEvent(v12 + 4096, v13, 1);
  if ( *(_DWORD *)(v2[2] - 4) != a1 )
  {
    MmFlushAllFilesystemPages(1);
    KeBugCheck2(119, v29, *(_DWORD *)(v2[2] - 4), 0, v2[2], 0);
  }
  return result;
}
