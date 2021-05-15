// AlpcpSetOwnerProcessPort 
 
signed int __fastcall AlpcpSetOwnerProcessPort(int a1, _DWORD *a2)
{
  int v3; // r4
  signed int result; // r0

  if ( a2 && (*a2 & 0x100000) != 0 )
    v3 = PsInitialSystemProcess;
  else
    v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  result = ObfReferenceObjectWithTag(v3);
  *(_DWORD *)(a1 + 12) = v3;
  return result;
}
