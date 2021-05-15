// PspIoMiniPacketCallbackRoutine 
 
int __fastcall PspIoMiniPacketCallbackRoutine(int a1, _DWORD *a2)
{
  __dmb(0xBu);
  *a2 = 0;
  return ObfDereferenceObject((int)a2);
}
