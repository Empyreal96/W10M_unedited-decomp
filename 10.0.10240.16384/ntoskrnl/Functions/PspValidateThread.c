// PspValidateThread 
 
int __fastcall PspValidateThread(int a1)
{
  int v2; // r2
  int v3; // r3

  if ( a1 == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x58C) )
    return -1073741637;
  if ( (unsigned int)KeGetCurrentIrql(a1) >= 2
    || ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a1 - 12)] == PsThreadType )
  {
    if ( a1 != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
      return 0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v2 = 0;
    }
    else
    {
      __disable_irq();
      v2 = 1;
    }
    v3 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v2 )
      __enable_irq();
    if ( (v3 & 0x10001) == 0 )
      return 0;
    return -1073741637;
  }
  return -1073741811;
}
