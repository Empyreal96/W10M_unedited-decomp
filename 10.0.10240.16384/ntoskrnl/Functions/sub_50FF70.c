// sub_50FF70 
 
void __fastcall sub_50FF70(int a1, int a2, unsigned int *a3)
{
  unsigned int v3; // r1

  do
    v3 = __ldrex(a3);
  while ( __strex(v3 - 1, a3) );
  __dmb(0xBu);
  JUMPOUT(0x426544);
}
