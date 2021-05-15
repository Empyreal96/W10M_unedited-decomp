// sub_520290 
 
void __fastcall sub_520290(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r5
  bool v5; // zf
  int v6; // r0
  int v7; // r6

  v4 = 2 * a3;
  v5 = 2 * a3 == 15;
  if ( (unsigned int)(2 * a3) < 0xF )
  {
    v4 = 15;
    v5 = 1;
  }
  if ( v5 && *(_WORD *)(v3 + 8) == 1 )
    v6 = ExAllocateFromPagedLookasideList((int)&FsRtlFirstMappingLookasideList);
  else
    v6 = ExAllocatePoolWithTag(*(unsigned __int16 *)(v3 + 8), 8 * v4);
  v7 = v6;
  if ( v6 )
  {
    memmove(v6, *(_DWORD *)(v3 + 12), 8 * *(_DWORD *)(v3 + 4));
    ExFreePoolWithTag(*(_DWORD *)(v3 + 12), 0);
    *(_DWORD *)(v3 + 12) = v7;
    *(_DWORD *)v3 = v4;
  }
  JUMPOUT(0x4513AA);
}
