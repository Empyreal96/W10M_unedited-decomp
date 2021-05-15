// PipIsProviderStarted 
 
int __fastcall PipIsProviderStarted(int a1)
{
  int v1; // r2

  v1 = *(_DWORD *)(a1 + 172);
  if ( v1 > 779 )
    return sub_817400();
  return v1 < 777 && v1 >= 769 && v1 > 775;
}
