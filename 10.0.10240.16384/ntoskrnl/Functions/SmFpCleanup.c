// SmFpCleanup 
 
int __fastcall SmFpCleanup(int result)
{
  int v1; // r4

  v1 = 0;
  while ( !*(_DWORD *)(result + 4 * (v1 + 5)) )
  {
    if ( (unsigned int)++v1 >= 5 )
      return result;
  }
  return sub_5112C4();
}
