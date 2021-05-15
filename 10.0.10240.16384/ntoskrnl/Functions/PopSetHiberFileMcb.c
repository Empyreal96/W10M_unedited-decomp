// PopSetHiberFileMcb 
 
int __fastcall PopSetHiberFileMcb(unsigned int a1, int a2)
{
  int v4; // r0

  if ( !a1 )
    return -1073741811;
  dword_61EEB4 = a2;
  v4 = ExAllocatePoolWithTag(512, a2, 1919052136);
  dword_61EEB0 = v4;
  if ( !v4 )
    return -1073741670;
  memmove(v4, a1, dword_61EEB4);
  ExFreePoolWithTag(a1);
  return 0;
}
