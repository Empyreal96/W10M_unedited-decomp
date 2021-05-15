// sub_8A3470 
 
int __fastcall sub_8A3470(int a1)
{
  int v1; // r7
  int v3; // r0
  int v4; // r0
  unsigned int v5; // r5
  int v6; // r8
  int v7; // r9
  __int16 v8; // r0
  unsigned int v9; // r10
  unsigned int v10; // r6
  int v11; // r0
  int v12; // r7
  int i; // r0
  int v14; // r0
  int v15; // r0
  int result; // r0
  unsigned __int16 v17; // [sp+18h] [bp-88h] BYREF
  unsigned __int16 v18; // [sp+1Ah] [bp-86h]
  char *v19; // [sp+1Ch] [bp-84h]
  int v20[2]; // [sp+20h] [bp-80h] BYREF
  _DWORD v21[2]; // [sp+28h] [bp-78h] BYREF
  int v22; // [sp+30h] [bp-70h]
  int v23; // [sp+34h] [bp-6Ch]
  unsigned __int16 *v24; // [sp+38h] [bp-68h]
  int v25; // [sp+3Ch] [bp-64h]
  int v26; // [sp+40h] [bp-60h]
  int v27; // [sp+44h] [bp-5Ch]
  char v28[8]; // [sp+48h] [bp-58h] BYREF
  char v29[24]; // [sp+50h] [bp-50h] BYREF
  unsigned int v30; // [sp+68h] [bp-38h]

  v1 = 0;
  if ( !ExpSetupModeDetected )
  {
    RtlInitUnicodeString((unsigned int)&v17, *(unsigned __int16 **)(a1 + 8));
    v22 = 24;
    v23 = 0;
    v25 = 576;
    v24 = &v17;
    v26 = 0;
    v27 = 0;
    NtClose();
    v20[0] = 131103;
    v3 = NtOpenKey();
    if ( v3 < 0 )
      KeBugCheckEx(154, 18, v3, 0, 0);
    v4 = NtQueryKey(*(_DWORD *)a1, 2, v29, 0x30u, v21);
    if ( v4 < 0 )
      KeBugCheckEx(154, 19, v4, 0, 0);
    v5 = 2 * (v30 + 28);
    if ( v5 < v30 || v5 < 2 * (v30 + 16) )
      v1 = 1;
    v6 = ExAllocatePoolWithTag(512, 2 * (v30 + 28), 544826699);
    if ( !v6 || v1 )
      KeBugCheckEx(154, 20, v5, 0, 0);
    v7 = *(_DWORD *)(a1 + 8);
    v8 = wcslen((unsigned __int16 *)(v7 + 32));
    v9 = v30;
    v10 = (unsigned __int16)(2 * (v8 + v30));
    v17 = 2 * (v8 + v30);
    if ( v10 < v30 || v10 < wcslen((unsigned __int16 *)(v7 + 32)) || v10 < wcslen((unsigned __int16 *)(v7 + 32)) + v9 )
      v1 = 1;
    v18 = v10;
    v19 = (char *)ExAllocatePoolWithTag(512, v10, 544826699);
    if ( !v19 || v1 )
      KeBugCheckEx(154, 20, v17, 1, 0);
    RtlInitUnicodeString((unsigned int)v28, L"ConcurrentLimit");
    v11 = NtSetValueKey(*(_DWORD *)a1, (int)v28, 0, 4, a1 + 4, 4u);
    if ( v11 < 0 )
      KeBugCheckEx(154, 21, v11, 0, 0);
    v12 = 0;
    for ( i = NtEnumerateKey(*(_DWORD *)a1, 0, 0, v6, v5, (unsigned int)v21);
          i != -2147483622;
          i = NtEnumerateKey(*(_DWORD *)a1, v12, 0, v6, v5, (unsigned int)v21) )
    {
      if ( i >= 0 )
      {
        *(_WORD *)(v6 + 2 * (*(_DWORD *)(v6 + 12) >> 1) + 16) = 0;
        wcscpy_s(v19, v18 >> 1, *(char **)(a1 + 8));
        wcscat_s(v19, v18 >> 1, (char *)L"\\");
        wcscat_s(v19, v18 >> 1, (char *)(v6 + 16));
        v17 = 2 * wcslen((unsigned __int16 *)v19);
        v22 = 24;
        v23 = 0;
        v25 = 576;
        v24 = &v17;
        v26 = 0;
        v27 = 0;
        v14 = NtOpenKey();
        if ( v14 < 0 )
          KeBugCheckEx(154, 22, v14, 0, 0);
        v15 = NtSetValueKey(v20[1], (int)v28, 0, 4, a1 + 4, 4u);
        if ( v15 < 0 )
          KeBugCheckEx(154, 23, v15, 0, 0);
        NtClose();
      }
      ++v12;
    }
    ExFreePoolWithTag(v6);
    ExFreePoolWithTag((unsigned int)v19);
  }
  result = NtNotifyChangeKey(*(_DWORD *)a1, 0, a1 + 12, 1, a1 + 28, 268435461, 1u, a1 + 36, 4, 1u);
  if ( result < 0 )
    KeBugCheckEx(154, 24, result, 0, 0);
  if ( !ExpSetupModeDetected )
  {
    result = PsCreateSystemThread((int)v20, 0x1FFFFF, 0);
    if ( result >= 0 )
      result = ZwClose();
  }
  return result;
}
