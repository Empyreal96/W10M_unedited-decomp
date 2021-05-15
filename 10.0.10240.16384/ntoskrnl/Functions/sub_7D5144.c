// sub_7D5144 
 
void __fastcall sub_7D5144(unsigned int *a1)
{
  unsigned int v1; // r4
  unsigned int v2; // r7
  _BYTE **v3; // r8
  unsigned int v4; // r9
  int v5; // r6
  unsigned int v6; // r4

  v5 = RtlFindClearBitsAndSet(a1, v2, v1);
  if ( v5 != v1 )
  {
    RtlClearBits(*v3, v1, v2);
    if ( v5 != -1 )
      RtlClearBits(v3[1], v5, v2);
    v6 = RtlFindClearBits((unsigned int *)*v3, v2, v4);
    if ( v6 == -1 )
      JUMPOUT(0x6D7A0A);
    RtlSetBits(*v3, v6, v2);
    RtlSetBits(v3[1], v6, v2);
  }
  JUMPOUT(0x6D7A02);
}
