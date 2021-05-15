// CmpAllocate 
 
int __fastcall CmpAllocate(int a1, int a2, int a3)
{
  int v6; // r0
  int v7; // r4

  if ( !CmpClaimGlobalQuota(a1) )
    return 0;
  if ( a2 )
    v6 = 5;
  else
    v6 = 1;
  v7 = ExAllocatePoolWithTag(v6, a1, a3);
  if ( !v7 )
    return sub_805AD8();
  return v7;
}
