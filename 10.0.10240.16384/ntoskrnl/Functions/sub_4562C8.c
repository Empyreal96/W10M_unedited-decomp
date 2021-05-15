// sub_4562C8 
 
int __fastcall sub_4562C8(_WORD *a1, int a2, _DWORD *a3, int a4)
{
  int v4; // r5
  int v6; // r6
  int v7; // r7

  v4 = 0;
  if ( !a2 )
    return sub_50AC58();
  v6 = 2147483646;
  v7 = a4 - (_DWORD)a1;
  do
  {
    if ( !v6 )
      break;
    if ( !*(_WORD *)((char *)a1 + v7) )
      break;
    *a1 = *(_WORD *)((char *)a1 + v7);
    --a2;
    ++a1;
    --v6;
    ++v4;
  }
  while ( a2 );
  if ( !a2 )
    return sub_50AC58();
  *a1 = 0;
  if ( a3 )
    *a3 = v4;
  return 0;
}
