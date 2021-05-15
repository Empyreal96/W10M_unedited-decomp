// KseDsCallbackHookAddDevice 
 
int __fastcall KseDsCallbackHookAddDevice(_DWORD *a1, int a2)
{
  int v4; // r0
  int v5; // r5
  unsigned __int16 *v6; // r1
  char v8[8]; // [sp+10h] [bp-420h] BYREF
  char v9; // [sp+20h] [bp-410h] BYREF

  v4 = (*(int (**)(void))off_617624)();
  v5 = (*(int (__fastcall **)(_DWORD *, int))(v4 + 12))(a1, a2);
  if ( IoGetDeviceProperty(a2) < 0 )
    v6 = L"<error>";
  else
    v6 = (unsigned __int16 *)&v9;
  RtlInitUnicodeString((unsigned int)v8, v6);
  KsepDsEventAddDevice(a1[3], a1[4], a1, a2, v5, a1[6] + 12, v8);
  return v5;
}
