// MiUpdateAvailableEvents 
 
int __fastcall MiUpdateAvailableEvents(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int v5; // r5
  int v6; // r0
  int v8; // r0
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a1;
  v9[1] = a2;
  v9[2] = a3;
  v9[3] = a4;
  KeAcquireInStackQueuedSpinLock(a1 + 736, (unsigned int)v9);
  v5 = a1[928];
  v6 = a1[47];
  if ( v5 <= a1[747] )
    return sub_50EF0C(v6);
  KeResetEvent(v6);
  v8 = a1[48];
  if ( v5 <= a1[748] )
    KeResetEvent(v8);
  else
    KeSetEvent(v8, 0, 0);
  KeReleaseInStackQueuedSpinLock((int)v9);
  return v9[0];
}
