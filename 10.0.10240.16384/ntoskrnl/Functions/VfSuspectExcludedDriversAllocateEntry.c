// VfSuspectExcludedDriversAllocateEntry 
 
int __fastcall VfSuspectExcludedDriversAllocateEntry(unsigned __int16 *a1, int a2)
{
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r2
  unsigned __int16 v6; // r3
  int v7; // r1
  int v8; // r0

  v3 = ExAllocatePoolWithTag(512, a1[1] + 16, a2);
  v4 = v3;
  if ( v3 )
  {
    v5 = *a1;
    v6 = a1[1];
    v7 = *((_DWORD *)a1 + 1);
    v8 = v3 + 16;
    *(_WORD *)(v4 + 8) = v5;
    *(_WORD *)(v4 + 10) = v6;
    *(_DWORD *)(v4 + 12) = v8;
    memmove(v8, v7, v5);
  }
  return v4;
}
