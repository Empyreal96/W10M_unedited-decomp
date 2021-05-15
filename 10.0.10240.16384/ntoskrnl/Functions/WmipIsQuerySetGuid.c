// WmipIsQuerySetGuid 
 
int __fastcall WmipIsQuerySetGuid(int a1)
{
  _DWORD *i; // r2
  int v3; // r4

  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  for ( i = *(_DWORD **)(a1 + 32); i != (_DWORD *)(a1 + 32); i = (_DWORD *)*i )
  {
    if ( (i[2] & 0x89000) == 0 )
    {
      v3 = 1;
      goto LABEL_5;
    }
  }
  v3 = 0;
LABEL_5:
  KeReleaseMutex((int)&WmipSMMutex);
  return v3;
}
