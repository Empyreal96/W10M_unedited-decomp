// EtwTraceWakeCounter 
 
int *__fastcall EtwTraceWakeCounter(int a1, __int16 a2, __int64 a3, int a4, int a5)
{
  unsigned int v5; // r4
  int v6; // r5
  int v7; // r3
  _DWORD v9[4]; // [sp+8h] [bp-30h] BYREF
  int v10[8]; // [sp+18h] [bp-20h] BYREF

  if ( a3 <= 0 )
  {
    if ( !a3 )
    {
      v5 = -2147483136;
      WORD2(a3) = a2 + 848;
      goto LABEL_7;
    }
    WORD2(a3) = a2 + 832;
  }
  else
  {
    WORD2(a3) = a2 + 816;
  }
  v5 = -2147475456;
LABEL_7:
  v6 = WORD2(a3);
  v9[0] = a1;
  v9[1] = a5;
  v9[3] = a3;
  if ( a4 )
    v7 = *(_DWORD *)(a4 + 176);
  else
    v7 = -1;
  v9[2] = v7;
  v10[0] = (int)v9;
  v10[1] = 0;
  v10[2] = 16;
  v10[3] = 0;
  return EtwTraceKernelEvent(v10, 1, v5, v6, 5249282);
}
