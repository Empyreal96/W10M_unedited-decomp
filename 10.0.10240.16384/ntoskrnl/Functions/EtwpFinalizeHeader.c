// EtwpFinalizeHeader 
 
int __fastcall EtwpFinalizeHeader(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // r8
  unsigned int v7; // r7
  int v8; // r6
  int v9; // r4
  int v10; // r0
  int v11; // r3
  int v12; // r2
  unsigned int v13; // r3
  unsigned int v14; // r3
  unsigned int v15; // r0
  unsigned int v16; // r1
  unsigned __int64 v17; // kr00_8

  v3 = a1 + 20;
  if ( (_DWORD *)a1[20] == a1 + 20 )
    return sub_81B258();
  v7 = a1[1];
  v8 = ExAllocatePoolWithTag(1, (v7 + 4095) & 0xFFFFF000, 1350005829);
  if ( !v8 )
    return -1073741801;
  v9 = ZwReadFile();
  if ( v9 >= 0 )
  {
    if ( !a3 )
    {
      *(_DWORD *)(v8 + 140) = a1[44];
      if ( (a1[3] & 0x10000000) != 0 )
        v11 = 1;
      else
        v11 = KeNumberProcessors_0;
      *(_DWORD *)(v8 + 116) = v11;
      v12 = a1[42];
      __dmb(0xBu);
      *(_DWORD *)(v8 + 152) += v12;
      KeQuerySystemTimePrecise((__int64 *)(v8 + 120));
      *(_DWORD *)(v8 + 372) += a1[45];
    }
    if ( (_DWORD *)a1[158] != a1 + 158 || (_DWORD *)*v3 != v3 )
    {
      v13 = *(_DWORD *)(v8 + 4);
      if ( v13 < v7 && v13 >= 0x178 )
      {
        *(_DWORD *)(v8 + 48) = v13;
        if ( (_DWORD *)*v3 != v3 )
          EtwpAddDebugInfoEvents((int)a1, v8, v7, v8 + 88, 3);
        if ( (_DWORD *)a1[158] != a1 + 158 )
          EtwpAddBinaryInfoEvents(a1, v8, v7);
      }
    }
    v10 = ZwWriteFile();
    v9 = v10;
    if ( !a3 && v10 >= 0 && (a1[3] & 0x20) != 0 )
    {
      v14 = a1[54];
      if ( (a1[3] & 0x2000) != 0 )
      {
        v17 = (unsigned __int64)v14 << 10;
        v15 = HIDWORD(v17);
        v16 = v17;
      }
      else
      {
        v15 = v14 >> 12;
        v16 = a1[54] << 20;
      }
      if ( (unsigned int)a1[44] * (unsigned __int64)(unsigned int)a1[1] < __PAIR64__(v15, v16) )
        v9 = ZwSetInformationFile();
    }
  }
  ExFreePoolWithTag(v8);
  return v9;
}
