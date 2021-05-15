// ExpWorkerFactoryCheckCreate 
 
int __fastcall ExpWorkerFactoryCheckCreate(_DWORD *a1, int *a2, int a3, int a4)
{
  int *v4; // r4
  _DWORD *v7; // r2
  int v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r1
  int v12; // r1
  unsigned int v13; // r2
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r6
  int v17; // r3
  int v18; // r3
  int v19; // r6
  unsigned int v20; // r3
  int v21; // r2
  unsigned int *v22; // r2
  unsigned int v23; // r0
  int v24; // r7
  unsigned int v25; // r3
  _DWORD _0[10]; // [sp+0h] [bp-20h] BYREF

  _0[0] = a1;
  _0[1] = a2;
  _0[2] = a3;
  _0[3] = a4;
  v4 = a2;
  if ( !a2 )
  {
    v4 = _0;
    KeAcquireInStackQueuedSpinLock(a1[1], _0);
  }
  if ( a3 )
  {
    v17 = a1[22];
    if ( (v17 & 0x30) == 0 && (v17 & 0xC0) == 0 && (v17 & 0x3000) == 0 && (v17 & 0x100) == 0 )
      goto LABEL_51;
  }
  if ( a1[20] || a1[16] >= a1[15] || (v7 = (_DWORD *)a1[1], v7[4]) || (v12 = v7[1], !*(_DWORD *)(v12 + 4)) && !v7[3] )
  {
    a1[22] &= 0xFFFFCE0F;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(v4, _0[9]);
    }
    else
    {
      v8 = *v4;
      if ( !*v4 )
      {
        v9 = (unsigned int *)v4[1];
        __dmb(0xBu);
        do
          v10 = __ldrex(v9);
        while ( (int *)v10 == v4 && __strex(0, v9) );
        if ( (int *)v10 == v4 )
          goto LABEL_13;
        v8 = KxWaitForLockChainValid(v4);
      }
      *v4 = 0;
      __dmb(0xBu);
      v22 = (unsigned int *)(v8 + 4);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 ^ 1, v22) );
    }
LABEL_13:
    KfLowerIrql(*((unsigned __int8 *)v4 + 8));
    return _0[0];
  }
  if ( !a3 || (a1[22] & 0xC0) != 128 )
  {
    v13 = *(_DWORD *)(v12 + 24);
    __dmb(0xBu);
    if ( v13 >= KeNumberProcessors_0 )
    {
      v18 = a1[22];
      if ( !((unsigned __int8)v18 >> 6) )
      {
        v24 = 3;
        v25 = v18 & 0xFFFFFF3F | 0x40;
        goto LABEL_41;
      }
      if ( a3 && (unsigned __int8)v18 >> 6 == 1 )
      {
        v24 = 2;
        v25 = v18 & 0xFFFFFF3F | 0x80;
        goto LABEL_41;
      }
LABEL_51:
      KeReleaseInStackQueuedSpinLock(v4);
      return _0[0];
    }
  }
  if ( (!a3 || (a1[22] & 0x30) != 32) && ExpCheckThreadHistory((int)a1) )
  {
    v20 = a1[22];
    v21 = (v20 >> 4) & 3;
    if ( !v21 )
    {
      v24 = 3;
      v25 = v20 & 0xFFFFFFCF | 0x10;
      goto LABEL_41;
    }
    if ( a3 && v21 == 1 )
    {
      v24 = 2;
      v25 = v20 & 0xFFFFFFCF | 0x20;
      goto LABEL_41;
    }
    goto LABEL_51;
  }
  if ( !a3 || (a1[22] & 0x3000) != 0x2000 )
  {
    v14 = a1[19];
    if ( v14 )
    {
      if ( a1[16] > v14 )
        return sub_52C56C();
    }
  }
  if ( (a1[22] & 0x200) != 0 )
    ExpLeaveWorkerFactoryAwayMode((int)a1);
  v15 = a1[22];
  ++a1[20];
  a1[22] = v15 & 0xFFFFCE0F;
  KeReleaseInStackQueuedSpinLock(v4);
  v16 = ExpWorkerFactoryCreateThread(a1);
  if ( v16 >= 0 )
    return _0[0];
  KeAcquireInStackQueuedSpinLock(a1[1], v4);
  --a1[20];
  if ( v16 == -1073741814 || v16 == -1073741582 || v16 == -1073741823 || v16 == -1073741558 )
    goto LABEL_51;
  v24 = 1;
  v25 = a1[22] | 0x100;
LABEL_41:
  v19 = 0;
  a1[22] = v25;
  if ( (v25 & 8) == 0 )
  {
    a1[22] = v25 | 8;
    v19 = 1;
  }
  KeReleaseInStackQueuedSpinLock(v4);
  if ( v19 )
  {
    ObfReferenceObjectWithTag(a1, 1953261124);
    RtlpInterlockedPushEntrySList(ExpWorkerFactoryThreadCreationList, a1);
  }
  ExpSetWorkerFactoryDeferredCreateTimer(v24);
  return _0[0];
}
