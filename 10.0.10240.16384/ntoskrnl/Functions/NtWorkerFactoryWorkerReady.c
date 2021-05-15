// NtWorkerFactoryWorkerReady 
 
int __fastcall NtWorkerFactoryWorkerReady(int a1)
{
  int v1; // r3
  int v2; // r5
  _DWORD *v3; // r4
  int v4; // r3
  int v5; // r3
  _DWORD *v7; // [sp+8h] [bp-20h] BYREF
  char v8[24]; // [sp+10h] [bp-18h] BYREF

  v1 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v2 = ObReferenceObjectByHandle(a1, 16, ExpWorkerFactoryObjectType, v1, &v7, 0);
  if ( v2 >= 0 )
  {
    v3 = v7;
    KeAcquireInStackQueuedSpinLock(v7[1], v8);
    v4 = v3[20];
    if ( v4 )
    {
      v3[20] = v4 - 1;
      v5 = v3[18];
      if ( v5 )
      {
        v3[18] = v5 - 1;
        ++v3[16];
        ++v3[17];
      }
      else
      {
        v2 = -1073741558;
      }
    }
    else
    {
      v2 = -1073741823;
    }
    KeReleaseInStackQueuedSpinLock(v8);
    ObfDereferenceObjectWithTag(v3);
  }
  return v2;
}
