// PnpQueryID 
 
int __fastcall PnpQueryID(int a1, int a2, unsigned int *a3, int *a4)
{
  int v5; // r0
  int v9; // r4
  int v10; // r0
  bool v11; // zf

  v5 = *(_DWORD *)(a1 + 16);
  *a4 = 0;
  v9 = PnpIrpQueryID(v5, a2, a3);
  if ( v9 < 0 )
    goto LABEL_12;
  if ( !a2 )
  {
    v10 = PnpFixupID(*a3, 200, 0, 1, *(_DWORD *)(a1 + 8) + 28);
    goto LABEL_7;
  }
  if ( a2 > 0 )
  {
    if ( a2 <= 2 )
    {
      v10 = PnpFixupID(*a3, 1024, 1, -1, *(_DWORD *)(a1 + 8) + 28);
LABEL_7:
      *a4 = v10;
      goto LABEL_8;
    }
    if ( a2 == 3 )
    {
      v10 = PnpFixupID(*a3, 200, 0, 0, *(_DWORD *)(a1 + 8) + 28);
      goto LABEL_7;
    }
  }
  *a4 = 0;
LABEL_8:
  v11 = 2 * *a4 == 0;
  *a4 *= 2;
  if ( v11 )
    v9 = -1073479624;
  if ( v9 >= 0 )
    return v9;
LABEL_12:
  if ( v9 != -1073479624 && a2 && (a2 != 3 || v9 != -1073741670) )
  {
    if ( *a3 )
    {
      ExFreePoolWithTag(*a3);
      *a3 = 0;
      *a4 = 0;
    }
    return v9;
  }
  return sub_7CAC5C();
}
