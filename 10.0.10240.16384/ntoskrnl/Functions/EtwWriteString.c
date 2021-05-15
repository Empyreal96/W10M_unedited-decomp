// EtwWriteString 
 
int __fastcall EtwWriteString(int a1, int a2, unsigned int a3, int a4, __int64 a5, _DWORD *a6, unsigned __int16 *a7)
{
  unsigned __int16 *v8; // r10
  int v9; // r8
  int v11; // r3
  unsigned int v12; // r0
  int v13; // lr
  int v14; // r0
  int v15; // r0
  int v17[2]; // [sp+38h] [bp-50h] BYREF
  __int64 v18; // [sp+40h] [bp-48h]
  _DWORD v19[2]; // [sp+48h] [bp-40h] BYREF
  _DWORD v20[2]; // [sp+50h] [bp-38h] BYREF
  _DWORD v21[12]; // [sp+58h] [bp-30h] BYREF

  v20[0] = 0;
  v20[1] = 0;
  v19[0] = 0;
  v19[1] = 0;
  v8 = 0;
  v9 = 0;
  if ( !a1 )
    return -1073741816;
  v11 = *(_DWORD *)(a1 + 56);
  if ( v11 )
    v8 = (unsigned __int16 *)(v11 + 16);
  v18 = a5;
  v17[0] = 0;
  v17[1] = (unsigned __int8)a3;
  v12 = wcslen(a7);
  v21[0] = a7;
  v21[1] = 0;
  v13 = *(unsigned __int8 *)(a1 + 51);
  v21[2] = 2 * (v12 + 1);
  v21[3] = 0;
  if ( v13 )
  {
    v14 = *(_DWORD *)(a1 + 16);
    if ( *(_DWORD *)(v14 + 56) )
    {
      if ( (a3 <= *(unsigned __int8 *)(v14 + 60) || !*(_BYTE *)(v14 + 60))
        && ((*(_DWORD *)(v14 + 64) & 0x40) != 0 && !a5
         || (*(_QWORD *)(v14 + 72) & a5) != 0 && (*(_QWORD *)(v14 + 80) & a5) == *(_QWORD *)(v14 + 80)) )
      {
        v9 = EtwpEventWriteFull(
               (_DWORD *)v14,
               v13,
               0,
               0,
               0,
               (unsigned __int16 *)v17,
               4u,
               0,
               a6,
               0,
               1u,
               (int)v21,
               0,
               v19,
               0,
               *(_BYTE *)(a1 + 53),
               v8,
               v20);
      }
    }
  }
  if ( *(_BYTE *)(a1 + 52) )
  {
    v15 = *(_DWORD *)(a1 + 20);
    if ( *(_DWORD *)(v15 + 56) )
    {
      if ( (a3 <= *(unsigned __int8 *)(v15 + 60) || !*(_BYTE *)(v15 + 60))
        && ((*(_DWORD *)(v15 + 64) & 0x40) != 0 && !a5
         || (*(_QWORD *)(v15 + 72) & a5) != 0 && (*(_QWORD *)(v15 + 80) & a5) == *(_QWORD *)(v15 + 80)) )
      {
        v9 = EtwpEventWriteFull(
               *(_DWORD **)(a1 + 16),
               *(unsigned __int8 *)(a1 + 52),
               0,
               0,
               0,
               (unsigned __int16 *)v17,
               4u,
               0,
               a6,
               0,
               1u,
               (int)v21,
               0,
               v19,
               v15,
               *(_BYTE *)(a1 + 53),
               v8,
               v20);
      }
    }
  }
  return v9;
}
