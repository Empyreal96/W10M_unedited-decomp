// SeAccessCheckFromState 
 
int __fastcall SeAccessCheckFromState(int a1, int a2, int a3, int a4, int a5, int a6, int a7, char a8, int a9, int a10)
{
  int v14; // r0
  int result; // r0
  _DWORD v16[166]; // [sp+18h] [bp-550h] BYREF
  char v17; // [sp+2B0h] [bp-2B8h] BYREF
  char v18[663]; // [sp+2B1h] [bp-2B7h] BYREF

  v17 = 0;
  memset(v18, 0, sizeof(v18));
  LOBYTE(v16[0]) = 0;
  memset((_BYTE *)v16 + 1, 0, 663);
  v14 = SepTokenFromAccessInformation(a2, &v17);
  if ( a3 )
    result = sub_54B5E0(v14);
  else
    result = SeAccessCheckFromStateEx(a1, &v17, 0, a4, a5, a6, a7, a8, a9, a10, v16[0]);
  return result;
}
