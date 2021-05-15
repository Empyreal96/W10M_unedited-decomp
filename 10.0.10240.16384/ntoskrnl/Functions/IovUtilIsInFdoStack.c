// IovUtilIsInFdoStack 
 
BOOL __fastcall IovUtilIsInFdoStack(int a1)
{
  int v2; // r2

  KeAcquireQueuedSpinLock(10);
  do
  {
    if ( IovUtilIsDeviceObjectMarked(a1, 1) )
      break;
    a1 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 24);
  }
  while ( a1 );
  KeReleaseQueuedSpinLock(10, v2);
  return a1 != 0;
}
