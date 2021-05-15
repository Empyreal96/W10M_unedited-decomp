// MmIsDriverVerifying 
 
BOOL __fastcall MmIsDriverVerifying(int a1)
{
  int v1; // r3

  v1 = *(_DWORD *)(a1 + 20);
  return v1 && (*(_DWORD *)(v1 + 52) & 0x2000000) != 0;
}
