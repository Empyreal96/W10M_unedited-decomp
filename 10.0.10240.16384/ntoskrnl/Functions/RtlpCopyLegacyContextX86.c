// RtlpCopyLegacyContextX86 
 
int __fastcall RtlpCopyLegacyContextX86(int result, _DWORD *a2, int a3, _DWORD *a4)
{
  result = (char)result;
  *a2 = a3 & 0x67FFFFFF;
  if ( (_BYTE)result )
  {
    if ( (a3 & 0x40000000) != 0 )
      *a2 = *a4 & 0x98000000 | a3 & 0x67FFFFFF;
    result = a3 & 0x10001;
    if ( (a3 & 0x10001) == 65537 )
    {
      result = a4[45];
      a2[45] = result;
      a2[46] = a4[46];
      a2[47] = a4[47];
      a2[48] = a4[48];
      a2[49] = a4[49];
      a2[50] = a4[50];
    }
    if ( (a3 & 0x10002) == 65538 )
    {
      a2[39] = a4[39];
      a2[40] = a4[40];
      a2[41] = a4[41];
      a2[43] = a4[43];
      a2[42] = a4[42];
      a2[44] = a4[44];
    }
    if ( (a3 & 0x10004) == 65540 )
    {
      a2[35] = a4[35];
      a2[36] = a4[36];
      a2[37] = a4[37];
      a2[38] = a4[38];
    }
    if ( (a3 & 0x10008) == 65544 )
      result = memmove((int)(a2 + 7), (int)(a4 + 7), 0x70u);
    if ( (a3 & 0x10010) == 65552 )
    {
      a2[1] = a4[1];
      a2[2] = a4[2];
      a2[3] = a4[3];
      a2[4] = a4[4];
      a2[5] = a4[5];
      a2[6] = a4[6];
    }
    if ( (a3 & 0x10020) == 65568 )
      result = memmove((int)(a2 + 51), (int)(a4 + 51), 0x200u);
  }
  return result;
}
