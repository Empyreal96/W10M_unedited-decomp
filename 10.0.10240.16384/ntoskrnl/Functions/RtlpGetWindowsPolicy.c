// RtlpGetWindowsPolicy 
 
int __fastcall RtlpGetWindowsPolicy(unsigned __int16 *a1, int a2, int *a3, unsigned int *a4)
{
  unsigned int v4; // r4
  int v7; // r0
  int v9; // r6
  _BYTE *v10; // r0
  int v11; // r5
  _DWORD v12[8]; // [sp+8h] [bp-20h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  v4 = 0;
  if ( !a2 || !a3 || !a4 || !a1 )
  {
    v11 = -1073741811;
LABEL_15:
    if ( v4 )
      ExFreePoolWithTag(v4);
    return v11;
  }
  RtlInitUnicodeString((unsigned int)v12, a1);
  v7 = ZwQueryLicenseValue();
  if ( v7 >= 0 )
    return sub_80BFEC();
  if ( v7 == -1073741789 )
  {
    v9 = *a3;
    if ( *a3 )
    {
      v10 = (_BYTE *)ExAllocatePoolWithTag(1, *a3, 1920232557);
      v4 = (unsigned int)v10;
      if ( !v10 )
        return -1073741801;
      memset(v10, 0, v9);
    }
    else
    {
      v4 = 0;
    }
    if ( v4 )
      goto LABEL_12;
    return -1073741801;
  }
LABEL_12:
  v11 = ZwQueryLicenseValue();
  if ( v11 < 0 )
    goto LABEL_15;
  *a4 = v4;
  return v11;
}
