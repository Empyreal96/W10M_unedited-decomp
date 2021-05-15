// sub_540FE4 
 
void sub_540FE4()
{
  KiAcquireSpinLockInstrumented((int)&KiIntTrackSpinlock);
  JUMPOUT(0x4AE4A6);
}
