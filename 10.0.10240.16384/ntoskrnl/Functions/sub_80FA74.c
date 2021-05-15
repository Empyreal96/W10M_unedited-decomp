// sub_80FA74 
 
void sub_80FA74()
{
  int v0; // r5
  int v1; // r9
  __int64 v2; // r0

  HIDWORD(v2) = v1 + (v0 << 12) - 1;
  LODWORD(v2) = v1;
  MiFillGapAddresses(v2);
  JUMPOUT(0x79AAF6);
}
