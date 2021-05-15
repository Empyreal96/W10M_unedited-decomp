// CmpFindKeyNameAtIndex 
 
int __fastcall CmpFindKeyNameAtIndex(int a1, int a2, unsigned int a3)
{
  int result; // r0

  if ( a3 >= 8 )
    result = a2 + 8 * (a3 + 4);
  else
    result = a1 + 8 * a3;
  return result;
}
