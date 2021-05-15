// sub_553898 
 
void __fastcall sub_553898(int a1, int a2)
{
  int v2; // r5
  int v3; // r0

  v3 = *(unsigned __int16 *)(a2 + 4);
  if ( v3 != 4096 && v3 != 5120 )
  {
    if ( RtlLCIDToCultureName(v3, v2) )
      JUMPOUT(0x4F4250);
  }
  JUMPOUT(0x4F4256);
}
