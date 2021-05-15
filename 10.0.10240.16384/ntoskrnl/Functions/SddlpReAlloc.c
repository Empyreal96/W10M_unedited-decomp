// SddlpReAlloc 
 
int __fastcall SddlpReAlloc(unsigned int a1, int a2, unsigned int a3)
{
  _BYTE *v6; // r0
  int v7; // r4

  v6 = (_BYTE *)ExAllocatePoolWithTag(1, a2, 1683187027);
  v7 = (int)v6;
  if ( v6 )
  {
    memset(v6, 0, a2);
    memmove(v7, a3, a1);
  }
  ExFreePoolWithTag(a3);
  return v7;
}
