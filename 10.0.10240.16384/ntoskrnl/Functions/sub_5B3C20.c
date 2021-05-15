// sub_5B3C20 
 
int __fastcall sub_5B3C20(_WORD *a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4
  int v7; // r5

  v5 = 0;
  if ( !a2 )
    goto LABEL_7;
  v7 = a4 - (_DWORD)a1;
  do
  {
    if ( !a5 )
      break;
    if ( !*(_WORD *)((char *)a1 + v7) )
      break;
    *a1 = *(_WORD *)((char *)a1 + v7);
    --a2;
    ++a1;
    --a5;
  }
  while ( a2 );
  if ( !a2 )
  {
LABEL_7:
    v5 = -2147024774;
    --a1;
  }
  *a1 = 0;
  return v5;
}
