// KeReleaseMutant 
 
int __fastcall KeReleaseMutant(unsigned int a1, int a2, int a3, int a4)
{
  int v6; // r8
  unsigned int v7; // r7
  int v8; // r0
  int v9; // lr
  unsigned int v10; // r10
  unsigned int v11; // r5
  int v12; // r4
  int v13; // r3
  unsigned int *v14; // r5
  unsigned int v15; // r2
  __int64 v16; // r0
  _QWORD *v17; // r5
  unsigned int v18; // r1
  int v19; // r0
  __int16 v20; // r3
  unsigned int v22; // r1
  _QWORD *v23; // r1
  __int64 v24; // kr00_8
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r2
  int v28; // r2
  unsigned int *v29; // r5
  unsigned __int8 *v30; // r3
  unsigned int v31; // r1
  unsigned int v32; // r6
  unsigned int v33; // r1
  unsigned int v34; // r1
  int v35; // r0
  int v36; // [sp+8h] [bp-58h]
  int v37; // [sp+14h] [bp-4Ch]
  char v40[8]; // [sp+28h] [bp-38h] BYREF
  int v41; // [sp+30h] [bp-30h]

  v6 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = KfRaiseIrql(2);
  v9 = v8;
  v36 = v8;
  v10 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  do
    v11 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v11 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v11 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*(_DWORD *)a1 & 0x80) != 0 );
      do
        v27 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v27 | 0x80, (unsigned __int8 *)a1) );
      __dmb(0xBu);
    }
    while ( v27 >> 7 );
  }
  v12 = *(_DWORD *)(a1 + 4);
  if ( a3 )
  {
    *(_DWORD *)(a1 + 4) = 1;
    *(_BYTE *)(a1 + 28) = 1;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 24) != v7 || *(unsigned __int8 *)(a1 + 2) != *(unsigned __int8 *)(v10 + 1754) )
    {
      __dmb(0xBu);
      do
        v34 = __ldrex((unsigned int *)a1);
      while ( __strex(v34 & 0xFFFFFF7F, (unsigned int *)a1) );
      KfLowerIrql(v8);
      if ( *(_BYTE *)(a1 + 28) )
        v35 = 128;
      else
        v35 = -1073741754;
      RtlRaiseStatus(v35);
    }
    v13 = *(_DWORD *)(a1 + 4) + 1;
    *(_DWORD *)(a1 + 4) = v13;
    if ( v13 != 1 )
      goto LABEL_23;
  }
  if ( v12 > 0 )
  {
LABEL_23:
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)a1);
    while ( __strex(v22 & 0xFFFFFF7F, (unsigned int *)a1) );
    goto LABEL_19;
  }
  v41 = *(_DWORD *)a1;
  BYTE2(v41) = 0;
  *(_DWORD *)a1 = v41;
  v37 = *(unsigned __int8 *)(a1 + 29);
  v14 = (unsigned int *)(*(_DWORD *)(a1 + 24) + 44);
  while ( 1 )
  {
    do
      v15 = __ldrex(v14);
    while ( __strex(1u, v14) );
    __dmb(0xBu);
    if ( !v15 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v14 );
  }
  v16 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(v16 + 4) != a1 + 16 || *(_DWORD *)HIDWORD(v16) != a1 + 16 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v16) = v16;
  *(_DWORD *)(v16 + 4) = HIDWORD(v16);
  __dmb(0xBu);
  *v14 = 0;
  v17 = *(_QWORD **)(a1 + 8);
  *(_DWORD *)(a1 + 24) = 0;
  if ( v17 != (_QWORD *)(a1 + 8) )
  {
    while ( 1 )
    {
      v23 = v17;
      v24 = *v17;
      v17 = *(_QWORD **)v17;
      if ( *(_QWORD **)(v24 + 4) != v23 || *(_QWORD **)HIDWORD(v24) != v23 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v24) = v24;
      *(_DWORD *)(v24 + 4) = HIDWORD(v24);
      v25 = *((unsigned __int8 *)v23 + 8);
      if ( v25 == 1 )
      {
        if ( KiTryUnwaitThread(v10, v23, *((unsigned __int16 *)v23 + 5), v40) )
        {
          v26 = *(_DWORD *)(a1 + 4) - 1;
          *(_DWORD *)(a1 + 4) = v26;
          if ( !v26 )
          {
LABEL_31:
            v9 = v36;
            break;
          }
        }
      }
      else
      {
        if ( v25 == 2 )
          return sub_52E730();
        KiTryUnwaitThread(v10, v23, 256, 0);
      }
      if ( v17 == (_QWORD *)(a1 + 8) )
        goto LABEL_31;
    }
  }
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)a1);
  while ( __strex(v18 & 0xFFFFFF7F, (unsigned int *)a1) );
  if ( a3 )
  {
    v28 = (a1 >> 4) & 0x3F;
    v29 = (unsigned int *)((char *)&KiObjectRundownLocks + 128 * v28);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((char *)&KiObjectRundownLocks + 128 * v28);
      v9 = v36;
    }
    else
    {
      v30 = (unsigned __int8 *)v29 + 3;
      do
        v31 = __ldrex(v30);
      while ( __strex(v31 | 0x80, v30) );
      __dmb(0xBu);
      if ( v31 >> 7 )
      {
        ExpWaitForSpinLockExclusiveAndAcquire(v29);
        v9 = v36;
      }
      while ( 1 )
      {
        v32 = *v29;
        if ( (*v29 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v32 & 0x40000000) == 0 )
        {
          do
            v33 = __ldrex(v29);
          while ( v33 == v32 && __strex(v32 | 0x40000000, v29) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v29);
      v9 = v36;
    }
    else
    {
      __dmb(0xBu);
      *v29 = 0;
    }
  }
  v6 = v37;
LABEL_19:
  v19 = KiExitDispatcher(v10, a4, 1, a2, v9);
  if ( v6 )
  {
    v20 = *(_WORD *)(v7 + 308) + 1;
    *(_WORD *)(v7 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
      KiCheckForKernelApcDelivery(v19);
  }
  return v12;
}
