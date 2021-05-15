// sub_5BD604 
 
int __fastcall sub_5BD604(int *a1, int a2, _DWORD *a3)
{
  int result; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r3

  result = 1;
  switch ( a2 )
  {
    case 1:
      v8 = *(unsigned __int8 *)a1;
      goto LABEL_10;
    case 2:
      v8 = *(unsigned __int16 *)a1;
      goto LABEL_10;
    case 4:
      v8 = *a1;
LABEL_10:
      *a3 = v8;
      a3[1] = 0;
      return result;
  }
  if ( a2 != 8 )
    return 0;
  v6 = *a1;
  v7 = a1[1];
  *a3 = v6;
  a3[1] = v7;
  return result;
}
