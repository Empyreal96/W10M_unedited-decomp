// PfpQueryGpuUtilization 
 
int __fastcall PfpQueryGpuUtilization(int a1, char a2, _DWORD *a3)
{
  int result; // r0
  int *v6; // r2
  int v7; // r1
  _DWORD *v8; // r2
  int v9; // [sp+4h] [bp-2Ch] BYREF
  int v10; // [sp+8h] [bp-28h]
  int v11; // [sp+Ch] [bp-24h]
  int v12; // [sp+10h] [bp-20h] BYREF
  int v13; // [sp+14h] [bp-1Ch]

  v9 = a1;
  if ( *(_DWORD *)(a1 + 16) < 0x10u )
    return -1073741306;
  if ( a2 )
    ProbeForWrite(*(_DWORD *)(a1 + 12), 16, 8);
  v6 = *(int **)(a1 + 12);
  v10 = *v6;
  v7 = v6[1];
  v11 = v7;
  v12 = v6[2];
  v13 = v6[3];
  if ( v10 != 1 )
    return -1073741735;
  v9 = v7;
  if ( v7 == -1 )
    v9 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  result = PsInvokeWin32Callout(25, (int)&v12, 1, &v9);
  if ( result >= 0 )
  {
    v8 = *(_DWORD **)(a1 + 12);
    *v8 = v10;
    v8[1] = v11;
    v8[2] = v12;
    v8[3] = v13;
    *a3 = 16;
    result = 0;
  }
  return result;
}
