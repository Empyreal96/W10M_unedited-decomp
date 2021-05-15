// sub_542A78 
 
void __fastcall sub_542A78(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  int v6; // r8

  if ( a4 != 24 )
    KeBugCheckEx(26, 20736, v4, v6 - v5, a2);
  JUMPOUT(0x4B56E4);
}
