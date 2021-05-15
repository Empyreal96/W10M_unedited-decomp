// MiConvertInitialMemoryBlock 
 
_DWORD *__fastcall MiConvertInitialMemoryBlock(int a1, _DWORD *a2)
{
  unsigned int v4; // r6
  _DWORD *v5; // r0
  _DWORD *v6; // r4

  v4 = 8 * (*a2 + 1);
  v5 = (_DWORD *)ExAllocatePoolWithTag(512, v4 + 8, 1817013581);
  v6 = v5;
  if ( !v5 )
    return 0;
  *v5 = a1;
  v5[1] = 1;
  memmove((int)(v5 + 2), (int)a2, v4);
  return v6 + 2;
}
