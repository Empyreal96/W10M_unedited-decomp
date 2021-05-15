// IoBoostThreadIoPriority 
 
_DWORD *__fastcall IoBoostThreadIoPriority(int a1, int a2, int a3)
{
  int v3; // r5
  unsigned int v4; // r7
  int v6; // r9
  unsigned int *v7; // r4
  int v8; // r8
  _DWORD *result; // r0
  unsigned int v10; // r2
  int v11; // r4
  unsigned __int16 i; // r6
  unsigned int *v13; // r5
  int v14; // r6
  unsigned int v15; // r2
  int *v16; // r5
  int v17; // r2
  unsigned int v18; // r1
  int v19; // r6
  unsigned int v20; // r8
  int v21; // r5
  unsigned __int16 v22; // r10
  int v23; // r9
  unsigned int v24; // r4
  unsigned __int16 k; // r6
  _DWORD *v26; // r5
  int v27; // r3
  unsigned __int16 l; // r4
  unsigned int v29; // r1
  int v30; // r9
  int j; // r2
  int *v32; // r4
  int v33; // r0
  unsigned int *v34; // r2
  unsigned int v35; // r1
  int v36; // r4
  _QWORD *v37; // r6
  _DWORD *v38; // r8
  _DWORD *v39; // r4
  int *v40; // r1
  unsigned int *v41; // r2
  unsigned int v42; // r0
  int v43; // r0
  int v44; // r3
  int v45; // r0
  _DWORD *v46; // [sp+0h] [bp-B8h]
  int v47; // [sp+4h] [bp-B4h]
  unsigned __int16 v48; // [sp+4h] [bp-B4h]
  _QWORD *v50; // [sp+Ch] [bp-ACh]
  int v52; // [sp+14h] [bp-A4h]
  int v53; // [sp+14h] [bp-A4h]
  _QWORD v54[5]; // [sp+28h] [bp-90h] BYREF
  _DWORD *v55; // [sp+50h] [bp-68h]
  _DWORD var60[25]; // [sp+58h] [bp-60h]

  v3 = 0;
  v4 = 0;
  v6 = a1;
  if ( a3 < 0 )
  {
    v3 = 1;
  }
  else
  {
    v7 = (unsigned int *)(a1 + 1024);
    v8 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return (_DWORD *)sub_54ABF4();
    do
      v10 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    if ( v10 )
      KxWaitForSpinLockAndAcquire(v7);
    if ( *(_DWORD *)(v6 + 908) == v6 + 908 )
    {
      if ( (a3 & 0x40000000) == 0 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v7);
        }
        else
        {
          __dmb(0xBu);
          *v7 = 0;
        }
        return (_DWORD *)KfLowerIrql(v8);
      }
      v3 = 1;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v7);
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
    KfLowerIrql(v8);
  }
  v11 = 0;
  for ( i = 0; i < 8u; v11 = ++i )
  {
    result = (_DWORD *)ExReferenceCallBackBlock(&IopUpdatePriorityCallbackRoutine[v11]);
    var60[v11] = result;
    if ( result )
      var60[v11 + 8] = result[2];
  }
  if ( v3 == 1 )
    goto LABEL_33;
  v47 = 0;
  v13 = (unsigned int *)(a1 + 1024);
  v14 = KfRaiseIrql(2);
  v52 = v14;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v13);
  }
  else
  {
    do
      v15 = __ldrex(v13);
    while ( __strex(1u, v13) );
    __dmb(0xBu);
    if ( v15 )
      KxWaitForSpinLockAndAcquire(v13);
  }
  if ( *(_DWORD *)(a1 + 908) == a1 + 908 )
    goto LABEL_30;
  v50 = v54;
  v16 = *(int **)(a1 + 908);
  v46 = v54;
  do
  {
    v17 = *((char *)v16 + 18);
    if ( *((char *)v16 + 19) > v17 )
      goto LABEL_28;
    v18 = v16[20];
    if ( v18 >= (unsigned int)&v16[10 * v17 + 24] )
      goto LABEL_28;
    v19 = *(_DWORD *)(v18 + 24);
    if ( !v19 )
      goto LABEL_28;
    v20 = 0;
    while ( !var60[v20] )
    {
LABEL_27:
      v20 = (unsigned __int16)(v20 + 1);
      if ( v20 >= 8 )
        goto LABEL_28;
    }
    v30 = 0;
    KeAcquireQueuedSpinLockAtDpcLevel(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2640);
    for ( j = *(_DWORD *)(*(_DWORD *)(var60[v20 + 8] + 16) + 4); j; j = *(_DWORD *)(j + 12) )
    {
      if ( j == v19 && (*(_DWORD *)(j + 28) & 0x1000000) != 0 )
      {
        v30 = 1;
        break;
      }
    }
    v32 = (int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2640);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(v32);
      goto LABEL_62;
    }
    v33 = *v32;
    if ( *v32 )
      goto LABEL_86;
    v34 = (unsigned int *)v32[1];
    __dmb(0xBu);
    do
      v35 = __ldrex(v34);
    while ( (int *)v35 == v32 && __strex(0, v34) );
    if ( (int *)v35 != v32 )
    {
      v33 = KxWaitForLockChainValid(v32);
LABEL_86:
      *v32 = 0;
      __dmb(0xBu);
      v41 = (unsigned int *)(v33 + 4);
      do
        v42 = __ldrex(v41);
      while ( __strex(v42 ^ 1, v41) );
    }
