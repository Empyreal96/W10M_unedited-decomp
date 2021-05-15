// IopDeleteIoCompletionInternal 
 
int __fastcall IopDeleteIoCompletionInternal(int a1, int a2, int a3, int a4)
{
  int v6; // r1
  int result; // r0
  int v8; // r5
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a2;
  v9[1] = a3;
  v9[2] = a4;
  if ( a2 )
  {
    KeAcquireInStackQueuedSpinLock(a1 + 40, v9);
    *(_BYTE *)(a1 + 44) = 1;
    v6 = 0;
  }
  else
  {
    v6 = 1;
  }
  result = KeRundownQueueEx(a1, v6);
  v8 = result;
  if ( a2 )
    result = KeReleaseInStackQueuedSpinLock(v9);
  if ( v8 )
  {
    **(_DWORD **)(v8 + 4) = 0;
    result = IopFreeCompletionListPackets(v8, a1);
  }
  return result;
}
