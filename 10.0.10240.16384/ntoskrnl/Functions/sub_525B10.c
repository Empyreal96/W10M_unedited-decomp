// sub_525B10 
 
void __fastcall sub_525B10(_DWORD *a1)
{
  if ( !ExfAcquireRundownProtection(a1) )
    JUMPOUT(0x4600AE);
  JUMPOUT(0x4600A8);
}
