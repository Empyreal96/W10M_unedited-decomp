// sub_50A004 
 
void sub_50A004()
{
  int v0; // r4
  unsigned int v1; // r5

  MiRemovePteTracker(0, v0, v1 >> 12);
  JUMPOUT(0x430378);
}
