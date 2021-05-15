// NtSetQuotaInformationFile 
 
int __fastcall NtSetQuotaInformationFile(int a1, int *a2, unsigned int a3, unsigned int a4)
{
  return IopSetEaOrQuotaInformationFile(a1, a2, a3, a4);
}
