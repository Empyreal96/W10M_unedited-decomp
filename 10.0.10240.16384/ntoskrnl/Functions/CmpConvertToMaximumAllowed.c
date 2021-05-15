// CmpConvertToMaximumAllowed 
 
int *__fastcall CmpConvertToMaximumAllowed(int a1)
{
  int *result; // r0
  int v3; // r3
  int v4; // [sp+0h] [bp-8h] BYREF

  v4 = 0x2000000;
  result = RtlMapGenericMask(&v4, (_DWORD *)CmKeyObjectType + 13);
  v3 = v4;
  *(_DWORD *)(a1 + 16) = v4;
  *(_DWORD *)(a1 + 24) = v3;
  return result;
}
