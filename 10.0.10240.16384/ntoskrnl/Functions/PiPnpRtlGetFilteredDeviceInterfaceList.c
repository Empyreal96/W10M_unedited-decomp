// PiPnpRtlGetFilteredDeviceInterfaceList 
 
int __fastcall PiPnpRtlGetFilteredDeviceInterfaceList(_DWORD *a1, int a2, int a3)
{
  unsigned __int16 *v4; // r1
  int result; // r0
  int v6[2]; // [sp+10h] [bp-38h] BYREF
  BOOL v7; // [sp+18h] [bp-30h]
  int v8; // [sp+1Ch] [bp-2Ch]
  int v9; // [sp+20h] [bp-28h]
  unsigned __int16 v10[4]; // [sp+28h] [bp-20h] BYREF
  _DWORD v11[6]; // [sp+30h] [bp-18h] BYREF

  v11[0] = 0;
  v11[1] = 0;
  v11[2] = 0;
  v11[3] = 0;
  v6[0] = 0;
  v6[1] = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v7 = (a1[4] & 1) != 0;
  v4 = (unsigned __int16 *)a1[2];
  v8 = a1[5];
  v9 = a1[6];
  if ( !a1[3] )
  {
    if ( v4 )
      result = ((int (__fastcall *)(_DWORD, unsigned __int16 *, int (__fastcall *)(int, unsigned __int16 *, int, int), int *, _DWORD, _DWORD, _DWORD))PiDmGetCmObjectConstraintListFromCache)(
                 0,
                 v4,
                 PiPnpRtlInterfaceFilterCallback,
                 v6,
                 a1[7],
                 a1[8],
                 a1[9]);
    else
      result = sub_7C8D1C(a1, 0, a3, a1[9]);
    return result;
  }
  if ( !v4 )
    return ((int (__fastcall *)(int, _DWORD, int (__fastcall *)(int, unsigned __int16 *, int, int), int *, _DWORD, _DWORD, _DWORD))PiDmGetCmObjectConstraintListFromCache)(
             1,
             a1[3],
             PiPnpRtlInterfaceFilterCallback,
             v6,
             a1[7],
             a1[8],
             a1[9]);
  result = RtlInitUnicodeStringEx((int)v10, v4);
  if ( result >= 0 )
  {
    result = RtlGUIDFromString(v10, v11);
    if ( result >= 0 )
    {
      v6[0] = (int)v11;
      return ((int (__fastcall *)(int, _DWORD, int (__fastcall *)(int, unsigned __int16 *, int, int), int *, _DWORD, _DWORD, _DWORD))PiDmGetCmObjectConstraintListFromCache)(
               1,
               a1[3],
               PiPnpRtlInterfaceFilterCallback,
               v6,
               a1[7],
               a1[8],
               a1[9]);
    }
  }
  return result;
}
