// VmFlushTb 
 
int __fastcall VmFlushTb(int a1, int a2)
{
  int result; // r0

  result = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 800);
  if ( result )
    result = VmpFlushTb(result, a1, a2);
  return result;
}
