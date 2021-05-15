// PnpNotifyTargetDeviceChange 
 
int __fastcall PnpNotifyTargetDeviceChange(_DWORD *a1, int a2, _WORD *a3)
{
  signed int v5; // r0

  v5 = ObfReferenceObject(a2);
  if ( !a3 )
    return sub_7C1360(*a1);
  *a3 = 1;
  return sub_7C1360(v5);
}
