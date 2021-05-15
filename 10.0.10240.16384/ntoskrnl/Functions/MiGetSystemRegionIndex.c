// MiGetSystemRegionIndex 
 
int __fastcall MiGetSystemRegionIndex(unsigned int a1)
{
  return (int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2;
}
