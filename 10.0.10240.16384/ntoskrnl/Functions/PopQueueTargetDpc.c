// PopQueueTargetDpc 
 
int __fastcall PopQueueTargetDpc(int a1, int a2)
{
  int v2; // r4
  unsigned int v3; // r3
  __int16 v5; // [sp+8h] [bp-8h]

  v2 = *(_DWORD *)(a2 + 16);
  v3 = *(_DWORD *)(v2 + 4);
  if ( !v3 )
    return KeSetEvent(*(_DWORD *)(a2 + 12), 0, 0);
  v5 = __clz(__rbit(v3));
  *(_DWORD *)(v2 + 4) &= ~(1 << v5);
  *(_BYTE *)a1 = 19;
  *(_DWORD *)(a1 + 12) = PopExecuteProcessorCallback;
  *(_DWORD *)(a1 + 16) = a2;
  *(_BYTE *)(a1 + 1) = 3;
  *(_DWORD *)(a1 + 28) = 0;
  *(_WORD *)(a1 + 2) = v5 + 32;
  *(_DWORD *)(a1 + 8) = 0;
  return KiInsertQueueDpc(a1);
}
