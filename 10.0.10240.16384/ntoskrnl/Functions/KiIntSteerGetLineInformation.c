// KiIntSteerGetLineInformation 
 
int __fastcall KiIntSteerGetLineInformation(int *a1, int *a2, bool *a3, int a4)
{
  int v5; // r0
  int result; // r0
  BOOL v9; // r3
  bool v10; // r4
  int v11; // r3
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a4;
  v5 = *a1;
  v12[0] = -1;
  if ( v5 )
    return sub_51FB04();
  v12[0] = a1[12];
  v9 = off_617A68() == 0;
  v10 = v9;
  if ( v9 )
  {
    v11 = v12[0];
    result = 0;
  }
  else
  {
    result = off_617A5C(a1, v12);
    v11 = v12[0];
  }
  *a2 = v11;
  *a3 = v10;
  return result;
}
