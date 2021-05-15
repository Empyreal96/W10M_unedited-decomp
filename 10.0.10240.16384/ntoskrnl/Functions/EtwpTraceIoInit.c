// EtwpTraceIoInit 
 
int *__fastcall EtwpTraceIoInit(int a1)
{
  int v1; // r2
  int v2; // r3
  int v3; // r2
  int v4; // r2
  int v6[2]; // [sp+8h] [bp-28h] BYREF
  int v7[8]; // [sp+10h] [bp-20h] BYREF

  v1 = **(unsigned __int8 **)(a1 + 96);
  if ( v1 == 3 )
  {
    v2 = 268;
  }
  else
  {
    v2 = 269;
    if ( v1 == 9 )
      v2 = 271;
  }
  v3 = *(_DWORD *)(a1 + 80);
  v6[0] = a1;
  if ( v3 )
    v4 = *(_DWORD *)(v3 + 880);
  else
    v4 = -1;
  v6[1] = v4;
  v7[0] = (int)v6;
  v7[1] = 0;
  v7[2] = 8;
  v7[3] = 0;
  return EtwTraceKernelEvent(v7, 1, 0x400u, v2, 22026499);
}
