// MiInitializeMemoryEvents 
 
int __fastcall MiInitializeMemoryEvents(_DWORD *a1)
{
  unsigned int v1; // r4
  _DWORD *v3; // r6
  int *v4; // r5
  int v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r3
  __int64 v9; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v16; // [sp+0h] [bp-70h] BYREF
  const __int16 *v17; // [sp+4h] [bp-6Ch]
  int v18; // [sp+8h] [bp-68h]
  const __int16 *v19; // [sp+Ch] [bp-64h]
  int v20; // [sp+10h] [bp-60h]
  const __int16 *v21; // [sp+14h] [bp-5Ch]
  int v22; // [sp+18h] [bp-58h]
  const __int16 *v23; // [sp+1Ch] [bp-54h]
  int v24; // [sp+20h] [bp-50h]
  const __int16 *v25; // [sp+24h] [bp-4Ch]
  int v26; // [sp+28h] [bp-48h]
  const __int16 *v27; // [sp+2Ch] [bp-44h]
  int v28; // [sp+30h] [bp-40h]
  const __int16 *v29; // [sp+34h] [bp-3Ch]
  int v30; // [sp+38h] [bp-38h]
  const __int16 *v31; // [sp+3Ch] [bp-34h]
  int v32; // [sp+40h] [bp-30h]
  const __int16 *v33; // [sp+44h] [bp-2Ch]
  __int16 v34; // [sp+48h] [bp-28h]
  __int16 v35; // [sp+4Ah] [bp-26h]
  const __int16 *v36; // [sp+4Ch] [bp-24h]
  __int16 v37; // [sp+50h] [bp-20h]
  __int16 v38; // [sp+52h] [bp-1Eh]
  const __int16 *v39; // [sp+54h] [bp-1Ch]

  v16 = 4456514;
  v1 = 0;
  v17 = L"\\KernelObjects\\LowMemoryCondition";
  v18 = 4587588;
  v3 = a1 + 47;
  v19 = L"\\KernelObjects\\HighMemoryCondition";
  v20 = 4849736;
  v21 = L"\\KernelObjects\\LowPagedPoolCondition";
  v22 = 4980810;
  v23 = L"\\KernelObjects\\HighPagedPoolCondition";
  v24 = 5242958;
  v25 = L"\\KernelObjects\\LowNonPagedPoolCondition";
  v26 = 5374032;
  v27 = L"\\KernelObjects\\HighNonPagedPoolCondition";
  v28 = 4456514;
  v29 = L"\\KernelObjects\\LowCommitCondition";
  v30 = 4587588;
  v31 = L"\\KernelObjects\\HighCommitCondition";
  v32 = 4980810;
  v33 = L"\\KernelObjects\\MaximumCommitCondition";
  v34 = 54;
  v35 = 56;
  v36 = L"\\KernelObjects\\MemoryErrors";
  v37 = 70;
  v38 = 72;
  v4 = &v16;
  v39 = L"\\KernelObjects\\PhysicalMemoryChange";
  while ( 1 )
  {
    v5 = MiCreateMemoryEvent(v4, v3);
    if ( v5 < 0 )
      break;
    ++v1;
    ++v3;
    v4 += 2;
    if ( v1 >= 0xB )
    {
      v9 = MiInitializePagedPoolEvents(
             v5,
             v6,
             v7,
             v8,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33);
      MiSignalNonPagedPoolWatchers(v9, SHIDWORD(v9), v10, v11);
      MiUpdateAvailableEvents(a1, v12, v13, v14);
      return 1;
    }
  }
  return 0;
}
