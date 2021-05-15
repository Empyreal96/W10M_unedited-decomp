// PnprQuiesceWorker 
 
unsigned int __fastcall PnprQuiesceWorker(unsigned int a1)
{
  int v2; // r0
  int v3; // r3
  int v4; // r4
  unsigned int v6[2]; // [sp+10h] [bp-58h] BYREF
  int v7[20]; // [sp+18h] [bp-50h] BYREF

  v6[0] = PnprContext + 476;
  v6[1] = PnprContext + 508;
  if ( KeWaitForMultipleObjects(2u, v6, 1, 0, 0, 0, 0, 0) != 1 )
  {
    PnprLockPagesForReplace();
    v2 = PnprQuiesceDevices(v7);
    v3 = PnprContext;
    v4 = v2;
    *(_DWORD *)(PnprContext + 540) = v2;
    KeSetEvent(v3 + 492, 0, 0);
    if ( v4 >= 0 )
    {
      KeWaitForSingleObject(PnprContext + 508, 0, 0, 0, 0);
      PnprWakeDevices(v7);
    }
    PnprCompleteWake();
  }
  KeSetEvent(PnprContext + 524, 0, 0);
  return ExFreePoolWithTag(a1);
}
