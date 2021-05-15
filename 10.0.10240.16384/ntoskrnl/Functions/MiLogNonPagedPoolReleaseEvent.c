// MiLogNonPagedPoolReleaseEvent 
 
int *__fastcall MiLogNonPagedPoolReleaseEvent(_DWORD *a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r1
  int *result; // r0
  int v5; // [sp+8h] [bp-38h] BYREF
  int v6; // [sp+Ch] [bp-34h]
  unsigned int v7; // [sp+10h] [bp-30h]
  int v8; // [sp+14h] [bp-2Ch]
  int v9[10]; // [sp+18h] [bp-28h] BYREF

  do
  {
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v2 = a1[1] | 0x80000000;
    v3 = v2;
    do
    {
      a1 = (_DWORD *)*a1;
      v2 -= 4;
    }
    while ( a1 && (a1[1] | 0x80000000) == v2 );
    v5 = 5;
    v6 = 0;
    v7 = (v2 + 4) << 10;
    v8 = (int)(v3 - v2) >> 2;
    v9[0] = (int)&v5;
    v9[1] = 0;
    v9[2] = 16;
    v9[3] = 0;
    result = EtwTraceKernelEvent(v9, 1, 0x20000001u, 633, 289413890);
  }
  while ( a1 );
  return result;
}
