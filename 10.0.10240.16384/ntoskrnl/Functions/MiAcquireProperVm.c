// MiAcquireProperVm 
 
int __fastcall MiAcquireProperVm(unsigned int a1, unsigned __int8 *a2)
{
  int v2; // r7
  int v3; // r10
  int v5; // r4
  unsigned int v6; // r1
  unsigned int v7; // r0
  int *v8; // r2
  int *v9; // t1
  int v10; // r3
  int v11; // r3
  char v12; // r8
  int v13; // r7
  unsigned int v14; // r0
  unsigned int v15; // r1
  unsigned __int8 *v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r0
  unsigned __int8 *v19; // r4
  int v20; // r4
  unsigned int v21; // r1
  unsigned int v22; // r0
  int v23; // r2
  int *v24; // r1
  int *v25; // t1
  int v26; // r3
  unsigned int v27; // r2
  int v28; // r0
  int v29; // r3
  bool v30; // zf
  unsigned int v31; // r0
  unsigned int v32; // r1
  int v33; // r4
  unsigned int v34; // r0
  unsigned int v35; // r1
  unsigned int v36; // r1
  unsigned int v37; // r0
  unsigned int v38; // r1
  int v39; // r3
  unsigned int v40; // r0
  unsigned int v41; // r1
  unsigned int v42; // r0
  unsigned int v43; // r1
  unsigned int v44; // r0
  unsigned int v45; // r1
  unsigned int v48; // [sp+8h] [bp-28h]
  unsigned int v49; // [sp+Ch] [bp-24h] BYREF
  int v50; // [sp+10h] [bp-20h]

  *a2 = 17;
  v48 = ((a1 >> 20) & 0xFFC) - 1070596096;
  v49 = (a1 >> 20) & 0xFFC;
  v2 = 1;
  v3 = KfRaiseIrql(2);
  v50 = v3;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_512358();
  v5 = dword_6342C0 & 0x7FFFFFFF;
  v6 = (dword_6342C0 & 0x7FFFFFFF) + 1;
  do
    v7 = __ldrex((unsigned int *)&dword_6342C0);
  while ( v7 == v5 && __strex(v6, (unsigned int *)&dword_6342C0) );
  __dmb(0xBu);
  if ( v7 != v5 )
    ExpWaitForSpinLockSharedAndAcquire(&dword_6342C0, v6);
  v8 = (int *)&v49;
  do
  {
    v9 = (int *)*--v8;
    --v2;
    v10 = *v9;
    if ( (*v9 & 2) == 0 )
    {
      if ( (dword_682604 & 0x10000) == 0 )
      {
        __dmb(0xBu);
        do
          v44 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v44 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
        __dmb(0xBu);
        do
          v45 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v45 - 1, (unsigned int *)&dword_6342C0) );
        goto LABEL_114;
      }
      goto LABEL_113;
    }
  }
  while ( v2 );
  if ( (v10 & 0x400) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
    }
    else
    {
      __dmb(0xBu);
      do
        v42 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v42 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      do
        v43 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v43 - 1, (unsigned int *)&dword_6342C0) );
    }
    v13 = 1;
    goto LABEL_115;
  }
  if ( a1 < dword_63389C )
  {
LABEL_56:
    v12 = 8;
    v13 = (int)&dword_634F00;
    goto LABEL_17;
  }
  v11 = *((unsigned __int8 *)&MiState[2423]
        + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
  if ( v11 == 1 || v11 == 11 )
  {
    v12 = 1;
    v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    if ( v33 && !PsIsSystemProcess() )
    {
      v13 = v33 + 3248;
      goto LABEL_17;
    }
    if ( (dword_682604 & 0x10000) == 0 )
    {
      __dmb(0xBu);
      do
        v34 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v34 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      do
        v35 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v35 - 1, (unsigned int *)&dword_6342C0) );
      goto LABEL_114;
    }
LABEL_113:
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
LABEL_114:
    v13 = 0;
