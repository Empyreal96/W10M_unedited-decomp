// PiDaDriverEntry 
 
int __fastcall PiDaDriverEntry(_DWORD *a1)
{
  int result; // r0
  int v3; // [sp+10h] [bp-18h] BYREF
  __int16 v4[2]; // [sp+18h] [bp-10h] BYREF
  const __int16 *v5; // [sp+1Ch] [bp-Ch]

  v3 = 0;
  a1[14] = PiDaDispatch;
  a1[32] = PiDaDispatch;
  a1[16] = PiDaDispatch;
  a1[28] = PiDaDispatch;
  memset(FastIoDispatch, 0, 112);
  FastIoDispatch[0] = 112;
  dword_62F9C8 = (int)PiDaFastIoDispatch;
  v4[1] = 36;
  v4[0] = 34;
  a1[10] = FastIoDispatch;
  v5 = L"\\Device\\DeviceApi";
  result = IoCreateDevice((int)a1, 0, (char *)v4, 0x22u, 0x20000, 0, &v3);
  if ( result < 0 )
    return sub_969180();
  *(_DWORD *)(v3 + 28) &= 0xFFFFFF7F;
  return result;
}
