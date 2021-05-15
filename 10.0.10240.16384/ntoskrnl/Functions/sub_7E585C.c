// sub_7E585C 
 
int sub_7E585C()
{
  unsigned int *v0; // r2
  unsigned int v1; // r1
  int v2; // r3
  unsigned int v4; // r4
  _DWORD *v5; // r5
  __int64 v6; // r0
  int (__fastcall *v7)(_DWORD); // [sp-4h] [bp-4h]

  FsRtlNotifyCompleteIrpList(v4);
  v6 = *(_QWORD *)(v4 + 16);
  if ( *(_DWORD *)(v6 + 4) != v4 + 16 || *(_DWORD *)HIDWORD(v6) != v4 + 16 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v6) = v6;
  *(_DWORD *)(v6 + 4) = HIDWORD(v6);
  __dmb(0xBu);
  v0 = (unsigned int *)(v4 + 68);
  do
    v1 = __ldrex(v0);
  while ( __strex(v1 - 1, v0) );
  __dmb(0xBu);
  if ( !*(_DWORD *)(v4 + 68) )
  {
    if ( *(_DWORD *)(v4 + 44) )
    {
      PsReturnProcessPagedPoolQuota(*(_DWORD *)(v4 + 72), *(_DWORD *)(v4 + 56));
      ExFreePoolWithTag(*(_DWORD *)(v4 + 44));
    }
    if ( (*(_WORD *)(v4 + 36) & 0x40) != 0 || *(_DWORD *)(v4 + 80) )
      v2 = *(_DWORD *)(v4 + 12);
    else
      v2 = 0;
    *v5 = v2;
    LODWORD(v6) = ExFreePoolWithTag(v4);
  }
  return v7(v6);
}
