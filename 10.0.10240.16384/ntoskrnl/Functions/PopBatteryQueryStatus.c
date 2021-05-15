// PopBatteryQueryStatus 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopBatteryQueryStatus(int a1, int a2)
{
  __int64 v4; // kr00_8
  unsigned int v5; // r0
  unsigned int v6; // r3
  int result; // r0
  unsigned int v8; // r5
  int v9; // lr
  int v10; // r6
  unsigned int v11; // r7
  unsigned int v12; // r1
  unsigned int v13; // r3
  int v14; // r2
  int (__fastcall *v15)(int, int, _DWORD *); // r3
  _DWORD *v16; // r5
  _DWORD *v17; // r4
  int v18; // r1
  int v19; // r2
  int v20; // r3

  memset((_BYTE *)(a1 + 120), 0, 20);
  *(_DWORD *)(a1 + 120) = *(_DWORD *)(a1 + 60);
  if ( !a2 )
  {
    v4 = *(_QWORD *)(a1 + 100);
    v5 = -1;
    *(_DWORD *)(a1 + 124) = -1;
    *(_DWORD *)(a1 + 128) = v4;
    v6 = *(_DWORD *)(a1 + 88);
    if ( HIDWORD(v4) <= v6 )
      return sub_7F3A2C();
    v8 = v6 + 1;
    v9 = *(_DWORD *)(a1 + 80);
    v10 = 100;
    v11 = *(_DWORD *)(a1 + 104);
    v12 = 199 * v9;
    while ( 1 )
    {
      v13 = v12 / 0xC8;
      if ( v12 / 0xC8 - 1 >= v11 && v12 / 0xC8 - 1 < v5 )
        v5 = v13 - 1;
      if ( v13 <= v11 )
        break;
      --v10;
      v12 -= 2 * v9;
      if ( !v10 )
        goto LABEL_13;
    }
    if ( v13 > v8 )
      v8 = v12 / 0xC8;
LABEL_13:
    *(_DWORD *)(a1 + 132) = v8;
    *(_DWORD *)(a1 + 136) = v5;
    DbgPrintEx(146, 2, (int)"\nBattery Triggers [%p]\n|- High = %u\n|- Low  = %u\n", a1);
  }
  PopPrepareIoctl(*(_DWORD *)(a1 + 28), 2703436, 0, a1 + 120, 20, 16);
  if ( !a2 )
  {
    v14 = *(_DWORD *)(*(_DWORD *)(a1 + 28) + 96);
    v15 = PopBatteryIrpComplete;
    *(_QWORD *)(v14 - 8) = *(_QWORD *)(&a1 - 1);
    *(_BYTE *)(v14 - 37) = -32;
    IofCallDriver(*(_DWORD *)(a1 + 24), *(_DWORD *)(a1 + 28));
    return 0;
  }
  result = IoSynchronousCallDriver(*(_DWORD *)(a1 + 24), *(_DWORD *)(a1 + 28));
  if ( result >= 0 )
  {
    v16 = (_DWORD *)(a1 + 100);
    v17 = (_DWORD *)(a1 + 120);
    v18 = v17[1];
    v19 = v17[2];
    v20 = v17[3];
    *v16 = *v17;
    v16[1] = v18;
    v16[2] = v19;
    v16[3] = v20;
    return 0;
  }
  return result;
}
