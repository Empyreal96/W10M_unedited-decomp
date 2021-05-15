// CmpValueToData 
 
int __fastcall CmpValueToData(int a1, int a2, int a3, unsigned int *a4, int a5)
{
  int result; // r0
  char v6[4]; // [sp+10h] [bp-18h] BYREF
  int v7[5]; // [sp+14h] [bp-14h] BYREF

  if ( !CmpGetValueData(a1, a2, a3, a4, v7, v6, a5) )
    return 0;
  result = v7[0];
  if ( v6[0] == 1 )
    sub_80C04C(v7[0]);
  return result;
}
