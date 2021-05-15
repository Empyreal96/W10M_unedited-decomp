// sub_5119C8 
 
void sub_5119C8()
{
  int v0; // r6
  int v1; // r7
  int v2; // r8

  if ( (v1 & v0) == 0 )
  {
    KeReleaseQueuedSpinLock(5, v2);
    JUMPOUT(0x42AE06);
  }
  JUMPOUT(0x42AD80);
}
