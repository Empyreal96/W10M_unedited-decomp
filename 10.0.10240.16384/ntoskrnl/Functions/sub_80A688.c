// sub_80A688 
 
void sub_80A688()
{
  _DWORD *v0; // r4
  int v1; // r5

  ExfAcquirePushLockExclusiveEx(v0, v1, (unsigned int)v0);
  JUMPOUT(0x75FFC4);
}
