// sub_7BFC84 
 
void __fastcall sub_7BFC84(unsigned int *a1, unsigned int a2)
{
  if ( a2 != 1 )
    ExfWaitForRundownProtectionRelease(a1, a2);
  JUMPOUT(0x6A5444);
}
