// PipEnumerateCompleted 
 
int __fastcall PipEnumerateCompleted(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r5
  _DWORD *v6; // r3
  unsigned int v7; // r5
  int v8; // r2
  int v9; // r3
  _DWORD **v10; // r0
  _DWORD *v11; // r6
  int v12; // r0
  unsigned int v13; // r1
  int v14; // r3
  _DWORD *v16; // r5
  int v17; // r7
  int v18; // r1
  int v19; // r2
  int v20; // r3
  int v21; // r5
  _DWORD *v22; // r6
  _DWORD *i; // r5
  int v24; // r0
  int v25[6]; // [sp+0h] [bp-18h] BYREF

  v25[1] = a4;
  v25[0] = 0;
  v5 = (_DWORD *)a1[1];
  if ( a1[88] )
  {
    while ( v5 )
    {
      PipClearDevNodeFlags(v5, 16);
      v5 = (_DWORD *)*v5;
    }
  }
  else
  {
    for ( ; v5; v5 = (_DWORD *)*v5 )
    {
      if ( *(_DWORD *)(v5[4] + 8) == PiSwDeviceDriverObject )
        PipClearDevNodeFlags(v5, 16);
    }
  }
  v6 = (_DWORD *)a1[88];
  if ( v6 )
  {
    v7 = 0;
    if ( *v6 )
    {
      do
        PipProcessEnumeratedChildDevice(a1, *(_DWORD *)(a1[88] + 4 * v7++ + 4));
      while ( v7 < *(_DWORD *)a1[88] );
    }
    ExFreePoolWithTag(a1[88]);
    a1[88] = 0;
  }
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(__int16 *)(v8 + 0x134) - 1;
  *(_WORD *)(v8 + 308) = v9;
  ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v8, v9);
  v10 = (_DWORD **)PiSwFindChildren(a1 + 5);
  v11 = v10;
  if ( v10 )
  {
    for ( i = *v10; i != v11; i = (_DWORD *)*i )
    {
      v24 = PiSwGetChildPdo(a1[4], i);
      if ( v24 )
        PipProcessEnumeratedChildDevice(a1, v24);
    }
  }
  v12 = ExReleaseResourceLite((int)&PiSwLockObj);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = (__int16)(*(_WORD *)(v13 + 0x134) + 1);
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 )
    return sub_7CB3AC(v12);
  v16 = (_DWORD *)a1[1];
  v17 = 0;
  if ( v16 )
  {
    do
    {
      v22 = (_DWORD *)*v16;
      if ( (v16[67] & 0x10010) == 0 )
      {
        PipSetDevNodeFlags(v16, 0x10000);
        PnpRequestDeviceRemoval(v16, 1, 24);
        v17 = 1;
      }
      v16 = v22;
    }
    while ( v22 );
  }
  PipSetDevNodeState(a1, 776);
  if ( !v17 || (v20 = IopRootDeviceNode, a1 == (_DWORD *)IopRootDeviceNode) )
    v21 = 0;
  else
    v21 = -1073741106;
  PiPnpRtlBeginOperation(v25, v18, v19, v20);
  PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(IopRootDeviceNode + 24), 15);
  PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(IopRootDeviceNode + 24), 20);
  if ( v25[0] )
    PiPnpRtlEndOperation(v25[0]);
  return v21;
}
