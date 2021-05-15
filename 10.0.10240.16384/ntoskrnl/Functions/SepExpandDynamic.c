// SepExpandDynamic 
 
int __fastcall SepExpandDynamic(_DWORD *a1, unsigned int a2)
{
  unsigned int v4; // r5
  int v5; // r3
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r7
  int v9; // r3
  int v10; // r3

  v4 = a1[35] + 4 * (*(unsigned __int8 *)(a1[39] + 1) + 2);
  v5 = a1[41];
  if ( v5 )
    v4 += *(unsigned __int16 *)(v5 + 2);
  if ( a2 <= v4 )
    return 0;
  v6 = ExAllocatePoolWithTag(1, a2, 1683252563);
  v7 = v6;
  if ( v6 )
  {
    v8 = a1[40];
    memmove(v6, v8, v4);
    v9 = a1[35];
    a1[40] = v7;
    a1[35] = v9 - v4 + a2;
    v10 = a1[41];
    if ( v10 )
      a1[41] = v10 - v8 + v7;
    a1[39] = a1[39] - v8 + v7;
    ExFreePoolWithTag(v8);
    return 0;
  }
  return -1073741670;
}
