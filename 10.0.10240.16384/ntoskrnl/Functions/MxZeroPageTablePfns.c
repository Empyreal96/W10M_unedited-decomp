// MxZeroPageTablePfns 
 
_BYTE *__fastcall MxZeroPageTablePfns(_BYTE *result, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // r5
  unsigned int v6; // r6
  int v7; // [sp+0h] [bp-28h]

  v4 = (unsigned int)result;
  if ( (unsigned int)result <= a2 )
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)v4;
      if ( (*(_DWORD *)v4 & 2) != 0 )
      {
        v7 = MmPfnDatabase;
        result = memset(
                   (_BYTE *)(MmPfnDatabase + 24 * (*(_DWORD *)(((v4 >> 10) & 0x3FFFFC) - 0x40000000) >> 12)),
                   0,
                   24);
        if ( a3 != 1 || (v6 & 0x400) == 0 )
        {
          result = memset((_BYTE *)(v7 + 24 * (v6 >> 12)), 0, 24);
          if ( a3 > 1 && v4 != -1070593024 )
            break;
        }
      }
      v4 += 4;
      if ( v4 > a2 )
        return result;
    }
    result = (_BYTE *)sub_96B7F8(result);
  }
  return result;
}
