// ExSpinLockIsContended 
 
BOOL __fastcall ExSpinLockIsContended(_DWORD *a1)
{
  return (*a1 & 0x40000000) != 0;
}
