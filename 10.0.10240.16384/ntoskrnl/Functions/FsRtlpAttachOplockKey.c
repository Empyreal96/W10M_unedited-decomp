// FsRtlpAttachOplockKey 
 
int __fastcall FsRtlpAttachOplockKey(int a1)
{
  int v1; // r8
  int *v2; // r2
  int v4; // r3
  __int16 v5; // r3
  int v6; // [sp+0h] [bp-38h]
  int v7; // [sp+4h] [bp-34h]

  v1 = *(_DWORD *)(a1 + 96);
  if ( !*(_BYTE *)v1 )
  {
    v2 = *(int **)(*(_DWORD *)(v1 + 28) + 124);
    if ( !v2
      || v2 == IopRevocationExtension
      || (v4 = v2[7]) == 0
      || (v5 = *(_WORD *)(v4 + 2), (v5 & 1) == 0) && (v5 & 2) == 0 )
    {
      v6 = 0;
      v7 = 0;
      IoGetIrpExtraCreateParameter(a1);
    }
  }
  return 0;
}
