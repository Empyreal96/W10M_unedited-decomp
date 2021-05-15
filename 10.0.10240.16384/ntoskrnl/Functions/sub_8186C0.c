// sub_8186C0 
 
void __fastcall sub_8186C0(unsigned int *a1, unsigned int a2)
{
  if ( a2 != 1 )
    ExfWaitForRundownProtectionRelease(a1, a2);
  JUMPOUT(0x7B2C1C);
}
