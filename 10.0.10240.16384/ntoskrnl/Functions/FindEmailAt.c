// FindEmailAt 
 
int __fastcall FindEmailAt(int a1, int a2)
{
  int v2; // r2
  unsigned __int16 *v3; // r0
  int v4; // t1

  v2 = a2 - 1;
  v3 = (unsigned __int16 *)(a1 + 2 * a2 - 2);
  while ( v2 >= 0 )
  {
    v4 = *v3--;
    if ( v4 == 64 )
      return v2 + 1;
    --v2;
  }
  return a2;
}
