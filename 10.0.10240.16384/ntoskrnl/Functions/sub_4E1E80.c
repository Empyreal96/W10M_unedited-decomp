// sub_4E1E80 
 
int __fastcall sub_4E1E80(_BYTE *a1, int a2, _DWORD *a3, int a4)
{
  int v4; // r5
  int v6; // r6
  int v7; // r7

  v4 = 0;
  if ( !a2 )
    return sub_50EE74();
  v6 = 2147483646;
  v7 = a4 - (_DWORD)a1;
  do
  {
    if ( !v6 )
      break;
    if ( !a1[v7] )
      break;
    *a1 = a1[v7];
    --a2;
    ++a1;
    --v6;
    ++v4;
  }
  while ( a2 );
  if ( !a2 )
    return sub_50EE74();
  *a1 = 0;
  if ( a3 )
    *a3 = v4;
  return 0;
}
