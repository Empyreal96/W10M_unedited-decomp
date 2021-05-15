// EtwpAddEventToBuffer 
 
int __fastcall EtwpAddEventToBuffer(int a1, __int16 a2, _DWORD *a3, int a4, unsigned int a5, unsigned int a6, unsigned int *a7)
{
  unsigned int v9; // r5
  int v10; // r3
  int v11; // r1

  v9 = (a5 + 23) & 0xFFFFFFF8;
  *a7 = v9;
  if ( v9 > a6 )
    return -1073741789;
  v10 = *(_DWORD *)(a1 + 48);
  v11 = v10 + a1;
  *(_DWORD *)(a1 + 48) = v10 + v9;
  *(_WORD *)(v11 + 4) = a5 + 16;
  *(_WORD *)(v11 + 6) = a2;
  *(_DWORD *)v11 = -1072693246;
  *(_DWORD *)(v11 + 8) = *a3;
  *(_DWORD *)(v11 + 12) = a3[1];
  memmove(v10 + a1 + 16, a4, a5);
  return 0;
}
