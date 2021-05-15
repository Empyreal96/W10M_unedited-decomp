// EtwpOpenConsumer 
 
int __fastcall EtwpOpenConsumer(_DWORD *a1)
{
  int v1; // r2

  v1 = __mrc(15, 0, 13, 0, 3);
  return ObOpenObjectByPointer(*(_DWORD *)((v1 & 0xFFFFFFC0) + 0x74), 512, 0, 40, PsProcessType, 0, a1);
}
