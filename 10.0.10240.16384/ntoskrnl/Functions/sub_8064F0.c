// sub_8064F0 
 
void sub_8064F0()
{
  unsigned int v0; // r4
  unsigned int v1; // r5
  int v2; // r0
  int v3; // t1

  v1 = v0 + 16;
  v2 = *(_DWORD *)(v0 + 16);
  if ( v2 )
  {
    do
    {
      CcUnpinData(v2);
      v3 = *(_DWORD *)(v1 + 4);
      v1 += 4;
      v2 = v3;
    }
    while ( v3 );
  }
  ExFreePoolWithTag(v0);
  JUMPOUT(0x7539D4);
}
