// sub_817128 
 
void __fastcall sub_817128(unsigned __int16 *a1)
{
  int v1; // r4
  int v2; // r6

  if ( PnpAllocatePWSTR(a1, 0x7FFFFFFFu, v2, (int *)(v1 + 24)) < 0 )
  {
    PnpFreeDevProperty(v1);
    memset((_BYTE *)v1, 0, 40);
    JUMPOUT(0x7ADFF2);
  }
  JUMPOUT(0x7ADFD4);
}
