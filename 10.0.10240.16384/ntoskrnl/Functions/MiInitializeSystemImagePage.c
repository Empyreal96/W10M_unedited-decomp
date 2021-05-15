// MiInitializeSystemImagePage 
 
unsigned int __fastcall MiInitializeSystemImagePage(int a1, int *a2, unsigned int a3)
{
  int v5; // r9
  int v6; // r2
  unsigned int result; // r0

  v5 = MmPfnDatabase;
  v6 = 32 * (a3 & 0x1F);
  if ( (unsigned int)a2 >= 0xC0000000 )
    return sub_969C08(a1);
  *a2 = v6;
  MiInitializePfn(v5 + 24 * a1, a2, a3, 0);
  result = (MmProtectToPteMask[a3] & 0x3ED | (a1 << 12) | MiDetermineUserGlobalPteMask((unsigned int)a2)) & 0xFFFFF3FF | 0x12;
  if ( (a3 & 4) != 0 )
    result &= 0xFFFFFDFF;
  return result;
}
