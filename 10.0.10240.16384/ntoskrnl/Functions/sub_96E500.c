// sub_96E500 
 
void __fastcall sub_96E500(int a1, int a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  unsigned int *v10; // r0
  unsigned int v11; // r1
  _DWORD *v12; // r4
  int v13; // r5
  int v14; // r6
  unsigned int v15; // r3

  do
  {
    a3 >>= 1;
    ++a4;
  }
  while ( a3 );
  v12[10] = 0;
  v12[11] = v14;
  v12[8] = v14;
  v12[9] = a4;
  v15 = 4;
  do
  {
    v15 >>= 1;
    ++v13;
  }
  while ( v15 );
  v12[16] = 0;
  v12[17] = v14;
  v12[14] = v14;
  v12[15] = v13;
  v12[3] = v12 + 4;
  v12[20] = v14;
  v10 = v12 + 20;
  do
    v11 = __ldrex(v10);
  while ( !v11 && __strex(1u, v10) );
  __dmb(0xBu);
  if ( v11 != 1 && v11 )
    ExfWaitForRundownProtectionRelease(v10, v11);
  if ( (dword_6370C4 & 2) != 0 )
    PfpRpStart((int)v12);
  __asm { POP.W           {R3-R6,R11,PC} }
}
