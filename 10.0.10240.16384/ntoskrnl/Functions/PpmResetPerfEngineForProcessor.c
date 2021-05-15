// PpmResetPerfEngineForProcessor 
 
int __fastcall PpmResetPerfEngineForProcessor(int a1)
{
  int v1; // r2
  int v2; // r3
  void (__fastcall *v4)(_DWORD); // r2

  v1 = *(_DWORD *)(a1 + 3200);
  v2 = *(_DWORD *)(a1 + 3204);
  if ( v1 )
  {
    if ( v2 )
    {
      v4 = *(void (__fastcall **)(_DWORD))(v1 + 64);
      if ( v4 )
        v4(*(_DWORD *)(v2 + 4));
    }
  }
  return PpmResetPerfTimes(a1);
}
