// MiTbFlushType 
 
int __fastcall MiTbFlushType(int a1)
{
  if ( (*(_BYTE *)(a1 + 112) & 7) == 0 )
    return 1;
  if ( (*(_BYTE *)(a1 + 112) & 7u) < 2 )
    return 2;
  return 0;
}
