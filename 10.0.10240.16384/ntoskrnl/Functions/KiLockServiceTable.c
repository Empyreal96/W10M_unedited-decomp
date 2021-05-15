// KiLockServiceTable 
 
int __fastcall KiLockServiceTable(int a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0
  int v6; // r0
  int v7; // r5
  int v8; // r0
  unsigned int *v9; // r0
  int v10; // r1
  int v11; // r0
  _DWORD *v12; // r2
  int v13; // r3
  _DWORD *v14; // [sp+8h] [bp-18h] BYREF
  _DWORD v15[5]; // [sp+Ch] [bp-14h] BYREF

  v14 = a2;
  v15[0] = a3;
  v15[1] = a4;
  result = KiLockExtendedServiceTable();
  if ( !a4 )
  {
    v6 = RtlCaptureImageExceptionValues(0x400000, (int *)&v14, (int)v15);
    v7 = (int)v14;
    if ( !v14 )
      KeBugCheck(49);
    v8 = KiFastGetCallersAddress(v6);
    v9 = RtlpSearchFunctionTable(v7, v15[0] >> 3, v8, 0x400000);
    if ( !v9 )
      KeBugCheck(49);
    v11 = RtlLookupExceptionHandler(v9, v10);
    if ( v11 < 0 )
      KeBugCheckEx(49, v11, 0);
    v12 = v14;
    if ( (int)*v14 < 0 )
    {
      v12 = (_DWORD *)((*v14 & 0x7FFFFFFF) + 0x400000);
      v14 = v12;
    }
    if ( *v12 != 1 || (v13 = v12[3], v13 == 1) )
      KeBugCheck(49);
    result = ((int (__fastcall *)(_DWORD, _DWORD))(v13 + 0x400000))(0, 0);
  }
  return result;
}
