// sub_7C02A0 
 
void __fastcall sub_7C02A0(unsigned __int16 a1)
{
  __int16 *v1; // r4
  __int16 v2; // r2

  v2 = a1;
  if ( a1 < 0xC000u )
  {
    if ( !a1 )
      v2 = -16384;
    if ( v1 )
      *v1 = v2;
    JUMPOUT(0x6A64A6);
  }
  JUMPOUT(0x6A64A4);
}
