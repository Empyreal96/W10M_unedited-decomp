// sub_7EB064 
 
void __fastcall sub_7EB064(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  unsigned int *v10; // r4
  unsigned int v11; // r5
  int v12; // r6
  unsigned int v13; // r0
  unsigned int v14; // r1

  while ( 1 )
  {
    v13 = v11;
    __dmb(0xBu);
    do
      v14 = __ldrex(v10);
    while ( v14 == v11 && __strex(v11 & 0xCFFFFFFF | (v12 << 28), v10) );
    v11 = v14;
    __dmb(0xBu);
    if ( v14 == v13 )
      __asm { POP.W           {R3-R6,R11,PC} }
  }
}
