// sub_7BDE88 
 
void __fastcall sub_7BDE88(int a1, int a2, int a3, unsigned __int8 *a4)
{
  unsigned int v4; // r1

  do
    v4 = __ldrex(a4);
  while ( __strex(v4 | 1, a4) );
  JUMPOUT(0x71FD84);
}
