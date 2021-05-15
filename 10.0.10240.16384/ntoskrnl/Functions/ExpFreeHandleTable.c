// ExpFreeHandleTable 
 
int __fastcall ExpFreeHandleTable(unsigned int a1)
{
  __int64 v2; // kr00_8
  int v3; // r1
  int result; // r0
  _DWORD *v5; // r8
  unsigned int i; // r7

  v2 = *(_QWORD *)(a1 + 8);
  if ( (v2 & 3) != 0 )
  {
    v5 = (_DWORD *)(v2 & 0xFFFFFFFC);
    if ( (v2 & 3) != 1 )
      return sub_7E95AC();
    for ( i = 0; i < 0x400; ++i )
    {
      if ( !*v5++ )
        break;
      ExpFreeLowLevelTable(HIDWORD(v2));
    }
    ExpFreeTablePagedPool(HIDWORD(v2), v2 & 0xFFFFFFFC, 4096);
  }
  else
  {
    ExpFreeLowLevelTable(HIDWORD(v2));
  }
  v3 = *(_DWORD *)(a1 + 60);
  if ( v3 )
    ExDereferenceHandleDebugInfo(a1, v3);
  result = ExFreePoolWithTag(a1);
  if ( HIDWORD(v2) )
    result = PsReturnProcessPagedPoolQuota(SHIDWORD(v2), 0x5Cu);
  return result;
}
