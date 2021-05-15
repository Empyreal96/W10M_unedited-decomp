// IoAcquireCancelSpinLock 
 
int __fastcall IoAcquireCancelSpinLock(_BYTE *a1)
{
  int result; // r0

  result = KeAcquireQueuedSpinLock(7);
  *a1 = result;
  return result;
}
