// PspQueryJobHierarchyInterferenceCount 
 
int __fastcall PspQueryJobHierarchyInterferenceCount(int a1, _DWORD *a2)
{
  int v4; // r3
  unsigned int v5; // r4
  int v6; // r5
  int v7; // r0
  __int16 v8; // r3
  int v10; // [sp+8h] [bp-28h] BYREF
  int v11; // [sp+Ch] [bp-24h]
  _DWORD v12[8]; // [sp+10h] [bp-20h] BYREF

  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = v4 & 0xFFFFFFC0;
  if ( (v4 & 0xFFFFFFC0) != 0 )
    --*(_WORD *)((v4 & 0xFFFFFFC0) + 0x136);
  ExAcquireResourceSharedLite(a1 + 32, 1);
  v10 = 0;
  v11 = 0;
  v12[0] = &v10;
  v12[1] = a1;
  v6 = PspEnumJobsAndProcessesInJobHierarchy(a1, 0, 0, (int)PspQueryProcessInterferenceCountCallback, (int)v12, 1u);
  v7 = ExReleaseResourceLite(a1 + 32);
  if ( v5 )
  {
    v8 = *(_WORD *)(v5 + 310) + 1;
    *(_WORD *)(v5 + 310) = v8;
    if ( !v8 && *(_DWORD *)(v5 + 100) != v5 + 100 )
      KiCheckForKernelApcDelivery(v7);
  }
  if ( v6 >= 0 )
  {
    *a2 = v10;
    a2[1] = v11;
  }
  return v6;
}
