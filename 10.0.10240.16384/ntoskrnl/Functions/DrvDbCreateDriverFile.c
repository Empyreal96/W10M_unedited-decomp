// DrvDbCreateDriverFile 
 
int __fastcall DrvDbCreateDriverFile(int **a1, int a2, int a3, int a4, bool *a5)
{
  int result; // r0
  int v6; // [sp+10h] [bp-8h] BYREF

  v6 = 0;
  result = DrvDbOpenObjectRegKey(a1, 0, 4, a2, a3, 1, a4, &v6);
  if ( result >= 0 )
    *a5 = v6 == 1;
  return result;
}
