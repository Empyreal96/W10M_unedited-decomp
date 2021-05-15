// SepReadAndInsertCaps 
 
int __fastcall SepReadAndInsertCaps(int a1, int a2, int a3)
{
  int v4; // r2
  int v5; // r3
  int v6; // r6
  _DWORD *v7; // r5
  int v8; // r4
  int v9; // r0
  unsigned int v10; // r9
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r0
  bool v15; // zf
  int v17; // [sp+8h] [bp-2F0h] BYREF
  int v18; // [sp+Ch] [bp-2ECh] BYREF
  int v19; // [sp+10h] [bp-2E8h] BYREF
  int v20; // [sp+14h] [bp-2E4h]
  int v21; // [sp+18h] [bp-2E0h]
  int v22; // [sp+1Ch] [bp-2DCh]
  unsigned int v23; // [sp+20h] [bp-2D8h]
  int v24; // [sp+24h] [bp-2D4h]
  unsigned __int16 v25[360]; // [sp+28h] [bp-2D0h] BYREF

  v17 = 0;
  v18 = 0;
  v4 = *(_DWORD *)(a3 + 44);
  v20 = a3;
  v21 = a1;
  v5 = *(_DWORD *)(a3 + 40);
  v24 = v4;
  v6 = 0;
  v19 = 0;
  v22 = v5;
  v7 = (_DWORD *)ExAllocatePoolWithTag(1, a2 + 50, 1884513619);
  if ( !v7 )
    goto LABEL_2;
  v9 = ZwQueryKey();
  v8 = v9;
  if ( v9 < 0 )
  {
    if ( v9 != -2147483643 && v9 != -1073741789 )
      goto LABEL_28;
    v7 = (_DWORD *)SepRmCapPoolExpand((int)v7, v18);
    if ( !v7 )
    {
LABEL_2:
      v8 = -1073741670;
      goto LABEL_32;
    }
    v8 = ZwQueryKey();
    if ( v8 < 0 )
      goto LABEL_32;
  }
  v10 = 0;
  v23 = v7[5];
  if ( v23 )
  {
    while ( 1 )
    {
      v11 = ZwEnumerateKey();
      v8 = v11;
      if ( v11 < 0 )
      {
        if ( v11 != -2147483643 && v11 != -1073741789 )
          break;
        v7 = (_DWORD *)SepRmCapPoolExpand((int)v7, v18);
        if ( !v7 )
          goto LABEL_2;
        v8 = ZwEnumerateKey();
        if ( v8 < 0 )
          goto LABEL_32;
      }
      *((_WORD *)v7 + (v7[3] >> 1) + 8) = 0;
      v8 = RtlStringCchPrintfW(
             v25,
             0x156u,
             (int)L"%s\\%s",
             (int)L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPs");
      if ( v8 < 0 )
        goto LABEL_32;
      v8 = SepRegOpenKey(v25, 513, &v17);
      if ( v8 < 0 )
        goto LABEL_32;
      v12 = ZwQueryKey();
      v8 = v12;
      if ( v12 < 0 )
      {
        if ( v12 != -2147483643 && v12 != -1073741789 )
          break;
        v7 = (_DWORD *)SepRmCapPoolExpand((int)v7, v18);
        v13 = v17;
        if ( !v7 )
        {
          v8 = -1073741670;
          goto LABEL_33;
        }
        v8 = ZwQueryKey();
        if ( v8 < 0 )
          goto LABEL_32;
      }
      v8 = SepReadSingleCap(v17, v7[10], v22, v24, &v19, &v18);
      v6 = v19;
      if ( v8 < 0 )
      {
        v13 = v17;
        goto LABEL_30;
      }
      *(_DWORD *)(v19 + 16) = v20;
      v14 = SepComputeSidSignature(*(_DWORD *)(v6 + 12));
      v15 = RtlInsertEntryHashTable(v20, v6, v14, 0) == 0;
      v13 = v17;
      if ( v15 )
      {
        v8 = -1073741670;
        goto LABEL_29;
      }
      v6 = 0;
      v19 = 0;
      ZwClose();
      v13 = 0;
      ++v10;
      v17 = 0;
      if ( v10 >= v23 )
        goto LABEL_29;
    }
  }
LABEL_28:
  v13 = v17;
LABEL_29:
  if ( v8 < 0 )
  {
LABEL_30:
    if ( !v6 )
      goto LABEL_33;
    ExFreePoolWithTag(v6);
LABEL_32:
    v13 = v17;
LABEL_33:
    if ( v13 )
      ZwClose();
  }
  if ( v7 )
    ExFreePoolWithTag((unsigned int)v7);
  return v8;
}
