// MiIsPteProtectionCompatible 
 
BOOL __fastcall MiIsPteProtectionCompatible(char a1, int a2)
{
  int v2; // r2

  v2 = MmCompatibleProtectionMask[a1 & 7] | 0x700;
  return (v2 | a2) == v2;
}
