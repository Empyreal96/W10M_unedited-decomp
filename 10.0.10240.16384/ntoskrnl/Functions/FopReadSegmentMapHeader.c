// FopReadSegmentMapHeader 
 
int __fastcall FopReadSegmentMapHeader(_DWORD *a1, int a2, unsigned __int16 *a3)
{
  int result; // r0
  unsigned int v5; // r3

  result = FioFwReadBytesAtOffset(a1, a2, 0xEu, (int)a3);
  if ( result >= 0 )
  {
    v5 = __rev16(*a3);
    *a3 = v5;
    if ( v5 == 4 )
    {
      result = 0;
      a3[1] = __rev16(a3[1]);
      a3[2] = __rev16(a3[2]);
      a3[3] = __rev16(a3[3]);
      a3[4] = __rev16(a3[4]);
      a3[5] = __rev16(a3[5]);
      a3[6] = __rev16(a3[6]);
    }
    else
    {
      result = -1073741701;
    }
  }
  return result;
}
