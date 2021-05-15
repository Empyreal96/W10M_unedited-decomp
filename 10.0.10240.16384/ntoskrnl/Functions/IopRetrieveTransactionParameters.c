// IopRetrieveTransactionParameters 
 
int __fastcall IopRetrieveTransactionParameters(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // r4
  int v6; // [sp+18h] [bp-28h]
  int v7; // [sp+1Ch] [bp-24h]
  int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  v7 = a1;
  varg_r0 = a1;
  result = TmCurrentTransaction();
  v5 = result;
  if ( result == -1073741637 )
    return 0;
  if ( result < 0 )
  {
    v6 = result;
    return result;
  }
  return v5;
}
