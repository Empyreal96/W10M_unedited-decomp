// SepGetScopedPolicySid 
 
unsigned __int8 *__fastcall SepGetScopedPolicySid(int a1)
{
  unsigned __int8 *v2; // r0
  unsigned int v4; // [sp+0h] [bp-8h] BYREF

  v4 = 0;
  while ( 1 )
  {
    v2 = RtlFindAceByType(a1, 19, &v4);
    if ( v2 )
    {
      if ( (v2[1] & 8) == 0 )
        break;
    }
    ++v4;
    if ( !v2 )
      return 0;
  }
  return v2 + 8;
}
