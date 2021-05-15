// RtlpLockAtomTable 
 
int __fastcall RtlpLockAtomTable(_DWORD *a1)
{
  unsigned int v1; // r2
  unsigned __int8 *v2; // r5
  int v3; // r0
  unsigned int v4; // r2

  if ( !a1 || *a1 != 1836020801 )
    return 0;
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  v2 = (unsigned __int8 *)(a1 + 2);
  v3 = KeAbPreAcquire((unsigned int)(a1 + 2), 0, 0);
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 | 1, v2) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7C0310(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  return 1;
}
