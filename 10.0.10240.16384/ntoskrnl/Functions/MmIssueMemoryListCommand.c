// MmIssueMemoryListCommand 
 
int __fastcall MmIssueMemoryListCommand(int *a1, unsigned int a2, int a3, int a4)
{
  int v6; // r1
  int v7; // r4
  int *varg_r0; // [sp+18h] [bp+8h]
  int varg_r2; // [sp+20h] [bp+10h]

  varg_r0 = a1;
  varg_r2 = a3;
  a3 = (char)a3;
  LOBYTE(varg_r2) = a3;
  if ( a2 < 4 )
    return -1073741820;
  v6 = 6;
  v7 = *a1;
  if ( (unsigned int)*a1 > 5 )
    return -1073741811;
  if ( v7 == 3
    || SeSinglePrivilegeCheck(
         SeProfileSingleProcessPrivilege,
         dword_922B94,
         (char)a3,
         (int)&SeProfileSingleProcessPrivilege) )
  {
    return MmPerformMemoryListCommand(v7, v6, a3, (int)a1);
  }
  return -1073741727;
}
