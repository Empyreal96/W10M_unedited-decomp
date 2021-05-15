// KiSetHeteroPolicyThread 
 
int __fastcall KiSetHeteroPolicyThread(int a1, int a2, int a3, int a4)
{
  int v8; // r0
  unsigned int *v9; // r10
  unsigned int v10; // r5
  int v11; // r5
  int v12; // r3
  char v13; // r3
  int v14; // r4
  int v15; // r7
  int v16; // r0
  int v17; // r1
  int v18; // r3
  BOOL v19; // r3
  unsigned int v20; // r3
  int v21; // r2
  int v22; // r3
  int v23; // r8
  int v24; // r0
  _DWORD *v25; // r4
  unsigned int *v26; // r7
  unsigned int v27; // r3
  unsigned __int8 *v28; // r3
  unsigned int v29; // r2
  unsigned int v30; // r3
  int v31; // r0
  int v32; // r3
  unsigned int *v33; // r2
  unsigned int v34; // r4
  unsigned int v35; // r3
  unsigned int v37; // [sp+8h] [bp-30h] BYREF
  int v38; // [sp+Ch] [bp-2Ch] BYREF
  int v39; // [sp+10h] [bp-28h]
  unsigned int *v40; // [sp+14h] [bp-24h] BYREF
  int v41[8]; // [sp+18h] [bp-20h] BYREF

  v8 = KfRaiseIrql(2);
  v39 = v8;
  v9 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v10 = __ldrex(v9);
    while ( __strex(1u, v9) );
    __dmb(0xBu);
    if ( !v10 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v9 );
  }
  if ( a3 )
  {
    v11 = *(unsigned __int8 *)(a1 + 85);
    v12 = *(unsigned __int8 *)(a1 + 86) ^ (*(_BYTE *)(a1 + 86) ^ (unsigned __int8)a2) & 0x7F;
    *(_BYTE *)(a1 + 86) = v12;
    if ( (v12 & 0xFFFFFF80) != 0 )
      goto LABEL_9;
    goto LABEL_8;
  }
  if ( a4 )
  {
LABEL_8:
    v11 = a2;
    goto LABEL_9;
  }
  v13 = *(_BYTE *)(a1 + 86);
  v11 = v13 & 0x7F;
  *(_BYTE *)(a1 + 86) = v13 & 0x7F;
LABEL_9:
  if ( v11 == 8 )
    v11 = KiDefaultHeteroCpuPolicy;
  if ( !KiHeteroSystem )
  {
    v11 = 0;
    *(_BYTE *)(a1 + 86) &= 0x7Fu;
  }
  if ( *(unsigned __int8 *)(a1 + 85) == v11 )
  {
    __dmb(0xBu);
    *v9 = 0;
    goto LABEL_15;
  }
  v14 = v11;
  v15 = (int)*(&KiProcessorBlock + *(_DWORD *)(a1 + 364));
  if ( v11 >= 5 )
  {
    if ( (KiDynamicHeteroCpuPolicyMask & 1) != 0 && *(_BYTE *)(*(_DWORD *)(a1 + 336) + 606) == 2 )
      goto LABEL_31;
    if ( (KiDynamicHeteroCpuPolicyMask & 2) == 0 )
      goto LABEL_37;
    v16 = *(char *)(a1 + 123);
    if ( v16 < 16 && *(_DWORD *)(a1 + 68) )
    {
      v17 = *(_DWORD *)(a1 + 68);
      if ( !v17 )
        goto LABEL_30;
      v18 = *(_DWORD *)(v15 + 2352) + v17;
      if ( !v18 )
        goto LABEL_30;
      v19 = (*(_BYTE *)(v18 + 92) & 8) != 0;
    }
    else
    {
      v19 = 0;
    }
    if ( v19 )
      v16 = 1;
LABEL_30:
    if ( v16 >= KiDynamicHeteroCpuPolicyImportantPriority )
    {
      if ( (KiDynamicHeteroCpuPolicyMask & 4) == 0 )
        goto LABEL_36;
LABEL_31:
      v20 = *(_DWORD *)(a1 + 56);
      if ( v20 <= *(_DWORD *)(a1 + 60) )
        v20 = *(_DWORD *)(a1 + 60);
      if ( v20 < KiDynamicHeteroCpuPolicyExpectedCycles )
        v14 = KiDynamicHeteroCpuPolicyImportantShort;
      else
LABEL_36:
        v14 = KiDynamicHeteroCpuPolicyImportant;
      goto LABEL_38;
    }
LABEL_37:
    v14 = KiDefaultDynamicHeteroCpuPolicy;
  }
