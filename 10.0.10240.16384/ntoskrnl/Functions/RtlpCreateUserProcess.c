// RtlpCreateUserProcess 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlpCreateUserProcess(unsigned __int16 *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, _BYTE *a11)
{
  int v12; // r1
  int v13; // r4 OVERLAPPED
  int *v14; // r2
  int v15; // r3
  int v17[14]; // [sp+28h] [bp-128h] BYREF
  int v18[18]; // [sp+60h] [bp-F0h] BYREF
  int v19[42]; // [sp+A8h] [bp-A8h] BYREF

  memset(a11, 0, 68);
  *(_DWORD *)a11 = 68;
  v17[8] = 24;
  v17[9] = 0;
  v17[10] = 0;
  v17[12] = 0;
  v17[13] = 0;
  v17[2] = 24;
  v17[11] = 512;
  v17[5] = 512;
  v17[3] = 0;
  v17[4] = 0;
  v17[6] = 0;
  v17[7] = 0;
  memset(v18, 0, sizeof(v18));
  v18[0] = 72;
  v12 = 2;
  LOBYTE(v18[2]) |= 4u;
  v19[1] = 65539;
  v19[2] = 8;
  v19[4] = 0;
  v19[3] = (int)(a11 + 12);
  v19[5] = 6;
  v19[6] = 48;
  v19[8] = 0;
  v19[7] = (int)(a11 + 20);
  if ( a1 )
  {
    v19[9] = 131077;
    v19[10] = *a1;
    v19[12] = 0;
    v19[11] = *((_DWORD *)a1 + 1);
    v17[0] = v17[0] & 0xFFFFFFE0 | 2;
    v19[13] = 131082;
    v19[14] = 8;
    v19[16] = 0;
    v19[15] = (int)v17;
    v12 = 4;
  }
  v13 = 1;
  if ( ((a7 | 0x100) & 0x40) != 0 )
  {
    v14 = &v19[4 * v12];
    v15 = 393233;
    *(_QWORD *)(v14 + 1) = *(_QWORD *)(&v13 - 1);
    v14[4] = 0;
    v14[3] = 97;
    ++v12;
  }
  v19[0] = 16 * v12 + 4;
  return ZwCreateUserProcess();
}
