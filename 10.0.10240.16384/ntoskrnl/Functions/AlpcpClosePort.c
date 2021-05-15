// AlpcpClosePort 
 
int __fastcall AlpcpClosePort(int result, int a2, int a3)
{
  int v4; // r3
  int v5; // r3
  unsigned int v6; // r1
  __int16 v7; // r3

  v4 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v4 & 0xFFFFFFC0) + 0x134);
  if ( a3 == 1 )
  {
    if ( (*(_DWORD *)(a2 + 152) & 0x100000) != 0 )
      goto LABEL_6;
    v5 = *(_DWORD *)(a2 + 12);
    if ( (v5 & 1) != 0 )
      v5 = 0;
    if ( v5 == result )
    {
LABEL_6:
      result = AlpcpDoPortCleanup(a2);
      if ( (*(_DWORD *)(a2 + 152) & 0x1000) == 0 )
        result = AlpcpSendCloseMessage(a2);
    }
  }
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
