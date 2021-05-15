// MmMdlPageContentsState 
 
BOOL __fastcall MmMdlPageContentsState(int a1, int a2)
{
  __int16 v2; // r3
  __int16 v4; // r3

  v2 = *(_WORD *)(a1 + 6);
  if ( a2 == 2 )
    return (v2 & 0x4000) != 0;
  if ( a2 == 1 )
    v4 = v2 | 0x4000;
  else
    v4 = v2 & 0xBFFF;
  *(_WORD *)(a1 + 6) = v4;
  return a2;
}
