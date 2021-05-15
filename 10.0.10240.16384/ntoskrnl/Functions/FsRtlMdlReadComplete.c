// FsRtlMdlReadComplete 
 
int __fastcall FsRtlMdlReadComplete(_DWORD *a1, int a2)
{
  int v4; // r0
  _DWORD *v5; // r2
  int (__fastcall *v6)(_DWORD *, int, int); // r3
  int result; // r0

  v4 = IoGetRelatedDeviceObject(a1);
  v5 = *(_DWORD **)(*(_DWORD *)(v4 + 8) + 40);
  if ( v5 && *v5 > 0x44u && (v6 = (int (__fastcall *)(_DWORD *, int, int))v5[17]) != 0 )
    result = v6(a1, a2, v4);
  else
    result = 0;
  return result;
}
