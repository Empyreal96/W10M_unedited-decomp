// _CmCreateDeviceInterfaceWorker 
 
int __fastcall CmCreateDeviceInterfaceWorker(int *a1, unsigned __int16 *a2, int a3, _DWORD *a4, _BYTE *a5, __int16 a6)
{
  int v11; // r4
  BOOL v12; // r3
  int v13; // [sp+10h] [bp-78h] BYREF
  unsigned __int16 v14[56]; // [sp+18h] [bp-70h] BYREF

  v13 = 0;
  if ( a6 )
    return sub_7EF320();
  if ( CmGetDeviceInterfaceClassGuidString((int)a1, a2, v14) < 0
    || CmCreateInterfaceClass(a1, v14, 0, 0, 0, 0) < 0
    || (v11 = CmOpenDeviceInterfaceRegKey(a1, a2, 48, 1, a3, 1, (int)a4, &v13), v11 < 0) )
  {
    JUMPOUT(0x7EF322);
  }
  v12 = v13 == 1;
  *a5 = v12;
  if ( v12 )
    CmRaiseCreateEvent(a1, a2, 3, *a4);
  return v11;
}
