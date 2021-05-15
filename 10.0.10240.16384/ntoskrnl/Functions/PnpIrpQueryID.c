// PnpIrpQueryID 
 
int __fastcall PnpIrpQueryID(int a1, int a2, _DWORD *a3)
{
  int result; // r0
  int v7[14]; // [sp+8h] [bp-38h] BYREF

  *a3 = 0;
  memset(v7, 0, 40);
  LOWORD(v7[0]) = 4891;
  v7[2] = a2;
  result = IopSynchronousCall(a1, (int)v7, -1073741637, 0, a3);
  if ( result < 0 )
  {
    *a3 = 0;
  }
  else if ( !*a3 )
  {
    result = -1073741637;
  }
  return result;
}
