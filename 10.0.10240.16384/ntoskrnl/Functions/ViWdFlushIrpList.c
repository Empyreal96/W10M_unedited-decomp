// ViWdFlushIrpList 
 
__int64 ViWdFlushIrpList()
{
  __int64 result; // r0
  int i; // r2

  HIDWORD(result) = 0;
  for ( i = VfWdIrpListHead; (int *)i != &VfWdIrpListHead; i = *(_DWORD *)i )
  {
    __dmb(0xBu);
    *(_BYTE *)(i + 16) = 0;
  }
  VfWdIrpListHead = (int)&VfWdIrpListHead;
  dword_908F14 = (int)&VfWdIrpListHead;
  __dmb(0xBu);
  ViWdIrpListLength = 0;
  return result;
}
