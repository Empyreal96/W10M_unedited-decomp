// MiSectionCreated 
 
int __fastcall MiSectionCreated(int a1, _DWORD *a2, _DWORD *a3)
{
  unsigned int *v6; // r10
  int result; // r0
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  _DWORD *v11; // r3
  _DWORD *v12; // r4
  unsigned int *v13; // lr
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r1
  int v18; // r4
  _DWORD *v19; // r7
  int v20; // r9
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r0
  int v24; // r7
  _DWORD *v25; // r4
  unsigned int v26; // r7
  int v27; // r6
  unsigned __int8 *v28; // r1
  unsigned int v29; // r2
  unsigned int *v30; // r2
  unsigned int v31; // r4
  int v32; // r3
  int v33; // r0
  unsigned int v34; // r1
  unsigned int v35; // r1
  unsigned int v36; // r1
  int v37; // r1
  unsigned int v38; // r0
  int v39; // r3
  unsigned int v40; // r2
  int v41; // r3
  char v42[4]; // [sp+0h] [bp-38h] BYREF
  unsigned int *v43; // [sp+4h] [bp-34h]
  int v44; // [sp+8h] [bp-30h]
  _DWORD *v45; // [sp+Ch] [bp-2Ch]
  int v46; // [sp+10h] [bp-28h]
  int v47; // [sp+14h] [bp-24h]
  int v48; // [sp+18h] [bp-20h]

  v45 = a2;
  v46 = a1;
  v6 = a2 + 9;
  v47 = KfRaiseIrql(2);
  v48 = 0x80000000;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51A620();
  v8 = (unsigned __int8 *)v6 + 3;
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v6);
  while ( 1 )
  {
    v10 = *v6;
    if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v10 & 0x40000000) == 0 )
    {
      do
        v34 = __ldrex(v6);
      while ( v34 == v10 && __strex(v10 | 0x40000000, v6) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( (*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C8) & 0x40) != 0 )
    a2[7] |= 0x200u;
  v11 = *(_DWORD **)(a1 + 20);
  if ( a3 )
  {
    v12 = (_DWORD *)v11[2];
    v13 = v12 + 9;
    v43 = v12 + 9;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v12 + 9);
      v13 = v12 + 9;
    }
    else
    {
      v21 = (unsigned __int8 *)v12 + 39;
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 | 0x80, v21) );
      __dmb(0xBu);
      if ( v22 >> 7 )
      {
        ExpWaitForSpinLockExclusiveAndAcquire(v12 + 9);
        v13 = v12 + 9;
      }
      while ( 1 )
      {
        v23 = *v13;
        if ( (*v13 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v23 & 0x40000000) == 0 )
        {
          do
            v35 = __ldrex(v13);
          while ( v35 == v23 && __strex(v23 | 0x40000000, v13) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    a2[11] = v12[11];
    v44 = 0;
  }
  else
  {
    v12 = (_DWORD *)*v11;
    v13 = (unsigned int *)(*v11 + 36);
    v43 = v13;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v12 + 9);
      v13 = v12 + 9;
    }
    else
    {
      v14 = (unsigned __int8 *)v12 + 39;
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 0x80, v14) );
      __dmb(0xBu);
      if ( v15 >> 7 )
      {
        ExpWaitForSpinLockExclusiveAndAcquire(v12 + 9);
        v13 = v12 + 9;
      }
      while ( 1 )
      {
        v16 = *v13;
        if ( (*v13 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v16 & 0x40000000) == 0 )
        {
          do
            v36 = __ldrex(v13);
          while ( v36 == v16 && __strex(v16 | 0x40000000, v13) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v44 = v12[11];
  }
  a2[8] = v12[8];
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632E00);
    v13 = v43;
  }
  else
  {
    do
      v17 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
    while ( __strex(v17 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
    __dmb(0xBu);
    if ( v17 >> 7 )
    {
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
      v13 = v43;
    }
    while ( 1 )
    {
      v18 = dword_632E00;
      if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632E00 & 0x40000000) == 0 )
      {
        v37 = dword_632E00 | 0x40000000;
        do
          v38 = __ldrex((unsigned int *)&dword_632E00);
        while ( v38 == v18 && __strex(v37, (unsigned int *)&dword_632E00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( a3 )
  {
    v24 = (int)v45;
    *(_DWORD *)(*(_DWORD *)(v46 + 20) + 8) = v45;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
      v13 = v43;
    }
    else
    {
      __dmb(0xBu);
      dword_632E00 = 0;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v13);
    }
    else
    {
      __dmb(0xBu);
      *v13 = 0;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    KfLowerIrql(v47);
    v25 = *(_DWORD **)(v24 + 84);
    v26 = (int)((unsigned __int64)(715827883i64 * ((int)a3 - MmPfnDatabase)) >> 32) >> 2;
    while ( 1 )
    {
      v27 = MiLockProtoPoolPage(v25, v42);
      if ( v27 )
        break;
      MmAccessFault(1, v25, 0, 0);
    }
    v28 = (unsigned __int8 *)a3 + 15;
    do
      v29 = __ldrex(v28);
    while ( __strex(v29 | 0x80, v28) );
    __dmb(0xBu);
    if ( v29 >> 7 )
    {
      v33 = v48;
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v39 = a3[3];
          __dmb(0xBu);
        }
        while ( (v39 & v33) != 0 );
        do
          v40 = __ldrex(v28);
        while ( __strex(v40 | 0x80, v28) );
        __dmb(0xBu);
      }
      while ( v40 >> 7 );
    }
    if ( (BYTE2(MiFlags) & 3) == 2 )
    {
      v41 = (*v25 & 0x400) != 0 ? (*(unsigned __int16 *)((*v25 & 0xFFFFF800 | (2 * (*v25 & 0x3FC))) + 0x10) >> 1) & 0x1F : (*v25 >> 5) & 0x1F;
      if ( (v41 & 2) != 0 )
        MiMarkPfnVerified(a3, 6);
    }
    MiInitializeTransitionPfn(v26 + (v26 >> 31), v25);
    __dmb(0xBu);
    v30 = a3 + 3;
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 & 0x7FFFFFFF, v30) );
    MiUnlockProtoPoolPage(v27, (unsigned __int8)v42[0]);
    v32 = a3[2];
    *a3 = 0;
    if ( (v32 & 0x400) != 0 )
      MiReferenceControlAreaPfn(v45, 0, 1);
    result = v44;
  }
  else
  {
    v19 = *(_DWORD **)(v46 + 20);
    v20 = (int)v45;
    *v19 = v45;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
      v13 = v43;
    }
    else
    {
      __dmb(0xBu);
      dword_632E00 = 0;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v13);
    }
    else
    {
      __dmb(0xBu);
      *v13 = 0;
    }
    *(_DWORD *)(v20 + 28) &= 0xFFFFFFFD;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    KfLowerIrql(v47);
    KeAbPostRelease(v19);
    result = v44;
  }
  return result;
}
