// sub_528EB4 
 
void __fastcall sub_528EB4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, unsigned int a14)
{
  if ( a12 == 4 && a13 == 4 )
  {
    PopProcessorThrottleLogInterval = a14;
    if ( a14 > 0x2710 )
      PopProcessorThrottleLogInterval = 10000;
  }
  JUMPOUT(0x4E0FCC);
}
