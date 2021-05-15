// CcMdlReadComplete 
 
int __fastcall CcMdlReadComplete(_DWORD *a1, _DWORD *a2)
{
  int result; // r0
  _DWORD *v5; // r2
  int (__fastcall *v6)(_DWORD *, _DWORD *, int); // r3

  result = IoGetRelatedDeviceObject(a1);
  v5 = *(_DWORD **)(*(_DWORD *)(result + 8) + 40);
  if ( !v5
    || *v5 <= 0x4Cu
    || (v6 = (int (__fastcall *)(_DWORD *, _DWORD *, int))v5[17]) == 0
    || (result = v6(a1, a2, result)) == 0 )
  {
    result = CcMdlReadComplete2(result, a2);
  }
  return result;
}
