// sub_903BF0 
 
void __fastcall sub_903BF0(int a1)
{
  int v1; // r4

  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v1 = 0;
  }
  else
  {
    __disable_irq();
    v1 = 1;
  }
  KiSweepIcacheTarget(a1);
  if ( v1 )
    __enable_irq();
  JUMPOUT(0x902776);
}
