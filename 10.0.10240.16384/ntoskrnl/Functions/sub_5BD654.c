// sub_5BD654 
 
int __fastcall sub_5BD654(int *a1, int a2, int a3)
{
  int result; // r0
  int v6; // r3
  int v7; // r2

  result = 1;
  switch ( a2 )
  {
    case 1:
      v6 = *(char *)a1;
      goto LABEL_10;
    case 2:
      v6 = *(__int16 *)a1;
LABEL_10:
      v7 = v6 >> 31;
      goto LABEL_11;
    case 4:
      *(_QWORD *)a3 = *a1;
      return result;
  }
  if ( a2 != 8 )
    return 0;
  v6 = *a1;
  v7 = a1[1];
LABEL_11:
  *(_DWORD *)a3 = v6;
  *(_DWORD *)(a3 + 4) = v7;
  return result;
}
