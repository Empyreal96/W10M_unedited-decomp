// SepPotentialGlobalTableAttribute 
 
int __fastcall SepPotentialGlobalTableAttribute(int a1)
{
  __int16 *v1; // r4
  unsigned __int16 *v2; // r6
  unsigned int v3; // r5
  unsigned int v4; // r2

  v1 = &PotentialGlobalAttributePrefixes;
  v2 = (unsigned __int16 *)a1;
  v3 = 0;
  while ( 1 )
  {
    if ( (unsigned int)KeGetCurrentIrql(a1) >= 2 )
    {
      v4 = (unsigned __int16)*v1;
      a1 = v4 <= *v2 && memcmp(*((_DWORD *)v1 + 1), *((_DWORD *)v2 + 1), v4) == 0;
    }
    else
    {
      a1 = RtlPrefixUnicodeString(v1, v2, 1);
    }
    if ( a1 )
      break;
    ++v3;
    v1 += 4;
    if ( v3 >= 2 )
      return 0;
  }
  return 1;
}
