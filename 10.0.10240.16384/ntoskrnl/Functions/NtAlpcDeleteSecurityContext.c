// NtAlpcDeleteSecurityContext 
 
int __fastcall NtAlpcDeleteSecurityContext(int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int v4; // r1
  __int16 v5; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  if ( !a2 )
    return sub_7F7CBC();
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_WORD *)(v4 + 0x134) + 1;
  *(_WORD *)(v4 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return -1073741811;
}
