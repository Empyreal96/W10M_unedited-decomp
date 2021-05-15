// sub_54D4D4 
 
void __fastcall sub_54D4D4(int a1, unsigned int a2)
{
  unsigned int *v2; // r4

  if ( a2 )
    ExfWaitForRundownProtectionRelease(v2, a2);
  JUMPOUT(0x4E1924);
}
