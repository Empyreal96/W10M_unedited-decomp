// WmiVerifierTakeEventOwnership 
 
BOOL __fastcall WmiVerifierTakeEventOwnership(int a1)
{
  return (*(_DWORD *)(a1 + 44) & 0x20000) == 0;
}
