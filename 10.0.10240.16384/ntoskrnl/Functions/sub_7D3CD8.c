// sub_7D3CD8 
 
void sub_7D3CD8()
{
  int v0; // r4
  int v1; // r6

  PsBoostThreadIo(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1);
  KeRemovePriorityBoost(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  *(_DWORD *)(v0 + 8) = v1;
  JUMPOUT(0x6D4306);
}
