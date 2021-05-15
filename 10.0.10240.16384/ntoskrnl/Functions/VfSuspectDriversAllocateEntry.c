// VfSuspectDriversAllocateEntry 
 
int __fastcall VfSuspectDriversAllocateEntry(unsigned __int16 *a1)
{
  int v2; // r0
  int v3; // r4
  int v4; // r0

  v2 = ExAllocatePoolWithTag(512, a1[1] + 24, 1146316374);
  v3 = v2;
  if ( v2 )
  {
    v4 = v2 + 24;
    *(_DWORD *)(v3 + 20) = v4;
    *(_DWORD *)(v3 + 8) = 0;
    *(_DWORD *)(v3 + 12) = 0;
    *(_WORD *)(v3 + 16) = *a1;
    *(_WORD *)(v3 + 18) = a1[1];
    memmove(v4, *((_DWORD *)a1 + 1), *a1);
  }
  return v3;
}
