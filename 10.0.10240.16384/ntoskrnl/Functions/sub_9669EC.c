// sub_9669EC 
 
int sub_9669EC()
{
  _DWORD *v1; // r4
  int v2; // r5
  int *i; // r5
  int v4; // r1
  unsigned int v5; // r0
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r3
  int (__fastcall *v10)(int); // [sp-4h] [bp-4h]

  ExfAcquirePushLockSharedEx(v1, v2, (unsigned int)v1);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  for ( i = (int *)PopFans; i != &PopFans; i = (int *)*i )
    PopSqmFanEnumeration();
  v1[1] = 0;
  __pld(v1);
  v4 = *v1;
  if ( (*v1 & 0xFFFFFFF0) <= 0x10 )
    v5 = 0;
  else
    v5 = v4 - 16;
  if ( (v4 & 2) != 0 )
    goto LABEL_13;
  __dmb(0xBu);
  do
    v6 = __ldrex(v1);
  while ( v6 == v4 && __strex(v5, v1) );
  if ( v6 != v4 )
LABEL_13:
    ExfReleasePushLock(v1, v4);
  v7 = KeAbPostRelease((unsigned int)v1);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = (__int16)(*(_WORD *)(v8 + 0x134) + 1);
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    v7 = KiCheckForKernelApcDelivery(v7);
  return v10(v7);
}
