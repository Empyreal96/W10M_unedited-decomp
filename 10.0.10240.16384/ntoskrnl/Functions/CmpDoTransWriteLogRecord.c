// CmpDoTransWriteLogRecord 
 
int __fastcall CmpDoTransWriteLogRecord(int a1, int a2, int a3)
{
  int v3; // r8
  int v4; // r4
  int v5; // r0
  _DWORD *v6; // r7
  unsigned int v7; // r5
  unsigned int v8; // r6
  unsigned int v9; // r3
  int v10; // r4
  int v11; // r3
  int v12; // r9
  _DWORD *v15; // [sp+28h] [bp-28h] BYREF
  int v16; // [sp+2Ch] [bp-24h]

  v15 = (_DWORD *)a2;
  v16 = a3;
  v3 = a2;
  v4 = ClfsReserveAndAppendLog(*(_DWORD *)(a1 + 56), &v15);
  if ( v4 == -1073741789 )
  {
    v5 = ExAllocatePoolWithTag(1, 3072, 538987843);
    v6 = (_DWORD *)v5;
    if ( v5 )
    {
      v7 = *(_DWORD *)(v3 + 4);
      v8 = 3020;
      v9 = v7;
      if ( v7 >= 0xBCC )
      {
        v10 = 0;
        while ( v9 >= 0xBCC )
        {
          v9 -= 3020;
          ++v10;
          if ( !v9 )
            goto LABEL_10;
        }
        ++v10;
LABEL_10:
        memmove(v5, v3, 0x28u);
        v11 = v6[3];
        v6[10] = v10;
        v12 = 0;
        v6[3] = v11 | 0x80000000;
        v15 = v6;
        do
        {
          memmove((int)(v6 + 13), v3, v8);
          v6[11] = v12;
          v6[12] = v8;
          v16 = v8 + 52;
          ++v12;
          v4 = ClfsReserveAndAppendLog(*(_DWORD *)(a1 + 56), &v15);
          if ( v4 < 0 )
            break;
          v7 -= v8;
          v3 += v8;
          if ( v7 < v8 )
            v8 = v7;
        }
        while ( v7 );
      }
      ExFreePoolWithTag((unsigned int)v6);
    }
    else
    {
      v4 = -1073741670;
    }
  }
  return v4;
}