LABEL_38:
  KiGenerateHeteroSets(*(_DWORD *)(v15 + 2360), *(_DWORD *)(a1 + 356), v14, (int *)&v37, &v38);
  if ( (*(_DWORD *)(v15 + 1048) & v37) == 0 )
  {
    v21 = ((unsigned __int8)__clz(__rbit(__ROR4__(v37, *(_BYTE *)(v15 + 1053)))) + *(_BYTE *)(v15 + 1053)) & 0x1F;
    v22 = *(_DWORD *)(a1 + 76);
    *(_DWORD *)(a1 + 364) = v21;
    if ( (v22 & 8) == 0 )
      *(_DWORD *)(a1 + 124) = v21;
  }
  v37 = 0;
  v23 = 0;
  v24 = KiAcquireThreadStateLock(a1, v41, &v40);
  v26 = v40;
  v25 = (_DWORD *)v41[0];
  *(_BYTE *)(a1 + 85) = v11;
  if ( v24 == 1 )
  {
    KiRemoveThreadFromAnyReadyQueue((int)v25, (int)v26, a1, *(_BYTE *)(a1 + 123));
    KiPrepareReadyThreadForRescheduling(a1, *(char *)(a1 + 123), &v37);
  }
  else if ( v24 == 2 )
  {
    if ( (v25[262] & v38) == 0 )
    {
      if ( *(_BYTE *)(a1 + 132) == 2 )
      {
        v28 = (unsigned __int8 *)(a1 + 81);
        do
          v29 = __ldrex(v28);
        while ( __strex(v29 | 8, v28) );
        if ( !v25[2] )
        {
          KiSelectNextThread((int)v25, &v37);
          v23 = 1;
        }
      }
      else
      {
        *(_BYTE *)(a1 + 72) |= 8u;
      }
    }
  }
  else if ( v24 == 3 && (v25[262] & v38) == 0 )
  {
    KiSelectNextThread((int)v25, &v37);
    *(_BYTE *)(a1 + 132) = 7;
    v27 = v37;
    v37 = a1 + 144;
    *(_DWORD *)(a1 + 144) = v27;
  }
  if ( v25 )
  {
    __dmb(0xBu);
    v25[6] = 0;
  }
  if ( v26 )
  {
    __dmb(0xBu);
    *v26 = 0;
  }
  __dmb(0xBu);
  *v9 = 0;
  v30 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( !v23 )
  {
    KiProcessDeferredReadyList(v30 + 1408, (_DWORD **)&v37, v39);
    return v11;
  }
  v31 = v25[5];
  if ( *(_DWORD *)(v30 + 1428) != v31 )
  {
    v32 = (int)*(&KiProcessorBlock + v31);
    __dmb(0xBu);
    v33 = (unsigned int *)(v32 + 1676);
    do
      v34 = __ldrex(v33);
    while ( __strex(v34 | 2, v33) );
    __dmb(0xBu);
    v35 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v35 & 0xFFFFF000) + 0x1414);
    HalSendSoftwareInterrupt(v31, 2);
  }
  v8 = v39;
LABEL_15:
  KfLowerIrql(v8);
  return v11;
}
