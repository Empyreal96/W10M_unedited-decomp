// FsRtlMdlRead 
 
int __fastcall FsRtlMdlRead(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v10; // r0
  _DWORD *v11; // r5
  int (__fastcall *v12)(_DWORD *, int, int, int, int, int, int, int); // r5
  int result; // r0
  int v14; // [sp+Ch] [bp-1Ch]

  v14 = a4;
  v10 = IoGetRelatedDeviceObject(a1);
  v11 = *(_DWORD **)(*(_DWORD *)(v10 + 8) + 40);
  if ( v11 && *v11 > 0x40u && (v12 = (int (__fastcall *)(_DWORD *, int, int, int, int, int, int, int))v11[16]) != 0 )
    result = v12(a1, a2, a3, a4, a5, a6, v10, v14);
  else
    result = 0;
  return result;
}
