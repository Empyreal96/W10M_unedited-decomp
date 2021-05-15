// IoCancelFileOpen 
 
int __fastcall IoCancelFileOpen(int a1, int a2)
{
  int v4; // r5
  int v5; // r3
  int result; // r0
  char v7[32]; // [sp+8h] [bp-20h] BYREF

  if ( (*(_DWORD *)(a2 + 44) & 0x40000) != 0 )
    KeBugCheckEx(232, a2, a1, 0, 0);
  KeInitializeEvent((int)v7, 1, 0);
  if ( (*(_DWORD *)(a2 + 44) & 0x4000000) == 0 )
    KeResetEvent(a2 + 92);
  v4 = IopAllocateIrpMustSucceed(a1, *(_BYTE *)(a1 + 48));
  *(_DWORD *)(v4 + 100) = a2;
  *(_DWORD *)(v4 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v4 + 44) = v7;
  *(_DWORD *)(v4 + 40) = v4 + 24;
  *(_DWORD *)(v4 + 8) = 1028;
  v5 = *(_DWORD *)(v4 + 96);
  *(_BYTE *)(v4 + 32) = 0;
  *(_DWORD *)(v4 + 48) = 0;
  *(_BYTE *)(v5 - 40) = 18;
  *(_DWORD *)(v5 - 12) = a2;
  IopQueueThreadIrp(v4);
  if ( PoCallDriver(a1, v4) == 259 )
    KeWaitForSingleObject((unsigned int)v7, 6, 0, 0, 0);
  IopDequeueIrpFromThread((_DWORD *)v4);
  IoFreeIrp(v4);
  result = KeResetEvent(a2 + 92);
  *(_DWORD *)(a2 + 44) |= 0x200000u;
  return result;
}
