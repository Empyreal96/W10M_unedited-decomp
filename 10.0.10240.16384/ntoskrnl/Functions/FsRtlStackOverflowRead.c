// FsRtlStackOverflowRead 
 
int __fastcall FsRtlStackOverflowRead(int a1)
{
  int result; // r0

  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 1;
  (*(void (__fastcall **)(_DWORD, _DWORD))(a1 + 16))(*(_DWORD *)(a1 + 20), *(_DWORD *)(a1 + 24));
  if ( (int *)a1 == &StackOverflowFallback )
    result = KeSetEvent((int)&StackOverflowFallbackSerialEvent, 0, 0);
  else
    result = ExFreePoolWithTag(a1);
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 0;
  return result;
}
