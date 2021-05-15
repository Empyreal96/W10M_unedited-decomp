// ExQueryPoolBlockSize 
 
int __fastcall ExQueryPoolBlockSize(unsigned int a1, char *a2, int a3)
{
  int result; // r0
  char v6; // r3
  int v7; // r0
  _BYTE *v8; // r2

  if ( MmIsSpecialPoolAddress(a1, (int)a2, a3) )
  {
    *a2 = 0;
    result = MmQuerySpecialPoolBlockSize(a1);
  }
  else
  {
    if ( (a1 & 0xFFF) != 0 )
    {
      v7 = 8 * (*(_WORD *)(a1 - 6) & 0x1FF);
      if ( (*(_WORD *)(a1 - 6) & 0x1000) != 0
        && (v8 = (_BYTE *)(ExpPoolQuotaCookie ^ *(_DWORD *)(v7 + a1 - 8 - 4) ^ (a1 - 8))) != 0 )
      {
        if ( (unsigned int)v8 < MmSystemRangeStart || (*v8 & 0x7F) != 3 )
          KeBugCheckEx(194, 13, a1, *(_DWORD *)(a1 - 4), ExpPoolQuotaCookie ^ *(_DWORD *)(v7 + a1 - 8 - 4) ^ (a1 - 8));
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      result = v7 - 8;
    }
    else
    {
      v6 = 0;
      result = 4096;
    }
    *a2 = v6;
  }
  return result;
}
