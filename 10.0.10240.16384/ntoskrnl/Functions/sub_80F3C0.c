// sub_80F3C0 
 
void sub_80F3C0()
{
  int v0; // r4
  int v1; // r6
  int v2; // r7

  ExfAcquirePushLockExclusiveEx((_DWORD *)(v1 + v0), v2, v1 + v0);
  JUMPOUT(0x799F68);
}
