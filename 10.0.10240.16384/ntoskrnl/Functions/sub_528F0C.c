// sub_528F0C 
 
void sub_528F0C()
{
  int v0; // r4
  int v1; // r5

  if ( (unsigned int)(v1 + 1) >= 8 )
  {
    RtlpSysVolFree(v0);
    JUMPOUT(0x4E11DA);
  }
  JUMPOUT(0x4E11A8);
}
