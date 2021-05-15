// sub_5237F8 
 
void sub_5237F8()
{
  int v0; // r4
  _DWORD *v1; // r5

  if ( v0 )
    __enable_irq();
  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v1 );
  __disable_irq();
  JUMPOUT(0x45A70C);
}
