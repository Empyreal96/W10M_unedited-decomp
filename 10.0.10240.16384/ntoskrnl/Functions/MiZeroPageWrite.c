// MiZeroPageWrite 
 
int __fastcall MiZeroPageWrite(int a1, _QWORD *a2, unsigned int a3, int a4)
{
  _DWORD *v4; // lr
  unsigned int v5; // r10
  char *v6; // r4
  __int16 v7; // r8
  unsigned int v10; // r7
  int v11; // r2
  __int16 v12; // r0
  unsigned int v13; // r6
  unsigned int v14; // r9
  _DWORD *v15; // r1
  unsigned int v16; // r2
  int v17; // r2
  int v18; // r5
  int v19; // [sp+8h] [bp-A8h]
  char v21[4]; // [sp+10h] [bp-A0h] BYREF
  int v22; // [sp+14h] [bp-9Ch]
  _DWORD v23[2]; // [sp+18h] [bp-98h] BYREF
  int v24; // [sp+20h] [bp-90h]
  int v25; // [sp+24h] [bp-8Ch]
  int v26[2]; // [sp+28h] [bp-88h] BYREF
  char v27[128]; // [sp+30h] [bp-80h] BYREF

  v4 = a2;
  v5 = (a3 + 4095) >> 12;
  v6 = 0;
  v7 = a3;
  v25 = a1;
  if ( a4 )
    return sub_5275C8();
  if ( a3 > 0x10000 )
  {
    v4 = a2;
    v6 = (char *)IoAllocateMdl(0, a3, 0, 0, 0);
  }
  v10 = (a3 + 4095) >> 12;
  if ( v6 )
  {
    v11 = *((__int16 *)v6 + 3);
  }
  else
  {
    if ( v10 > 0x10 )
      v10 = 16;
    v11 = 0;
    v6 = v27;
  }
  v12 = v11 | 0x4002;
  v19 = 0;
  v24 = v11 | 0x4002;
  v13 = v10;
  do
  {
    if ( v13 > v5 )
      v13 = v5;
    v14 = v13 << 12;
    if ( v5 == v13 )
    {
      v10 = v5;
      if ( (v7 & 0xFFF) != 0 )
        v14 = (v7 & 0xFFF | v14) - 4096;
    }
    *((_WORD *)v6 + 2) = 4 * (((v14 + 4095) >> 12) + 7);
    *(_DWORD *)v6 = 0;
    *((_DWORD *)v6 + 4) = 0;
    *((_DWORD *)v6 + 5) = v14;
    *((_DWORD *)v6 + 6) = 0;
    *((_WORD *)v6 + 3) = v12;
    v15 = v6 + 28;
    if ( v13 )
    {
      v16 = v13;
      do
      {
        --v16;
        *v15++ = dword_634900;
      }
      while ( v16 );
    }
    v21[0] = 0;
    v21[1] = 0;
    v21[2] = 4;
    v22 = 0;
    v23[0] = v23;
    v23[1] = v23;
    v26[0] = 0;
    v26[1] = 0;
    v18 = IoSynchronousPageWriteEx(v25, v6, v4, (int)v21, 0, (int)v26);
    if ( v18 >= 0 )
    {
      KeWaitForSingleObject((unsigned int)v21, 19, 0, 0, 0);
      v18 = v26[0];
    }
    if ( (*((_WORD *)v6 + 3) & 0x200) != 0 )
      MiRetardMdl(v6);
    if ( (*((_WORD *)v6 + 3) & 1) != 0 )
      MmUnmapLockedPages(*((_DWORD *)v6 + 3), (int)v6, v17);
    if ( v18 >= 0 )
    {
      v4 = a2;
      v5 -= v13;
      *a2 += v14;
      if ( v19 )
      {
        --v19;
      }
      else if ( v13 < v10 )
      {
        v13 = v10;
      }
      goto LABEL_26;
    }
    v19 = 8;
    if ( v18 != -1073741670
      && v18 != -1073741663
      && v18 != -1073741801
      && (v14 <= 0x1000 || FsRtlIsTotalDeviceFailure(v18)) )
    {
      break;
    }
    if ( v13 == 1 )
      break;
    v4 = a2;
    v13 >>= 1;
LABEL_26:
    v12 = v24;
  }
  while ( v5 );
  if ( v6 != v27 )
    IoFreeMdl((int)v6);
  return v18;
}
