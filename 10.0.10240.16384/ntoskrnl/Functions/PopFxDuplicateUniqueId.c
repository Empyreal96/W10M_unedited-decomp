// PopFxDuplicateUniqueId 
 
int __fastcall PopFxDuplicateUniqueId(unsigned __int16 *a1, int a2)
{
  unsigned int v4; // r2
  unsigned int v5; // r6
  int v6; // r0
  int v7; // r7
  __int16 v8; // r3

  v4 = *a1 + 2;
  if ( a1[1] < v4 )
    return -1073741811;
  v5 = (unsigned __int16)v4;
  v6 = ExAllocatePoolWithTag(512, (unsigned __int16)v4);
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  memmove(v6, *((_DWORD *)a1 + 1), v5);
  v8 = *a1;
  *(_DWORD *)(a2 + 4) = v7;
  *(_WORD *)(a2 + 2) = v5;
  *(_WORD *)a2 = v8;
  return 0;
}
