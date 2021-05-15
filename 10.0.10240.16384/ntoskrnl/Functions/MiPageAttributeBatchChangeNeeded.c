// MiPageAttributeBatchChangeNeeded 
 
int __fastcall MiPageAttributeBatchChangeNeeded(int a1, int a2)
{
  int v2; // r3
  int v4; // r2
  char v5; // r3
  unsigned int v6; // r3

  v2 = *(unsigned __int8 *)(a1 + 18) >> 6;
  if ( v2 != a2 )
  {
    if ( a2 != 1 )
      return 1;
    if ( v2 != 3 )
    {
      v4 = (*(_DWORD *)(a1 + 12) >> 20) & 0xF;
      __dmb(0xFu);
      v5 = KiTbFlushTimeStamp;
      __dmb(0xBu);
      v6 = (v5 - (_BYTE)v4) & 0xF;
      if ( v6 <= 2 && ((v4 & 1) != 0 || v6 < 2) )
        return 1;
    }
    MiChangePageAttribute(a1, 1, 4);
  }
  return 0;
}
