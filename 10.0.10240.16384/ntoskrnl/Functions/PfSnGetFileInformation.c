// PfSnGetFileInformation 
 
int __fastcall PfSnGetFileInformation(int a1, int a2)
{
  int *v2; // r2
  int v4; // r8
  unsigned int v5; // r4
  int v7; // r9
  int v8; // t1
  unsigned int *v9; // r10
  int v11; // r0
  unsigned int v12; // r1
  _DWORD *v13; // r5
  unsigned int v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r2
  int v17; // r5
  _BYTE *v18; // r0
  _DWORD *v19; // r10
  int v20; // r5
  unsigned int *v21; // r7
  unsigned __int8 *v22; // r3
  unsigned int v23; // r1
  unsigned int v24; // r5
  _DWORD *v25; // r3
  unsigned int v26; // r2
  unsigned int *v27; // r5
  unsigned int v28; // r0
  unsigned int v29; // r1
  _DWORD *v30; // r1
  int v31; // r2
  _DWORD *v32; // r3
  unsigned __int16 *v33; // r2
  unsigned int v34; // r0
  unsigned int v35; // r1
  unsigned int *v36; // r0
  unsigned int v37; // r4
  unsigned int v38; // r2
  unsigned int v39; // r1
  int v40; // [sp+0h] [bp-20h]
  int v41; // [sp+0h] [bp-20h]

  v2 = (int *)(a1 + 348);
  v4 = 0;
  v5 = *(_DWORD *)(a2 + 12);
  v7 = 0;
  if ( a1 + 348 < (unsigned int)(a1 + 364) )
  {
    do
    {
      v8 = *v2++;
      if ( v8 == v5 )
        return 0;
    }
    while ( (unsigned int)v2 < a1 + 364 );
  }
  v9 = (unsigned int *)(a1 + 392);
  v40 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_537870();
  v11 = *v9 & 0x7FFFFFFF;
  do
    v12 = __ldrex(v9);
  while ( v12 == v11 && __strex(v11 + 1, v9) );
  __dmb(0xBu);
  if ( v12 != v11 )
    ExpWaitForSpinLockSharedAndAcquire((unsigned int *)(a1 + 392));
  v13 = *(_DWORD **)(a1 + 364);
  while ( v13 )
  {
    v14 = v13[3];
    if ( v14 > v5 )
    {
      v13 = (_DWORD *)*v13;
    }
    else
    {
      if ( v14 >= v5 )
        break;
      v13 = (_DWORD *)v13[1];
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(a1 + 392);
  }
  else
  {
    __dmb(0xBu);
    do
      v15 = __ldrex(v9);
    while ( __strex(v15 & 0xBFFFFFFF, v9) );
    __dmb(0xBu);
    do
      v16 = __ldrex(v9);
    while ( __strex(v16 - 1, v9) );
  }
  KfLowerIrql(v40);
  if ( v13 )
  {
    *(_DWORD *)(a1 + 4 * (++*(_BYTE *)(a1 + 396) & 3) + 348) = v5;
    return 0;
  }
  v18 = (_BYTE *)ExAllocatePoolWithTag(512, 24, 1850762051);
  v19 = v18;
  if ( !v18 )
  {
    if ( (*(_WORD *)(a1 + 344) & 2) == 0 )
    {
      __dmb(0xBu);
      v33 = (unsigned __int16 *)(a1 + 344);
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 | 2, v33) );
      __dmb(0xBu);
    }
    return -1073741670;
  }
  memset(v18, 0, 24);
  ObfReferenceObject(a2);
  v19[5] = a2;
  v19[3] = v5;
  v20 = KfRaiseIrql(2);
  v41 = v20;
  v21 = (unsigned int *)(a1 + 392);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 392);
  }
  else
  {
    v22 = (unsigned __int8 *)(a1 + 395);
    do
      v23 = __ldrex(v22);
    while ( __strex(v23 | 0x80, v22) );
    __dmb(0xBu);
    if ( v23 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 392));
    while ( 1 )
    {
      v24 = *v21;
      if ( (*v21 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v24 & 0x40000000) == 0 )
      {
        do
          v35 = __ldrex(v21);
        while ( v35 == v24 && __strex(v24 | 0x40000000, v21) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v20 = v41;
  }
  v25 = *(_DWORD **)(a1 + 364);
  while ( v25 )
  {
    v26 = v25[3];
    if ( v26 > v5 )
    {
      v25 = (_DWORD *)*v25;
    }
    else
    {
      if ( v26 >= v5 )
      {
        v17 = 0;
LABEL_75:
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 392);
        }
        else
        {
          __dmb(0xBu);
          *v21 = 0;
        }
        KfLowerIrql(v41);
        ObfDereferenceObjectWithTag(v19[5]);
        ExFreePoolWithTag(v19, 0);
        return v17;
      }
      v25 = (_DWORD *)v25[1];
    }
  }
  if ( !*(_DWORD *)(a1 + 388) )
  {
    v27 = (unsigned int *)(a1 + 268);
    __pld((void *)(a1 + 268));
    v28 = *(_DWORD *)(a1 + 268) & 0xFFFFFFFE;
    do
      v29 = __ldrex(v27);
    while ( v29 == v28 && __strex(v28 + 2, v27) );
    __dmb(0xBu);
    if ( v29 == v28 )
    {
      v4 = 1;
    }
    else
    {
      v4 = ExfAcquireRundownProtection((_DWORD *)(a1 + 268));
      if ( !v4 )
      {
        v17 = -1073741431;
        goto LABEL_75;
      }
    }
    v20 = v41;
    v7 = 1;
    *(_DWORD *)(a1 + 384) = PfSnNameQueryWorker;
    *(_DWORD *)(a1 + 388) = a1;
    *(_DWORD *)(a1 + 376) = 0;
  }
  v19[4] = *(_DWORD *)(a1 + 372);
  *(_DWORD *)(a1 + 372) = v19 + 4;
  v30 = *(_DWORD **)(a1 + 364);
  v31 = 0;
  if ( !v30 )
    goto LABEL_52;
  while ( v30[3] > v5 )
  {
    v32 = (_DWORD *)*v30;
    if ( !*v30 )
    {
      v31 = 0;
      goto LABEL_52;
    }
LABEL_49:
    v30 = v32;
  }
  v32 = (_DWORD *)v30[1];
  if ( v32 )
    goto LABEL_49;
  v31 = 1;
LABEL_52:
  RtlRbInsertNodeEx(a1 + 364, (unsigned int)v30, v31, v19);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 392);
  }
  else
  {
    __dmb(0xBu);
    *v21 = 0;
  }
  KfLowerIrql(v20);
  if ( v7 )
  {
    v4 = 0;
    ExQueueWorkItem((_DWORD *)(a1 + 376), 1);
  }
  ++*(_BYTE *)(a1 + 396);
  v17 = 0;
  *(_DWORD *)(a1 + 4 * (*(_BYTE *)(a1 + 396) & 3) + 348) = v5;
  if ( v4 )
  {
    v36 = (unsigned int *)(a1 + 268);
    __pld((void *)(a1 + 268));
    v37 = *(_DWORD *)(a1 + 268) & 0xFFFFFFFE;
    __dmb(0xBu);
    v38 = v37 - 2;
    do
      v39 = __ldrex(v36);
    while ( v39 == v37 && __strex(v38, v36) );
    if ( v39 != v37 )
      ExfReleaseRundownProtection(v36, v39, v38);
  }
  return v17;
}
