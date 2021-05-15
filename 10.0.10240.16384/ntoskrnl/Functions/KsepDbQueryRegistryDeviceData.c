// KsepDbQueryRegistryDeviceData 
 
int __fastcall KsepDbQueryRegistryDeviceData(int a1)
{
  int v1; // r4
  int v3; // [sp+8h] [bp-28h] BYREF
  int v4; // [sp+10h] [bp-20h] BYREF
  int v5; // [sp+14h] [bp-1Ch]

  v4 = 0;
  v5 = 0;
  v3 = 0;
  v1 = KsepStringTransform(&v4, a1);
  if ( v1 >= 0 )
  {
    if ( KsepRegistryOpenKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility\\Device", v5, &v3) >= 0 )
      return sub_7CE544();
    v1 = -1073741275;
    if ( v3 )
      KsepRegistryCloseKey(v3);
  }
  KsepStringFree(&v4);
  return v1;
}
