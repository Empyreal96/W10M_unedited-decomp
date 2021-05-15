// sub_50CDF8 
 
void sub_50CDF8()
{
  unsigned int v0; // r6

  __dsb(0xFu);
  __mcr(15, 0, 0xFFu, 13, 0, 1);
  __isb(0xFu);
  __mcr(15, 0, v0, 2, 0, 0);
  __isb(0xFu);
  __dsb(0xFu);
  JUMPOUT(0x481FAA);
}
