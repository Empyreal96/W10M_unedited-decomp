// -StringCchCopyNW@@YAJPAGIPBGI@Z 
 
int __fastcall StringCchCopyNW(unsigned __int16 *a1, unsigned int a2, const unsigned __int16 *a3, unsigned int a4)
{
  int v4; // r5
  unsigned __int16 *v6; // r4
  unsigned int v7; // r2
  int v8; // r0

  v4 = 0;
  v6 = a1;
  if ( !a2 || a2 > 0x7FFFFFFF )
    v4 = -2147024809;
  if ( v4 < 0 )
  {
    if ( !a2 )
      return v4;
  }
  else if ( a4 > 0x7FFFFFFE )
  {
    v4 = -2147024809;
  }
  else
  {
    v4 = 0;
    if ( !a2 )
      goto LABEL_15;
    v7 = a4 - a2;
    v8 = (char *)a3 - (char *)a1;
    do
    {
      if ( !(v7 + a2) )
        break;
      if ( !*(unsigned __int16 *)((char *)v6 + v8) )
        break;
      *v6 = *(unsigned __int16 *)((char *)v6 + v8);
      ++v6;
      --a2;
    }
    while ( a2 );
    if ( !a2 )
    {
LABEL_15:
      v4 = -2147024774;
      --v6;
    }
  }
  *v6 = 0;
  return v4;
}
