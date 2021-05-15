// sub_80468C 
 
void sub_80468C()
{
  _DWORD *v0; // r5
  _DWORD *v1; // r9

  CmpUnlockTwoKcbs(v0, v1);
  JUMPOUT(0x74C6C6);
}
