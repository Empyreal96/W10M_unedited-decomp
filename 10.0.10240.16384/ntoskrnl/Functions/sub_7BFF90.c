// sub_7BFF90 
 
void sub_7BFF90()
{
  unsigned int v0; // r0
  unsigned int v1; // r1
  int v2; // r0
  unsigned int v3; // r1
  int v4; // r3
  char v5; // zf
  unsigned int v6; // r4
  _DWORD *v7; // r5

  if ( !v5 )
    __fastfail(0xEu);
  __dmb(0xBu);
  if ( RtlRemoveEntryHashTable(*(_DWORD *)(v6 + 4), v7, 0) )
  {
    SepDereferenceLowBoxObjects(v7[5], v7[6]);
    v0 = v7[6];
    if ( v0 )
      ExFreePoolWithTag(v0);
    ExFreePoolWithTag((unsigned int)v7);
  }
  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)v6);
  while ( __strex(v1 - 1, (unsigned int *)v6) );
  if ( (v1 & 2) != 0 && (v1 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v6);
  v2 = KeAbPostRelease(v6);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = (__int16)(*(_WORD *)(v3 + 0x134) + 1);
  *(_WORD *)(v3 + 308) = v4;
  if ( !v4 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    KiCheckForKernelApcDelivery(v2);
  JUMPOUT(0x6A5D38);
}
