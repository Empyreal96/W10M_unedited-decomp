// sub_53C3F4 
 
void sub_53C3F4()
{
  int v0; // r4
  int v1; // r8

  KeAcquireQueuedSpinLock(5);
  *(_DWORD *)(v0 + 96) &= ~v1;
  --*(_DWORD *)(v0 + 76);
  JUMPOUT(0x49FA64);
}
