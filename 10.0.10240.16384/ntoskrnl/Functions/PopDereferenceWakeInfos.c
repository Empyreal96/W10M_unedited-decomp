// PopDereferenceWakeInfos 
 
int __fastcall PopDereferenceWakeInfos(int a1, int *a2, int a3, int a4)
{
  int *v6; // r4
  int v7; // t1
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[1] = a3;
  v9[2] = a4;
  PopAcquireWakeSourceSpinLock((unsigned int)v9);
  if ( a1 )
  {
    v6 = a2;
    do
    {
      v7 = *v6++;
      PopWakeInfoDereference(v7);
      --a1;
    }
    while ( a1 );
  }
  PopWakeSourceLockOwner = 0;
  KeReleaseInStackQueuedSpinLock((int)v9);
  return ExFreePoolWithTag(a2);
}
