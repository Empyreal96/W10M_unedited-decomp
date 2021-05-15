// sub_50C608 
 
void sub_50C608()
{
  int v0; // r4
  int v1; // r5

  KiAcquireQueuedSpinLockInstrumented(v0, v1);
  JUMPOUT(0x47C436);
}
