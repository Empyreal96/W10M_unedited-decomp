// RtlpValidateContextFlags 
 
int __fastcall RtlpValidateContextFlags(int a1, int *a2)
{
  int v3; // r4

  if ( (a1 & 0x10000) != 0 )
    return sub_547AC8();
  if ( ((a1 & 0x100000) == 0 || (a1 & 0x27EFFFA0) != 0)
    && ((a1 & 0x200000) == 0 || (a1 & 0x7DFFFF0) != 0)
    && ((a1 & 0x400000) == 0 || (a1 & 0x7BFFFF0) != 0) )
  {
    return -1073741811;
  }
  v3 = 1;
  if ( (a1 & 0x10040) == 65600 || (a1 & 0x100040) == 1048640 )
  {
    if ( !MEMORY[0xFFFF93D8] )
      return -1073741637;
    v3 = 3;
  }
  if ( a2 )
    *a2 = v3;
  return 0;
}
