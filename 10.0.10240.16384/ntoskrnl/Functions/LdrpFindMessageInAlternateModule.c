// LdrpFindMessageInAlternateModule 
 
int __fastcall LdrpFindMessageInAlternateModule(int a1, int *a2, int a3, int *a4, char a5)
{
  int result; // r0
  _DWORD *v7; // r1
  int v8; // r2
  int v9; // t1
  int *v10; // [sp+0h] [bp-10h]

  v10 = a4;
  if ( !a1 || !a2 )
    return -1073741811;
  if ( !a5 )
  {
    result = LdrpAccessResourceDataNoMultipleLanguage();
    if ( result < 0 )
      return result;
    a2 = v10;
  }
  v9 = *a2;
  v7 = a2 + 1;
  v8 = v9;
  if ( a5 )
    return sub_54DC2C();
  while ( 1 )
  {
    if ( !v8 )
      return -1073741559;
    --v8;
    if ( (unsigned int)a4 >= *v7 && (unsigned int)a4 <= v7[1] )
      break;
    v7 += 3;
  }
  return 0;
}
