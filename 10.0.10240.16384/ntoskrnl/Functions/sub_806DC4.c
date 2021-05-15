// sub_806DC4 
 
void sub_806DC4()
{
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) == 1 )
    JUMPOUT(0x757AF0);
  JUMPOUT(0x757B08);
}
