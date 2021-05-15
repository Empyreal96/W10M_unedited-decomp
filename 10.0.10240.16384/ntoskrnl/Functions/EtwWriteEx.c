// EtwWriteEx 
 
int __fastcall EtwWriteEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int result; // r0
  int v14; // r3
  int v15; // r5
  int v16; // r7
  __int64 v17; // kr00_8
  int v18; // r7
  __int64 v19; // r8
  _DWORD v20[2]; // [sp+38h] [bp-30h] BYREF
  _DWORD v21[10]; // [sp+40h] [bp-28h] BYREF

  result = 0;
  v20[0] = 0;
  v20[1] = 0;
  v21[0] = 0;
  v21[1] = 0;
  if ( !a1 )
    return sub_50A50C(0);
  v14 = *(_DWORD *)(a1 + 56);
  if ( v14 )
    v15 = v14 + 16;
  else
    v15 = 0;
  if ( *(_BYTE *)(a1 + 51) )
  {
    v16 = *(_DWORD *)(a1 + 16);
    v17 = *(_QWORD *)(a3 + 8);
    if ( *(_DWORD *)(v16 + 56) )
    {
      if ( (*(unsigned __int8 *)(a3 + 4) <= (unsigned int)*(unsigned __int8 *)(v16 + 60) || !*(_BYTE *)(v16 + 60))
        && ((*(_DWORD *)(v16 + 64) & 0x40) != 0 && !v17
         || (*(_QWORD *)(v16 + 72) & v17) != 0 && (*(_QWORD *)(v16 + 80) & v17) == *(_QWORD *)(v16 + 80)) )
      {
        result = ((int (__fastcall *)(int, _DWORD, int, int, int, int, _DWORD, _DWORD, int, int, int, int, _DWORD, _DWORD *, _DWORD, _DWORD, int, _DWORD *))EtwpEventWriteFull)(
                   v16,
                   *(unsigned __int8 *)(a1 + 51),
                   a5,
                   a6,
                   a7,
                   a3,
                   0,
                   0,
                   a8,
                   a9,
                   a10,
                   a11,
                   0,
                   v21,
                   0,
                   *(unsigned __int8 *)(a1 + 53),
                   v15,
                   v20);
      }
    }
  }
  if ( *(_BYTE *)(a1 + 52) )
  {
    v18 = *(_DWORD *)(a1 + 20);
    v19 = *(_QWORD *)(a3 + 8);
    if ( *(_DWORD *)(v18 + 56) )
    {
      if ( (*(unsigned __int8 *)(a3 + 4) <= (unsigned int)*(unsigned __int8 *)(v18 + 60) || !*(_BYTE *)(v18 + 60))
        && ((*(_DWORD *)(v18 + 64) & 0x40) != 0 && !v19
         || (*(_QWORD *)(v18 + 72) & v19) != 0 && (*(_QWORD *)(v18 + 80) & v19) == *(_QWORD *)(v18 + 80)) )
      {
        result = ((int (__fastcall *)(_DWORD, _DWORD, int, int, int, int, _DWORD, _DWORD, int, int, int, int, _DWORD, _DWORD *, int, _DWORD, int, _DWORD *))EtwpEventWriteFull)(
                   *(_DWORD *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 52),
                   a5,
                   a6,
                   a7,
                   a3,
                   0,
                   0,
                   a8,
                   a9,
                   a10,
                   a11,
                   0,
                   v21,
                   v18,
                   *(unsigned __int8 *)(a1 + 53),
                   v15,
                   v20);
      }
    }
  }
  return result;
}
