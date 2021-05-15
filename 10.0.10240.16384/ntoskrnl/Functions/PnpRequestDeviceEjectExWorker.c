// PnpRequestDeviceEjectExWorker 
 
unsigned int __fastcall PnpRequestDeviceEjectExWorker(unsigned int a1)
{
  int v2; // r0
  void (*v3)(void); // r3
  int v4; // r0
  int v6; // [sp+8h] [bp-18h] BYREF
  char v7[16]; // [sp+10h] [bp-10h] BYREF

  RtlInitUnicodeString((unsigned int)v7, (unsigned __int16 *)(a1 + 32));
  v6 = 1024;
  v2 = PnpQueueQueryAndRemoveEvent((int)v7, (_DWORD *)(a1 + 432), (_WORD *)(a1 + 436), &v6, 8, 1);
  v3 = *(void (**)(void))a1;
  *(_DWORD *)(a1 + 12) = v2;
  if ( v3 )
    v3();
  v4 = *(_DWORD *)(a1 + 8);
  if ( v4 )
    ObfDereferenceObject(v4);
  return ExFreePoolWithTag(a1);
}
