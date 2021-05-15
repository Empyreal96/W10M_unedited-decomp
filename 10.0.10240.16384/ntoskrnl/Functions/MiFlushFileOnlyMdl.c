// MiFlushFileOnlyMdl 
 
int __fastcall MiFlushFileOnlyMdl(int a1, _DWORD *a2, int a3, int *a4)
{
  unsigned int v6; // r8
  int v8; // r0
  int v9; // r5
  int v10; // r4
  int v11; // r0
  int v12; // r1
  int result; // r0
  int *v14; // [sp+8h] [bp-20h] BYREF

  v14 = a4;
  v6 = (a2[5] + (((unsigned __int16)a2[6] + (unsigned __int16)a2[4]) & 0xFFFu) + 4095) >> 12;
  *a4 = 0;
  a4[1] = 0;
  if ( v6 )
  {
    v8 = a2[7];
    v9 = MmPfnDatabase + 24 * v8;
    v10 = MiMapPageInHyperSpaceWorker(v8, (int)&v14, 0x80000000);
    KeInvalidatePage(v10, a2[7], a2[7] << 12, (unsigned __int64)(unsigned int)a2[7] >> 20);
    MiUnmapPageInHyperSpaceWorker(v10, (unsigned __int8)v14, 0x80000000);
    v11 = MiReadyFlushMdlToWrite((int)a2, *(_DWORD *)(v9 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v9 + 8) & 0x3FC)), 0);
    MiIssueSynchronousFlush(a1, (int)a2, v11, v12);
    if ( *a4 >= 0 && ((a4[1] + 4095) & 0xFFFFF000) < v6 << 12 )
      *a4 = -1073741801;
    result = *a4;
  }
  else
  {
    *(_QWORD *)a4 = 0i64;
    result = 0;
  }
  return result;
}
