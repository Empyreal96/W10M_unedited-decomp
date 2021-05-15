// RtlpComputeScopeSize 
 
int __fastcall RtlpComputeScopeSize(unsigned __int8 *a1, unsigned int a2)
{
  int result; // r0
  unsigned int v4; // r4
  unsigned int v5; // r3

  result = 0;
  if ( (unsigned int)a1 < a2 )
  {
    while ( 1 )
    {
      v4 = *a1;
      if ( v4 >= 0xFD )
        break;
      v5 = *((unsigned __int8 *)dword_40A180 + v4);
      result += v5 >> 4;
      a1 += v5 & 0xF;
      if ( (unsigned int)a1 >= a2 )
        return result;
    }
    if ( *a1 != 255 )
      result = sub_5480A4(result);
  }
  return result;
}
