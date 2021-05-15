// sub_53DDCC 
 
void __fastcall sub_53DDCC(__int64 a1)
{
  int v1; // r4

  HIDWORD(a1) = &CcVacbFreeHighPriorityList;
  CcSetVacbIntoList(a1);
  *(_DWORD *)(v1 + 4) = 0;
  JUMPOUT(0x4A504C);
}
