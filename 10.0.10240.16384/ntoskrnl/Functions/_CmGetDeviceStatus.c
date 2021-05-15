// _CmGetDeviceStatus 
 
int __fastcall CmGetDeviceStatus(int a1, unsigned __int16 *a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  int v10; // r5
  char v11; // r2
  unsigned int v13; // [sp+10h] [bp-38h] BYREF
  int v14; // [sp+14h] [bp-34h] BYREF
  int v15; // [sp+18h] [bp-30h] BYREF
  char v16[40]; // [sp+20h] [bp-28h] BYREF

  *a4 = 0;
  *a5 = 0;
  *a6 = 0;
  v14 = 0;
  v10 = RtlInitUnicodeStringEx((int)v16, a2);
  if ( v10 >= 0 )
  {
    v10 = NtPlugPlayGetDeviceStatus(a1, (int)v16, (int)a4, (int)a5);
    if ( v10 >= 0 )
    {
      v13 = 4;
      if ( CmGetDeviceRegProp(a1, (int)a2, a3, 11, (int)&v15, (int)&v14, (int)&v13) || v13 < 4 || v15 != 4 )
        v11 = 0;
      else
        v11 = v14;
      if ( (v11 & 4) != 0 )
        return sub_7C754C();
      if ( (*a4 & 0x400) == 0 && (v11 & 0x40) != 0 )
      {
        *a4 |= 0x400u;
        *a5 = 28;
      }
    }
  }
  return v10;
}
