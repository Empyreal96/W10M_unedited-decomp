// SepDuplicateSid 
 
int __fastcall SepDuplicateSid(int a1, int *a2)
{
  unsigned int v4; // r7
  int v5; // r0
  int v6; // r6
  unsigned int v7; // r2

  if ( !a2 )
    return -1073741811;
  *a2 = 0;
  v4 = 4 * (*(unsigned __int8 *)(a1 + 1) + 2);
  v5 = ExAllocatePoolWithTag(1, (v4 + 3) & 0xFFFFFFFC, 1767073107);
  v6 = v5;
  if ( !v5 )
    return -1073741670;
  v7 = 4 * (*(unsigned __int8 *)(a1 + 1) + 2);
  if ( v7 <= v4 )
    memmove(v5, a1, v7);
  *a2 = v6;
  return 0;
}
