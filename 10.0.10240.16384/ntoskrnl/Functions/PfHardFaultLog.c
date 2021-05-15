// PfHardFaultLog 
 
int __fastcall PfHardFaultLog(int a1, int a2)
{
  int result; // r0
  int v5; // r0
  int v6; // r4
  __int64 v7; // r2
  __int64 v8; // [sp+8h] [bp-28h] BYREF
  int v9[8]; // [sp+10h] [bp-20h] BYREF

  if ( !*(_QWORD *)a1 )
    return sub_5440D8();
  switch ( a2 )
  {
    case 0:
      goto LABEL_4;
    case 1:
      v5 = 626;
      break;
    case 2:
      v5 = 627;
      break;
    default:
LABEL_4:
      v5 = 544;
      break;
  }
  result = EtwTraceTimedEvent(v5, 0x2000, a1 + 16, 24, 4200450, a1);
  if ( *(_QWORD *)(a1 + 40) )
  {
    if ( a2 != 2 )
    {
      KeQueryTickCount((int *)&v8);
      v6 = v8;
      v7 = *(_QWORD *)(a1 + 40) - v8;
      *(_QWORD *)(a1 + 40) = v7;
      HIDWORD(v7) = -(int)v7;
      LODWORD(v7) = (unsigned __int64)-__SPAIR64__(*(_DWORD *)(a1 + 44), v7) >> 32;
      *(_DWORD *)(a1 + 40) = HIDWORD(v7);
      *(_DWORD *)(a1 + 44) = v7;
      v9[0] = 2 * HIDWORD(v7);
      LODWORD(v7) = *(_DWORD *)(a1 + 16);
      v9[1] = dword_643B68;
      v9[4] = *(_DWORD *)(a1 + 28);
      v9[2] = (*(_DWORD *)(a1 + 20) << 23) | ((unsigned int)v7 >> 9);
      LODWORD(v7) = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150);
      v9[5] = (*(_DWORD *)(v7 + 200) >> 3) & 0x1C000000 ^ (*(_DWORD *)(v7 + 204) ^ *(_DWORD *)(v7 + 200) ^ v7) & 0x1FFFFFFF;
      v9[3] = *(_DWORD *)(a1 + 24);
      result = PfLogEvent(29, v6, v9, 24);
    }
  }
  return result;
}
