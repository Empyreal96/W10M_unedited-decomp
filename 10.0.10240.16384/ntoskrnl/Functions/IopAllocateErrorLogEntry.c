// IopAllocateErrorLogEntry 
 
int __fastcall IopAllocateErrorLogEntry(int a1, int a2, unsigned int a3)
{
  int v5; // r5
  unsigned int v6; // r4
  int v8; // r4

  if ( a3 < 0x30 || a3 > 0x98 )
    return 0;
  v5 = ((a3 + 3) & 0xFC) + 32;
  __dmb(0xBu);
  do
    v6 = __ldrex(&IopErrorLogAllocation);
  while ( __strex(v6 + v5, &IopErrorLogAllocation) );
  __dmb(0xBu);
  if ( v6 > 0x64000 )
    return sub_554F0C();
  v8 = ExAllocatePoolWithTag(512, v5);
  if ( !v8 )
    return sub_554F0C();
  if ( a1 )
    ObfReferenceObjectWithTag(a1);
  if ( a2 )
    ObfReferenceObjectWithTag(a2);
  memset((_BYTE *)v8, 0, v5);
  *(_WORD *)v8 = 11;
  *(_WORD *)(v8 + 2) = v5;
  *(_DWORD *)(v8 + 12) = a1;
  *(_DWORD *)(v8 + 16) = a2;
  return v8 + 32;
}
