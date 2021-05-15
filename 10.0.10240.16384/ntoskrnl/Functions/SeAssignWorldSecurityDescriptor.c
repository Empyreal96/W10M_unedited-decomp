// SeAssignWorldSecurityDescriptor 
 
int __fastcall SeAssignWorldSecurityDescriptor(int a1, unsigned int *a2, _DWORD *a3)
{
  int v5; // r8
  unsigned int v6; // r7
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r6
  int result; // r0

  if ( !a3 )
    return -1073741790;
  v5 = SeWorldSid;
  v6 = 4 * (*(unsigned __int8 *)(SeWorldSid + 1) + 2);
  v7 = 2 * (v6 + 10);
  v8 = *a2;
  *a2 = v7;
  if ( v8 < v7 )
    return -1073741789;
  memset((_BYTE *)a1, 0, 20);
  *(_BYTE *)a1 = 1;
  v9 = a1 + 20;
  if ( (*a3 & 1) != 0 )
  {
    memmove(a1 + 20, v5, v6);
    *(_DWORD *)(a1 + 4) = 20;
    v9 += v6;
  }
  if ( (*a3 & 2) != 0 )
  {
    memmove(v9, v5, v6);
    *(_DWORD *)(a1 + 8) = v9 - a1;
  }
  if ( (*a3 & 4) != 0 )
    *(_WORD *)(a1 + 2) |= 4u;
  if ( (*a3 & 8) != 0 )
    *(_WORD *)(a1 + 2) |= 0x10u;
  result = 0;
  *(_WORD *)(a1 + 2) |= 0x8000u;
  return result;
}
