// sub_7E10E8 
 
void __fastcall sub_7E10E8(int a1)
{
  unsigned int v1; // r5
  _DWORD *v2; // r6
  int v3; // lr
  _DWORD *i; // r2
  int v5; // r3

  for ( i = v2; (unsigned int)i < v1; i += 10 )
  {
    if ( (int)i[9] < 0 || i[5] )
    {
      v5 = i[1];
      i[9] = a1;
      i[1] = v5 | v3;
    }
  }
  JUMPOUT(0x77870C);
}
