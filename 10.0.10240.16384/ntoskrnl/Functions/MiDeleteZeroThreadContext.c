// MiDeleteZeroThreadContext 
 
int __fastcall MiDeleteZeroThreadContext(int a1, unsigned int *a2)
{
  MiReleasePtes(&dword_634D58, *a2, 0x400u);
  MiReleaseNonPagedResources(a1, 1024);
  return ExFreePoolWithTag(a2, 0);
}
