// IopTranslateBusAddress 
 
int __fastcall IopTranslateBusAddress(int a1, int a2, int a3, int a4, char *a5)
{
  int v6; // r6
  char v7; // r2
  int result; // r0
  int varg_r2; // [sp+28h] [bp+10h]

  varg_r2 = a3;
  if ( a3 == 3 || a3 == 7 )
  {
    v6 = 0;
  }
  else
  {
    if ( a3 != 1 )
      return -1073741811;
    v6 = 1;
  }
  if ( !HalTranslateBusAddress(1, 0, a1, a2) )
    return -1073741823;
  if ( v6 == 1 )
  {
    v7 = 1;
  }
  else if ( a3 == 7 )
  {
    v7 = 7;
  }
  else
  {
    v7 = 3;
  }
  result = 0;
  *a5 = v7;
  return result;
}
