// sub_7BDAB4 
 
void __fastcall sub_7BDAB4(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v5; // r3

  ExAcquireResourceExclusiveLite((int)&PiEngineLock, 1, a3, a4);
  ExAcquireResourceExclusiveLite((int)&IopDeviceTreeLock, 1, v4, v5);
  JUMPOUT(0x6CA2DA);
}
