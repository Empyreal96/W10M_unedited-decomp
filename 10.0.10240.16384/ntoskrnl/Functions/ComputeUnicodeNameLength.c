// ComputeUnicodeNameLength 
 
int __fastcall ComputeUnicodeNameLength(unsigned __int16 *a1)
{
  int v2; // r3
  int result; // r0
  int v4; // r2
  unsigned __int16 *v5; // r1
  int v6; // t1

  v2 = *a1 >> 1;
  if ( !v2 )
    return 1;
  result = 1;
  v4 = v2 - 1;
  if ( v2 != 1 )
  {
    v5 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
    do
    {
      v6 = *v5++;
      if ( v6 == 92 )
        ++result;
      --v4;
    }
    while ( v4 );
  }
  return result;
}
