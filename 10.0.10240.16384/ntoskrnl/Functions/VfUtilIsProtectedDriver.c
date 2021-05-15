// VfUtilIsProtectedDriver 
 
int __fastcall VfUtilIsProtectedDriver(unsigned __int16 *a1)
{
  unsigned __int16 *v1; // r5
  unsigned int v3; // r4

  v1 = (unsigned __int16 *)&VfProtectedDriverNames;
  v3 = 0;
  while ( !RtlEqualUnicodeString(v1, a1, 1) )
  {
    ++v3;
    v1 += 4;
    if ( v3 >= 0x12 )
      return 0;
  }
  return 1;
}
