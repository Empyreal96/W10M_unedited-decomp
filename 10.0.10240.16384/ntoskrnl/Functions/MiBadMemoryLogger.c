// MiBadMemoryLogger 
 
int __fastcall MiBadMemoryLogger(_DWORD *a1)
{
  int result; // r0
  unsigned int *v3; // r2
  unsigned int v4; // r1

  result = IoAllocateGenericErrorLogEntry(0x30u);
  if ( result )
  {
    *(_DWORD *)(result + 12) = -1073740023;
    *(_DWORD *)(result + 16) = *a1;
    *(_DWORD *)(result + 32) = a1[4];
    *(_DWORD *)(result + 36) = a1[5];
    *(_DWORD *)(result + 40) = a1[2];
    *(_WORD *)(result + 2) = 4;
    result = IoWriteErrorLogEntry(result);
  }
  __dmb(0xBu);
  v3 = a1 + 1;
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 - 1, v3) );
  return result;
}
