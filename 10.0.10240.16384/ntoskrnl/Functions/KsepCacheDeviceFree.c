// KsepCacheDeviceFree 
 
int __fastcall KsepCacheDeviceFree(int result)
{
  int v1; // r5

  v1 = result;
  if ( result )
  {
    if ( *(_DWORD *)(result + 28) == result + 28 )
    {
      KsepStringFree((_DWORD *)(result + 20));
      result = KsepPoolFreePaged(v1);
    }
    else
    {
      result = sub_7CE4E0();
    }
  }
  return result;
}
