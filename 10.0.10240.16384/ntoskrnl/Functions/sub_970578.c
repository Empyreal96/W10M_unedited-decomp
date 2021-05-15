// sub_970578 
 
void __fastcall sub_970578(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  if ( a7 == 4 && a8 == 4 )
  {
    if ( a9 )
    {
      KeDynamicPartitioningSupported = 1;
      MEMORY[0xFFFF92F0] |= 0x20u;
    }
  }
  JUMPOUT(0x9643A2);
}
