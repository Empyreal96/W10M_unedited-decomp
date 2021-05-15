// _wcsnset_s 
 
int __fastcall wcsnset_s(unsigned __int16 *a1, int a2, unsigned __int16 a3, int a4)
{
  int v4; // r4
  int v7; // r3
  unsigned __int16 *v8; // r2
  int i; // r3
  int v10; // t1

  v4 = a4;
  if ( a4 )
  {
    if ( !a1 )
      goto LABEL_19;
  }
  else if ( !a1 )
  {
    if ( !a2 )
      return 0;
    goto LABEL_19;
  }
  if ( a2 )
  {
    v7 = *a1;
    v8 = a1;
    while ( v7 )
    {
      if ( !v4 )
        goto LABEL_13;
      if ( !--a2 )
        break;
      *v8++ = a3;
      v7 = *v8;
      --v4;
    }
    if ( v4 )
      goto LABEL_17;
LABEL_13:
    for ( i = *v8; i; i = v10 )
    {
      if ( !--a2 )
        break;
      v10 = v8[1];
      ++v8;
    }
LABEL_17:
    if ( a2 )
      return 0;
    *a1 = 0;
  }
LABEL_19:
  PopPoCoalescinCallback();
  return 22;
}
