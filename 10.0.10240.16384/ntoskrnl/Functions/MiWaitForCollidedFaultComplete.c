// MiWaitForCollidedFaultComplete 
 
int MiWaitForCollidedFaultComplete(int a1, int a2, unsigned int a3, unsigned int *a4, unsigned __int8 a5, ...)
{
  __int64 v6; // kr00_8
  int v8; // r4
  _DWORD *v9; // r9
  unsigned int *v12; // r2
  unsigned int v13; // r1
  unsigned int *v14; // r10
  unsigned int v15; // r1
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r4
  unsigned __int8 *v20; // r3
  unsigned int v21; // r1
  unsigned int v22; // r0
  unsigned __int8 *v23; // r1
  unsigned int v24; // r2
  int v25; // r3
  unsigned int v26; // r4
  int v27; // r4
  unsigned int v28; // r1
  unsigned __int8 *v29; // r1
  unsigned int v30; // r2
  unsigned __int8 *v31; // r1
  unsigned int v32; // r2
  int v33; // r3
  unsigned int *v34; // r2
  unsigned int v35; // r0
  unsigned int v36; // r1
  unsigned int v37; // r3
  unsigned int v38; // r3
  int v39; // [sp+8h] [bp-28h] BYREF
  int v40; // [sp+Ch] [bp-24h]
  unsigned int v41; // [sp+10h] [bp-20h]
  int v42; // [sp+4Ch] [bp+1Ch] BYREF
  va_list va; // [sp+4Ch] [bp+1Ch]
  _DWORD *v44; // [sp+50h] [bp+20h]
  va_list va1; // [sp+54h] [bp+24h] BYREF

  va_start(va1, a5);
  va_start(va, a5);
  v42 = va_arg(va1, _DWORD);
  v44 = va_arg(va1, _DWORD *);
  v6 = *(_QWORD *)a1;
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 4) | 0x80000000);
  v9 = v44;
  v40 = *(_DWORD *)(a1 + 4) | 0x80000000;
  v41 = a3;
  v39 = v8;
  if ( !*v44 )
  {
    if ( !MiAddLockedPageCharge(a1, 2) )
      return sub_549E40(0, 1);
    if ( a2 && !*v9 && *(unsigned __int16 *)(a2 + 16) >= 0x7FFFu )
    {
      *v9 = 1;
      MiRemoveLockedPageChargeAndDecRef(a1);
    }
  }
  if ( *v9 == 1 && a2 )
  {
    v31 = (unsigned __int8 *)(a2 + 15);
    do
      v32 = __ldrex(v31);
    while ( __strex(v32 | 0x80, v31) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v32 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
        v33 = *(_DWORD *)(a2 + 12);
        __dmb(0xBu);
      }
      while ( (v33 & 0x80000000) != 0 );
      do
        v32 = __ldrex(v31);
      while ( __strex(v32 | 0x80, v31) );
    }
    MiRemoveLockedPageChargeAndDecRef(a2);
    __dmb(0xBu);
    v34 = (unsigned int *)(a2 + 12);
    do
      v35 = __ldrex(v34);
    while ( __strex(v35 & 0x7FFFFFFF, v34) );
  }
  v12 = (unsigned int *)(v6 + 84);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 + 1, v12) );
  __dmb(0xBu);
  __dmb(0xBu);
  v14 = (unsigned int *)(a1 + 12);
  if ( a2 )
  {
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 & 0x7FFFFFFF, v14) );
    MiUnlockProtoPoolPage(a2, (unsigned __int8)v42);
  }
  else
  {
    do
      v28 = __ldrex(v14);
    while ( __strex(v28 & 0x7FFFFFFF, v14) );
    KfLowerIrql((unsigned __int8)v42);
  }
  if ( a4 )
    MiUnlockWorkingSetExclusive((int)a4, a5);
  if ( *(_DWORD *)(v6 + 108) )
  {
    v16 = KeAbPreAcquire(v6 - 16, 0, 0);
    v19 = v16;
    if ( v16 )
      KeAbPreWait(v16, v17, v18);
  }
  else
  {
    v19 = 0;
  }
  KeWaitForSingleObject(v6 + 16, 9, 0, 0, 0);
  if ( v19 )
  {
    KeAbPreAcquire(v6 - 16, v19, 0);
    KeAbPostReleaseEx(v6 - 16, v19);
  }
  MiFreeInPageSupportBlock(v6 - 16);
  if ( a4 )
  {
    KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a4);
    }
    else
    {
      v20 = (unsigned __int8 *)a4 + 3;
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 | 0x80, v20) );
      __dmb(0xBu);
      if ( v21 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(a4);
      while ( 1 )
      {
        v22 = *a4;
        if ( (*a4 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v22 & 0x40000000) == 0 )
        {
          do
            v36 = __ldrex(a4);
          while ( v36 == v22 && __strex(v22 | 0x40000000, a4) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
  if ( *v9 == 1 )
    return -1073740748;
  if ( a2 )
  {
    MiRelockProtoPoolPage(a2, (int *)va);
    v23 = (unsigned __int8 *)(a1 + 15);
    do
      v24 = __ldrex(v23);
    while ( __strex(v24 | 0x80, v23) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v24 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
        v37 = *v14;
        __dmb(0xBu);
      }
      while ( (v37 & 0x80000000) != 0 );
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 | 0x80, v23) );
    }
  }
  else
  {
    KfRaiseIrql(2);
    v29 = (unsigned __int8 *)(a1 + 15);
    do
      v30 = __ldrex(v29);
    while ( __strex(v30 | 0x80, v29) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v30 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
        v38 = *v14;
        __dmb(0xBu);
      }
      while ( (v38 & 0x80000000) != 0 );
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 | 0x80, v29) );
    }
  }
  v25 = *(_DWORD *)(a1 + 12);
  if ( (v25 & 0x40000000) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 19) & 0x10) != 0 )
    {
      v27 = -1073741801;
      goto LABEL_36;
    }
  }
  else
  {
    v26 = v41;
    if ( MiIsFaultPteIntact(v41, v40, &v39, v25) && MiImagePageOk(v26, a1) )
      return 0;
  }
  v27 = -1073740748;
LABEL_36:
  MiRemoveLockedPageChargeAndDecRef(a1);
  return v27;
}
