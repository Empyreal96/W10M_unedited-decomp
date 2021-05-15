// sub_6E2544 
 
int __fastcall sub_6E2544(int *a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  v5 = 0;
  if ( !a1 )
    return -1073741811;
  v7[0] = *a1;
  sub_6E2418(v7);
  *a1 = v7[0];
  return v5;
}
