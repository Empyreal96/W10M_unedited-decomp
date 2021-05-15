// MiGetStandbyRepurposed 
 
int __fastcall MiGetStandbyRepurposed(int a1, unsigned int a2)
{
  int result; // r0
  int v4; // r2
  unsigned int v5; // r1
  int v6; // r3

  result = 0;
  if ( a2 < 8 )
  {
    v4 = a1 + 4 * a2;
    v5 = 8 - a2;
    do
    {
      v6 = *(_DWORD *)(v4 + 2484);
      v4 += 4;
      result += v6;
      --v5;
    }
    while ( v5 );
  }
  return result;
}
