// FsRtlGetFileSize 
 
int __fastcall FsRtlGetFileSize(_DWORD *a1, _DWORD *a2)
{
  int v4; // r4
  int v5; // r3
  int result; // r0
  int (__fastcall *v7)(_DWORD *, int, int *, int *, int); // r5
  int v8[6]; // [sp+8h] [bp-50h] BYREF
  int v9; // [sp+20h] [bp-38h] BYREF
  int v10[5]; // [sp+24h] [bp-34h] BYREF

  v8[0] = 0;
  v8[1] = 0;
  v9 = 0;
  memset(v10, 0, sizeof(v10));
  v4 = IoGetRelatedDeviceObject(a1);
  v5 = *(_DWORD *)(*(_DWORD *)(v4 + 8) + 40);
  if ( !v5 )
    return sub_7D4E4C();
  v7 = *(int (__fastcall **)(_DWORD *, int, int *, int *, int))(v5 + 20);
  if ( !v7 || !v7(a1, 1, &v9, v8, v4) )
    return sub_7D4E4C();
  result = v8[0];
  if ( v8[0] >= 0 )
  {
    if ( BYTE1(v10[4]) )
    {
      result = -1073741638;
    }
    else
    {
      *a2 = v10[1];
      a2[1] = v10[2];
    }
  }
  return result;
}
