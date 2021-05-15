// WheapCreateLiveTriageDump 
 
int __fastcall WheapCreateLiveTriageDump(int a1)
{
  int v2; // r6
  int v3; // r4
  int v4; // r1
  int v5; // r3
  int v6; // r5
  int v7; // r4
  int v8; // r6
  int v10; // [sp+10h] [bp-1B0h] BYREF
  char v11[412]; // [sp+14h] [bp-1ACh] BYREF

  v10 = 0;
  memset(v11, 0, sizeof(v11));
  v2 = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 32);
  v3 = a1 + 28;
  v6 = ExAllocatePoolWithTag(512, 0x20000, 1634035799);
  if ( !v6 )
    return -1073741670;
  v10 = 2097159;
  RtlCaptureContext(&v10, v4, 2097159, v5);
  v8 = KeCapturePersistentThreadState((int)&v10, 0, 0x124u, v2, v3, 0, 0, v6);
  v7 = WheapInsertTriageDataBlock(v6, v3, *(_DWORD *)(v3 + 20));
  if ( v7 < 0 )
  {
    ExFreePoolWithTag(v6);
  }
  else
  {
    WheapTriageDump = v6;
    WheapTriageDumpLength = v8;
  }
  return v7;
}
