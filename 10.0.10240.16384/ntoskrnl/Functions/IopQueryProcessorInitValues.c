// IopQueryProcessorInitValues 
 
int __fastcall IopQueryProcessorInitValues(int a1)
{
  int result; // r0
  int v3; // r3

  result = MmIsThisAnNtAsSystem();
  if ( result )
    return sub_81C03C();
  *(_WORD *)(a1 + 6) = 32;
  *(_WORD *)a1 = 32;
  *(_WORD *)(a1 + 4) = 64;
  *(_WORD *)(a1 + 8) = 128;
  *(_DWORD *)(a1 + 28) = 1536;
  *(_WORD *)(a1 + 2) = *(_WORD *)(a1 + 4);
  *(_DWORD *)(a1 + 28) >>= 5;
  *(_DWORD *)(a1 + 12) = 152;
  *(_DWORD *)(a1 + 16) = 40 * IopMediumIrpStackLocations + 112;
  v3 = IopLargeIrpStackLocations;
  *(_DWORD *)(a1 + 24) = 96;
  *(_DWORD *)(a1 + 20) = 40 * v3 + 112;
  return result;
}
