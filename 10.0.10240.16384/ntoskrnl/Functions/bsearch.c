// bsearch 
 
unsigned int __fastcall bsearch(int a1, unsigned int a2, unsigned int a3, int a4, int (*a5)(void))
{
  unsigned int v5; // r6
  unsigned int v6; // r8
  unsigned int v8; // r4
  unsigned int v10; // r5
  int v11; // r10
  unsigned int v12; // r3
  int v13; // r0
  int v14; // [sp+8h] [bp-20h]

  v5 = a2;
  v6 = a2 + (a3 - 1) * a4;
  v14 = a1;
  if ( (a2 || !a3) && a4 && a5 )
  {
    while ( 1 )
    {
      if ( v5 > v6 )
        return 0;
      v10 = a3 >> 1;
      if ( !(a3 >> 1) )
      {
        if ( a3 && !((int (__fastcall *)(int, unsigned int))a5)(a1, v5) )
          return v5;
        return 0;
      }
      v11 = a3 & 1;
      if ( (a3 & 1) != 0 )
        v12 = a3 >> 1;
      else
        v12 = v10 - 1;
      v8 = v5 + v12 * a4;
      v13 = a5();
      if ( !v13 )
        return v8;
      if ( v13 < 0 )
      {
        v6 = v8 - a4;
        if ( !v11 )
        {
          a3 = v10 - 1;
          goto LABEL_19;
        }
      }
      else
      {
        v5 = v8 + a4;
      }
      a3 = v10;
LABEL_19:
      a1 = v14;
    }
  }
  PopPoCoalescinCallback();
  return 0;
}
