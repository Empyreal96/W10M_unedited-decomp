// WmipCompleteGuidIrpWithError 
 
int __fastcall WmipCompleteGuidIrpWithError(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r4
  unsigned int *v6; // r2
  unsigned int v7; // r1
  int result; // r0
  _DWORD v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[1] = a3;
  v9[2] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&WmipCancelSpinLock, (unsigned int)v9);
  v5 = *(_DWORD **)(a1 + 48);
  if ( v5 )
  {
    WmipClearIrpObjectList(v5);
    __dmb(0xBu);
    v6 = v5 + 14;
    do
      v7 = __ldrex(v6);
    while ( __strex(0, v6) );
    __dmb(0xBu);
    if ( !v7 )
      v5 = 0;
  }
  result = KeReleaseInStackQueuedSpinLock((int)v9);
  if ( v5 )
  {
    v5[6] = -1073741816;
    result = pIofCompleteRequest(v5, 0);
  }
  return result;
}
