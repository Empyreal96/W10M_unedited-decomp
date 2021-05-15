// PsSetJobProperty 
 
int __fastcall PsSetJobProperty(int a1, int a2, int a3)
{
  int result; // r0
  _DWORD *v7; // r0

  if ( (unsigned int)KeGetCurrentIrql(a1) < 2
    && ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a1 - 12)] != PsJobType )
  {
    return -1073741811;
  }
  v7 = (_DWORD *)(a1 + 724);
  if ( a3 )
    result = PspInsertProperty(v7, a2, a3);
  else
    result = PspRemoveProperty((int)v7, a2, 0);
  return result;
}
