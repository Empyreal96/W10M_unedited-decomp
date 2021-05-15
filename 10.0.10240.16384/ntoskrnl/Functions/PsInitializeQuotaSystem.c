// PsInitializeQuotaSystem 
 
int __fastcall PsInitializeQuotaSystem(int a1)
{
  char *v2; // r4
  int v3; // r0
  int *v4; // r1
  char v5; // t1
  int v6; // r0
  _DWORD *v7; // r3
  int v8; // r2

  if ( a1 )
    return sub_969D3C();
  v2 = PspResourceFlags;
  dword_641580 = 1;
  v3 = 4;
  dword_641584 = 1;
  v4 = PspSystemQuotaBlock;
  do
  {
    v5 = *v2;
    v2 += 8;
    if ( (v5 & 2) == 0 )
      v4[32] = -1;
    v4 += 64;
    --v3;
  }
  while ( v3 );
  *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 332) = PspSystemQuotaBlock;
  PspSanitizeResourceLimits(&PspDefaultResourceLimits, 1);
  v6 = ExAllocatePoolWithTag(1, 384, 1951494992);
  PspQuotaBlockTable = v6;
  if ( !v6 )
    return 0;
  v7 = (_DWORD *)(v6 + 4);
  v8 = 32;
  do
  {
    *v7 = v7;
    v7[1] = v7;
    *(v7 - 1) = 0;
    v7 += 3;
    --v8;
  }
  while ( v8 );
  return 1;
}
