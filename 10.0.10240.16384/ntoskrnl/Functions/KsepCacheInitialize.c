// KsepCacheInitialize 
 
int __fastcall KsepCacheInitialize(int a1, int a2, int a3, int a4)
{
  _DWORD *v7; // r0
  _DWORD *v8; // r5
  int v9; // r0
  unsigned int i; // r2
  _DWORD *v12; // r3

  v7 = (_DWORD *)KsepPoolAllocatePaged(60);
  v8 = v7;
  if ( !v7 )
    JUMPOUT(0x7CF136);
  v7[4] = 256;
  v7[5] = v7 + 5;
  v7[6] = v7 + 5;
  v7[12] = a2;
  v7[13] = a3;
  v7[14] = a4;
  v7[2] = 223;
  v9 = KsepPoolAllocatePaged(1784);
  v8[3] = v9;
  if ( !v9 )
    return sub_7CF130();
  for ( i = 0; i < v8[2]; ++i )
  {
    v12 = (_DWORD *)(v8[3] + 8 * i);
    *v12 = v12;
    v12[1] = v12;
  }
  *v8 = 0;
  return (int)v8;
}
