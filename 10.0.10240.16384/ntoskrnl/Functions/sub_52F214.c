// sub_52F214 
 
void sub_52F214()
{
  KiAcquireSpinLockInstrumented((int)&KiTimer2CollectionLock);
  JUMPOUT(0x47FAAE);
}
