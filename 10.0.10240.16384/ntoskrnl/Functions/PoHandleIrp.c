// PoHandleIrp 
 
int __fastcall PoHandleIrp(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r8
  int v6; // r3
  int v7; // r4
  int v8; // r6
  int v9; // r2
  int v10; // r3
  BOOL v11; // r5
  _DWORD v13[10]; // [sp+0h] [bp-28h] BYREF

  v13[0] = a1;
  v13[1] = a2;
  v13[2] = a3;
  v13[3] = a4;
  v4 = *(_DWORD *)(a1 + 96);
  v6 = *(_DWORD *)(a1 + 40 * *(char *)(a1 + 34) + 108);
  v7 = *(_DWORD *)(v4 + 24);
  v8 = a1;
  v9 = *(_DWORD *)(v6 + 20);
  v11 = 1;
  if ( v9 )
  {
    a1 = PoDeviceReleaseIrp(a1, *(unsigned __int8 *)(v6 + 112), v9);
    v10 = *(_DWORD *)(v7 + 28);
    if ( (v10 & 0x8000) == 0 )
    {
      if ( (v10 & 0x2000) == 0 || (a1 = KeGetCurrentIrql(a1), a1 != 2) )
        v11 = 0;
    }
  }
  if ( !v11 || (*(_DWORD *)(v7 + 28) & 0x8000) != 0 )
    a1 = PoDeviceAcquireIrp(v8, *(unsigned __int8 *)(v4 + 1), v7);
  if ( !v11 )
    return v11;
  if ( (*(_DWORD *)(v7 + 28) & 0x8000) == 0 )
  {
    KeAcquireInStackQueuedSpinLock((unsigned int *)&PopIrpLock, (unsigned int)v13);
    PopIrpLockThread = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    PopDispatchQuerySetIrp(v8);
    PopIrpLockThread = 0;
    KeReleaseInStackQueuedSpinLock((int)v13);
    *a2 = 259;
    return v11;
  }
  return sub_54B0AC(a1);
}
