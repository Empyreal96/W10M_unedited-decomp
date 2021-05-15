// sub_7F55D8 
 
void __fastcall sub_7F55D8(_DWORD *a1)
{
  int v1; // r6

  if ( v1 )
  {
    MiWriteDemandZeroPte(a1);
    JUMPOUT(0x716276);
  }
  JUMPOUT(0x716280);
}
