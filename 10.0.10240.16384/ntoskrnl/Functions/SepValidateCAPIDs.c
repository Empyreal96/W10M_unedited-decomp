// SepValidateCAPIDs 
 
int __fastcall SepValidateCAPIDs(int a1, int *a2)
{
  int *v2; // r6
  int v3; // r4
  int v4; // r5
  int v5; // t1
  int result; // r0

  v2 = a2;
  v3 = 0;
  while ( 1 )
  {
    v5 = *v2++;
    v4 = v5;
    if ( !v5 )
      break;
    if ( !RtlValidSid(v4, a2) )
      return -1073741704;
    if ( memcmp(v4 + 2, (unsigned int)&CAP_AUTHORITY, 6) )
      return -1073741692;
    ++v3;
    result = 0;
    if ( v3 )
      return result;
  }
  return -1073741811;
}
