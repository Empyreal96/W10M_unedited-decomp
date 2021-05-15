// ProbeForWrite 
 
unsigned int __fastcall ProbeForWrite(unsigned int result, int a2, int a3)
{
  unsigned int v3; // r2
  unsigned int v4; // r2

  if ( a2 )
  {
    if ( ((a3 - 1) & result) != 0 )
      sub_7E6284();
    v3 = result + a2 - 1;
    if ( result > v3 || v3 >= MmUserProbeAddress )
      ExRaiseAccessViolation();
    v4 = (v3 & 0xFFFFF000) + 4096;
    do
    {
      *(_BYTE *)result = *(_BYTE *)result;
      result = (result & 0xFFFFF000) + 4096;
    }
    while ( result != v4 );
  }
  return result;
}
