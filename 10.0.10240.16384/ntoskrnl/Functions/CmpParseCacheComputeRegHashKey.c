// CmpParseCacheComputeRegHashKey 
 
unsigned int __fastcall CmpParseCacheComputeRegHashKey(unsigned __int16 *a1)
{
  unsigned int v1; // r7
  unsigned __int16 *v2; // r6
  unsigned int v3; // r4
  unsigned int v4; // r5
  unsigned int v5; // r0
  unsigned int v6; // t1

  v1 = *a1;
  v2 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v3 = 0;
  if ( *a1 )
  {
    LOWORD(v4) = 0;
    do
    {
      v6 = *v2++;
      v5 = v6;
      if ( v6 != 92 )
      {
        if ( v5 >= 0x61 )
        {
          if ( v5 > 0x7A )
            v5 = RtlUpcaseUnicodeChar(v5);
          else
            v5 -= 32;
        }
        v3 = 37 * v3 + v5;
      }
      v4 = (unsigned __int16)(v4 + 2);
    }
    while ( v4 < v1 );
  }
  return v3;
}
