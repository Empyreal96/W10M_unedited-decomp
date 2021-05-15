// PopFanRemove 
 
int __fastcall PopFanRemove(int a1)
{
  int result; // r0

  *(_BYTE *)(a1 + 84) = 1;
  IoCancelIrp(*(_DWORD *)(a1 + 28));
  result = KeWaitForSingleObject(a1 + 68, 0, 0, 0, 0);
  if ( (PoDebug & 0x20) != 0 )
    result = DbgPrint("Fan %p: going away\n", (const void *)a1);
  return result;
}
