// PnpRemoveDeviceActionRequests 
 
int __fastcall PnpRemoveDeviceActionRequests(int a1)
{
  int v2; // r9
  unsigned int v3; // r2
  int v4; // r5
  int *v5; // r6
  int **v6; // r2
  _DWORD *v7; // r2
  int v8; // r0
  int vars4; // [sp+24h] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PnpSpinLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&PnpSpinLock);
    while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
  }
  v4 = PnpEnumerationRequestList;
  if ( (int *)PnpEnumerationRequestList != &PnpEnumerationRequestList )
  {
    do
    {
      v5 = *(int **)v4;
      if ( *(_DWORD *)(v4 + 8) == a1 )
      {
        v6 = *(int ***)(v4 + 4);
        if ( v5[1] != v4 || *v6 != (int *)v4 )
          __fastfail(3u);
        *v6 = v5;
        v5[1] = (int)v6;
        v7 = *(_DWORD **)(v4 + 28);
        if ( v7 )
          *v7 = -1073741810;
        v8 = *(_DWORD *)(v4 + 24);
        if ( v8 )
          KeSetEvent(v8, 0, 0);
        ObfDereferenceObjectWithTag(*(_DWORD *)(v4 + 8));
        ExFreePoolWithTag(v4);
      }
      v4 = (int)v5;
    }
    while ( v5 != &PnpEnumerationRequestList );
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
  return KfLowerIrql(v2);
}
