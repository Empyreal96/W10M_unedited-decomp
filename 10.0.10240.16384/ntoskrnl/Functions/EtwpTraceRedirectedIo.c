// EtwpTraceRedirectedIo 
 
int __fastcall EtwpTraceRedirectedIo(int a1, int a2)
{
  int v2; // r3
  int v4[2]; // [sp+8h] [bp-28h] BYREF
  int v5[8]; // [sp+10h] [bp-20h] BYREF

  v4[0] = a1;
  if ( a2 )
    v2 = *(_DWORD *)(a2 + 12);
  else
    v2 = 0;
  v4[1] = v2;
  v5[0] = (int)v4;
  v5[1] = 0;
  v5[2] = 8;
  v5[3] = 0;
  return EtwTraceKernelEvent(v5, 1, 768, 272, 290461954);
}
