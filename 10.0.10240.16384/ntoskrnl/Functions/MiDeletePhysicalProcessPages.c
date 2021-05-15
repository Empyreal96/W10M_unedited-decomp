// MiDeletePhysicalProcessPages 
 
int __fastcall MiDeletePhysicalProcessPages(int a1)
{
  unsigned int *v1; // r5
  int result; // r0

  v1 = *(unsigned int **)(a1 + 328);
  if ( *v1 )
  {
    PsReturnProcessNonPagedPoolQuota(
      a1,
      4 * ((((dword_633850 + 1) & 0x1F) != 0) + ((unsigned int)(dword_633850 + 1) >> 5) + 2));
    ExFreePoolWithTag(*v1);
  }
  result = MiFreeAweInfo(v1);
  *(_DWORD *)(a1 + 328) = 0;
  return result;
}
