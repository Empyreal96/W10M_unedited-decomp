// PiDqGrowPropertyArray 
 
int __fastcall PiDqGrowPropertyArray(int *a1, int a2, int a3)
{
  int v4; // r5
  int v5; // r0

  v4 = 0;
  v5 = ExAllocatePoolWithTag(1, 40 * a3, 1483763280);
  if ( !v5 )
    return -1073741670;
  if ( *a1 )
    return sub_7EE554();
  *a1 = v5;
  return v4;
}
