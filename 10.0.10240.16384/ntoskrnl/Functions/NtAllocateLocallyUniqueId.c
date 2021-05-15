// NtAllocateLocallyUniqueId 
 
int __fastcall NtAllocateLocallyUniqueId(unsigned int a1)
{
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a1 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a1 = *(_BYTE *)a1;
    *(_BYTE *)(a1 + 4) = *(_BYTE *)(a1 + 4);
  }
  ExAllocateLocallyUniqueId((int *)a1);
  return 0;
}
