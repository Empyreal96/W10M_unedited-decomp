// MiTryLockLeafAndContainingPagesAtDpc 
 
int __fastcall MiTryLockLeafAndContainingPagesAtDpc(int a1, int *a2, int a3)
{
  int v6; // r4
  int v7; // r0

  *a2 = 0;
  v6 = MiTryLockProtoPoolPageAtDpc(a1, a3);
  if ( !v6 )
    return 0;
  v7 = MiTryLockLeafPage(a1, a3);
  if ( v7 )
    *a2 = v7;
  return v6;
}
