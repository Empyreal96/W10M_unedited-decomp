// sub_804F44 
 
void __fastcall sub_804F44(int a1)
{
  CmpLockTableConvertSharedToExclusive(a1, *(_DWORD *)(a1 + 36));
  JUMPOUT(0x74E816);
}
