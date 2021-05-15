// EtwpAllocDataBlock 
 
int __fastcall EtwpAllocDataBlock(unsigned int a1, int a2, _DWORD *a3)
{
  int v4; // r4
  _BYTE *v7; // r0
  _BYTE *v8; // r5

  v4 = 0;
  *a3 = 0;
  if ( a2 && *(_DWORD *)(a2 + 4) != a1 )
    return -1073741820;
  v7 = (_BYTE *)ExAllocatePoolWithTag(1, a1, 1148679237);
  v8 = v7;
  if ( !v7 )
    return -1073741801;
  if ( a2 )
    memmove((int)v7, a2, a1);
  else
    memset(v7, 0, a1);
  *((_DWORD *)v8 + 2) = 1;
  *a3 = v8;
  return v4;
}
