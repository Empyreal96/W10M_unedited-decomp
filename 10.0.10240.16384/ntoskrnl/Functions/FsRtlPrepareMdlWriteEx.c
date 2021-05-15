// FsRtlPrepareMdlWriteEx 
 
int __fastcall FsRtlPrepareMdlWriteEx(_DWORD *a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v8; // r5
  int v9; // r5
  int v10; // r0
  _DWORD *v11; // r4
  int v12; // r3

  if ( FsRtlPrepareMdlWrite(a1, a2, a3, a4, (int)a5, (int)a6) )
    return 0;
  v9 = IoGetRelatedDeviceObject(a1);
  v10 = IoBuildAsynchronousFsdRequest(4, v9, 0);
  v11 = (_DWORD *)v10;
  if ( v10 )
  {
    v12 = *(_DWORD *)(v10 + 96);
    *(_DWORD *)(v12 - 12) = a1;
    *(_BYTE *)(v12 - 39) = 2;
    *(_DWORD *)(v12 - 28) = a4;
    *(_DWORD *)(v10 + 8) |= 4u;
    v8 = IoSynchronousCallDriver(v9, v10);
    if ( v8 >= 0 )
    {
      *a5 = v11[1];
      v11[1] = 0;
      *a6 = v11[6];
      a6[1] = v11[7];
    }
    IoFreeIrp((int)v11);
  }
  else
  {
    v8 = -1073741670;
    *a6 = -1073741670;
  }
  return v8;
}
