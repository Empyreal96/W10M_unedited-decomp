// WheapGetAllPolicyValues 
 
int __fastcall WheapGetAllPolicyValues(_DWORD *a1, unsigned int a2, int a3)
{
  int result; // r0
  unsigned int i; // r4

  if ( a2 < 0x1C )
    return -1073741789;
  *a1 = 7;
  for ( i = 0; i < 7; ++i )
  {
    result = WheapGetPolicyValue(i, a3);
    if ( result < 0 )
      break;
    a3 += 4;
  }
  return result;
}
