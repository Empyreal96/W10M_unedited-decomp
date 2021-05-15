// sub_811D0C 
 
void __fastcall sub_811D0C(int a1, int a2, int a3, int a4, int a5, int a6, char a7)
{
  unsigned __int16 *v7; // r6
  int v8; // r8

  if ( CmIsDevicePresent(v8, v7, &a7) >= 0 )
  {
    if ( a7 )
      JUMPOUT(0x7A2764);
  }
  JUMPOUT(0x7A27AA);
}
