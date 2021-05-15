// sub_44CE2C 
 
int __fastcall sub_44CE2C(int *a1, int a2, _DWORD *a3)
{
  int v4; // r4
  int v7; // r0
  int result; // r0
  int v9; // r3

  v4 = *a1;
  if ( !*a1 )
    return 0;
  while ( 1 )
  {
    v7 = ((int (__fastcall *)(int *, int, int))a1[6])(a1, a2, v4 + 24);
    if ( v7 )
      break;
    v9 = *(_DWORD *)(v4 + 4);
    if ( !v9 )
    {
      result = 2;
      goto LABEL_5;
    }
LABEL_7:
    v4 = v9;
  }
  if ( v7 != 1 )
  {
    result = 1;
    goto LABEL_5;
  }
  v9 = *(_DWORD *)(v4 + 8);
  if ( v9 )
    goto LABEL_7;
  result = 3;
LABEL_5:
  *a3 = v4;
  return result;
}
