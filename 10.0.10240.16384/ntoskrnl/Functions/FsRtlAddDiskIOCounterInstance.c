// FsRtlAddDiskIOCounterInstance 
 
int __fastcall FsRtlAddDiskIOCounterInstance(int a1)
{
  unsigned int v1; // r7
  unsigned int v2; // r6
  unsigned int v4; // lr
  __int64 v5; // r8
  void **v6; // r4
  _QWORD *v7; // r1
  unsigned __int64 v8; // kr00_8
  char v10[8]; // [sp+10h] [bp-38h] BYREF
  unsigned __int64 v11; // [sp+18h] [bp-30h]
  __int64 v12; // [sp+20h] [bp-28h]

  v1 = 0;
  v2 = 0;
  v11 = 0i64;
  v4 = 0;
  v5 = 0i64;
  v12 = 0i64;
  if ( KeNumberProcessors_0 )
  {
    v6 = &KiProcessorBlock;
    if ( !KeNumberProcessors_0 )
    {
      v7 = 0;
      goto LABEL_5;
    }
    do
    {
      v7 = *v6;
LABEL_5:
      v8 = __PAIR64__(v4, v1) + v7[487];
      v4 = HIDWORD(v8);
      v1 = v8;
      v11 = v8;
      v5 += v7[488];
      ++v2;
      ++v6;
      v12 = v5;
    }
    while ( v2 < KeNumberProcessors_0 );
  }
  RtlInitUnicodeString((unsigned int)v10, L"default");
  return PcwAddInstance(a1, (int)v10, 0, 1);
}
