// IopIncDisableableDepends 
 
int __fastcall IopIncDisableableDepends(int result)
{
  _DWORD *v1; // r4
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1
  int v5; // r1

  v1 = (_DWORD *)result;
  if ( result )
  {
    do
    {
      __dmb(0xBu);
      v2 = v1 + 97;
      do
      {
        v3 = __ldrex(v2);
        v4 = v3 + 1;
      }
      while ( __strex(v4, v2) );
      __dmb(0xBu);
      if ( v4 != 1 )
        break;
      v5 = v1[6];
      if ( v5 )
        result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v5, 11);
      v1 = (_DWORD *)v1[2];
    }
    while ( v1 );
  }
  return result;
}
