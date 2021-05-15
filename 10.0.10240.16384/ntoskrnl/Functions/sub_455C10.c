// sub_455C10 
 
int __fastcall sub_455C10(_BYTE *a1, int a2, int a3, int a4, int a5)
{
  int v7; // r5

  if ( !a2 )
    return sub_50AB98(a1);
  v7 = a4 - (_DWORD)a1;
  do
  {
    if ( !a5 )
      break;
    if ( !a1[v7] )
      break;
    *a1 = a1[v7];
    --a2;
    ++a1;
    --a5;
  }
  while ( a2 );
  if ( !a2 )
    return sub_50AB98(a1);
  *a1 = 0;
  return 0;
}
