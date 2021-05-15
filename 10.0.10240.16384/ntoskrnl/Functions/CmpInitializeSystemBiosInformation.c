// CmpInitializeSystemBiosInformation 
 
int __fastcall CmpInitializeSystemBiosInformation(int a1)
{
  int v1; // r0
  _WORD *v2; // r4

  v1 = ExAllocatePoolWithTag(
         1,
         *(unsigned __int16 *)(*(_DWORD *)(a1 + 132) + 2236)
       + *(unsigned __int16 *)(*(_DWORD *)(a1 + 132) + 2228)
       + *(unsigned __int16 *)(*(_DWORD *)(a1 + 132) + 2220)
       + 8,
         538987843);
  v2 = (_WORD *)v1;
  if ( v1 )
  {
    CmpBuildRegMultiSz(v1);
    CmpBuildRegMultiSz(v2);
    CmpBuildRegMultiSz(v2);
    *v2 = 0;
    if ( ZwCreateKey() >= 0 )
      ZwSetValueKey();
    ExFreePoolWithTag((unsigned int)v2);
  }
  return -1;
}
