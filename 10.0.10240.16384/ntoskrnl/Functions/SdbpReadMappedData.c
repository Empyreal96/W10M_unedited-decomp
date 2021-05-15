// SdbpReadMappedData 
 
int __fastcall SdbpReadMappedData(int a1, int a2, int a3, unsigned int a4)
{
  int result; // r0

  if ( a2 + a4 < a4 )
  {
    AslLogCallPrintf(
      1,
      "SdbpReadMappedData",
      405,
      "Offset and region size add up to cause an integer overflow or underflow",
      a1,
      a2,
      a3,
      a4);
    result = 0;
  }
  else if ( *(_DWORD *)(a1 + 12) >= a2 + a4 )
  {
    memmove(a3, a2 + *(_DWORD *)(a1 + 4), a4);
    result = 1;
  }
  else
  {
    result = sub_7CCCC0();
  }
  return result;
}
