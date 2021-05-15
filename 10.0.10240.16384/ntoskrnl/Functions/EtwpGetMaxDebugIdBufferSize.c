// EtwpGetMaxDebugIdBufferSize 
 
int __fastcall EtwpGetMaxDebugIdBufferSize(int a1)
{
  _DWORD *v1; // r2
  _DWORD *v3; // r0
  int v4; // r1
  int v5; // r3

  v1 = (_DWORD *)(a1 + 80);
  if ( *(_DWORD *)(a1 + 80) == a1 + 80 )
    return 0;
  v3 = *(_DWORD **)(a1 + 80);
  v4 = 56;
  while ( v3 != v1 )
  {
    v5 = v3[3];
    v3 = (_DWORD *)*v3;
    v4 += (v5 + 19) & 0xFFFFFFF8;
  }
  return v4 + 72;
}
