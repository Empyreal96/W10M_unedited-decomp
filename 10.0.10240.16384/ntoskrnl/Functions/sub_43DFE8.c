// sub_43DFE8 
 
int __fastcall sub_43DFE8(_WORD *a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r2
  int v6; // r4

  v4 = 0;
  if ( a2 )
  {
    v5 = 2147483646;
    v6 = a4 - (_DWORD)a1;
    while ( v5 && *(_WORD *)((char *)a1 + v6) )
    {
      *a1 = *(_WORD *)((char *)a1 + v6);
      --a2;
      ++a1;
      --v5;
      if ( !a2 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    --a1;
    v4 = -2147483643;
  }
  *a1 = 0;
  return v4;
}
