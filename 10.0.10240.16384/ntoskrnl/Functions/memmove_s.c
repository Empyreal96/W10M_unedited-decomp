// memmove_s 
 
int __fastcall memmove_s(int a1, unsigned int a2, int a3, unsigned int a4)
{
  int v4; // r4

  if ( !a4 )
    return 0;
  if ( a1 )
  {
    if ( !a3 )
    {
      v4 = 22;
LABEL_8:
      PopPoCoalescinCallback();
      return v4;
    }
    if ( a2 < a4 )
    {
      v4 = 34;
      goto LABEL_8;
    }
    memmove(a1, a3, a4);
    return 0;
  }
  PopPoCoalescinCallback();
  return 22;
}
