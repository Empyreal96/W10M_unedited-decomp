// PfSnGetUnsafeProcessParameters 
 
int __fastcall PfSnGetUnsafeProcessParameters(int a1)
{
  int v1; // r3
  int v2; // r4

  v1 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 320);
  if ( !v1 )
    return 0;
  v2 = *(_DWORD *)(v1 + 16);
  if ( (v2 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  return v2;
}