LABEL_115:
    KfLowerIrql(v3);
    return v13;
  }
  if ( v11 != 8 )
  {
    if ( v11 == 6 || v11 == 14 || v11 == 7 )
    {
      v12 = 2;
      v13 = (int)&dword_634E80;
      goto LABEL_17;
    }
    goto LABEL_56;
  }
  v12 = 4;
  v13 = (int)&dword_634E00;
LABEL_17:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
  }
  else
  {
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)&dword_6342C0);
    while ( __strex(v14 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)&dword_6342C0);
    while ( __strex(v15 - 1, (unsigned int *)&dword_6342C0) );
  }
  KfLowerIrql(v50);
  v50 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v13);
  }
  else
  {
    v16 = (unsigned __int8 *)(v13 + 3);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 | 0x80, v16) );
    __dmb(0xBu);
    if ( v17 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v13);
    while ( 1 )
    {
      v18 = *(_DWORD *)v13;
      if ( (*(_DWORD *)v13 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v18 & 0x40000000) == 0 )
      {
        do
          v36 = __ldrex((unsigned int *)v13);
        while ( v36 == v18 && __strex(v18 | 0x40000000, (unsigned int *)v13) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v19 = a2;
  *a2 = v50;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&dword_6342C0);
  }
  else
  {
    v20 = dword_6342C0 & 0x7FFFFFFF;
    v21 = (dword_6342C0 & 0x7FFFFFFF) + 1;
    do
      v22 = __ldrex((unsigned int *)&dword_6342C0);
    while ( v22 == v20 && __strex(v21, (unsigned int *)&dword_6342C0) );
    __dmb(0xBu);
    if ( v22 != v20 )
      ExpWaitForSpinLockSharedAndAcquire(&dword_6342C0, v21);
    v19 = a2;
  }
  v23 = 1;
  v24 = (int *)&v49;
  do
  {
    v25 = (int *)*--v24;
    --v23;
    v26 = *v25;
    if ( (*v25 & 2) == 0 )
      goto LABEL_92;
  }
  while ( v23 );
  if ( (v26 & 0x400) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
    }
    else
    {
      __dmb(0xBu);
      do
        v37 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v37 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      do
        v38 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v38 - 1, (unsigned int *)&dword_6342C0) );
    }
    MiUnlockWorkingSetExclusive(v13, *v19);
    v13 = 1;
  }
  else
  {
    v27 = a1;
    v28 = *(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
    if ( (v28 & 2) != 0 || MiFaultPteIntact(v28) )
    {
      if ( (v12 & 1) != 0 )
      {
        if ( v27 >= dword_63389C )
        {
          v39 = *((unsigned __int8 *)&MiState[2423] + ((int)(v49 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
          if ( v39 == 1 || v39 == 11 )
            goto LABEL_47;
        }
      }
      else
      {
        if ( v27 < dword_63389C )
          goto LABEL_60;
        v29 = *((unsigned __int8 *)&MiState[2423] + ((int)(v49 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
        if ( v29 != 1 && v29 != 11 )
        {
          if ( v29 == 8 )
          {
            v30 = (v12 & 4) == 0;
            goto LABEL_46;
          }
          if ( v29 == 6 || v29 == 14 || v29 == 7 )
            v30 = (v12 & 2) == 0;
          else
LABEL_60:
            v30 = (v12 & 8) == 0;
LABEL_46:
          if ( !v30 )
          {
LABEL_47:
            if ( (dword_682604 & 0x10000) != 0 )
            {
              ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
            }
            else
            {
              __dmb(0xBu);
              do
                v31 = __ldrex((unsigned int *)&dword_6342C0);
              while ( __strex(v31 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
              __dmb(0xBu);
              do
                v32 = __ldrex((unsigned int *)&dword_6342C0);
              while ( __strex(v32 - 1, (unsigned int *)&dword_6342C0) );
            }
            return v13;
          }
        }
      }
    }
LABEL_92:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
    }
    else
    {
      __dmb(0xBu);
      do
        v40 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v40 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      do
        v41 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v41 - 1, (unsigned int *)&dword_6342C0) );
    }
    MiUnlockWorkingSetExclusive(v13, *v19);
    v13 = 0;
  }
  return v13;
}
