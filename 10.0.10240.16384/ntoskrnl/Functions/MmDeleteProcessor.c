// MmDeleteProcessor 
 
int __fastcall MmDeleteProcessor(int result)
{
  unsigned int v1; // r2
  int v2; // r4

  v1 = *(_DWORD *)(result + 3588);
  v2 = result;
  if ( v1 )
  {
    result = MiReleasePtes(&dword_634D58, ((v1 >> 10) & 0x3FFFFC) - 0x40000000, 0x10u);
    *(_DWORD *)(v2 + 3588) = 0;
  }
  return result;
}
