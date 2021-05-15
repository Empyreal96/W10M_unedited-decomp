// sub_7CD760 
 
void sub_7CD760()
{
  if ( (*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 192) & 0x10000) != 0 )
    JUMPOUT(0x77174C);
  JUMPOUT(0x7719A6);
}
