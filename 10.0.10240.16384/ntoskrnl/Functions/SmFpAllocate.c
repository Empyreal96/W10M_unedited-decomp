// SmFpAllocate 
 
int __fastcall SmFpAllocate(int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v9; // r4
  int v10; // r0
  unsigned int v11; // r0

  if ( a2 >= 4 )
  {
    if ( (*(_WORD *)(a4 + 6) & 5) != 0 )
    {
      v9 = *(_DWORD *)(a4 + 12);
      goto LABEL_13;
    }
    v10 = MmMapLockedPagesSpecifyCache(a4, 0, 1, 0, 0, 1073741840);
LABEL_12:
    v9 = v10;
LABEL_13:
    if ( v9 )
      return v9;
    goto LABEL_14;
  }
  if ( a2 == 2 )
  {
    v10 = SmKmAllocateMdlForLock(*(unsigned __int16 *)(a1 + 52) << 12);
    goto LABEL_12;
  }
  if ( a2 != 3 )
  {
    v10 = ExAllocatePoolWithTag(512, *(unsigned __int16 *)(a1 + 2 * a2 + 48));
    goto LABEL_12;
  }
  if ( SmAcquireReleaseCharges(*(unsigned __int16 *)(a1 + 54) << 12, 1, 0) )
    return -8;
  v9 = 0;
LABEL_14:
  if ( a5 )
  {
    v11 = SmpFpWaitForResource(a1, a2, a3);
    v9 = v11;
    if ( a2 >= 4 )
      MmMapLockedPagesWithReservedMapping(v11, 1834118515, (_DWORD *)a4, 1);
  }
  return v9;
}
