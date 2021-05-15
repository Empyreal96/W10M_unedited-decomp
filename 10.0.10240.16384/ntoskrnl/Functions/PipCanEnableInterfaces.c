// PipCanEnableInterfaces 
 
int __fastcall PipCanEnableInterfaces(int a1)
{
  int v1; // r2

  v1 = *(_DWORD *)(a1 + 172);
  if ( v1 > 783 )
    return sub_7C8B8C();
  return v1 < 782 && v1 != 769 && v1 > 769;
}
