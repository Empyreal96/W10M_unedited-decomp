// AlpcpSignalAndWait 
 
int __fastcall AlpcpSignalAndWait(int a1, int a2, int a3, char a4)
{
  int v5; // r6
  unsigned int v8; // r0
  __int16 v9; // r2
  int v10; // r4
  unsigned int v11; // r3
  int v13; // r0

  v5 = a4;
  AlpcpSignal(a1, 1);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v8);
  v10 = KeWaitForSingleObject(a2, a3, v5);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v11 + 308);
  if ( AlpcpLogEnabled )
    return sub_52C654();
  v13 = *(_DWORD *)(a1 + 16);
  if ( v13 )
    ObfDereferenceObject(v13);
  return v10;
}
