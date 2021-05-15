// PpmWmiDispatch 
 
int __fastcall PpmWmiDispatch(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v7; // r1
  int result; // r0
  int v9; // [sp+4h] [bp-1Ch]

  v9 = a2;
  v7 = 0;
  switch ( a1 )
  {
    case 0:
      v7 = 1;
      goto LABEL_13;
    case 1:
LABEL_13:
      result = PpmWmiGetAllData(a5 - 176, a2, a3, a4, a6, v7, a3, a4);
      goto LABEL_10;
    case 4:
      return sub_8186E0(4, 0);
    case 5:
      JUMPOUT(0x8186E2);
  }
  if ( a1 != 8 )
  {
    result = -1073741808;
    *a6 = 0;
    return result;
  }
  result = PpmWmiRegisterInfo(*(_DWORD *)(a5 - 3100), 0, a3, a4, a6, v9, a3, a4);
LABEL_10:
  if ( result >= 0 )
    result = 0;
  return result;
}
