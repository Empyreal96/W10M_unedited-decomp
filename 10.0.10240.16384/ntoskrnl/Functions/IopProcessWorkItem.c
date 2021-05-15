// IopProcessWorkItem 
 
int __fastcall IopProcessWorkItem(int a1)
{
  __int64 v1; // kr00_8
  int result; // r0
  int v4; // r0
  int v5; // r4
  int v6; // r1
  int v7; // r3
  unsigned int v8; // r5
  int v9; // r3

  v1 = *(_QWORD *)(a1 + 16);
  if ( memcmp((unsigned int)&NullGuid, a1 + 36, 16) )
    return sub_53F868();
  v4 = *(_DWORD *)(a1 + 28);
  if ( v4 )
  {
    if ( (v4 & 1) != 0 )
      PsImpersonateContainerOfThread(v4 & 0xFFFFFFFE);
    else
      PsImpersonateContainerOfProcess();
    v7 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 28) = 0;
    v5 = v7 & 0xFFFFFFFE;
  }
  else
  {
    v5 = 0;
  }
  if ( (dword_682608 & 0x8000000) != 0 )
    EtwTraceThreadWorkItem(v1, 1344);
  v6 = *(_DWORD *)(a1 + 24);
  if ( *(_DWORD *)(a1 + 32) )
  {
    ((void (__fastcall *)(_DWORD, int, int))v1)(HIDWORD(v1), v6, a1);
  }
  else if ( *(_WORD *)HIDWORD(v1) == 3 )
  {
    ((void (__fastcall *)(_DWORD, int))v1)(HIDWORD(v1), v6);
  }
  else
  {
    ((void (__fastcall *)(_DWORD, int))v1)(0, v6);
  }
  if ( (dword_682608 & 0x8000000) != 0 )
    EtwTraceThreadWorkItem(v1, 1345);
  result = ObfDereferenceObjectWithTag(SHIDWORD(v1));
  if ( v5 )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = *(_DWORD *)(v8 + 0x420);
    if ( v9 )
    {
      if ( (v9 & 1) != 0 )
        KeSetThreadChargeOnlySchedulingGroup(v8, 0);
      ObfDereferenceObjectWithTag(*(_DWORD *)(v8 + 1056) & 0xFFFFFFFE);
      *(_DWORD *)(v8 + 1056) = 0;
    }
    result = ObfDereferenceObjectWithTag(v5);
  }
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
    KeBugCheck2(
      1,
      v1,
      *(unsigned __int8 *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A),
      *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134),
      0,
      0);
  return result;
}
