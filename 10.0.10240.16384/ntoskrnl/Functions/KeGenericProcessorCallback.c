// KeGenericProcessorCallback 
 
int __fastcall KeGenericProcessorCallback(__int16 *a1, int a2, int a3, char a4, int a5)
{
  __int16 *v5; // r5
  unsigned int v7; // r7
  char *v8; // r9
  unsigned int v9; // r0
  unsigned int v10; // r5
  void (__fastcall *v11)(unsigned int, int); // r4
  char v12; // r2
  unsigned int v13; // r10
  int result; // r0
  int v15; // r3
  int v16; // r8
  int (__fastcall **v17)(int); // r3
  int v18; // r0
  unsigned int *v19; // r1
  unsigned int v20; // r2
  int v21; // r3
  __int64 v22; // r0
  __int64 v23; // kr00_8
  unsigned __int64 *v24; // r6
  unsigned __int64 v25; // kr08_8
  unsigned __int64 v26; // kr10_8
  __int64 v27; // r2
  char v28; // r9
  int v29; // r4
  unsigned int v30; // r6
  int i; // r1
  int v32; // r4
  unsigned int v33; // r5
  unsigned __int64 *v34; // r4
  unsigned __int64 v35; // kr18_8
  unsigned __int64 v36; // kr20_8
  int v37; // r1
  int v38; // [sp+0h] [bp-68h]
  int v39; // [sp+4h] [bp-64h]
  int v40; // [sp+8h] [bp-60h]
  int v41; // [sp+8h] [bp-60h]
  int v42; // [sp+10h] [bp-58h] BYREF
  __int16 v43; // [sp+14h] [bp-54h]
  int v44; // [sp+16h] [bp-52h]
  __int16 v45; // [sp+1Ah] [bp-4Eh]
  void (__fastcall *v46)(unsigned int, int); // [sp+20h] [bp-48h]
  __int16 v47[2]; // [sp+28h] [bp-40h] BYREF
  int v48; // [sp+2Ch] [bp-3Ch]
  int v49; // [sp+30h] [bp-38h]
  char v50[48]; // [sp+38h] [bp-30h] BYREF

  v5 = a1;
  v46 = (void (__fastcall *)(unsigned int, int))a2;
  if ( !a1 )
  {
    v47[0] = 1;
    v47[1] = 1;
    v48 = 0;
    v5 = v47;
    v49 = 1;
  }
  v38 = 0;
  v44 = 0;
  v45 = 0;
  v7 = 0;
  v8 = v50;
  v39 = __mrc(15, 0, 13, 0, 3);
  v40 = a4 & 2;
  v9 = v39 & 0xFFFFFFC0;
  if ( (a4 & 2) != 0 )
    v38 = KeSetPriorityThread(v9, 30);
  else
    KeSetPriorityBoost(v9, 15);
  v10 = *((_DWORD *)v5 + 2);
  v11 = v46;
  while ( v10 )
  {
    v12 = __clz(__rbit(v10));
    v10 &= ~(1 << v12);
    v42 = 1 << v12;
    v43 = 0;
    KeSetSystemGroupAffinityThread(&v42, v8);
    v8 = 0;
    v7 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v11(v7, a3);
  }
  v13 = KfRaiseIrql(2);
  *(_BYTE *)(v7 + 1754) = 1;
  if ( v40 )
    KeSetPriorityThread(v39 & 0xFFFFFFC0, v38);
  else
    KiRemoveBoostThread(v7, v39 & 0xFFFFFFC0);
  result = KeRevertToUserGroupAffinityThread(v50);
  *(_BYTE *)(v7 + 1754) = 0;
  v15 = *(_DWORD *)(v7 + 8);
  if ( v13 < 2 )
  {
    v16 = *(_DWORD *)(v7 + 4);
    if ( v15 )
    {
      KiAbProcessContextSwitch(*(_DWORD *)(v7 + 4), 0);
      v19 = (unsigned int *)(v7 + 24);
      while ( 1 )
      {
        do
          v20 = __ldrex(v19);
        while ( __strex(1u, v19) );
        __dmb(0xBu);
        if ( !v20 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v19 );
      }
      v21 = *(_DWORD *)(v7 + 8);
      *(_DWORD *)(v7 + 8) = 0;
      __disable_irq();
      v41 = v21;
      *(_BYTE *)(v7 + 16) = 1;
      LODWORD(v22) = ReadTimeStampCounter();
      v24 = (unsigned __int64 *)(v16 + 48);
      v23 = v22 - *(_QWORD *)(v7 + 2376);
      v25 = *(_QWORD *)(v16 + 48) + v23;
      __dmb(0xBu);
      do
        v26 = __ldrexd(v24);
      while ( __strexd(v25, v24) );
      __dmb(0xBu);
      v27 = v23 + *(unsigned int *)(v16 + 56);
      if ( HIDWORD(v27) )
        return sub_50A76C();
      *(_QWORD *)(v7 + 2376) = v22;
      v28 = *(_BYTE *)(v16 + 2);
      *(_DWORD *)(v16 + 56) = v27;
      if ( (v28 & 0x3E) != 0 )
      {
        if ( (v28 & 0x10) != 0 )
        {
          v30 = v7 + 8 * *(unsigned __int8 *)(v16 + 84);
          *(_QWORD *)(v30 + 2392) = *(_QWORD *)(v30 + 2392) - *(_QWORD *)(v7 + 2384) + *(_QWORD *)(v7 + 2376);
          *(_DWORD *)(v7 + 2384) = 0;
          *(_DWORD *)(v7 + 2388) = 0;
          v28 &= 0xEFu;
        }
        if ( (v28 & 0x3E) != 0 )
        {
          if ( (v28 & 0x20) != 0 )
          {
            v32 = *(_DWORD *)(v16 + 1084);
            if ( v32 )
            {
              v33 = HIDWORD(v23);
              v34 = (unsigned __int64 *)(v32 + 8 * (*(unsigned __int8 *)(v7 + 2986) + 2 * PoGetFrequencyBucket(v7)));
              v35 = *v34 + v23;
              __dmb(0xBu);
              do
                v36 = __ldrexd(v34);
              while ( __strexd(v35, v34) );
              __dmb(0xBu);
            }
            else
            {
              v33 = HIDWORD(v23);
            }
            v28 &= 0xDFu;
          }
          else
          {
            v33 = HIDWORD(v23);
          }
          if ( (v28 & 0x3E) != 0 )
          {
            v37 = *(_DWORD *)(v16 + 68);
            if ( v37 )
            {
              for ( i = v37 + *(_DWORD *)(v7 + 2352); i; i = *(_DWORD *)(i + 236) )
                *(_QWORD *)i += __PAIR64__(v33, v23);
            }
            if ( (*(_BYTE *)(v16 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v7 + 2360) + 260) & *(_DWORD *)(v16 + 356)) != *(_DWORD *)(*(_DWORD *)(v7 + 2360) + 260) )
            {
              *(_QWORD *)(v7 + 2368) += __PAIR64__(v33, v23);
            }
            if ( *(_DWORD *)(v16 + 236) )
              KiEndCounterAccumulation(v16);
          }
        }
      }
      v29 = v41;
      __enable_irq();
      *(_DWORD *)(v7 + 4) = v29;
      *(_BYTE *)(v29 + 132) = 2;
      *(_BYTE *)(v16 + 395) = 32;
      *(_BYTE *)(v16 + 134) = v13;
      KiQueueReadyThread(v7, v16);
      if ( !KiSwapContext(v16, v29, v13) )
      {
LABEL_15:
        v17 = &KfLowerIrql;
        v18 = v13;
        return (*v17)(v18);
      }
    }
    else if ( (*(_DWORD *)(v16 + 76) & 0x40) == 0 )
    {
      goto LABEL_15;
    }
    KfLowerIrql(1);
    *(_DWORD *)(v16 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    goto LABEL_15;
  }
  if ( v15 && !*(_BYTE *)(v7 + 1754) )
  {
    v17 = (int (__fastcall **)(int))&HalRequestSoftwareInterrupt;
    v18 = 2;
    return (*v17)(v18);
  }
  return result;
}
