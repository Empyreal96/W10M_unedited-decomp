// PpCreateLegacyDeviceIds 
 
int __fastcall PpCreateLegacyDeviceIds(int a1, unsigned __int16 *a2, int a3)
{
  unsigned int v3; // r6
  int v4; // r5
  int v5; // r4
  unsigned int v6; // r8
  _BYTE *v7; // r0
  int v8; // r4
  int v10; // [sp+18h] [bp-28h] BYREF
  int v11[9]; // [sp+1Ch] [bp-24h] BYREF

  v3 = 0;
  v10 = 0;
  v11[0] = 0;
  if ( a1 )
    v4 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v4 = 0;
  if ( v4 && *(_DWORD *)(v4 + 24) )
  {
    if ( a3 )
    {
      v5 = *(_DWORD *)(a3 + 4);
      if ( v5 > 18 || v5 < -1 )
        v5 = 18;
    }
    else
    {
      v5 = 0;
    }
    v6 = 2 * (*a2 + wcslen((unsigned __int16 *)off_416FA0[v5 + 1]) + 21);
    v7 = (_BYTE *)ExAllocatePoolWithTag(1, v6, 1869181008);
    v3 = (unsigned int)v7;
    if ( !v7 )
      return -1073741670;
    memset(v7, 0, v6);
    v8 = RtlStringCchPrintfExW(v3, v6 >> 1, &v10, v11, 0, L"%ws%ws\\%wZ");
    if ( v8 >= 0 )
    {
      v8 = RtlStringCchPrintfW((_WORD *)(v10 + 2), v11[0] - 1, (int)L"%ws\\%wZ", (int)L"DETECTED");
      if ( v8 >= 0 )
        v8 = CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(v4 + 24), 0, 3, 7, v3, v6, 0);
    }
  }
  else
  {
    v8 = -1073741811;
  }
  if ( v3 )
    ExFreePoolWithTag(v3);
  return v8;
}
