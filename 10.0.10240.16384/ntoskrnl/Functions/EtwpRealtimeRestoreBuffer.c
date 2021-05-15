// EtwpRealtimeRestoreBuffer 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpRealtimeRestoreBuffer(int a1, int a2)
{
  int v4; // r7 OVERLAPPED
  int v5; // r8 OVERLAPPED
  __int64 v6; // kr08_8
  int result; // r0
  unsigned int v8; // r1
  unsigned int v9; // r2
  unsigned int v10; // r5
  int v11; // [sp+18h] [bp-28h]
  int v12; // [sp+1Ch] [bp-24h]

  v6 = *(_QWORD *)(a1 + 296) + 72i64;
  v5 = HIDWORD(v6);
  v4 = v6;
  if ( v6 > *(_QWORD *)(a1 + 304) )
    return -1073741566;
  result = ZwReadFile();
  if ( result < 0 )
    return result;
  if ( v11 < 0 )
    return v11;
  if ( v12 != 72 )
    return -1073741807;
  v8 = *(_DWORD *)(a1 + 4);
  if ( *(_DWORD *)a2 != v8 )
    return -1073741566;
  v9 = *(_DWORD *)(a2 + 48);
  if ( v9 < 0x48 || v9 > v8 )
    return -1073741566;
  v10 = v9 - 72;
  *(_WORD *)(a2 + 52) |= 0x10u;
  *(_QWORD *)(a1 + 296) = *(_QWORD *)&v4;
  if ( v9 != 72 )
  {
    if ( v6 + v10 <= *(_QWORD *)(a1 + 304) )
    {
      result = ZwReadFile();
      if ( result >= 0 )
      {
        result = v11;
        if ( v12 != v10 )
          result = -1073741807;
      }
      *(_QWORD *)(a1 + 296) += v10;
      goto LABEL_15;
    }
    return -1073741566;
  }
LABEL_15:
  if ( *(_QWORD *)(a1 + 296) >= *(_QWORD *)(a1 + 304) )
  {
    *(_DWORD *)(a1 + 296) = 72;
    *(_DWORD *)(a1 + 300) = 0;
  }
  return result;
}
