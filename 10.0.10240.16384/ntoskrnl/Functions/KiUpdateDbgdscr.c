// KiUpdateDbgdscr 
 
int __fastcall KiUpdateDbgdscr(int result)
{
  int v1; // r2
  unsigned int v2; // r3

  if ( KiCP14DebugEnabled )
  {
    v1 = __mrc(14, 0, 0, 2, 2);
    if ( result )
    {
      if ( (v1 & 0x8000) != 0 )
        return result;
      v2 = v1 | 0x8000;
    }
    else
    {
      if ( (v1 & 0x8000) == 0 )
        return result;
      v2 = v1 & 0xFFFF7FFF;
    }
    __mcr(14, 0, v2, 0, 2, 2);
    __dsb(0xFu);
  }
  return result;
}
