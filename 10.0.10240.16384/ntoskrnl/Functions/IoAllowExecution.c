// IoAllowExecution 
 
int __fastcall IoAllowExecution(int a1)
{
  int v1; // r0
  BOOL v2; // r4

  v1 = IopGetDevicePDO(*(_DWORD *)(a1 + 4));
  if ( !v1 )
    return 1;
  v2 = (*(_DWORD *)(v1 + 28) & 0x800000) == 0;
  ObfDereferenceObjectWithTag(v1);
  return v2;
}
