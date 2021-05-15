// sub_7E59D0 
 
void sub_7E59D0()
{
  int v0; // r6
  unsigned int v1; // r2

  if ( !v0 )
  {
    v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v1 + 308);
    JUMPOUT(0x6EFEA2);
  }
  JUMPOUT(0x6EFE66);
}
