// CcMdlWriteComplete 
 
int __fastcall CcMdlWriteComplete(_DWORD *a1, unsigned int *a2, int a3)
{
  int v6; // r0
  _DWORD *v7; // r4
  int (__fastcall *v8)(_DWORD *, unsigned int *, int, int); // r4
  int result; // r0

  v6 = IoGetRelatedDeviceObject(a1);
  v7 = *(_DWORD **)(*(_DWORD *)(v6 + 8) + 40);
  if ( !v7
    || *v7 <= 0x4Cu
    || (v8 = (int (__fastcall *)(_DWORD *, unsigned int *, int, int))v7[19]) == 0
    || (result = v8(a1, a2, a3, v6)) == 0 )
  {
    result = CcMdlWriteComplete2((int)a1, a2, a3);
  }
  return result;
}
