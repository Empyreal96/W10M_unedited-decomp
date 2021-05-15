// sub_96E4A4 
 
void __fastcall sub_96E4A4(int a1, unsigned int a2)
{
  int v2; // r4
  int v3; // r5

  if ( a2 != 1 )
    ExfWaitForRundownProtectionRelease((unsigned int *)(v2 + v3), a2);
  JUMPOUT(0x9601EA);
}
