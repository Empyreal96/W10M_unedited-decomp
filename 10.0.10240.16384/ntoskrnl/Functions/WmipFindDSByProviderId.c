// WmipFindDSByProviderId 
 
_DWORD *__fastcall WmipFindDSByProviderId(int a1)
{
  _DWORD *i; // r4

  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  for ( i = *(_DWORD **)WmipDSHeadPtr; ; i = (_DWORD *)*i )
  {
    if ( i == (_DWORD *)WmipDSHeadPtr )
    {
      i = 0;
      goto LABEL_6;
    }
    if ( i[7] == a1 )
      break;
  }
  WmipReferenceEntry((int)i);
LABEL_6:
  KeReleaseMutex((int)&WmipSMMutex);
  return i;
}
