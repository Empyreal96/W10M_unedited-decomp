// PiDeviceRegistration 
 
int __fastcall PiDeviceRegistration(unsigned __int16 *a1, int a2, int a3)
{
  unsigned __int16 *v4; // r7
  unsigned int v7; // r0
  int v9; // r4
  int v10[2]; // [sp+18h] [bp-28h] BYREF
  int v11; // [sp+20h] [bp-20h] BYREF
  unsigned int v12[7]; // [sp+24h] [bp-1Ch] BYREF

  v4 = 0;
  v11 = 0;
  if ( a3 )
  {
    *(_WORD *)(a3 + 2) = 0;
    *(_WORD *)a3 = 0;
    *(_DWORD *)(a3 + 4) = 0;
  }
  v7 = *a1;
  if ( v7 <= 2 )
    return sub_7C9EB4();
  if ( *(_WORD *)(*((_DWORD *)a1 + 1) + 2 * (v7 >> 1) - 2) == 92 )
    *a1 = v7 - 2;
  v9 = PnpUnicodeStringToWstr(v10, 0, a1);
  if ( v9 < 0 )
    goto LABEL_23;
  v12[0] = 512;
  v4 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 512, 538996816);
  if ( !v4 )
  {
    v9 = -1073741670;
    goto LABEL_23;
  }
  v9 = CmGetDeviceRegProp(PiPnpRtlCtx, v10[0], 0, 5, (int)&v11, (int)v4, (int)v12);
  PnpUnicodeStringToWstrFree(v10[0], (int)a1);
  if ( v9 < 0 )
  {
    if ( v9 == -1073741275 )
      v9 = 0;
  }
  else
  {
    v9 = -1073741772;
    if ( v11 != 1 || v12[0] <= 2 )
    {
LABEL_23:
      if ( a3 && *(_WORD *)a3 )
      {
        ExFreePoolWithTag(*(_DWORD *)(a3 + 4));
        *(_DWORD *)(a3 + 4) = 0;
        *(_WORD *)(a3 + 2) = 0;
        *(_WORD *)a3 = 0;
      }
      goto LABEL_16;
    }
    RtlInitUnicodeStringEx((int)v10, v4);
    if ( !a3 )
      goto LABEL_15;
    v9 = PnpConcatenateUnicodeStrings((unsigned __int16 *)a3, (unsigned __int16 *)v10);
  }
  if ( v9 < 0 )
    goto LABEL_23;
LABEL_15:
  v9 = PpForEachDeviceInstanceDriver(a1);
  if ( v9 < 0 )
  {
    if ( a2 )
      PpForEachDeviceInstanceDriver(a1);
    goto LABEL_23;
  }
LABEL_16:
  if ( v4 )
    ExFreePoolWithTag((unsigned int)v4);
  return v9;
}
