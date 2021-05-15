// CmpTryConvertKcbLockSharedToExclusive 
 
int __fastcall CmpTryConvertKcbLockSharedToExclusive(_DWORD *a1)
{
  unsigned int *v1; // r2
  int v2; // r4
  unsigned int v3; // r1

  v1 = a1 + 7;
  __dmb(0xBu);
  v2 = 1;
  do
    v3 = __ldrex(v1);
  while ( v3 == 17 && __strex(1u, v1) );
  __dmb(0xBu);
  if ( v3 != 17 )
    return 0;
  a1[8] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (a1[1] & 0x100000) != 0 )
    return sub_804F44();
  return v2;
}
