// sub_7C6FCC 
 
void __fastcall sub_7C6FCC(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  unsigned int v5; // r7

  if ( v4 && RtlValidRelativeSecurityDescriptor(v4, v5, 0, a4) )
  {
    RtlLengthSecurityDescriptor(v4);
    JUMPOUT(0x6CB3B2);
  }
  JUMPOUT(0x6CB3CE);
}
