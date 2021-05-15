// MiInitializeModifiedWriterParameters 
 
int __fastcall MiInitializeModifiedWriterParameters(int result, int a2)
{
  int v2; // r3

  v2 = dword_681270;
  if ( (unsigned int)dword_681270 > 0x40 )
  {
    v2 = 64;
  }
  else if ( !dword_681270 )
  {
    v2 = 1;
  }
  dword_681270 = v2 << 8;
  if ( (dword_681260 & 0xFFFFFFFE) != 0 )
    result = sub_96A0C8(result, a2, &MmRegistryState, dword_681260 & 0xFFFFFFFE);
  return result;
}
