// PoSetPowerRequestInternal 
 
int __fastcall PoSetPowerRequestInternal(int a1, unsigned int a2, int a3, int a4)
{
  BOOL v6; // r6
  int v8; // r1
  int v9; // r3
  int v10; // r3
  int v11; // r3
  int v12; // r4
  _DWORD v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = a1;
  v13[1] = a2;
  v13[2] = a3;
  v13[3] = a4;
  v6 = (unsigned int)KeGetCurrentIrql(a1) < 2;
  if ( a2 <= 4 && ((1 << a2) & *(_DWORD *)(a1 + 12)) != 0 )
  {
    if ( a2 == 3 )
      return sub_52981C();
    KeAcquireInStackQueuedSpinLock(&PopPowerRequestSpinLock, v13);
    v8 = a1 + 4 * a2;
    v9 = *(_DWORD *)(v8 + 24);
    if ( v9 == -1 )
    {
      v12 = -1073741675;
    }
    else
    {
      *(_DWORD *)(v8 + 24) = v9 + 1;
      if ( ((1 << a2) & *(_DWORD *)(a1 + 16)) != 0 || v9 )
      {
LABEL_11:
        PopDiagTracePowerRequestChange(a1, v8);
        v12 = 0;
        goto LABEL_12;
      }
      v10 = PopPowerRequestAttributes[2 * a2];
      if ( v10 != -1 )
      {
        v11 = v10 + 1;
        PopPowerRequestAttributes[2 * a2] = v11;
        if ( v11 == 1 || !a2 )
          PopQueuePowerRequestCallback(a1, a2, 1, !v6);
        goto LABEL_11;
      }
      v12 = -1073741675;
      *(_DWORD *)(v8 + 24) = 0;
    }
LABEL_12:
    KeReleaseInStackQueuedSpinLock(v13);
    if ( v6 )
    {
      if ( *(_BYTE *)(a1 + 57) )
        PopPowerRequestCallbackWorker(0);
    }
    return v12;
  }
  return -1073741637;
}
