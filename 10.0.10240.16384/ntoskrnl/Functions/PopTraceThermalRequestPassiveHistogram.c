// PopTraceThermalRequestPassiveHistogram 
 
int __fastcall PopTraceThermalRequestPassiveHistogram(int a1)
{
  int v2; // r4
  int result; // r0
  unsigned int v4; // r3
  int v5; // r5
  int v6; // r7
  unsigned int v7; // r3
  int v8; // r8
  unsigned int v9[2]; // [sp+8h] [bp-E0h] BYREF
  _DWORD v10[14]; // [sp+10h] [bp-D8h] BYREF
  int v11[2]; // [sp+48h] [bp-A0h] BYREF
  char v12[16]; // [sp+50h] [bp-98h] BYREF
  int *v13; // [sp+60h] [bp-88h]
  int v14; // [sp+64h] [bp-84h]
  int v15; // [sp+68h] [bp-80h]
  int v16; // [sp+6Ch] [bp-7Ch]
  void *v17; // [sp+70h] [bp-78h]
  int v18; // [sp+74h] [bp-74h]
  int v19; // [sp+78h] [bp-70h]
  int v20; // [sp+7Ch] [bp-6Ch]
  int v21[26]; // [sp+80h] [bp-68h] BYREF

  v2 = 0;
  result = IoGetDeviceAttachmentBaseRef(*(_DWORD *)(*(_DWORD *)(a1 + 16) + 24));
  v5 = result;
  if ( result )
  {
    v4 = *(_DWORD *)(result + 176);
    v6 = *(_DWORD *)(v4 + 20);
  }
  else
  {
    v6 = 0;
  }
  if ( v6 )
  {
    PoStoreDiagnosticContext(*(_DWORD **)(a1 + 12), 0, v9, v4);
    result = ExAllocatePoolWithTag(1, v9[0]);
    v2 = result;
    if ( result )
    {
      result = PoStoreDiagnosticContext(*(_DWORD **)(a1 + 12), result, v9, v7);
      if ( result >= 0 )
      {
        v8 = *(_DWORD *)(v2 + 8);
        result = PopDiagSnapPassiveHistogram(a1 + 24, v21);
        if ( (unsigned int)dword_6163C8 > 5 )
        {
          result = TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64);
          if ( result )
          {
            v10[8] = v11;
            v10[9] = 0;
            v10[10] = 2;
            v10[11] = 0;
            v10[12] = *(_DWORD *)(v6 + 164);
            v10[13] = 0;
            v11[0] = *(unsigned __int16 *)(v6 + 160);
            v11[1] = 0;
            TlgCreateWsz((int)v12, (unsigned __int16 *)(v8 + v2));
            v13 = v21;
            v14 = 0;
            v15 = 80;
            v16 = 0;
            v17 = &PopThermalTrackingThresholds;
            v18 = 0;
            v19 = 20;
            v20 = 0;
            result = TlgWrite(&dword_6163C8, (unsigned __int8 *)dword_414338 + 1, 0, 0, 7, v10);
          }
        }
      }
    }
  }
  if ( v5 )
    result = ObfDereferenceObjectWithTag(v5);
  if ( v2 )
    result = ExFreePoolWithTag(v2);
  return result;
}
