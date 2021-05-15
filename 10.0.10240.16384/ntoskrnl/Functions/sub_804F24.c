// sub_804F24 
 
void sub_804F24()
{
  int v0; // r5

  *(_DWORD *)(v0 + 36) = CmpLockTableAdd(v0, 1);
  JUMPOUT(0x74E6FC);
}
