// MiRaisedIrqlFault 
 
int __fastcall MiRaisedIrqlFault(int a1, unsigned int a2, int a3, int **a4)
{
  unsigned int *v5; // r9
  int v10; // r1
  int *v11; // t1
  int v12; // r2
  unsigned int v13; // r4
  int v14; // r2

  v5 = (unsigned int *)(((a2 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( (a3 & 1) != 0 )
    return sub_514580();
  if ( KeInvalidAccessAllowed(a3) == 1 || MiTransientCombineAddress(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, a2) == 1 )
    return -1073741819;
  if ( a2 >= dword_63389C )
  {
    v10 = 0;
    do
    {
      v11 = *a4++;
      v12 = *v11;
      if ( (*v11 & 2) == 0 )
        return -805306362;
      ++v10;
    }
    while ( !v10 );
    if ( (v12 & 0x400) != 0 )
    {
      if ( (a1 & 1) != 0 && (v12 & 0x80) == 0 )
        KeBugCheckEx(190, a2, v12);
      MI_CHECK_KERNEL_NOEXECUTE_FAULT(a1, a2, a3, v12);
      return 0;
    }
    v13 = *v5;
    if ( (*v5 & 2) == 0 )
      return -805306362;
    if ( (a1 & 1) != 0 )
    {
      if ( (v13 & 0x100) != 0 )
        return -805306362;
      if ( (v13 & 0x80) == 0 )
        KeBugCheckEx(190, a2, v13);
    }
    MI_CHECK_KERNEL_NOEXECUTE_FAULT(a1, a2, a3, v13);
    v14 = MmPfnDatabase + 24 * (v13 >> 12);
    if ( *(unsigned __int16 *)(v14 + 16) > 1u || !*(_DWORD *)v14 || (*(_BYTE *)(v14 + 19) & 8) != 0 )
    {
      MiNoFaultFound(a1, v5, a2, 1, v13);
      return 0;
    }
    if ( (v13 & 0x10) != 0 && ((a1 & 1) == 0 || (v13 & 0x200) == 0) )
      return 0;
  }
  return -805306362;
}
