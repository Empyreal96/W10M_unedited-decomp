// EtwpSendDataBlock 
 
int __fastcall EtwpSendDataBlock(int a1, unsigned int a2)
{
  int v3; // r8
  __int64 v5; // kr00_8
  unsigned int v6; // r0
  unsigned int v7; // r1
  int v8; // r4
  __int64 v9; // kr08_8
  unsigned int v10; // r3
  int v11; // r2
  int v12; // r4
  __int64 v13; // kr10_8
  int v14; // [sp+20h] [bp-68h]
  int v15; // [sp+24h] [bp-64h]
  void (__fastcall *v16)(int, int, int); // [sp+28h] [bp-60h]
  int v17; // [sp+30h] [bp-58h] BYREF
  __int64 v18; // [sp+34h] [bp-54h]
  int v19; // [sp+3Ch] [bp-4Ch]
  __int64 v20; // [sp+40h] [bp-48h]
  int v21; // [sp+48h] [bp-40h]
  int v22; // [sp+4Ch] [bp-3Ch]

  v3 = 0;
  if ( (*(_BYTE *)(a1 + 50) & 1) == 0 )
  {
    if ( (*(_BYTE *)(a1 + 50) & 2) != 0 )
      v3 = EtwpQueueNotification(*(_DWORD *)(a1 + 40), a2, a1);
    return v3;
  }
  v5 = *(_QWORD *)(a1 + 40);
  if ( !HIDWORD(v5) )
    return v3;
  if ( (*(_BYTE *)(a1 + 50) & 0x10) == 0 )
  {
    if ( *(_DWORD *)a2 != 3 )
      return -1073741811;
    if ( (*(_BYTE *)(a1 + 50) & 8) != 0 )
    {
      v8 = *(_DWORD *)(a1 + 16);
      LOWORD(v17) = *(_WORD *)(v8 + 48);
      HIWORD(v17) = *(unsigned __int8 *)(v8 + 50);
      v9 = *(_QWORD *)(v8 + 40);
      v19 = 0;
      v18 = v9;
      (*(void (__fastcall **)(int, _DWORD, int *, _DWORD))(a1 + 44))(
        v8 + 12,
        (unsigned __int8)*(_DWORD *)(a2 + 112),
        &v17,
        v5);
    }
    else
    {
      v16 = *(void (__fastcall **)(int, int, int))(a1 + 44);
      v14 = *(unsigned __int8 *)(a2 + 76);
      v15 = *(_DWORD *)(a2 + 72);
      if ( !v15 )
        v14 = 0;
      v6 = *(_DWORD *)(a2 + 116);
      v7 = 0;
      if ( v6 )
      {
        v10 = a2 + 120;
        while ( 1 )
        {
          v11 = *(_DWORD *)(v10 + 12);
          if ( (v11 & 0x80000000) == 0 || v11 == 0x80000000 )
            break;
          ++v7;
          v10 += 16;
          if ( v7 >= v6 )
            goto LABEL_13;
        }
        v12 = a2 + 120 + 16 * v7;
        v13 = *(_QWORD *)v12;
        v22 = *(_DWORD *)(v10 + 12);
        v20 = v13 + a2;
        v21 = *(_DWORD *)(v12 + 8);
      }
LABEL_13:
      v16(a2 + 56, v15, v14);
    }
    return v3;
  }
  return sub_80850C();
}
