// PpDevNodeRemoveFromTree 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PpDevNodeRemoveFromTree(int a1)
{
  int v2; // r8
  int v3; // r9
  unsigned int v4; // r2
  int v5; // r3
  _DWORD *i; // r2
  _DWORD *v7; // r1
  int v8; // r0
  int v9; // r1 OVERLAPPED
  _DWORD *v10; // r2 OVERLAPPED
  _DWORD *v11; // r5
  _DWORD *v12; // r0
  int v13; // r1 OVERLAPPED
  _DWORD *v14; // r2 OVERLAPPED
  __int64 v15; // kr00_8
  _QWORD *v16; // r5
  _QWORD *v17; // r0
  int v18; // r1 OVERLAPPED
  _DWORD *v19; // r2 OVERLAPPED
  __int64 v20; // kr08_8
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = 0;
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PnpSpinLock);
  }
  else
  {
    do
      v4 = __ldrex((unsigned int *)&PnpSpinLock);
    while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
  }
  v5 = *(_DWORD *)(a1 + 8);
  if ( v5 )
  {
    for ( i = (_DWORD *)(v5 + 4); *i != a1; i = (_DWORD *)*i )
      ;
    v7 = *(_DWORD **)a1;
    *i = *(_DWORD *)a1;
    v8 = *(_DWORD *)(a1 + 8);
    if ( *(_DWORD *)(v8 + 4) )
    {
      while ( v7 )
      {
        i = v7;
        v7 = (_DWORD *)*v7;
      }
      *(_DWORD *)(v8 + 12) = i;
    }
    else
    {
      *(_DWORD *)(v8 + 12) = 0;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PnpSpinLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      PnpSpinLock = 0;
    }
    KfLowerIrql(v3);
    *(_QWORD *)&v9 = *(_QWORD *)(a1 + 400);
    if ( *(_DWORD *)(v9 + 4) != a1 + 400 || *v10 != a1 + 400 )
      __fastfail(3u);
    *v10 = v9;
    *(_DWORD *)(v9 + 4) = v10;
    PnpOrphanNotification(a1);
    v2 = 1;
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PnpSpinLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      PnpSpinLock = 0;
    }
    KfLowerIrql(v3);
  }
  v11 = *(_DWORD **)(a1 + 92);
  while ( v11 != (_DWORD *)(a1 + 92) )
  {
    v12 = v11 - 3;
    *(_QWORD *)&v13 = *(_QWORD *)(v11 - 3);
    v11 = (_DWORD *)*v11;
    if ( *(_DWORD **)(v13 + 4) != v12 || (_DWORD *)*v14 != v12 )
      __fastfail(3u);
    *v14 = v13;
    *(_DWORD *)(v13 + 4) = v14;
    v15 = *(_QWORD *)(v12 + 3);
    if ( *(_DWORD **)(v15 + 4) != v12 + 3 || *(_DWORD **)HIDWORD(v15) != v12 + 3 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v15) = v15;
    *(_DWORD *)(v15 + 4) = HIDWORD(v15);
    ExFreePoolWithTag(v12);
  }
  v16 = *(_QWORD **)(a1 + 100);
  while ( v16 != (_QWORD *)(a1 + 100) )
  {
    v17 = v16;
    *(_QWORD *)&v18 = *v16;
    v16 = *(_QWORD **)v16;
    if ( *(_QWORD **)(v18 + 4) != v17 || (_QWORD *)*v19 != v17 )
      __fastfail(3u);
    *v19 = v18;
    *(_DWORD *)(v18 + 4) = v19;
    v20 = *(_QWORD *)((char *)v17 + 12);
    if ( *(_QWORD **)(v20 + 4) != (_QWORD *)((char *)v17 + 12)
      || *(_QWORD **)HIDWORD(v20) != (_QWORD *)((char *)v17 + 12) )
    {
      __fastfail(3u);
    }
    *(_DWORD *)HIDWORD(v20) = v20;
    *(_DWORD *)(v20 + 4) = HIDWORD(v20);
    ExFreePoolWithTag(v17);
  }
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 12) = 0;
  return v2;
}
