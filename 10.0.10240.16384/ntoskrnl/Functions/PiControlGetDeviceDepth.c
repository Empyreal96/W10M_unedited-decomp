// PiControlGetDeviceDepth 
 
int __fastcall PiControlGetDeviceDepth(int a1, unsigned __int16 *a2, int a3, char a4)
{
  unsigned int v5; // r2
  int v6; // r6
  int v7; // r4
  __int16 v9[2]; // [sp+8h] [bp-18h] BYREF
  unsigned int v10[5]; // [sp+Ch] [bp-14h] BYREF

  v5 = *a2;
  v6 = a4;
  v9[1] = v5;
  v9[0] = v5;
  if ( !v5 || v5 > 0x190 || (v5 & 1) != 0 )
    return -1073741811;
  v7 = PiControlMakeUserModeCallersCopy((int *)v10, *((_DWORD *)a2 + 1), v5, 2, a4, 1);
  if ( v7 >= 0 )
  {
    v7 = PiGetDeviceDepth(v9, a2 + 4);
    if ( v6 )
    {
      if ( v10[0] )
        ExFreePoolWithTag(v10[0]);
    }
  }
  return v7;
}
