// KeRundownQueueEx 
 
int __fastcall KeRundownQueueEx(unsigned int a1, int a2)
{
  int v2; // r6
  unsigned int **v4; // r8
  unsigned int v5; // r9
  unsigned int v6; // r2
  __int64 *v8; // r2
  unsigned __int8 *v9; // r3
  unsigned int v10; // r2
  int *v11; // r8
  int *v12; // r7
  unsigned int v13; // r1
  unsigned int *i; // r1
  int v15; // r2
  unsigned int *v16; // r4
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  unsigned int v19; // r0
  int *v20; // r5
  int v21; // r3
  int v22; // r6
  unsigned int v23; // r3
  unsigned int v24; // r0
  int v25; // r9
  unsigned int v26; // r2
  unsigned int v27; // r1
  __int64 v28; // r0
  unsigned int *v29; // r6
  unsigned int **v30; // r0
  unsigned int *v31; // r0
  unsigned int v32; // r2
  _DWORD *v33; // r1
  int v34; // r2
  BOOL v35; // r2
  unsigned int v36; // r1
  int v37; // [sp+8h] [bp-30h]
  unsigned int v38; // [sp+Ch] [bp-2Ch]
  unsigned int v39; // [sp+10h] [bp-28h]
  int v41; // [sp+18h] [bp-20h]

  v2 = a2;
  v4 = (unsigned int **)(a1 + 32);
  v41 = KfRaiseIrql(2);
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v39 = v5;
  do
    v6 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v6 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    return sub_50AD94();
  v8 = (__int64 *)(a1 + 16);
  v37 = *(_DWORD *)(a1 + 16);
  if ( v37 == a1 + 16 )
  {
    v37 = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 4) = 0;
    v28 = *v8;
    if ( *(__int64 **)(*(_DWORD *)v8 + 4) != v8 || *(__int64 **)HIDWORD(v28) != v8 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v28) = v28;
    *(_DWORD *)(v28 + 4) = HIDWORD(v28);
    *(_DWORD *)v8 = v8;
    *(_DWORD *)(a1 + 20) = a1 + 16;
  }
  __dmb(0xBu);
  v9 = (unsigned __int8 *)(a1 + 1);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 1, v9) );
  __dmb(0xBu);
  if ( v2 )
  {
    for ( i = *v4; i != (unsigned int *)v4; *v31 = 0 )
    {
      v29 = i - 78;
      i = (unsigned int *)*i;
      v30 = (unsigned int **)v29[79];
      if ( (unsigned int *)i[1] != v29 + 78 || *v30 != v29 + 78 )
        __fastfail(3u);
      *v30 = i;
      i[1] = (unsigned int)v30;
      v31 = v29 + 11;
      while ( 1 )
      {
        do
          v32 = __ldrex(v31);
        while ( __strex(1u, v31) );
        __dmb(0xBu);
        if ( !v32 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v31 );
      }
      v29[38] = 0;
      __dmb(0xBu);
    }
    *(_DWORD *)(a1 + 24) = 0;
  }
  v11 = *(int **)(a1 + 8);
  v12 = (int *)(a1 + 8);
  while ( v11 != v12 )
  {
    v20 = v11;
    v21 = *((unsigned __int8 *)v11 + 8);
    v11 = (int *)*v11;
    if ( v21 == 1 )
    {
      v34 = *((unsigned __int16 *)v20 + 5);
    }
    else
    {
      if ( v21 == 2 )
      {
        *((_BYTE *)v20 + 9) = 5;
        v22 = v20[3];
        *v20 = 0;
        KfRaiseIrql(2);
        v23 = (unsigned int)KeGetPcr();
        v24 = (v23 & 0xFFFFF000) + 1408;
        v25 = *(_DWORD *)((v23 & 0xFFFFF000) + 0x584);
        v38 = v24;
        if ( (dword_682604 & 0x1000000) != 0 )
        {
          v35 = *(_BYTE *)(v25 + 132) == 2
             && *(_DWORD *)(v25 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
          EtwTraceEnqueueWork(v25, v20, v35);
          v24 = v38;
        }
        do
          v26 = __ldrex((unsigned __int8 *)v22);
        while ( __strex(v26 | 0x80, (unsigned __int8 *)v22) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v26 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v22 & 0x80) != 0 );
          do
            v26 = __ldrex((unsigned __int8 *)v22);
          while ( __strex(v26 | 0x80, (unsigned __int8 *)v22) );
        }
        if ( *(_DWORD *)(v22 + 12) == v22 + 8
          || *(_DWORD *)(v22 + 24) >= *(_DWORD *)(v22 + 28)
          || *(_DWORD *)(v25 + 152) == v22 && *(_BYTE *)(v25 + 395) == 15
          || !KiWakeQueueWaiter(v24, v22, v20) )
        {
          ++*(_DWORD *)(v22 + 4);
          v33 = *(_DWORD **)(v22 + 20);
          *v20 = v22 + 16;
          v20[1] = (int)v33;
          if ( *v33 != v22 + 16 )
            __fastfail(3u);
          *v33 = v20;
          *(_DWORD *)(v22 + 20) = v20;
        }
        __dmb(0xBu);
        do
          v27 = __ldrex((unsigned int *)v22);
        while ( __strex(v27 & 0xFFFFFF7F, (unsigned int *)v22) );
        v5 = v39;
        continue;
      }
      v34 = 256;
    }
    KiTryUnwaitThread(v5 + 1408, v20, v34, 0);
  }
  *v12 = (int)v12;
  *(_DWORD *)(a1 + 12) = a1 + 8;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)a1);
  while ( __strex(v13 & 0xFFFFFF7F, (unsigned int *)a1) );
  if ( a2 )
  {
    v15 = (a1 >> 4) & 0x3F;
    v16 = (unsigned int *)((char *)&KiObjectRundownLocks + 128 * v15);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((char *)&KiObjectRundownLocks + 128 * v15);
    }
    else
    {
      v17 = (unsigned __int8 *)v16 + 3;
      do
        v18 = __ldrex(v17);
      while ( __strex(v18 | 0x80, v17) );
      __dmb(0xBu);
      if ( v18 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v16);
      while ( 1 )
      {
        v19 = *v16;
        if ( (*v16 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v19 & 0x40000000) == 0 )
        {
          do
            v36 = __ldrex(v16);
          while ( v36 == v19 && __strex(v19 | 0x40000000, v16) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v16);
    }
    else
    {
      __dmb(0xBu);
      *v16 = 0;
    }
  }
  KiExitDispatcher(v5 + 1408, 0, 1, 0, v41);
  return v37;
}
