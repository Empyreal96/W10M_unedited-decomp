// FsRtlpRegisterProviderWithMUP 
 
int __fastcall FsRtlpRegisterProviderWithMUP(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int v7; // r0
  unsigned int v8; // r5
  int v9; // r0
  __int16 v10; // r3
  int v11; // r4
  int v13; // [sp+18h] [bp-20h]

  v7 = ExAllocatePoolWithTag(512, *a2 + 16, 1853182790);
  v8 = v7;
  if ( !v7 )
    return -1073741670;
  v9 = v7 + 16;
  *(_DWORD *)(v8 + 4) = v9;
  *(_WORD *)v8 = *a2;
  v10 = *a2;
  *(_DWORD *)(v8 + 8) = a3;
  *(_DWORD *)(v8 + 12) = a4;
  *(_WORD *)(v8 + 2) = v10;
  memmove(v9, *((_DWORD *)a2 + 1), *a2);
  v11 = ZwFsControlFile();
  if ( v11 == 259 )
  {
    ZwWaitForSingleObject();
    v11 = v13;
  }
  ExFreePoolWithTag(v8);
  return v11;
}
