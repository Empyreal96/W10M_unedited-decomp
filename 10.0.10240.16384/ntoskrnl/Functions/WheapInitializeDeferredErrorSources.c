// WheapInitializeDeferredErrorSources 
 
int __fastcall WheapInitializeDeferredErrorSources(int a1)
{
  int v1; // r5
  int i; // r4
  int (__fastcall *v4)(int, int, _DWORD); // r3

  v1 = 0;
  for ( i = dword_641934; v1 < dword_641930; ++v1 )
  {
    if ( *(_DWORD *)(i + 81) == a1 )
    {
      if ( *(_BYTE *)(i + 72) )
      {
        if ( WheapInitializeErrorSource(i) >= 0 )
        {
          v4 = (int (__fastcall *)(int, int, _DWORD))dword_649F60[7 * *(_DWORD *)(i + 32)];
          __dmb(0xBu);
          if ( v4(1, i + 73, *(_DWORD *)(i + 40)) >= 0 )
          {
            *(_DWORD *)(i + 85) = 2;
            *(_BYTE *)(i + 72) = 0;
          }
        }
      }
    }
    i = *(_DWORD *)i;
  }
  return 0;
}
