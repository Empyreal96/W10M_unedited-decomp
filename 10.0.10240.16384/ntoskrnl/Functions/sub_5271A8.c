// sub_5271A8 
 
void sub_5271A8()
{
  int v0; // r4
  _DWORD *v1; // r6

  if ( v0 )
    __enable_irq();
  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v1 );
  __disable_irq();
  JUMPOUT(0x462E14);
}
