// KeQueryNodeActiveAffinity 
 
unsigned int __fastcall KeQueryNodeActiveAffinity(unsigned int result, _DWORD *a2, _WORD *a3)
{
  int v4; // r2
  unsigned int v5; // r2
  int v6; // r1
  int v7; // r3

  if ( a2 )
  {
    *a2 = 0;
    a2[1] = 0;
    a2[2] = 0;
  }
  if ( a3 )
    *a3 = 0;
  if ( result < (unsigned __int16)KeNumberNodes )
  {
    v4 = (int)*(&KeNodeBlock + result);
    if ( a2 )
    {
      *((_WORD *)a2 + 2) = *(_WORD *)(v4 + 264);
      *a2 = *(_DWORD *)(v4 + 260);
    }
    if ( a3 )
    {
      v5 = ~*(_DWORD *)(v4 + 260);
      v6 = *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)v5);
      v5 >>= 8;
      v7 = *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)v5);
      result = v7 + v6;
      *a3 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + BYTE1(v5))
                            + *((_BYTE *)RtlpBitsClearTotal + HIWORD(v5))
                            + v7
                            + v6);
    }
  }
  return result;
}
