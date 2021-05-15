// _wcslwr_s 
 
int __fastcall wcslwr_s(unsigned __int16 *a1, unsigned int a2)
{
  unsigned __int16 *v2; // r4
  int i; // r3
  unsigned int v5; // r3
  int v6; // t1

  v2 = a1;
  if ( !a1 )
    goto LABEL_2;
  if ( wcsnlen(a1, a2) >= a2 )
  {
    *v2 = 0;
LABEL_2:
    PopPoCoalescinCallback();
    return 22;
  }
  for ( i = *v2; i; i = v6 )
  {
    v5 = *v2;
    if ( v5 >= 0x41 && v5 <= 0x5A )
      *v2 = v5 + 32;
    v6 = v2[1];
    ++v2;
  }
  return 0;
}
