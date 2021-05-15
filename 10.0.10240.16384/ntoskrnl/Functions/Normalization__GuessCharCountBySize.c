// Normalization__GuessCharCountBySize 
 
int __fastcall Normalization__GuessCharCountBySize(int a1, int a2)
{
  int result; // r0

  result = a2 + (a2 >> 3);
  if ( result < 64 )
  {
    result = *(_DWORD *)(a1 + 12) * a2;
    if ( result > 64 )
      result = 64;
  }
  return result;
}
