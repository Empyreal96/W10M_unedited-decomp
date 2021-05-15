// PiDmObjectManagerInit 
 
_BYTE *__fastcall PiDmObjectManagerInit(int a1, int a2)
{
  _BYTE *result; // r0

  ExInitializeResourceLite(a1);
  result = RtlInitializeGenericTableAvl(
             a1 + 56,
             (unsigned int)PiDmCompareObjects,
             (unsigned int)PiDmAllocateGenericTableEntry,
             (int)PiDmFreeGenericTableEntry,
             0);
  *(_DWORD *)(a1 + 112) = a2;
  return result;
}
