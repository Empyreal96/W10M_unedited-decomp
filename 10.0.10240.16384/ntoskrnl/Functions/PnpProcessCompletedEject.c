// PnpProcessCompletedEject 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall PnpProcessCompletedEject(unsigned int a1)
{
  int v2; // r1
  int v3; // r6
  int v4; // r3
  int v5; // r0
  int v6; // r1 OVERLAPPED
  _DWORD *v7; // r2 OVERLAPPED
  int v8; // r3
  int v9; // r5
  int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r0

  v2 = *(_DWORD *)(a1 + 52);
  v3 = 0;
  if ( v2 != 1 && v2 )
  {
    *(_BYTE *)(a1 + 49) = 0;
    v3 = IopWarmEjectDevice(*(_DWORD *)(a1 + 28));
  }
  v4 = *(_DWORD *)(a1 + 56);
  if ( v4 )
  {
    (*(void (__fastcall **)(_DWORD, int))(v4 + 16))(*(_DWORD *)(v4 + 4), 1);
    (*(void (__fastcall **)(_DWORD))(*(_DWORD *)(a1 + 56) + 12))(*(_DWORD *)(*(_DWORD *)(a1 + 56) + 4));
  }
  v5 = PpDevNodeLockTree(1, v2);
  *(_QWORD *)&v6 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v7 != a1 )
    __fastfail(3u);
  *v7 = v6;
  *(_DWORD *)(v6 + 4) = v7;
  v8 = *(_DWORD *)(a1 + 28);
  if ( v8 )
    v9 = *(_DWORD *)(*(_DWORD *)(v8 + 176) + 20);
  else
    v9 = 0;
  if ( *(_DWORD *)(a1 + 32) )
  {
    if ( *(_BYTE *)(a1 + 48) )
      PpProfileMarkAllTransitioningDocksEjected(v5);
    PnpInvalidateRelationsInList(*(_DWORD *)(a1 + 32), 4, 0);
    IopFreeRelationList(*(_DWORD **)(a1 + 32));
    *(_DWORD *)(v9 + 452) = 0;
  }
  else
  {
    *(_BYTE *)(a1 + 49) = 0;
  }
  PpDevNodeUnlockTree(1);
  v12 = *(_DWORD *)(a1 + 24);
  if ( v12 )
    PnpCompleteDeviceEvent(v12, v3, v10, v11);
  if ( *(_BYTE *)(a1 + 49) )
    PnpSetDeviceRemovalSafe(*(_DWORD *)(a1 + 28));
  ObfDereferenceObject(*(_DWORD *)(a1 + 28));
  return ExFreePoolWithTag(a1);
}
