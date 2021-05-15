// sub_50CE50 
 
void sub_50CE50()
{
  _DWORD *v0; // r5

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *v0 );
  JUMPOUT(0x48226C);
}
