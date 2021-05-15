// MxComputePfnPagesNeeded 
 
int __fastcall MxComputePfnPagesNeeded(int a1, int a2)
{
  return (((int)((((unsigned int)(24 * a2) >> 20) & 0xFFC) - (((unsigned int)(24 * a1) >> 20) & 0xFFC)) >> 2) + 1) << 10;
}
