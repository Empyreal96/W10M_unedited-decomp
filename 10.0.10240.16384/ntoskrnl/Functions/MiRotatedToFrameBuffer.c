// MiRotatedToFrameBuffer 
 
int __fastcall MiRotatedToFrameBuffer(unsigned int a1)
{
  unsigned int v2; // r3
  int v3; // r5

  v2 = *(_DWORD *)a1;
  if ( (*(_DWORD *)a1 & 2) == 0 )
    return 0;
  v3 = MmPfnDatabase + 24 * (v2 >> 12);
  if ( MI_IS_PFN(v2 >> 12) )
  {
    if ( (*(_DWORD *)(v3 + 4) | 0x80000000) != a1
      || (*(_DWORD *)(v3 + 20) & 0xFFFFF) != *(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000) >> 12 )
    {
      return sub_521C7C();
    }
    return 0;
  }
  return 1;
}
