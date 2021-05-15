// KeStartThread 
 
int __fastcall KeStartThread(int a1, int *a2, unsigned int *a3)
{
  int *v3; // r5
  int v6; // r4
  unsigned int v7; // r8
  char v8; // r3
  int v9; // r3
  int v10; // r2
  int v11; // r7
  unsigned int v12; // r10
  unsigned int v13; // r0
  int v14; // r5
  unsigned int v15; // r9
  int v16; // r2
  int v17; // r3
  int v18; // r0
  unsigned int v19; // r2
  int *v20; // r1
  int v21; // r2
  unsigned int v22; // r1
  unsigned int *v23; // r2
  int result; // r0
  unsigned __int8 *v25; // r3
  unsigned int v26; // r2
  int v27; // r3
  int **v28; // r0
  int v29; // r0
  unsigned int *v30; // r1
  int *v31; // r0
  unsigned int *v32; // r2
  unsigned int v33; // r0
  unsigned __int8 *v34; // r3
  unsigned int v35; // r2
  char v36[4]; // [sp+0h] [bp-48h] BYREF
  int v37; // [sp+4h] [bp-44h]
  int v38[4]; // [sp+8h] [bp-40h] BYREF
  int v39; // [sp+18h] [bp-30h] BYREF
  int v40; // [sp+1Ch] [bp-2Ch]
  int v41; // [sp+20h] [bp-28h]

  v3 = a2;
  if ( a2 && !a3 )
    return sub_5477D8();
  v37 = 1;
  if ( !a2 )
  {
    v39 = 0;
    v40 = 0;
    v41 = 0;
  }
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_DWORD *)(a1 + 116);
  *(_DWORD *)(a1 + 80) ^= ((unsigned __int8)*(_DWORD *)(a1 + 80) ^ (unsigned __int8)(2 * (*(int *)(v6 + 100) >> 1))) & 2;
  KiAcquireProcessLockExclusive(v6, v36);
  v8 = *(_BYTE *)(v6 + 104);
  *(_BYTE *)(a1 + 347) = v8;
  *(_BYTE *)(a1 + 123) = v8;
  if ( !v3 )
  {
    if ( v6 == *(_DWORD *)(v7 + 336) )
    {
      LOWORD(v40) = *(_WORD *)(v7 + 344);
      v9 = *(_DWORD *)(v6 + 4 * (unsigned __int16)v40 + 72);
    }
    else
    {
      v9 = *(_DWORD *)(v6 + 72);
      if ( !v9 )
        goto LABEL_8;
      v39 = 0;
      v40 = 0;
      v41 = 0;
    }
    v39 = v9;
LABEL_8:
    v3 = &v39;
    goto LABEL_9;
  }
  v27 = *(_DWORD *)(v6 + 4 * *((unsigned __int16 *)v3 + 2) + 72);
  if ( !v27 || (v27 & *v3) != *v3 )
    KiExtendProcessAffinity(v6);
  if ( !*v3 )
    *v3 = *(_DWORD *)(v6 + 4 * *((unsigned __int16 *)v3 + 2) + 72);
