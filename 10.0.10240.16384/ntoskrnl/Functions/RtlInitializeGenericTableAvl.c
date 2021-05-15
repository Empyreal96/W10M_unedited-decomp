// RtlInitializeGenericTableAvl 
 
_BYTE *__fastcall RtlInitializeGenericTableAvl(int a1, unsigned int a2, unsigned int a3, int a4, int a5)
{
  unsigned __int64 v5; // r4
  _BYTE *result; // r0

  v5 = __PAIR64__(a3, a2);
  result = memset((_BYTE *)a1, 0, 56);
  *(_DWORD *)a1 = a1;
  *(_QWORD *)(a1 + 40) = v5;
  *(_DWORD *)(a1 + 48) = a4;
  *(_DWORD *)(a1 + 52) = a5;
  return result;
}
