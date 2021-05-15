// sub_96C528 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_96C528(int a1, char a2, int a3, _BYTE *a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int *v13; // r3
  int v14; // r2
  int v15; // [sp-E4h] [bp-E4h] BYREF

  do
  {
    *a4++ = a2;
    --a3;
  }
  while ( a3 );
  v13 = &v15;
  v14 = 220;
  do
  {
    *(_BYTE *)v13 = a2;
    v13 = (int *)((char *)v13 + 1);
    --v14;
  }
  while ( v14 );
  ExpSecurityCookieRandomData = ExGenRandom(0);
  if ( !ExpSecurityCookieRandomData )
    ExpSecurityCookieRandomData = 1;
  __asm { POP.W           {R4-R11,PC} }
}
