// MiQueueWorkingSetRequest 
 
int __fastcall MiQueueWorkingSetRequest(int result, int a2)
{
  unsigned int v2; // r4
  char v4[24]; // [sp+8h] [bp-18h] BYREF

  v2 = *(_DWORD *)(result + 3512);
  if ( v2 )
  {
    KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v4);
    if ( !*(_DWORD *)(v2 + 32) )
      KeResetEvent(v2);
    *(_DWORD *)(v2 + 32) |= a2;
    KeReleaseInStackQueuedSpinLock((int)v4);
    KeSetEvent(v2 + 72, 0, 0);
    result = KeWaitForSingleObject(v2, 18, 0, 0, 0);
  }
  return result;
}
