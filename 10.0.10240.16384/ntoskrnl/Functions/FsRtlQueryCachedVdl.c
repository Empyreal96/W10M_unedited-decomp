// FsRtlQueryCachedVdl 
 
int __fastcall FsRtlQueryCachedVdl(_DWORD *a1, _DWORD *a2)
{
  int v4; // r5
  int v5; // r0
  int result; // r0
  int v7; // r3
  int v8; // r6
  _DWORD *v9; // r5
  int v10; // [sp+18h] [bp-70h]
  char v11[16]; // [sp+20h] [bp-68h] BYREF
  _DWORD v12[2]; // [sp+30h] [bp-58h] BYREF
  int v13; // [sp+38h] [bp-50h]
  int v14; // [sp+3Ch] [bp-4Ch]
  int v15; // [sp+40h] [bp-48h]

  KeInitializeEvent((int)v11, 0, 0);
  v4 = IoGetRelatedDeviceObject(a1);
  v5 = IoBuildDeviceIoControlRequest(590468, v4, 0, 0, 0, 0);
  if ( !v5 )
    return -1073741670;
  v12[0] = 0;
  v12[1] = 0;
  v13 = -1;
  v14 = 0x7FFFFFFF;
  v15 = 1;
  *(_DWORD *)(v5 + 12) = v12;
  v7 = *(_DWORD *)(v5 + 96);
  *(_BYTE *)(v7 - 40) = 13;
  *(_DWORD *)(v7 - 28) = 24;
  *(_DWORD *)(v7 - 32) = 64;
  *(_DWORD *)(v7 - 12) = a1;
  result = IofCallDriver(v4, v5);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)v11, 0, 0, 0, 0);
    result = v10;
  }
  if ( (result & 0xC0000000) != -1073741824 )
  {
    *a2 = 0;
    a2[1] = 0;
    v8 = v13;
    if ( v13 )
    {
      v9 = v12;
      do
      {
        if ( (v9[8] & 1) != 0 )
          *(_QWORD *)a2 = *((_QWORD *)v9 + 2) + *((_QWORD *)v9 + 3);
        v9 += 6;
        --v8;
      }
      while ( v8 );
    }
  }
  return result;
}
