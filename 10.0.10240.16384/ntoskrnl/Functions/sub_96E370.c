// sub_96E370 
 
void sub_96E370()
{
  char v0; // cf
  char v1; // zf
  int v2; // r4
  int v3; // r5
  int v4; // r7

  if ( !(!v1 & v0) )
    JUMPOUT(0x95F866);
  MiMarkLargeNonPagedPool(v2 << 10, v4 + (v2 << 10), v3 - 1);
  JUMPOUT(0x95F8A4);
}
