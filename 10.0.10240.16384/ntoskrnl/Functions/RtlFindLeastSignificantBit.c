// RtlFindLeastSignificantBit 
 
int __fastcall RtlFindLeastSignificantBit(unsigned __int64 a1)
{
  char v1; // r4

  if ( (_DWORD)a1 )
  {
    if ( (_WORD)a1 )
    {
      if ( (_BYTE)a1 )
        v1 = 0;
      else
        v1 = 8;
    }
    else if ( (a1 & 0xFF0000) != 0 )
    {
      v1 = 16;
    }
    else
    {
      v1 = 24;
    }
    return (char)(*((_BYTE *)RtlpBitsClearLow + (unsigned __int8)(a1 >> v1)) + v1);
  }
  if ( WORD2(a1) )
  {
    if ( BYTE4(a1) )
      v1 = 32;
    else
      v1 = 40;
    return (char)(*((_BYTE *)RtlpBitsClearLow + (unsigned __int8)(a1 >> v1)) + v1);
  }
  if ( (a1 & 0xFF000000000000i64) != 0 )
  {
    v1 = 48;
    return (char)(*((_BYTE *)RtlpBitsClearLow + (unsigned __int8)(a1 >> v1)) + v1);
  }
  if ( a1 )
  {
    v1 = 56;
    return (char)(*((_BYTE *)RtlpBitsClearLow + (unsigned __int8)(a1 >> v1)) + v1);
  }
  return -1;
}
