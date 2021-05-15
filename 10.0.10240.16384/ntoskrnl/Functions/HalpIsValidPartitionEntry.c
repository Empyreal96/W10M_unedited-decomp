// HalpIsValidPartitionEntry 
 
BOOL __fastcall HalpIsValidPartitionEntry(_BYTE *a1, unsigned __int64 a2, unsigned __int64 a3)
{
  BOOL result; // r0
  int v5; // r1

  result = 1;
  if ( a1[4] )
  {
    v5 = (unsigned __int8)a1[8]
       + (((unsigned __int8)a1[9] + (((unsigned __int8)a1[10] + ((unsigned __int8)a1[11] << 8)) << 8)) << 8);
    if ( (unsigned __int8)a1[12]
       + (((unsigned __int8)a1[13] + (((unsigned __int8)a1[14] + ((unsigned __int8)a1[15] << 8)) << 8)) << 8)
       + (unsigned __int64)(unsigned int)v5 > a3
      || (unsigned int)v5 > a2 )
    {
      result = 0;
    }
  }
  return result;
}
