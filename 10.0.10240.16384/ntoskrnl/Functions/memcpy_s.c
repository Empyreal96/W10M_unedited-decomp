// memcpy_s 
 
int __fastcall memcpy_s(_BYTE *a1, unsigned int a2, int a3, unsigned int a4)
{
  int v7; // r4

  if ( !a4 )
    return 0;
  if ( !a1 )
  {
    PopPoCoalescinCallback();
    return 22;
  }
  if ( !a3 || a2 < a4 )
  {
    memset(a1, 0, a2);
    if ( a3 )
    {
      if ( a2 >= a4 )
        return 22;
      v7 = 34;
    }
    else
    {
      v7 = 22;
    }
    PopPoCoalescinCallback();
    return v7;
  }
  memmove((int)a1, a3, a4);
  return 0;
}
