// KeRegisterProcessorChangeCallback 
 
int __fastcall KeRegisterProcessorChangeCallback(int a1, int a2, char a3)
{
  int v7; // r5
  int v8; // r6
  unsigned int v9; // r2
  int v10; // r6
  unsigned __int8 v11; // r5
  unsigned int v12; // r1
  unsigned int v13; // r5
  unsigned int v14; // r8
  void **v15; // r9
  int v16; // t1
  int v17; // r3
  unsigned int v18; // r8
  void (__fastcall *v19)(int, int *, int *); // r4
  void **v20; // r7
  int v21; // t1
  int v22; // [sp+0h] [bp-68h] BYREF
  void (__fastcall *v23)(int, int *, int *); // [sp+4h] [bp-64h]
  int v24; // [sp+8h] [bp-60h] BYREF
  int v25[6]; // [sp+10h] [bp-58h] BYREF
  char v26[8]; // [sp+28h] [bp-40h] BYREF
  int v27; // [sp+30h] [bp-38h] BYREF
  unsigned int v28; // [sp+34h] [bp-34h]
  int v29; // [sp+38h] [bp-30h]
  __int16 v30; // [sp+3Ch] [bp-2Ch]
  char v31; // [sp+3Eh] [bp-2Ah]
  char v32; // [sp+3Fh] [bp-29h]
  char v33[40]; // [sp+40h] [bp-28h] BYREF

  v23 = (void (__fastcall *)(int, int *, int *))a1;
  RtlInitUnicodeString((unsigned int)v26, L"\\Callback\\ProcessorAdd");
  v25[0] = 24;
  v25[1] = 0;
  v25[3] = 576;
  v25[2] = (int)v26;
  v25[4] = 0;
  v25[5] = 0;
  v22 = ExCreateCallback(&v24, v25, 0);
  if ( v22 < 0 )
    return sub_810788();
  v7 = KeAbPreAcquire((unsigned int)&KiDynamicProcessorLock, 0, 0);
  v8 = KfRaiseIrql(1);
  do
    v9 = __ldrex((unsigned __int8 *)&KiDynamicProcessorLock);
  while ( __strex(v9 & 0xFE, (unsigned __int8 *)&KiDynamicProcessorLock) );
  __dmb(0xBu);
  if ( (v9 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&KiDynamicProcessorLock, v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  dword_624E44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_624E5C = v8;
  v10 = ExRegisterCallback(v24, a1, a2);
  ObfDereferenceObject(v24);
  if ( v10 && (a3 & 1) != 0 )
  {
    v13 = 0;
    v14 = KeNumberProcessors_0;
    v32 = 0;
    if ( KeNumberProcessors_0 )
    {
      v15 = &KiProcessorBlock;
      while ( 1 )
      {
        v16 = (int)*v15++;
        v28 = v13;
        v30 = *(unsigned __int8 *)(v16 + 1052);
        v31 = *(_BYTE *)(v16 + 1053);
        v29 = 0;
        HalGetProcessorIdByNtNumber(v13, v33);
        v27 = 0;
        v22 = 0;
        v23(a2, &v27, &v22);
        v17 = v22;
        if ( v22 < 0 )
          break;
        if ( ++v13 >= v14 )
          goto LABEL_23;
      }
    }
    else
    {
      v17 = v22;
LABEL_23:
      if ( v17 >= 0 )
      {
        v27 = 1;
        goto LABEL_26;
      }
    }
    v27 = 2;
    KeDeregisterProcessorChangeCallback(v10);
    v17 = v22;
    v10 = 0;
LABEL_26:
    v29 = v17;
    v18 = 0;
    if ( v13 )
    {
      v19 = v23;
      v20 = &KiProcessorBlock;
      do
      {
        v21 = (int)*v20++;
        v28 = v18;
        v30 = *(unsigned __int8 *)(v21 + 1052);
        v31 = *(_BYTE *)(v21 + 1053);
        HalGetProcessorIdByNtNumber(v18, v33);
        v19(a2, &v27, &v22);
        ++v18;
      }
      while ( v18 < v13 );
    }
  }
  dword_624E44 = 0;
  v11 = dword_624E5C;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&KiDynamicProcessorLock);
  while ( !v12 && __strex(1u, (unsigned int *)&KiDynamicProcessorLock) );
  if ( v12 )
    ExpReleaseFastMutexContended((unsigned int *)&KiDynamicProcessorLock, v12);
  KfLowerIrql(v11);
  KeAbPostRelease((unsigned int)&KiDynamicProcessorLock);
  return v10;
}
