// WmipRemoveDS 
 
signed int __fastcall WmipRemoveDS(signed int result)
{
  _DWORD *v1; // r4

  v1 = *(_DWORD **)(result + 16);
  if ( v1 )
  {
    WmipGenerateRegistrationNotification(*(_DWORD **)(result + 16), 2);
    v1[2] |= 1u;
    result = WmipUnreferenceEntry((int *)&WmipDSChunkInfo, v1);
  }
  return result;
}
