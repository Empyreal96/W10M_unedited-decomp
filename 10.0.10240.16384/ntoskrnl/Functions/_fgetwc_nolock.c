// _fgetwc_nolock 
 
int __fastcall fgetwc_nolock(unsigned __int16 **a1)
{
  int v1; // r2
  int v2; // r3

  if ( a1 )
  {
    v2 = (int)(a1[1] - 1);
    a1[1] = (unsigned __int16 *)v2;
    if ( v2 < 0 )
      v1 = (unsigned __int16)filwbuf_s();
    else
      v1 = *(*a1)++;
  }
  else
  {
    PopPoCoalescinCallback();
    v1 = 0xFFFF;
  }
  return v1;
}
