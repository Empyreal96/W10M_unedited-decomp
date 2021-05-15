// PpIrpQueryResourceRequirements 
 
int __fastcall PpIrpQueryResourceRequirements(int a1, _DWORD *a2)
{
  int result; // r0
  char v5[56]; // [sp+8h] [bp-38h] BYREF

  *a2 = 0;
  memset(v5, 0, 40);
  v5[0] = 27;
  v5[1] = 11;
  result = IopSynchronousCall(a1, (int)v5, -1073741637, 0, a2);
  if ( result < 0 )
  {
    *a2 = 0;
  }
  else if ( !*a2 )
  {
    result = -1073741637;
  }
  return result;
}
