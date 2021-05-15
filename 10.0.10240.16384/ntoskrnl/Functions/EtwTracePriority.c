// EtwTracePriority 
 
int *__fastcall EtwTracePriority(int *result, int a2, int a3, int a4, _DWORD *a5)
{
  char v5; // r5
  char v6; // r6
  int *v8; // r7
  int v9; // r0
  int v10; // [sp+8h] [bp-30h] BYREF
  char v11; // [sp+Ch] [bp-2Ch]
  char v12; // [sp+Dh] [bp-2Bh]
  char v13; // [sp+Eh] [bp-2Ah]
  char v14; // [sp+Fh] [bp-29h]
  int v15[10]; // [sp+10h] [bp-28h] BYREF

  v5 = a4;
  v6 = a3;
  v8 = result;
  if ( a3 != a4 )
  {
    if ( (dword_61AD44 & 0x2000) != 0 )
      EtwpPsProvTracePriority();
    v9 = v8[220];
    v13 = 0;
    v14 = 0;
    v10 = v9;
    v11 = v6;
    v12 = v5;
    if ( a5 )
      v13 = *a5;
    v15[0] = (int)&v10;
    v15[1] = 0;
    v15[2] = 8;
    v15[3] = 0;
    result = EtwTraceKernelEvent(v15, 1, 0x20002000u, a2, 22026499);
  }
  return result;
}
