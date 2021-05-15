// KeRemoveEntryDeviceQueue 
 
int __fastcall KeRemoveEntryDeviceQueue(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v5; // r5
  __int64 v6; // kr00_8
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[0] = a1;
  v8[1] = a2;
  v8[2] = a3;
  v8[3] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 12), (unsigned int)v8);
  v5 = a2[12];
  if ( v5 == 1 )
  {
    a2[12] = 0;
    v6 = *(_QWORD *)a2;
    if ( *(unsigned __int8 **)(*(_DWORD *)a2 + 4) != a2 || *(unsigned __int8 **)HIDWORD(v6) != a2 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v6) = v6;
    *(_DWORD *)(v6 + 4) = HIDWORD(v6);
  }
  KeReleaseInStackQueuedSpinLock((int)v8);
  return v5;
}