LABEL_9:
  *(_WORD *)(a1 + 360) = *((_WORD *)v3 + 2);
  *(_DWORD *)(a1 + 356) = *v3;
  *(_WORD *)(a1 + 344) = *((_WORD *)v3 + 2);
  *(_DWORD *)(a1 + 340) = *v3;
  KiUpdateNodeAffinitizedFlag(a1);
  if ( a3 )
  {
    v13 = *a3;
  }
  else
  {
    v10 = *((unsigned __int16 *)v3 + 2);
    v11 = (int)*(&KeNodeBlock + *(unsigned __int16 *)(v6 + 2 * v10 + 112));
    v12 = *(_DWORD *)(v6 + 4 * v10 + 108);
    *v3 &= *(_DWORD *)(v11 + 260);
    v13 = KiSelectIdealProcessor(v11, v12, v3);
    if ( v37 )
      *(_DWORD *)(v6 + 4 * *((unsigned __int16 *)v3 + 2) + 108) = v13;
  }
  v14 = v6 + 40;
  *(_DWORD *)(a1 + 124) = v13;
  *(_DWORD *)(a1 + 364) = v13;
  v15 = (unsigned int)*(&KiProcessorBlock + v13);
  if ( *(_DWORD *)(v6 + 40) != v6 + 40 || (_UNKNOWN *)v6 == &KiInitialProcess )
    goto LABEL_13;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(KiProcessListLock, v38);
  v28 = (int **)dword_624D7C;
  *(_DWORD *)(v6 + 120) = &KiProcessListHead;
  *(_DWORD *)(v6 + 124) = v28;
  if ( *v28 != &KiProcessListHead )
    __fastfail(3u);
  *v28 = (int *)(v6 + 120);
  dword_624D7C = v6 + 120;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(v38);
  }
  else
  {
    v29 = v38[0];
    if ( !v38[0] )
    {
      v30 = (unsigned int *)v38[1];
      __dmb(0xBu);
      do
        v31 = (int *)__ldrex(v30);
      while ( v31 == v38 && __strex(0, v30) );
      if ( v31 == v38 )
        goto LABEL_13;
      v29 = KxWaitForLockChainValid(v38);
    }
    v38[0] = 0;
    __dmb(0xBu);
    v32 = (unsigned int *)(v29 + 4);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 ^ 1, v32) );
  }
LABEL_13:
  *(_DWORD *)(a1 + 80) ^= (*(_DWORD *)(a1 + 80) ^ (*(int *)(v6 + 100) >> 2 << 7)) & 0x80;
  v16 = *(unsigned __int8 *)(v6 + 105);
  v17 = KiCyclesPerClockQuantum;
  *(_BYTE *)(a1 + 403) = v16;
  v18 = v17 * v16;
  if ( (*(_DWORD *)(a1 + 80) & 0x10) != 0 )
  {
    __dmb(0xBu);
    v34 = (unsigned __int8 *)(a1 + 80);
    do
      v35 = __ldrex(v34);
    while ( __strex(v35 & 0xEF, v34) );
    __dmb(0xBu);
  }
  *(_DWORD *)(a1 + 24) = v18;
  *(_DWORD *)(a1 + 28) = 0;
  do
    v19 = __ldrex((unsigned __int8 *)v6);
  while ( __strex(v19 | 0x80, (unsigned __int8 *)v6) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v19 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)v6 & 0x80) != 0 );
    do
      v19 = __ldrex((unsigned __int8 *)v6);
    while ( __strex(v19 | 0x80, (unsigned __int8 *)v6) );
  }
  v20 = *(int **)(v6 + 44);
  v21 = a1 + 468;
  *(_DWORD *)(a1 + 468) = v14;
  *(_DWORD *)(a1 + 472) = v20;
  if ( *v20 != v14 )
    __fastfail(3u);
  *v20 = v21;
  *(_DWORD *)(v6 + 44) = v21;
  __dmb(0xBu);
  do
    v22 = __ldrex((unsigned int *)v6);
  while ( __strex(v22 & 0xFFFFFF7F, (unsigned int *)v6) );
  if ( (*(_DWORD *)(v6 + 100) & 8) != 0 )
    KiFreezeSingleThread(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, a1);
  *(_DWORD *)(a1 + 68) = *(_DWORD *)(v6 + 144);
  if ( *(_DWORD *)(v6 + 144) )
  {
    __dmb(0xBu);
    v25 = (unsigned __int8 *)(a1 + 2);
    do
      v26 = __ldrex(v25);
    while ( __strex(v26 | 4, v25) );
    __dmb(0xBu);
  }
  KiUpdateSharedReadyQueueAffinityThread(v15, a1);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6 + 48);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)(v6 + 48) = 0;
  }
  KfLowerIrql((unsigned __int8)v36[0]);
  __dmb(0xBu);
  v23 = (unsigned int *)(v6 + 116);
  do
    result = __ldrex(v23);
  while ( __strex(result + 8, v23) );
  __dmb(0xBu);
  return result;
}
