// MiFreeWriteWatchView 
 
unsigned int __fastcall MiFreeWriteWatchView(int a1, int a2)
{
  unsigned int result; // r0
  unsigned int v4; // r4

  result = MiGetVadWakeList(a2, 4);
  v4 = result;
  if ( result )
  {
    PsReturnProcessNonPagedPoolQuota(
      a1,
      4 * (((*(_DWORD *)(result + 8) & 0x1F) != 0) + (*(_DWORD *)(result + 8) >> 5) + 6));
    result = ExFreePoolWithTag(v4);
  }
  return result;
}
