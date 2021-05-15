// EtwpAcquireTokenAccessInformation 
 
int __fastcall EtwpAcquireTokenAccessInformation(int a1)
{
  unsigned int v2; // r0
  int v3; // r5
  int v4; // r4

  v2 = *(_DWORD *)(a1 + 572);
  if ( v2 )
  {
    ExFreePoolWithTag(v2);
    *(_DWORD *)(a1 + 572) = 0;
  }
  v3 = PsReferencePrimaryToken(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  v4 = SeQueryInformationToken(v3, 22, (_DWORD *)(a1 + 572));
  ObfDereferenceObject(v3);
  return v4;
}
