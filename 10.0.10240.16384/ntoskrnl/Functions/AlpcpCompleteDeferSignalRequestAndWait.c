// AlpcpCompleteDeferSignalRequestAndWait 
 
int __fastcall AlpcpCompleteDeferSignalRequestAndWait(int a1, unsigned int a2, int a3, char a4, int *a5)
{
  char v5; // r4
  BOOL v8; // r4
  int v9; // r0
  __int16 v10; // r2
  int v11; // r4
  unsigned int v12; // r2

  v5 = *(_BYTE *)(a1 + 24);
  *(_BYTE *)(a1 + 24) = v5 & 0xFB;
  if ( (unsigned __int8)(v5 & 4) >> 2 )
    return AlpcpSignalAndWait(a1, a2, 16, a4);
  v8 = (*(_DWORD *)(a1 + 24) & 0x200000) != 0;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v9);
  v11 = KeWaitForSingleObject(a2, 16, a4, (_DWORD *)v8, a5);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 0x134);
  if ( AlpcpLogEnabled )
    return sub_7E7A90();
  return v11;
}
