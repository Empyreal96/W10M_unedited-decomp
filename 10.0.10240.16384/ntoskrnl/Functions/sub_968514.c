// sub_968514 
 
void sub_968514()
{
  int v0; // r4
  int v1; // r5
  int v2; // [sp+20h] [bp-48h] BYREF

  CmpFreeDriverList(v1, &v2);
  CmpUnlockRegistry();
  ObfDereferenceObject(v0);
  NtClose();
  JUMPOUT(0x94F8CE);
}
