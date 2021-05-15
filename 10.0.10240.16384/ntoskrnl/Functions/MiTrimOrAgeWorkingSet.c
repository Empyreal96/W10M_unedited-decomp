// MiTrimOrAgeWorkingSet 
 
int __fastcall MiTrimOrAgeWorkingSet(int a1, unsigned __int8 *a2, int a3)
{
  int v7; // r9
  unsigned int v8; // r2
  int v9; // r5
  int v10; // r2
  int v11; // r3
  int v12; // r0
  unsigned int *v13; // r1
  unsigned int v14; // r2
  char *v15; // r3
  unsigned __int8 *v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r5
  char v20; // r5
  int v21; // r5
  int v22; // r9
  _DWORD **v23; // r0
  unsigned int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r2
  int v28; // r0
  int v29; // r3
  int v30; // r1
  _DWORD *v31; // r3
  _DWORD *i; // r2
  unsigned int v33; // r1
  unsigned int v34; // r2
  int j; // r10
  unsigned int v36; // r0
  unsigned int v37; // r0
  unsigned int v38; // [sp+8h] [bp-40h]
  char v39; // [sp+10h] [bp-38h] BYREF

  if ( *(_BYTE *)(a1 + 114) == 2 )
    return sub_542E08();
  v7 = dword_6404B8;
  if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 112) & 7) == 1 )
      MiAttachSession(a1 - 3248);
  }
  else if ( a1 - 492 != PsInitialSystemProcess )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( *(_BYTE *)(v8 + 0x16A) )
      KeBugCheckEx(5, a1 - 492, *(_DWORD *)(v8 + 116));
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v10 = 0;
    }
    else
    {
      __disable_irq();
      v10 = 1;
    }
    v11 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v10 )
      __enable_irq();
    if ( (v11 & 0x10001) != 0 )
    {
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v27 = 0;
      }
      else
      {
        __disable_irq();
        v27 = 1;
      }
      if ( v27 )
        __enable_irq();
      KeBugCheckEx(5, a1 - 492, *(_DWORD *)(v9 + 116));
    }
    if ( *(_DWORD *)(v9 + 116) != a1 - 492 )
    {
      v12 = KfRaiseIrql(2);
      v13 = (unsigned int *)(v9 + 44);
      while ( 1 )
      {
        do
          v14 = __ldrex(v13);
        while ( __strex(1u, v13) );
        __dmb(0xBu);
        if ( !v14 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v13 );
      }
      if ( *(_BYTE *)(v9 + 362) )
        v15 = &v39;
      else
        v15 = (char *)(v9 + 372);
      KiAttachProcess(v9, a1 - 492, v12, 1, (int)v15);
    }
  }
  KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1);
  }
  else
  {
    v16 = (unsigned __int8 *)(a1 + 3);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 | 0x80, v16) );
    __dmb(0xBu);
    if ( v17 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)a1);
    while ( 1 )
    {
      v18 = *(_DWORD *)a1;
      if ( (*(_DWORD *)a1 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v18 & 0x40000000) == 0 )
      {
        do
          v24 = __ldrex((unsigned int *)a1);
        while ( v24 == v18 && __strex(v18 | 0x40000000, (unsigned int *)a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( (a3 & 4) != 0 )
    MiEmptyWorkingSet((unsigned int *)a1, 0, 0);
  if ( (a3 & 0x20) != 0 && (*(_BYTE *)(a1 + 112) & 7) == 0 )
    MiTrimWorkingSet(*(_DWORD *)(a1 + 60), a1, 0, 0, 2);
  if ( (a3 & 0x100) != 0 )
    MiTrimWorkingSet(*(_DWORD *)(a1 + 60), a1, 0, 0, 4);
  v19 = *(unsigned __int16 *)(v7 + 1218);
  if ( (a3 & 1) != 0 )
  {
    a2[1] = *((_BYTE *)MiTrimPassToAge + (*a2 & 0x7F));
    v28 = MiComputeTrimAmount(a2, a1, 1);
    if ( v28 )
      *((_DWORD *)a2 + 12) += MiTrimWorkingSet(v28, a1, 0, a2[1], 1);
    v29 = *a2;
    v30 = 0;
    if ( ((v29 & 0x7F) == 0 && (v29 & 0xFFFFFF80) == 0 || (v29 & 0x7F) == 4) && *(_WORD *)(v7 + 1218) )
      v30 = 1;
    v25 = v30;
    goto LABEL_62;
  }
  if ( (a3 & 2) != 0 )
  {
    MiAgeWorkingSet(a1, 0, 1, *(unsigned __int16 *)(v7 + 1218));
    if ( *(_BYTE *)(v7 + 47) != 1 || v19 >= 0xA || !v19 )
    {
LABEL_34:
      if ( *(_BYTE *)(a1 + 114) == 2 )
        v20 = 3;
      else
        v20 = 1;
      *((_DWORD *)a2 + 2) += *(_DWORD *)(a1 + 20) >> v20;
      *((_DWORD *)a2 + 3) += *(_DWORD *)(a1 + 24) >> v20;
      *((_DWORD *)a2 + 4) += *(_DWORD *)(a1 + 28) >> v20;
      *((_DWORD *)a2 + 5) += *(_DWORD *)(a1 + 32) >> v20;
      *((_DWORD *)a2 + 6) += *(_DWORD *)(a1 + 36) >> v20;
      *((_DWORD *)a2 + 7) += *(_DWORD *)(a1 + 40) >> v20;
      *((_DWORD *)a2 + 8) += *(_DWORD *)(a1 + 44) >> v20;
      goto LABEL_37;
    }
    v26 = 10;
    v25 = 2;
LABEL_63:
    MiAgeWorkingSet(a1, 0, v25, v26);
    goto LABEL_34;
  }
  if ( (a3 & 0x40) != 0 )
  {
    v25 = 1;
LABEL_62:
    v26 = v19;
    goto LABEL_63;
  }
  if ( (a3 & 0x80) != 0 )
  {
    v25 = 2;
    goto LABEL_62;
  }
LABEL_37:
  if ( (a3 & 0x10) != 0 || (a3 & 8) != 0 )
    MiCaptureAndResetWorkingSetAccessBits(a1, a3);
  while ( 1 )
  {
    v21 = dword_690384;
    __dmb(0xBu);
    v22 = KeTickCount;
    __dmb(0xBu);
    if ( v21 == dword_690388 )
      break;
    __dmb(0xAu);
    __yield();
  }
  v23 = *(_DWORD ***)(a1 + 8);
  if ( v23 )
  {
    v31 = *v23;
    for ( i = *(_DWORD **)(a1 + 8); v31; v31 = (_DWORD *)*v31 )
      i = v31;
    if ( __PAIR64__(v21, v22) - *((_QWORD *)i + 2) > PfKernelGlobals )
    {
      MiEmptyPageAccessLog();
      *(_DWORD *)(a1 + 8) = 0;
    }
  }
  if ( (*(_BYTE *)(a1 + 115) & 0x10) != 0 )
  {
    *(_BYTE *)(a1 + 115) &= 0xEFu;
    MiAgeWorkingSet(a1, 0, 1, *(unsigned __int16 *)(dword_6404B8 + 1218));
  }
  if ( (*(_BYTE *)(a1 + 115) & 0x20) != 0 )
  {
    v33 = *(_DWORD *)(a1 + 68);
    v34 = *(_DWORD *)(a1 + 60);
    v38 = v33;
    *(_BYTE *)(a1 + 115) &= 0xDFu;
    for ( j = 7; v34 > v33; --j )
    {
      if ( j )
      {
        v36 = *(_DWORD *)(a1 + 4 * j + 16);
        if ( v36 > v34 - v33 )
          v36 = v34 - v33;
      }
      else
      {
        v36 = v34 - v33;
      }
      if ( v36 )
      {
        MiTrimWorkingSet(v36, a1, 0, j, 0);
        if ( !j )
          break;
        v33 = v38;
      }
      v34 = *(_DWORD *)(a1 + 60);
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  KfLowerIrql(0);
  if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 112) & 7) == 1 )
      MiDetachSession();
  }
  else if ( a1 - 492 != PsInitialSystemProcess )
  {
    KiDetachProcess((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 372, 1);
  }
  if ( dword_634480 )
  {
    do
      v37 = __ldrex((unsigned int *)&dword_634480);
    while ( __strex(0, (unsigned int *)&dword_634480) );
    if ( v37 )
    {
      if ( __PAIR64__(v21, v22) - *(_QWORD *)(v37 + 16) > PfKernelGlobals || (a3 & 0x18) != 0 )
        MiQueuePageAccessLog();
      else
        MiReturnCcAccessLog();
    }
  }
  return 1;
}
