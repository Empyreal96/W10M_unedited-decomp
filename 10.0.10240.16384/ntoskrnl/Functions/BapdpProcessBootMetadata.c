// BapdpProcessBootMetadata 
 
int BapdpProcessBootMetadata()
{
  int result; // r0

  ExSoftRebootFlags = 0;
  ExBootLoaderMetadata = 0;
  if ( (dword_61A1F8 & 4) != 0 )
    result = sub_96D7B0();
  return result;
}
