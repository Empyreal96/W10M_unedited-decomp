// PspQueryJobHierarchyProcessIdList 
 
int __fastcall PspQueryJobHierarchyProcessIdList(int a1, _DWORD *a2, int a3, _DWORD *a4)
{
  int v8; // r4
  unsigned int v9; // r5
  int v10; // r0
  int v11; // r4
  int v12; // r0
  __int16 v13; // r3
  _DWORD v15[2]; // [sp+10h] [bp-30h] BYREF
  int v16; // [sp+18h] [bp-28h]
  int v17; // [sp+1Ch] [bp-24h]
  int varg_r0; // [sp+48h] [bp+8h]
  _DWORD *varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  _DWORD *varg_r3; // [sp+54h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  varg_r0 = a1;
  v8 = __mrc(15, 0, 13, 0, 3);
  v9 = v8 & 0xFFFFFFC0;
  if ( (v8 & 0xFFFFFFC0) != 0 )
    --*(_WORD *)((v8 & 0xFFFFFFC0) + 0x136);
  ExAcquireResourceSharedLite(a1 + 32, 1);
  v15[0] = a2 + 2;
  v15[1] = a3 - 8;
  v16 = 0;
  v17 = *(_DWORD *)(a1 + 144);
  v10 = PspEnumJobsAndProcessesInJobHierarchy(a1, 0, 0, PspQueryProcessIdListCallback, v15, 1, v8 & 0xFFFFFFC0);
  v11 = v10;
  if ( v10 >= 0 || v10 == -2147483643 )
  {
    *a4 = 4 * (*(_DWORD *)(a1 + 144) + 2);
    *a2 = *(_DWORD *)(a1 + 144);
    a2[1] = v16;
  }
  v12 = ExReleaseResourceLite(a1 + 32);
  if ( v9 )
  {
    v13 = *(_WORD *)(v9 + 310) + 1;
    *(_WORD *)(v9 + 310) = v13;
    if ( !v13 && *(_DWORD *)(v9 + 100) != v9 + 100 )
      KiCheckForKernelApcDelivery(v12);
  }
  return v11;
}
