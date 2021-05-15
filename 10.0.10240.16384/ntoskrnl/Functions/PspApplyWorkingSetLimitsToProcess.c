// PspApplyWorkingSetLimitsToProcess 
 
int __fastcall PspApplyWorkingSetLimitsToProcess(_DWORD *a1)
{
  unsigned int v2; // r5
  _DWORD *v3; // r4
  int v4; // r8
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r4
  unsigned int v9; // r1
  unsigned int *v10; // r1
  unsigned int v11; // r4
  unsigned int *v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r0
  int v15; // r0
  int v16; // r3
  unsigned int *v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r0
  int v20; // r0
  __int16 v21; // r3
  int v22; // r5
  unsigned int *v23; // r0
  unsigned int v24; // r4
  unsigned int v25; // r1
  unsigned __int8 *v26; // r3
  unsigned int v27; // r2
  unsigned int *v28; // r0
  unsigned int v29; // r4
  unsigned int v30; // r1
  _DWORD *v32; // [sp+0h] [bp-50h]
  int v33; // [sp+4h] [bp-4Ch]
  unsigned int v34; // [sp+Ch] [bp-44h]
  unsigned int v35; // [sp+10h] [bp-40h]
  _BYTE v36[56]; // [sp+18h] [bp-38h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = (_DWORD *)a1[72];
  v32 = v3;
  __dmb(0xBu);
  v4 = 0;
  KiStackAttachProcess((int)a1, 0, (int)v36);
  v5 = *(__int16 *)(v2 + 310) - 1;
  *(_WORD *)(v2 + 310) = v5;
  ExAcquireResourceExclusiveLite((int)(v3 + 8), 1, v6, v5);
  v35 = v3[92];
  v34 = v3[93];
  if ( (v3[100] & 1) != 0 )
    v7 = 1;
  else
    v7 = 2;
  v33 = v7;
  v8 = KeAbPreAcquire((unsigned int)&dword_618E28, 0, 0);
  do
    v9 = __ldrex((unsigned __int8 *)&dword_618E28);
  while ( __strex(v9 | 1, (unsigned __int8 *)&dword_618E28) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_618E28, v8, (unsigned int)&dword_618E28);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  __dmb(0xBu);
  v10 = v32 + 186;
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x100, v10) );
  __dmb(0xBu);
  ExReleaseResourceLite((int)(v32 + 8));
  if ( v33 == 2 || (v4 = MmAdjustWorkingSetSize(v35, v34, 0, 1), v4 >= 0) )
  {
    MmEnforceWorkingSetLimit((int)a1, v33);
    __dmb(0xBu);
    v17 = v32 + 186;
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 & 0xFFFFFEFF, v17) );
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)&dword_618E28);
    while ( __strex(v19 - 1, (unsigned int *)&dword_618E28) );
    if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_618E28);
    v20 = KeAbPostRelease((unsigned int)&dword_618E28);
    v21 = *(_WORD *)(v2 + 310) + 1;
    *(_WORD *)(v2 + 310) = v21;
    if ( !v21 && *(_DWORD *)(v2 + 100) != v2 + 100 )
      KiCheckForKernelApcDelivery(v20);
    v22 = a1[80];
    if ( v22 )
    {
      v23 = a1 + 43;
      __pld(a1 + 43);
      v24 = a1[43] & 0xFFFFFFFE;
      do
        v25 = __ldrex(v23);
      while ( v25 == v24 && __strex(v24 + 2, v23) );
      __dmb(0xBu);
      if ( v25 == v24 || ExfAcquireRundownProtection(v23) )
      {
        __dmb(0xBu);
        v26 = (unsigned __int8 *)(v22 + 40);
        do
          v27 = __ldrex(v26);
        while ( __strex(v27 | 1, v26) );
        __dmb(0xBu);
        v28 = a1 + 43;
        __pld(a1 + 43);
        v29 = a1[43] & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v30 = __ldrex(v28);
        while ( v30 == v29 && __strex(v29 - 2, v28) );
        if ( v30 != v29 )
          ExfReleaseRundownProtection((unsigned __int8 *)v28);
      }
      else
      {
        v4 = -1073741558;
      }
    }
  }
  else
  {
    __dmb(0xBu);
    v12 = v32 + 186;
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 & 0xFFFFFEFF, v12) );
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)&dword_618E28);
    while ( __strex(v14 - 1, (unsigned int *)&dword_618E28) );
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_618E28);
    v15 = KeAbPostRelease((unsigned int)&dword_618E28);
    v16 = (__int16)(*(_WORD *)(v2 + 310) + 1);
    *(_WORD *)(v2 + 310) = v16;
    if ( !v16 && *(_DWORD *)(v2 + 100) != v2 + 100 )
      KiCheckForKernelApcDelivery(v15);
  }
  KiUnstackDetachProcess((unsigned int)v36, 0);
  return v4;
}
