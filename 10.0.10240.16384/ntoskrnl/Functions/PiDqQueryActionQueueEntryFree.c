// PiDqQueryActionQueueEntryFree 
 
unsigned int __fastcall PiDqQueryActionQueueEntryFree(unsigned int a1)
{
  int v2; // r0
  unsigned int *v3; // r0

  v2 = *(_DWORD *)(a1 + 8);
  if ( v2 )
    PiDmObjectRelease(v2);
  v3 = *(unsigned int **)(a1 + 12);
  if ( v3 )
    PiPnpRtlObjectEventRelease(v3);
  return ExFreePoolWithTag(a1);
}
