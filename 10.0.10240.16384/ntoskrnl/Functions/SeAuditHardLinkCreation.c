// SeAuditHardLinkCreation 
 
int __fastcall SeAuditHardLinkCreation(int a1, int a2, int a3)
{
  return SeAuditHardLinkCreationWithTransaction(a1, a2, a3, 0);
}
