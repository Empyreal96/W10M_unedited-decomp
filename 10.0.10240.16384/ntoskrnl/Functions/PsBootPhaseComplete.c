// PsBootPhaseComplete 
 
int __fastcall PsBootPhaseComplete(int a1, int a2, int a3)
{
  int v3; // r0
  int v4; // r2
  int result; // r0
  int v6; // r5
  int v7; // r0
  int v8; // r1
  int v9; // r6
  int v10; // r2
  int v11; // r3
  __int16 *v12; // r5
  int v13; // r7
  int v14; // r2
  int v15; // r0
  unsigned __int8 *v16; // r3
  unsigned int v17; // r2
  int v18; // [sp+10h] [bp-A8h]
  char v19[8]; // [sp+50h] [bp-68h] BYREF
  __int16 v20; // [sp+58h] [bp-60h]
  __int16 v21; // [sp+5Ah] [bp-5Eh]
  const __int16 *v22; // [sp+5Ch] [bp-5Ch]
  __int16 v23; // [sp+60h] [bp-58h]
  __int16 v24; // [sp+62h] [bp-56h]
  const __int16 *v25; // [sp+64h] [bp-54h]
  int v26; // [sp+6Ch] [bp-4Ch]
  int v27; // [sp+70h] [bp-48h]
  int v28; // [sp+74h] [bp-44h]
  __int16 v29[2]; // [sp+78h] [bp-40h] BYREF
  const __int16 *v30; // [sp+7Ch] [bp-3Ch]
  int v31; // [sp+80h] [bp-38h]
  __int16 v32; // [sp+84h] [bp-34h]
  __int16 v33; // [sp+86h] [bp-32h]
  const __int16 *v34; // [sp+88h] [bp-30h]
  int v35; // [sp+8Ch] [bp-2Ch]
  __int16 v36; // [sp+90h] [bp-28h]
  __int16 v37; // [sp+92h] [bp-26h]
  const __int16 *v38; // [sp+94h] [bp-24h]
  int v39; // [sp+98h] [bp-20h]

  v20 = 130;
  v21 = 132;
  v22 = L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\LsaInformation";
  v29[0] = 18;
  v29[1] = 20;
  v30 = L"EnableLUA";
  v31 = 1;
  v32 = 40;
  v33 = 42;
  v34 = L"EnableVirtualization";
  v35 = 2;
  v36 = 48;
  v37 = 50;
  v38 = L"EnableInstallerDetection";
  v39 = 3;
  v23 = 116;
  v24 = 118;
  v25 = L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\OneCore";
  v3 = RtlQueryImageFileExecutionOptions(a1, L"DevOverrideEnable", a3, v19);
  if ( v3 >= 0 )
    return sub_80B394();
  RtlQueryImageFileExecutionOptions(v3, L"MaxLoaderThreads", v4, &PsDefaultLoaderThreads);
  v6 = 0;
  v7 = ZwOpenKey();
  if ( v7 >= 0 )
  {
    if ( ZwQueryValueKey() >= 0 && v26 == 4 && v27 == 4 && v28 )
      v6 = 1;
    v7 = ObCloseHandle(v18);
    v18 = 0;
    if ( v6 )
    {
      v9 = ZwOpenKey();
      v7 = 0;
      if ( v9 < 0 )
        v18 = 0;
      v10 = v27;
      v11 = v28;
      v8 = v26;
      v12 = v29;
      v13 = 3;
      do
      {
        if ( v9 < 0 || v8 != 4 || v10 != 4 || v11 )
        {
          v14 = *((_DWORD *)v12 + 2);
          __dmb(0xBu);
          v15 = 1 << (v14 & 7);
          v16 = (unsigned __int8 *)((v14 >> 3) - 27920);
          do
            v17 = __ldrex(v16);
          while ( __strex(v17 | v15, v16) );
          __dmb(0xBu);
          v7 = 0;
          v10 = v27;
          v11 = v28;
          v8 = v26;
        }
        v12 += 6;
        --v13;
      }
      while ( v13 );
    }
  }
  PsCpuFairShareEnabled = PspIsDfssEnabled(v7, v8);
  PspGlobalFlags &= 0xFFFFFFFB;
  result = ZwOpenKey();
  if ( result >= 0 )
  {
    if ( ZwQueryValueKey() >= 0 && v26 == 4 && v27 == 4 )
    {
      if ( v28 )
        PspGlobalFlags |= 4u;
    }
    result = ObCloseHandle(v18);
  }
  return result;
}
