// sub_53F048 
 
void __fastcall sub_53F048(int a1, int a2, int a3)
{
  if ( a3 >= 0 && a3 < 6 && *(_BYTE *)(a2 + 124 * a3) == 1 )
    JUMPOUT(0x4A7F32);
  JUMPOUT(0x4A7FA2);
}
