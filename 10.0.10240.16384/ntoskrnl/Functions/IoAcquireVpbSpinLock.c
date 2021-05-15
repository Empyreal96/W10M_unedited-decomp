// IoAcquireVpbSpinLock 
 
int __fastcall IoAcquireVpbSpinLock(_BYTE *a1)
{
  int result; // r0

  result = KeAcquireQueuedSpinLock(9);
  *a1 = result;
  return result;
}
