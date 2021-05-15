// ExFetchLicenseData 
 
int __fastcall ExFetchLicenseData(int a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r3
  unsigned int *v12; // r1
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  int v18; // [sp+0h] [bp-20h]

  v18 = 0;
  if ( !a3 )
    return -1073741811;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex((unsigned int *)&dword_922C40);
  while ( !v10 && __strex(0x11u, (unsigned int *)&dword_922C40) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(&dword_922C40, v8, (unsigned int)&dword_922C40);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  if ( byte_920AF2 )
    goto LABEL_11;
  v12 = (unsigned int *)dword_922C44;
  if ( off_920350 )
    v12 = (unsigned int *)off_920350;
  if ( !v12 )
  {
LABEL_11:
    v11 = -1073741595;
  }
  else
  {
    *a3 = *v12;
    if ( a1 && a2 && a2 >= *v12 )
    {
      memmove(a1, (int)v12, *v12);
      if ( a2 >= 0x14 )
        *(_DWORD *)(a1 + 12) &= 0xFFFFFFFE;
      goto LABEL_22;
    }
    v11 = -1073741789;
  }
  v18 = v11;
LABEL_22:
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&dword_922C40);
  while ( v13 == 17 && __strex(0, (unsigned int *)&dword_922C40) );
  if ( v13 != 17 )
    ExfReleasePushLockShared(&dword_922C40);
  v14 = KeAbPostRelease((unsigned int)&dword_922C40);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  return v18;
}
