// ComputeNameLength 
 
int __fastcall ComputeNameLength(unsigned __int16 *a1)
{
  unsigned int v2; // r1
  unsigned int v3; // r2
  int result; // r0
  int v5; // r5
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r4

  v2 = *a1 - 1;
  if ( NlsMbCodePageTag )
  {
    v3 = 0;
    result = 1;
    if ( v2 )
    {
      v5 = *((_DWORD *)a1 + 1);
      do
      {
        v6 = *(char *)(v5 + v3);
        if ( NlsLeadByteInfoTable[(unsigned __int8)v6] )
        {
          v3 += 2;
        }
        else
        {
          if ( v6 == 92 )
            ++result;
          ++v3;
        }
      }
      while ( v3 < v2 );
    }
  }
  else
  {
    result = 1;
    v7 = 0;
    if ( v2 )
    {
      v8 = *((_DWORD *)a1 + 1);
      do
      {
        if ( *(_BYTE *)(v8 + v7) == 92 )
          ++result;
        ++v7;
      }
      while ( v7 < v2 );
    }
  }
  return result;
}
