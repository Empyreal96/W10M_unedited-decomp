// MiFlushDataSection 
 
int __fastcall MiFlushDataSection(int a1)
{
  int v2; // r4
  int v3; // r0
  int v5; // r5
  int v6; // r0
  char v7[8]; // [sp+8h] [bp-20h] BYREF

  v2 = 0;
  v3 = MiLockSectionControlArea(*(_DWORD *)(a1 + 20), 1, v7);
  if ( !v3 )
    return v2;
  if ( *(_DWORD *)(v3 + 52) || *(_QWORD *)(v3 + 64) > 1ui64 )
    v2 = 1;
  v5 = *(_DWORD *)(v3 + 48);
  if ( (dword_682604 & 0x10000) == 0 )
  {
    __dmb(0xBu);
    *(_DWORD *)(v3 + 36) = 0;
    KfLowerIrql((unsigned __int8)v7[0]);
    v6 = *(_DWORD *)(a1 + 20);
    if ( v5 )
      CcFlushCachePriv(v6, 0, 0);
    else
      MmFlushSection(v6, 0, 0);
    return v2;
  }
  return sub_51A600();
}
