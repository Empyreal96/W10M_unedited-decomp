// PopBootLoaderTraceEtwEvents 
 
int __fastcall PopBootLoaderTraceEtwEvents(int a1, int a2)
{
  unsigned int v2; // r5
  int result; // r0
  _DWORD v5[12]; // [sp+0h] [bp-30h] BYREF

  v2 = *(_DWORD *)(a1 + 16);
  result = memmove((int)v5, v2, 0x28u);
  if ( v5[7] == 1 )
  {
    if ( a2 )
      v5[5] = 0;
    else
      a2 = v5[4];
    result = BapdWriteEtwEvents(v2, a2);
  }
  return result;
}
