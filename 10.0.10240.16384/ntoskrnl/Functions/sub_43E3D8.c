// sub_43E3D8 
 
int __fastcall sub_43E3D8(unsigned __int16 *a1, int a2, _DWORD *a3)
{
  int result; // r0
  int v5; // r5
  int v7; // r3

  result = 0;
  v5 = a2;
  if ( !a2 )
    goto LABEL_10;
  do
  {
    if ( !*a1++ )
      break;
    --a2;
  }
  while ( a2 );
  if ( !a2 )
LABEL_10:
    result = -1073741811;
  if ( a3 )
  {
    if ( result < 0 )
      v7 = 0;
    else
      v7 = v5 - a2;
    *a3 = v7;
  }
  return result;
}
