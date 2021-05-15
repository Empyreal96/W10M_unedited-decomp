// _vsnwprintf_s 
 
int __fastcall vsnwprintf_s(_WORD *a1, unsigned int a2, unsigned int a3, int a4)
{
  int v6; // r4
  int v7; // r0

  if ( !a4 )
    goto LABEL_17;
  if ( a3 )
  {
    if ( !a1 )
    {
LABEL_17:
      PopPoCoalescinCallback();
      return -1;
    }
  }
  else if ( !a1 )
  {
    if ( !a2 )
      return 0;
    goto LABEL_17;
  }
  if ( !a2 )
    goto LABEL_17;
  v6 = -1;
  if ( a2 > a3 )
  {
    v7 = swoutput_s();
    if ( v7 == -2 )
      return -1;
    goto LABEL_10;
  }
  v7 = swoutput_s();
  if ( v7 != -2 )
  {
LABEL_10:
    if ( v7 >= 0 )
      return v7;
    goto LABEL_11;
  }
  if ( a3 == -1 )
    return v6;
LABEL_11:
  *a1 = 0;
  if ( v7 == -2 )
    PopPoCoalescinCallback();
  return v6;
}
