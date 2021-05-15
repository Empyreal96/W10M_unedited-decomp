// sub_7D40AC 
 
void sub_7D40AC()
{
  int v0; // r5
  int v1; // r9

  MiLockVad(v1 & 0xFFFFFFC0, v0);
  MiUnlockAndDereferenceVad(v0);
  JUMPOUT(0x6D4DF4);
}
