// MiMappingHasIoTracker 
 
BOOL __fastcall MiMappingHasIoTracker(unsigned int a1)
{
  int v1; // r3

  v1 = *(_DWORD *)(((a1 >> 20) & 0xFFC) - 1070596096);
  if ( (v1 & 0x400) == 0 )
    v1 = *(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  return (v1 & 0x100) != 0;
}
