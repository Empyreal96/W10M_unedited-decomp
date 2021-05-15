// IopDisassociateThreadIrp 
 
int IopDisassociateThreadIrp()
{
  int v0; // r5
  unsigned int v1; // r4
  _DWORD **v2; // r6
  int result; // r0
  int v4; // r0
  int v5; // r7
  int v6; // r4
  int v7; // r0
  _DWORD *v8; // r1
  __int64 v9; // r2
  int **v10; // r0
  int v11; // r3
  __int16 *v12; // r4
  int v13; // r0

  v0 = KfRaiseIrql(1);
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = (_DWORD **)(v1 + 908);
  if ( *(_DWORD *)(v1 + 0x38C) == v1 + 908 )
    return KfLowerIrql(v0);
  v4 = KeAcquireQueuedSpinLock(11);
  v5 = v4;
  v6 = *(_DWORD *)(v1 + 908) - 16;
  if ( *(char *)(v6 + 35) == *(char *)(v6 + 34) + 2 )
  {
    KeReleaseQueuedSpinLock(11, v4);
    return KfLowerIrql(v0);
  }
  v7 = *(_DWORD *)(v6 + 80);
  IopDeadIrp = v6;
  ObfReferenceObjectWithTag(v7);
  LODWORD(v9) = *v2;
  HIDWORD(v9) = (*v2)[1];
  v8 = (_DWORD *)**v2;
  if ( v9 != __PAIR64__((unsigned int)v2, v8[1]) )
    __fastfail(3u);
  *v2 = v8;
  v8[1] = v2;
  *(_DWORD *)(v6 + 16) = v6 + 16;
  *(_DWORD *)(v6 + 20) = v6 + 16;
  v10 = (int **)dword_631A14;
  *(_DWORD *)v9 = &IopDeadIrps;
  *(_DWORD *)(v9 + 4) = v10;
  if ( *v10 != &IopDeadIrps )
    __fastfail(3u);
  *v10 = (int *)v9;
  dword_631A14 = v9;
  if ( *(char *)(v6 + 35) <= *(char *)(v6 + 34)
    && (v11 = *(_DWORD *)(v6 + 100)) != 0
    && (v12 = *(__int16 **)(*(_DWORD *)(v6 + 96) + 24), *(__int16 **)(v11 + 4) == v12) )
  {
    ObfReferenceObjectWithTag((int)v12);
  }
  else
  {
    v12 = 0;
  }
  KeReleaseQueuedSpinLock(11, v5);
  result = KfLowerIrql(v0);
  if ( v12 )
  {
    v13 = IoAllocateErrorLogEntry(v12, 48);
    if ( v13 )
    {
      *(_DWORD *)(v13 + 12) = -2147221450;
      IoWriteErrorLogEntry(v13);
    }
    result = ObfDereferenceObjectWithTag((int)v12);
  }
  return result;
}
