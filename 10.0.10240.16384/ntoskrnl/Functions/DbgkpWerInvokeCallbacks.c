// DbgkpWerInvokeCallbacks 
 
int __fastcall DbgkpWerInvokeCallbacks(_DWORD *a1)
{
  int v2; // r3
  int v3; // r4

  DbgPrintEx(5, 3, (int)"DBGK: DbgkpWerInvokeCallbacks entered, context 0x%p\n", (int)a1);
  v2 = a1[14];
  if ( !v2 )
    return 0;
  DbgPrintEx(5, 3, (int)"DBGK: Invoking callback at address 0x%p\n", v2);
  v3 = ((int (__fastcall *)(_DWORD *, int (__fastcall *)(_DWORD *, _DWORD *, int, unsigned int), _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))a1[14])(
         a1,
         DbgkWerAddSecondaryData,
         a1[8],
         a1[9],
         a1[10],
         a1[11],
         a1[12],
         a1[13]);
  if ( v3 < 0 )
    DbgPrintEx(5, 0, (int)"DBGK: callback at address 0x%p returned status 0x%X\n", a1[14]);
  return v3;
}
