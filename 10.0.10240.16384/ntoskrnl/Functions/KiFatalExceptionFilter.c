// KiFatalExceptionFilter 
 
int __fastcall KiFatalExceptionFilter(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  unsigned int *v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r0
  int result; // r0
  int v10; // [sp+8h] [bp-10h] BYREF
  int v11[3]; // [sp+Ch] [bp-Ch] BYREF

  v10 = a3;
  v11[0] = a4;
  v4 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  *(_DWORD *)(v4 + 2436) = (unsigned int)KiServiceTablesLocked & 0xFFFFFFFE;
  RtlCaptureImageExceptionValues(0x400000, &v10, (int)v11);
  if ( !v10 )
    sub_965078();
  v5 = RtlpSearchFunctionTable(v10, (unsigned int)v11[0] >> 3, (int)KiServiceTablesLocked, 0x400000);
  if ( !v5 )
    KeBugCheck(49);
  v8 = RtlLookupExceptionHandler((int)v5, v6, v7, (int)v11, v11, 0);
  if ( v8 < 0 )
    KeBugCheckEx(49, v8, 0, 0, 0);
  result = 0;
  *(_DWORD *)(v4 + 2432) = v11[0];
  KdpSecondaryFreezeLock = 0;
  return result;
}
