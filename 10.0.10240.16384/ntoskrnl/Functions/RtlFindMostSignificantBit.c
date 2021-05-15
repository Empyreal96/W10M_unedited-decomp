// RtlFindMostSignificantBit 
 
int __fastcall RtlFindMostSignificantBit(__int64 a1)
{
  char v2; // r5

  if ( HIDWORD(a1) )
    return sub_5426C0();
  if ( (a1 & 0xFFFF0000) != 0 )
  {
    if ( (a1 & 0xFF000000) != 0 )
      v2 = 24;
    else
      v2 = 16;
    return (char)(v2 - *((_BYTE *)RtlpBitsClearHigh + (unsigned __int8)((unsigned int)a1 >> v2)) + 7);
  }
  if ( (a1 & 0xFF00) != 0 )
  {
    v2 = 8;
    return (char)(v2 - *((_BYTE *)RtlpBitsClearHigh + (unsigned __int8)((unsigned int)a1 >> v2)) + 7);
  }
  if ( a1 )
  {
    v2 = 0;
    return (char)(v2 - *((_BYTE *)RtlpBitsClearHigh + (unsigned __int8)((unsigned int)a1 >> v2)) + 7);
  }
  return -1;
}
