// RtlLookupExceptionHandler 
 
int __fastcall RtlLookupExceptionHandler(int a1, int a2, int a3, int a4, int *a5, _DWORD *a6)
{
  int v6; // r3
  int v7; // r1
  unsigned int v8; // r2
  int v9; // r3
  unsigned int v10; // r0
  int v12; // r5
  _DWORD *v13; // r4
  _DWORD *v14; // r2

  v6 = *(_DWORD *)(a1 + 4);
  v7 = v6 + 4194308;
  v8 = *(_DWORD *)(v6 + 0x400000);
  if ( (v8 & 0xC0000) != 0 )
    return -1073741823;
  v9 = (v8 >> 23) & 0x1F;
  v10 = v8 >> 28;
  if ( !v9 )
    return sub_50A6A8(v10, v7);
  if ( (v8 & 0x200000) != 0 )
    v9 = 0;
  v12 = 0;
  v13 = 0;
  if ( (v8 & 0x100000) != 0 )
  {
    v14 = (_DWORD *)(v7 + 4 * (v9 + v10));
    v12 = *v14 + 0x400000;
    v13 = v14 + 1;
  }
  if ( a5 )
    *a5 = v12;
  if ( a6 )
    *a6 = v13;
  return 0;
}
