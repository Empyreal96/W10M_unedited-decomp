// sub_50A9B0 
 
void __fastcall sub_50A9B0(int a1, int a2)
{
  int *v2; // r7
  int v3; // r3

  __dmb(0xAu);
  __yield();
  v3 = *v2;
  __dmb(0xBu);
  if ( v3 - a2 >= 3 || v3 - a2 >= 2 && (a2 & a1) == 0 )
    JUMPOUT(0x447A8C);
  JUMPOUT(0x4479E6);
}
