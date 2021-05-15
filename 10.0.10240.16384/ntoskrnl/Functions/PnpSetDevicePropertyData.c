// PnpSetDevicePropertyData 
 
int __fastcall PnpSetDevicePropertyData(int a1)
{
  _BYTE *v2; // r0
  int v3; // r5
  int result; // r0
  char v5[168]; // [sp+1Eh] [bp-C6h] BYREF

  v2 = memset(v5, 0, sizeof(v5));
  if ( a1 )
    v3 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v3 = 0;
  if ( v3 )
    result = sub_7DEE20(v2);
  else
    result = -1073741808;
  return result;
}
