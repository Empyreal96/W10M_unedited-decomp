// BiGetElement 
 
int __fastcall BiGetElement(int a1, int a2, int *a3, _DWORD *a4)
{
  int v8; // r5
  int v9; // r6

  *a3 = 0;
  *a4 = 0;
  v8 = 0;
  v9 = BcdGetElementDataWithFlags(a1, a2);
  if ( v9 == -1073741789 )
  {
    v8 = ExAllocatePoolWithTag(1, 0, 1262764866);
    if ( !v8 )
      return -1073741670;
    v9 = BcdGetElementDataWithFlags(a1, a2);
    if ( v9 < 0 )
      goto LABEL_7;
    *a3 = v8;
    *a4 = 0;
  }
  if ( v9 >= 0 )
    return v9;
LABEL_7:
  if ( !v8 )
    return v9;
  return sub_813824();
}
