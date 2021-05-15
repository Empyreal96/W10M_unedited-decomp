// PiControlStartDevice 
 
int __fastcall PiControlStartDevice(int a1, unsigned __int16 *a2, int a3, unsigned int a4)
{
  unsigned int v4; // r2
  int v5; // r5
  int v6; // r2
  int v7; // r4
  int v9; // [sp+8h] [bp-10h] BYREF
  unsigned int v10[3]; // [sp+Ch] [bp-Ch] BYREF

  v9 = a3;
  v10[0] = a4;
  v4 = *a2;
  v5 = (char)a4;
  HIWORD(v9) = v4;
  LOWORD(v9) = v4;
  if ( !v4 || v4 > 0x190 || (v4 & 1) != 0 )
    return -1073741811;
  v7 = PiControlMakeUserModeCallersCopy((int *)v10, *((_DWORD *)a2 + 1), v4, 2, a4, 1);
  if ( v7 >= 0 )
  {
    v7 = PiQueueDeviceRequest((int)&v9, 16, v6, 1, 0);
    if ( v5 )
    {
      if ( v10[0] )
        ExFreePoolWithTag(v10[0]);
    }
  }
  return v7;
}
