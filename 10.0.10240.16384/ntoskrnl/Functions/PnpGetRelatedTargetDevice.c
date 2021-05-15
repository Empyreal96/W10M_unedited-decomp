// PnpGetRelatedTargetDevice 
 
int __fastcall PnpGetRelatedTargetDevice(int a1, _DWORD *a2)
{
  int v4; // r4
  int v5; // r6
  _BYTE *v6; // r0
  int v7; // r3
  int v8; // r3
  int v9; // r4
  int v10; // r5
  int v11; // r3
  int v13; // r2
  _DWORD *v14; // [sp+14h] [bp-4Ch] BYREF
  int v15[10]; // [sp+18h] [bp-48h] BYREF

  *a2 = 0;
  v4 = KeAcquireQueuedSpinLock(10);
  v5 = IoGetRelatedDeviceObject(a1);
  KeReleaseQueuedSpinLock(10, v4);
  if ( !v5 )
    return -1073741810;
  v6 = memset(v15, 0, sizeof(v15));
  LOWORD(v15[0]) = 1819;
  v15[2] = 4;
  v7 = *(_DWORD *)(v5 + 176);
  v15[6] = v5;
  v15[7] = a1;
  v8 = *(_DWORD *)(v7 + 20);
  if ( !v8 || (v13 = *(_DWORD *)(v8 + 420), v13 == -1) || v13 == -2 )
  {
    v9 = IopSynchronousCall(v5, v15, -1073741637, 0, &v14);
    if ( v9 < 0 )
      return v9;
    if ( v14 )
    {
      v10 = *v14 == 1 ? v14[1] : 0;
      ExFreePoolWithTag(v14, 0);
      if ( v10 )
      {
        v11 = *(_DWORD *)(*(_DWORD *)(v10 + 176) + 20);
        if ( v11 )
        {
          *a2 = v11;
          return v9;
        }
      }
    }
    return -1073741810;
  }
  return sub_529E24(v6);
}
