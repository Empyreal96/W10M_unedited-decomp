// PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion 
 
int __fastcall PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion(_DWORD *a1)
{
  int v1; // r3
  int result; // r0

  v1 = __mrc(15, 0, 13, 0, 3);
  *a1 = *(_DWORD *)((v1 & 0xFFFFFFC0) + 0x36C);
  --*(_WORD *)((v1 & 0xFFFFFFC0) + 0x134);
  result = *(_DWORD *)((v1 & 0xFFFFFFC0) + 0x11C);
  __dmb(0xBu);
  return result;
}