LABEL_62:
    if ( v30 != 1 || v47 == v19 )
      goto LABEL_27;
    v47 = v19;
    if ( v4 < 2 )
    {
      *v46 = var60[v20];
      *((_WORD *)v50 + 10) = v20;
      *((_DWORD *)v50 + 2) = a1;
      *((_DWORD *)v50 + 3) = a2;
      *((_DWORD *)v50 + 1) = v19;
      *((_DWORD *)v50 + 4) = 0;
      ObfReferenceObjectWithTag(v19);
      ObfReferenceObjectWithTag(a1);
      ++v4;
      v39 = v46 + 6;
      v50 += 3;
      goto LABEL_76;
    }
    v43 = ExAllocatePoolWithTag(512, 24, 1128427337);
    if ( v43 )
    {
      *(_DWORD *)(v43 + 16) = v55;
      v44 = var60[v20];
      v55 = (_DWORD *)v43;
      *(_WORD *)(v43 + 20) = v20;
      *(_DWORD *)v43 = v44;
      *(_DWORD *)(v43 + 4) = v19;
      *(_DWORD *)(v43 + 8) = a1;
      *(_DWORD *)(v43 + 12) = a2;
      ObfReferenceObjectWithTag(v19);
      ObfReferenceObjectWithTag(a1);
      ++v4;
      v39 = v46 + 6;
      v50 += 3;
LABEL_76:
      v46 = v39;
      if ( (*(v16 - 2) & 2) != 0 )
        v40 = &IoBoostedPagingIrpCount;
      else
        v40 = &IoBoostedThreadedIrpCount;
      ++*v40;
    }
LABEL_28:
    v16 = (int *)*v16;
  }
  while ( v16 != (int *)(a1 + 908) );
  v13 = (unsigned int *)(a1 + 1024);
  v14 = v52;
LABEL_30:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v13);
  }
  else
  {
    __dmb(0xBu);
    *v13 = 0;
  }
  result = (_DWORD *)KfLowerIrql(v14);
  if ( v4 )
    goto LABEL_38;
LABEL_33:
  v21 = 0;
  v22 = 0;
  v48 = 0;
  while ( 2 )
  {
    v23 = var60[v21];
    if ( !v23 )
      goto LABEL_35;
    v53 = KeAcquireQueuedSpinLock(10);
    v36 = *(_DWORD *)(*(_DWORD *)(var60[v21 + 8] + 16) + 4);
    if ( !v36 )
      goto LABEL_72;
    v37 = &v54[3 * v4];
    v38 = v37;
    while ( 2 )
    {
      if ( (*(_DWORD *)(v36 + 28) & 0x1000000) == 0 )
        goto LABEL_70;
      if ( v4 < 2 )
      {
        *v38 = v23;
        *((_WORD *)v37 + 10) = v21;
        *((_DWORD *)v37 + 2) = a1;
        *((_DWORD *)v37 + 3) = a2;
        *((_DWORD *)v37 + 4) = 0;
        *((_DWORD *)v37 + 1) = v36;
        goto LABEL_69;
      }
      v45 = ExAllocatePoolWithTag(512, 24, 1128427337);
      if ( v45 )
      {
        *(_DWORD *)(v45 + 16) = v55;
        v55 = (_DWORD *)v45;
        *(_DWORD *)v45 = v23;
        *(_DWORD *)(v45 + 4) = v36;
        *(_DWORD *)(v45 + 8) = a1;
        *(_DWORD *)(v45 + 12) = a2;
        *(_WORD *)(v45 + 20) = v21;
LABEL_69:
        ObfReferenceObjectWithTag(v36);
        ObfReferenceObjectWithTag(a1);
        ++v4;
        v37 += 3;
        v38 += 6;
LABEL_70:
        v36 = *(_DWORD *)(v36 + 12);
        if ( !v36 )
          break;
        continue;
      }
      break;
    }
    v22 = v48;
LABEL_72:
    result = (_DWORD *)KeReleaseQueuedSpinLock(10, v53);
LABEL_35:
    v21 = ++v22;
    v48 = v22;
    if ( v22 < 8u )
      continue;
    break;
  }
  if ( v4 )
    ++IoBlanketBoostCount;
LABEL_38:
  v24 = 0;
  if ( v4 )
  {
    for ( k = 0; k < v4; v24 = ++k )
    {
      if ( v24 >= 2 )
      {
        v26 = v55;
        v55 = (_DWORD *)v55[4];
      }
      else
      {
        v26 = &v54[3 * v24];
      }
      result = (_DWORD *)(*(int (__fastcall **)(_DWORD, _DWORD *, _DWORD))(*v26 + 4))(*v26, v26 + 1, 0);
      if ( v24 >= 2 )
        result = (_DWORD *)ExFreePoolWithTag(v26, 0);
    }
  }
  v27 = 0;
  for ( l = 0; l < 8u; v27 = ++l )
  {
    v29 = var60[v27];
    if ( v29 )
      result = ExDereferenceCallBackBlock(&IopUpdatePriorityCallbackRoutine[v27], v29);
  }
  return result;
}
