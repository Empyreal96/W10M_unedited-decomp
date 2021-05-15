// MiPfIssueCoalescedSupport 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiPfIssueCoalescedSupport(_DWORD *a1, unsigned int a2)
{
  int v4; // r0
  int v5; // r6
  _DWORD *v6; // lr
  int v7; // r0
  unsigned int v8; // r9 OVERLAPPED
  unsigned int v9; // r10 OVERLAPPED
  _DWORD *v10; // r7
  __int64 v11; // r2
  _DWORD *v12; // r1
  int v13; // r3
  __int64 v14; // r2
  unsigned int v15; // r5
  unsigned int v16; // r4
  unsigned int v17; // r3
  int v18; // r0
  _DWORD *v20; // [sp+8h] [bp-38h]
  int v21; // [sp+Ch] [bp-34h]
  int v22; // [sp+10h] [bp-30h]
  __int64 v23[5]; // [sp+18h] [bp-28h] BYREF

  v4 = ExAllocatePoolWithTag(512, 4 * ((a2 >> 12) + 45));
  v5 = v4;
  if ( !v4 )
    return 0;
  MiInitializeInPageSupport(v4, 0);
  *(_BYTE *)(v5 + 115) |= 0x40u;
  *(_WORD *)(v5 + 156) = 4 * (((a2 + 4095) >> 12) + 7);
  *(_DWORD *)(v5 + 152) = 0;
  *(_WORD *)(v5 + 158) = 0;
  *(_DWORD *)(v5 + 168) = 0;
  *(_DWORD *)(v5 + 172) = a2;
  *(_DWORD *)(v5 + 176) = 0;
  v6 = (_DWORD *)(v5 + 180);
  *(_WORD *)(v5 + 158) |= 0x4042u;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v22 = MmBadPointer;
  while ( 1 )
  {
    v10 = (_DWORD *)*a1;
    v20 = v6;
    v21 = v7;
    if ( (_DWORD *)*a1 == a1 )
      break;
    v11 = *(_QWORD *)v10;
    if ( (_DWORD *)v10[1] != a1 || *(_DWORD **)(v11 + 4) != v10 )
      __fastfail(3u);
    *a1 = v11;
    *(_DWORD *)(v11 + 4) = a1;
    v12 = *(_DWORD **)(v5 + 12);
    *v10 = v5 + 8;
    v10[1] = v12;
    if ( *v12 != v5 + 8 )
      __fastfail(3u);
    *v12 = v10;
    *(_DWORD *)(v5 + 12) = v10;
    if ( (*((_WORD *)v10 + 79) & 0x4000) == 0 )
      *(_WORD *)(v5 + 158) &= 0xBFFFu;
    if ( v7 )
    {
      LODWORD(v14) = v10[15];
      HIDWORD(v14) = v10[14];
      if ( __PAIR64__(v8, v9) != v14 )
      {
        *(_WORD *)(v5 + 158) &= 0xBFFFu;
        v15 = v10[14] - v8;
        RtlFillMemoryUlong(v6, 4 * (v15 >> 12), dword_6348FC);
        v6 += (4 * (v15 >> 12)) >> 2;
        v9 = (__PAIR64__(v9, v8) + v15) >> 32;
        v8 += v15;
        v20 += (4 * (v15 >> 12)) >> 2;
        v21 += v15;
      }
    }
    else
    {
      *(_QWORD *)&v8 = *((_QWORD *)v10 + 7);
      v13 = v10[29];
      v23[0] = *(_QWORD *)&v8;
      v22 = v13;
    }
    v16 = 4 * (v10[26] >> 12);
    memmove((int)v6, (int)(v10 + 45), v16);
    v6 = &v20[v16 >> 2];
    v17 = v10[26];
    v9 = (__PAIR64__(v9, v8) + v17) >> 32;
    v8 += v17;
    v7 = v21 + v17;
  }
  v18 = IoPageRead(v22 | 2, (v5 + 152) | 1, v23, v5 + 16, v5 + 48);
  if ( v18 < 0 )
  {
    *(_DWORD *)(v5 + 48) = v18;
    *(_DWORD *)(v5 + 52) = 0;
    KeSetEvent(v5 + 16, 0, 0);
  }
  return v5;
}
