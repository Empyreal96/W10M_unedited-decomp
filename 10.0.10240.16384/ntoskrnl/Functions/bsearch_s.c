// bsearch_s 
 
unsigned int __fastcall bsearch_s(int a1, unsigned int a2, unsigned int a3, int a4, int (__fastcall *a5)(int), int a6)
{
  unsigned int v6; // r5
  unsigned int v8; // r8
  unsigned int v9; // r4
  unsigned int v11; // r6
  int v12; // r10
  unsigned int v13; // r3
  int v14; // r0

  v6 = a2;
  v8 = a2 + (a3 - 1) * a4;
  if ( (a2 || !a3) && a4 && a5 )
  {
    while ( 1 )
    {
      if ( v6 > v8 )
        return 0;
      v11 = a3 >> 1;
      if ( !(a3 >> 1) )
      {
        if ( a3 && !a5(a6) )
          return v6;
        return 0;
      }
      v12 = a3 & 1;
      if ( (a3 & 1) != 0 )
        v13 = a3 >> 1;
      else
        v13 = v11 - 1;
      v9 = v6 + v13 * a4;
      v14 = a5(a6);
      if ( !v14 )
        return v9;
      if ( v14 >= 0 )
        break;
      v8 = v9 - a4;
      if ( v12 )
LABEL_18:
        a3 = v11;
      else
        a3 = v11 - 1;
    }
    v6 = v9 + a4;
    goto LABEL_18;
  }
  PopPoCoalescinCallback();
  return 0;
}
