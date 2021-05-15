// sub_51C208 
 
void __fastcall sub_51C208(int a1, unsigned int *a2)
{
  unsigned int v2; // r2

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *a2 );
  __dmb(0xBu);
  do
    v2 = __ldrex(a2);
  while ( !v2 && __strex(5u, a2) );
  JUMPOUT(0x4467E6);
}
