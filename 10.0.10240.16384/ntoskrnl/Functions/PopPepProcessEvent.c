// PopPepProcessEvent 
 
int __fastcall PopPepProcessEvent(int a1, unsigned int *a2, int a3, unsigned int a4, int a5, int a6)
{
  unsigned int *v11; // lr
  int v12; // r4
  unsigned int v13; // r1
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r4
  int v17; // r8
  unsigned int v18; // r0
  unsigned int *v19; // r3
  unsigned int *v20; // r1
  unsigned int v21; // r3
  char *v22; // r5
  int v23; // r3
  unsigned int *v24; // r3
  int *v25; // r2
  int v26; // r3
  int v27; // r9
  unsigned int v28; // r2
  int v29; // r5
  unsigned int *v30; // r1
  unsigned int v31; // r0
  unsigned int v32; // r2
  int v33; // r2
  unsigned __int8 v34; // r3
  unsigned int v35; // r1
  int v36; // r2
  _DWORD *v37; // r3
  unsigned int *v38; // r8
  unsigned __int8 *v39; // r3
  unsigned int v40; // r1
  unsigned int v41; // lr
  int v42; // r2
  int v43; // r1
  int v44; // r3
  int v45; // r1
  int v46; // r0
  int v47; // r3
  unsigned int v48; // r4
  unsigned int v49; // r1
  unsigned int v50; // r2
  unsigned int v51; // r1
  unsigned int v52; // r1
  int v53; // [sp+8h] [bp-28h]
  int v54; // [sp+Ch] [bp-24h]
  unsigned int v55; // [sp+10h] [bp-20h]
  int v56; // [sp+10h] [bp-20h]

  v53 = 0;
  if ( !a2 || *(_DWORD *)(a1 + 120) == 1 )
    goto LABEL_70;
  if ( a3 == 6 )
  {
    if ( a4 == 6 )
      goto LABEL_70;
  }
  else if ( a3 >= 0 && a3 < 6 && ActivityAttributes[124 * a3] == 1 )
  {
    goto LABEL_70;
  }
  if ( a4 > 5 || ActivityAttributes[124 * a4] != 1 )
  {
    v54 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_540218();
    v11 = (unsigned int *)(a1 + 44);
    v12 = *(_DWORD *)(a1 + 44) & 0x7FFFFFFF;
    do
      v13 = __ldrex(v11);
    while ( v13 == v12 && __strex(v12 + 1, v11) );
    __dmb(0xBu);
    if ( v13 != v12 )
    {
      ExpWaitForSpinLockSharedAndAcquire((unsigned int *)(a1 + 44));
      v11 = (unsigned int *)(a1 + 44);
    }
    if ( *(_BYTE *)(a1 + 77) != 1 )
    {
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a2);
      }
      else
      {
        v14 = (unsigned __int8 *)a2 + 3;
        do
          v15 = __ldrex(v14);
        while ( __strex(v15 | 0x80, v14) );
        __dmb(0xBu);
        if ( v15 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(a2);
        while ( 1 )
        {
          v16 = *a2;
          if ( (*a2 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v16 & 0x40000000) == 0 )
          {
            do
              v51 = __ldrex(a2);
            while ( v51 == v16 && __strex(v16 | 0x40000000, a2) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      goto LABEL_23;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v11);
    }
    else
    {
      __dmb(0xBu);
      do
        v49 = __ldrex(v11);
      while ( __strex(v49 & 0xBFFFFFFF, v11) );
      __dmb(0xBu);
      do
        v50 = __ldrex(v11);
      while ( __strex(v50 - 1, v11) );
    }
    KfLowerIrql(v54);
  }
LABEL_70:
  v53 = 1;
  v56 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 44);
  }
  else
  {
    v38 = (unsigned int *)(a1 + 44);
    v39 = (unsigned __int8 *)(a1 + 47);
    do
      v40 = __ldrex(v39);
    while ( __strex(v40 | 0x80, v39) );
    __dmb(0xBu);
    if ( v40 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 44));
    while ( 1 )
    {
      v41 = *v38;
      if ( (*v38 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v41 & 0x40000000) == 0 )
      {
        do
          v52 = __ldrex(v38);
        while ( v52 == v41 && __strex(v41 | 0x40000000, v38) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v54 = v56;
  *(_BYTE *)(a1 + 77) = 1;
LABEL_23:
  if ( a3 == 6 || (v17 = *(_DWORD *)&ActivityAttributes[124 * a3 + 12], v17 < 2) )
    v17 = 2;
  v18 = *(_DWORD *)(a1 + 72);
  v55 = v18;
  if ( v17 != 2 )
  {
    if ( v17 != 3 )
      goto LABEL_30;
    v42 = *(_DWORD *)(a1 + 120);
    if ( !v42 )
      goto LABEL_30;
    v43 = a1;
    do
    {
      v44 = *(_DWORD *)(v43 + 200);
      v43 += 168;
      v18 += v44;
      --v42;
    }
    while ( v42 );
    goto LABEL_29;
  }
  if ( a2 )
  {
    v18 += a2[18];
LABEL_29:
    v55 = v18;
  }
LABEL_30:
  if ( a3 != 6 )
  {
    if ( (unsigned int)a3 <= 5 && ActivityAttributes[124 * a3] == 1 )
      v19 = (unsigned int *)(a1 + 4 * a3);
    else
      v19 = &a2[a3];
    v20 = (unsigned int *)v19[12];
    v21 = *v20;
    if ( (*v20 & 4) == 0 )
      PopFxBugCheck(1639, v20, a3, v21);
    *v20 = v21 & 0xFFFFFFFB;
    (*(void (__fastcall **)(int, unsigned int *))&ActivityAttributes[124 * a3 + 120])(a1, a2);
  }
  if ( a4 != 6 )
  {
    v22 = &ActivityAttributes[124 * a4];
    v23 = *((_DWORD *)v22 + 1);
    if ( v23 )
    {
      if ( v23 == 1 )
      {
        PopPepCancelActivityRange(a1 + 48, a4, 0, 0, (unsigned int *)(a1 + 72));
        PopPepCancelActivityRange(a1 + 48, a4, 4, 5, (unsigned int *)(a1 + 72));
      }
      else if ( v23 == 2 )
      {
        PopPepCancelActivityRange((int)(a2 + 12), a4, 0, 5, a2 + 18);
      }
    }
    PopPepVerifyActivities(a1, a2, a4);
    if ( a2 )
      v24 = &a2[a4];
    else
      v24 = (unsigned int *)(a1 + 4 * a4);
    v25 = (int *)v24[12];
    v26 = *v25;
    v25[1] = 0;
    *v25 = v26 | 1;
    (*((void (__fastcall **)(int, unsigned int *, _DWORD))v22 + 28))(a1, a2, 0);
  }
  PopPepPromoteActivities(a1, a2, v17);
  v27 = PopPepComponentGetWork(a1, a2, a6);
  v28 = *(_DWORD *)(a1 + 72);
  if ( v17 == 2 )
  {
    if ( a2 )
      v28 += a2[18];
  }
  else if ( v17 == 3 )
  {
    v45 = *(_DWORD *)(a1 + 120);
    if ( v45 )
    {
      v46 = a1;
      do
      {
        v47 = *(_DWORD *)(v46 + 200);
        v46 += 168;
        v28 += v47;
        --v45;
      }
      while ( v45 );
    }
  }
  v29 = 0;
  if ( (*(_DWORD *)(a1 + 16) & 1) != 0 || v28 )
  {
    if ( v28 > v55 )
    {
      v48 = v28 - v55;
      if ( v28 != v55 )
      {
        do
        {
          PopFxRequestWorker(0);
          --v48;
        }
        while ( v48 );
      }
    }
  }
  else if ( !v27 && !*(_DWORD *)(a1 + 92) && *(_BYTE *)(a1 + 88) )
  {
    v29 = 1;
  }
  if ( v53 == 1 )
  {
    v35 = 0;
    v36 = a1;
    while ( 1 )
    {
      v37 = *(_DWORD **)(v36 + 48);
      if ( v37 )
      {
        if ( *v37 )
          break;
      }
      ++v35;
      v36 += 4;
      if ( v35 >= 6 )
      {
        if ( *(_BYTE *)(a1 + 88) )
          *(_BYTE *)(a1 + 77) = 0;
        break;
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 44);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(a1 + 44) = 0;
    }
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a2);
    }
    else
    {
      __dmb(0xBu);
      *a2 = 0;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(a1 + 44);
    }
    else
    {
      __dmb(0xBu);
      v30 = (unsigned int *)(a1 + 44);
      do
        v31 = __ldrex(v30);
      while ( __strex(v31 & 0xBFFFFFFF, v30) );
      __dmb(0xBu);
      do
        v32 = __ldrex(v30);
      while ( __strex(v32 - 1, v30) );
    }
  }
  KfLowerIrql(v54);
  if ( v29 )
    v27 = PopPepTryPowerDownDevice(a1, a6, v33, v34);
  return v27;
}
