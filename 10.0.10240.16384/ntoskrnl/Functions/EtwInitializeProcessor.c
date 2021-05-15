// EtwInitializeProcessor 
 
int __fastcall EtwInitializeProcessor(int a1)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r4

  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 1920, 1886876741);
  v3 = v2;
  *(_DWORD *)(a1 + 3596) = v2;
  if ( !v2 )
    return -1073741801;
  memset(v2, 0, 1920);
  *v3 = *(_DWORD *)(a1 + 20);
  EtwpInitializeActivityIdSeed(v3 + 224, *(_DWORD *)(a1 + 20));
  EtwpInitializeStackTracing(v3 + 228, *(_DWORD *)(a1 + 20));
  return EtwpCCSwapInitializeProcessor(v3);
}
