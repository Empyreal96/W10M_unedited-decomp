// MmCreateKernelStack 
 
int __fastcall MmCreateKernelStack(char a1, int a2, int a3)
{
  int v5; // r0
  int v6; // r10
  BOOL i; // r4
  int v8; // r8
  int v9; // r6
  int v10; // r0
  unsigned int v11; // r2
  int *v12; // lr
  int v13; // r6
  int v14; // r8
  unsigned int v16; // r9
  int v17; // r8
  int *v18; // r1
  unsigned __int8 *v19; // r3
  unsigned int v20; // r2
  unsigned int *v21; // r2
  unsigned int v22; // r0
  unsigned int v23; // r1
  int v24; // r0
  int v25; // r4
  unsigned int v26; // r4
  unsigned int v27; // r5
  unsigned int v28; // r3
  unsigned __int8 *v29; // r0
  int v30; // r3
  unsigned int v31; // r2
  unsigned int v32; // r1
  unsigned int v33; // r0
  int v34; // [sp+8h] [bp-30h]
  unsigned int v35; // [sp+Ch] [bp-2Ch]
  int v36; // [sp+10h] [bp-28h]
  int v37; // [sp+14h] [bp-24h]
  int v38; // [sp+14h] [bp-24h]

  v5 = a1 & 0x10;
  if ( v5 )
  {
    v6 = -5;
  }
  else if ( a3 )
  {
    v6 = a3 | 1;
  }
  else
  {
    v6 = -3;
  }
  if ( (a1 & 1) != 0 )
  {
    v23 = 15;
    v34 = 15;
    if ( (a1 & 4) != 0 )
      v28 = 61440;
    else
      v28 = 12288;
    v35 = v28 >> 12;
LABEL_36:
    if ( (a1 & 2) != 0 )
    {
      if ( !MiChargeCommit((int)MiSystemPartition, v23, 1) )
        return 0;
    }
    else if ( !MiChargeCommit((int)MiSystemPartition, v23, 0) )
    {
      return 0;
    }
    v14 = v34;
    v24 = MiReservePtes(&dword_634D58, v34 + 1);
    v25 = v24;
    v36 = v24;
    if ( v24 )
    {
      v13 = (v24 + 4 * (v34 + 1)) << 10;
      v38 = v24;
      if ( (a1 & 5) == 1 )
        v38 = v24 + 48;
      if ( MiChargeResident(MiSystemPartition, v35, 0) )
      {
        do
          v26 = __ldrex(&dword_634A00);
        while ( __strex(v26 + v35, &dword_634A00) );
        if ( MiAllocateKernelStackPages(v38 + 4, v35, v6, a2) )
        {
          do
            v27 = __ldrex(&dword_634DA8);
          while ( __strex(v27 + v34, &dword_634DA8) );
          goto LABEL_15;
        }
        MiReturnResidentAvailable(v35);
        do
          v33 = __ldrex(&dword_634A04[2]);
        while ( __strex(v33 + v35, &dword_634A04[2]) );
        v32 = v36;
      }
      else
      {
        v32 = v25;
      }
      MiReleasePtes(&dword_634D58, v32, v34 + 1);
    }
    MiReturnCommit((int)MiSystemPartition, v34);
    return 0;
  }
  v34 = (unsigned __int8)byte_634840;
  v35 = (unsigned __int8)byte_634840;
  for ( i = v5 != 0; ; i = 0 )
  {
    v8 = 176 * a2 + 24 * i + dword_6337E8;
    v9 = *(unsigned __int16 *)(v8 + 60);
    if ( !*(_WORD *)(v8 + 60) )
      goto LABEL_33;
    v37 = i ? 17 : KfRaiseIrql(2);
    v10 = RtlpInterlockedPopEntrySList((unsigned __int64 *)(v8 + 56));
    if ( v10 )
      break;
    if ( !i )
      KfLowerIrql(v37);
LABEL_33:
    ++*(_DWORD *)(v8 + 68);
    if ( !i )
    {
      v23 = v34;
      goto LABEL_36;
    }
  }
  if ( v9 == 1 && !*(_DWORD *)(v8 + 76) )
    *(_DWORD *)(v8 + 76) = 1;
  v11 = v10 - 4088;
  if ( *(_DWORD *)(v10 - 8) != (dword_634C80 ^ (v10 - 4088)) )
    sub_548154();
  v12 = (int *)(((v11 >> 10) & 0x3FFFFC) - 0x40000000);
  v13 = (((v11 >> 10) & 0x3FFFFC) - 1073741820) << 10;
  if ( !i )
  {
    v16 = (unsigned int)&v12[-(unsigned __int8)byte_634840 + 1];
    do
    {
      v17 = *v12;
      v18 = (int *)(MmPfnDatabase + 24 * ((unsigned int)*v12 >> 12));
      v19 = (unsigned __int8 *)v18 + 15;
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 | 0x80, v19) );
      __dmb(0xBu);
      if ( v20 >> 7 )
      {
        v29 = (unsigned __int8 *)v18 + 15;
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v30 = v18[3];
            __dmb(0xBu);
          }
          while ( v30 < 0 );
          do
            v31 = __ldrex(v29);
          while ( __strex(v31 | 0x80, v29) );
          __dmb(0xBu);
        }
        while ( v31 >> 7 );
      }
      if ( v17 == *v12 )
      {
        *v18 = v6;
        --v12;
      }
      __dmb(0xBu);
      v21 = (unsigned int *)(v18 + 3);
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 & 0x7FFFFFFF, v21) );
    }
    while ( (unsigned int)v12 >= v16 );
    KfLowerIrql(v37);
  }
  v14 = v34;
LABEL_15:
  if ( (dword_682604 & 1) != 0 && (a1 & 8) != 0 )
    MiLogKernelStackEvent(v13 - (v14 << 12), v35, 1);
  return v13;
}
