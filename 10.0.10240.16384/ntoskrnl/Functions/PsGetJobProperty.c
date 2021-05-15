// PsGetJobProperty 
 
int __fastcall PsGetJobProperty(int a1, int a2, int a3, int a4)
{
  int v7[6]; // [sp+0h] [bp-18h] BYREF

  v7[1] = a4;
  v7[0] = 0;
  if ( (unsigned int)KeGetCurrentIrql(a1) < 2
    && ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a1 - 12)] != PsJobType )
  {
    return 0;
  }
  PspGetJobProperty(a1, a2, v7);
  return v7[0];
}
