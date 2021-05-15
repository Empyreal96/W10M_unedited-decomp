// PsIsDpcActive 
 
BOOL __fastcall PsIsDpcActive(int a1)
{
  int v1; // r3
  BOOL result; // r0

  result = 0;
  if ( (unsigned int)KeGetCurrentIrql(a1) >= 2 )
  {
    v1 = *(unsigned __int8 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5A);
    __dmb(0xBu);
    if ( v1 )
      result = 1;
  }
  return result;
}
