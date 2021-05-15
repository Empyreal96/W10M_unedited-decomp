// sub_5483A4 
 
void __fastcall sub_5483A4(unsigned int a1)
{
  int v1; // r4
  unsigned int v2; // r5
  _DWORD *v3; // r6
  int *v4; // r7
  int v5; // r1
  unsigned int i; // r2
  int v7; // t1

  v5 = 0;
  for ( i = 0; i < v2; v5 += v7 )
  {
    if ( i + v1 >= a1 )
      break;
    v7 = *v4++;
    ++i;
  }
  *v3 = v5;
  JUMPOUT(0x4C7B3C);
}
