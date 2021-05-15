// sub_7FA448 
 
void __fastcall sub_7FA448(int a1)
{
  unsigned int **v1; // r9
  unsigned int *v2; // r4
  int v3; // r2
  unsigned int v4; // r0

  v2 = *v1;
  __dmb(0xBu);
  v3 = -a1;
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 + v3, v2) );
  JUMPOUT(0x729D9E);
}
