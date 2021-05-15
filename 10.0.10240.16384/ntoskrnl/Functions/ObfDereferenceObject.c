// ObfDereferenceObject 
 
int __fastcall ObfDereferenceObject(int a1)
{
  unsigned int v1; // r5
  unsigned int v3; // r4
  signed int v4; // r4
  BOOL v5; // r0
  int v6; // r3

  v1 = a1 - 24;
  if ( ObpTraceFlags )
    return sub_50C7D8();
  __dmb(0xBu);
  do
  {
    v3 = __ldrex((unsigned int *)v1);
    v4 = v3 - 1;
  }
  while ( __strex(v4, (unsigned int *)v1) );
  if ( v4 > 0 )
    return v4;
  if ( *(_DWORD *)(a1 - 20) )
    KeBugCheckEx(
      24,
      ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie],
      a1);
  if ( v4 < 0 )
    KeBugCheckEx(24, 0, a1);
  if ( *(_WORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x136)
    || !(v5 = KeAreInterruptsEnabled())
    || KeGetCurrentIrql(v5) )
  {
    ObpDeferObjectDeletion(v1);
    return v4;
  }
  __dmb(0xBu);
  if ( (*(_BYTE *)(v1 + 14) & 0x40) != 0 )
  {
    v6 = ObpInfoMaskToOffset[*(_BYTE *)(v1 + 14) & 0x7F];
    if ( v1 != v6 )
      ObpHandleRevocationBlockRemoveObject(v1 - v6);
  }
  if ( ObpTraceFlags )
    ObpDeregisterObject(v1);
  __dmb(0xBu);
  ObpRemoveObjectRoutine(v1, 0);
  return v4;
}
