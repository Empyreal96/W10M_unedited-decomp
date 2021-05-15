// EtwpDiskProvTraceDisk 
 
int __fastcall EtwpDiskProvTraceDisk(int result, int a2, int a3, _DWORD *a4)
{
  int v5; // r5
  int *v7; // r4
  int v8; // r3
  unsigned __int16 *v9; // r8
  __int64 v10; // kr00_8
  __int64 v11; // kr08_8
  _DWORD v13[2]; // [sp+40h] [bp-30h] BYREF
  _DWORD v14[10]; // [sp+48h] [bp-28h] BYREF

  v5 = EtwpDiskProvRegHandle;
  v14[0] = 0;
  v14[1] = 0;
  v13[0] = 0;
  v13[1] = 0;
  if ( EtwpDiskProvRegHandle )
  {
    if ( result == 266 )
    {
      v7 = &KDskEvt_Read;
    }
    else if ( result == 270 )
    {
      v7 = &KDskEvt_Flush;
    }
    else
    {
      v7 = &KDskEvt_Write;
    }
    *(_DWORD *)(a2 + 8) -= 4;
    v8 = *(_DWORD *)(v5 + 56);
    if ( v8 )
      v9 = (unsigned __int16 *)(v8 + 16);
    else
      v9 = 0;
    if ( *(_BYTE *)(v5 + 51) )
    {
      result = *(_DWORD *)(v5 + 16);
      v10 = *((_QWORD *)v7 + 1);
      if ( *(_DWORD *)(result + 56) )
      {
        if ( (*((unsigned __int8 *)v7 + 4) <= (unsigned int)*(unsigned __int8 *)(result + 60) || !*(_BYTE *)(result + 60))
          && ((*(_DWORD *)(result + 64) & 0x40) != 0 && !v10
           || (*(_QWORD *)(result + 72) & v10) != 0 && (*(_QWORD *)(result + 80) & v10) == *(_QWORD *)(result + 80)) )
        {
          result = EtwpEventWriteFull(
                     (_DWORD *)result,
                     *(unsigned __int8 *)(v5 + 51),
                     0,
                     0,
                     0,
                     (unsigned __int16 *)v7,
                     0,
                     0,
                     a4,
                     0,
                     1u,
                     a2,
                     a3,
                     v14,
                     0,
                     *(_BYTE *)(v5 + 53),
                     v9,
                     v13);
        }
      }
    }
    if ( *(_BYTE *)(v5 + 52) )
    {
      result = *(_DWORD *)(v5 + 20);
      v11 = *((_QWORD *)v7 + 1);
      if ( *(_DWORD *)(result + 56) )
      {
        if ( (*((unsigned __int8 *)v7 + 4) <= (unsigned int)*(unsigned __int8 *)(result + 60) || !*(_BYTE *)(result + 60))
          && ((*(_DWORD *)(result + 64) & 0x40) != 0 && !v11
           || (*(_QWORD *)(result + 72) & v11) != 0 && (*(_QWORD *)(result + 80) & v11) == *(_QWORD *)(result + 80)) )
        {
          result = EtwpEventWriteFull(
                     *(_DWORD **)(v5 + 16),
                     *(unsigned __int8 *)(v5 + 52),
                     0,
                     0,
                     0,
                     (unsigned __int16 *)v7,
                     0,
                     0,
                     a4,
                     0,
                     1u,
                     a2,
                     a3,
                     v14,
                     result,
                     *(_BYTE *)(v5 + 53),
                     v9,
                     v13);
        }
      }
    }
  }
  return result;
}
