// PipCallbackHasDeviceOverrides 
 
int __fastcall PipCallbackHasDeviceOverrides(int a1, int a2)
{
  int v3; // r4
  int result; // r0
  int v5; // [sp+44h] [bp-2Ch]

  if ( ZwOpenKey() < 0 )
    goto LABEL_10;
  v3 = ZwQueryKey();
  if ( v3 == -2147483643 )
    v3 = 0;
  if ( v3 >= 0 && v5 )
  {
    *(_DWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a2 + 12) = v5;
  }
  else
  {
    v3 = -1073741823;
    ZwClose();
  }
  if ( v3 < 0 )
LABEL_10:
    result = 0;
  else
    result = 1;
  return result;
}
